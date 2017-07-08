/*
 * Main window class
 * Copyright (C) 2017  Michał Walenciak <Kicer86@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "main_window.hpp"

#include <QDateTimeEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedLayout>


namespace 
{
    typedef std::pair<WaterParameters::Type, QString> ParameterName;
    const std::array<ParameterName, 10> parameterNames
    {
        std::make_pair( WaterParameters::Type::pH,  QObject::tr("pH")  ),
        std::make_pair( WaterParameters::Type::GH,  QObject::tr("TwO") ), 
        std::make_pair( WaterParameters::Type::KH,  QObject::tr("TwW") ), 
        std::make_pair( WaterParameters::Type::NH3, QObject::tr("NH₃") ), 
        std::make_pair( WaterParameters::Type::NO2, QObject::tr("NO₂") ),
        std::make_pair( WaterParameters::Type::NO3, QObject::tr("NO₃") ), 
        std::make_pair( WaterParameters::Type::K,   QObject::tr("K")   ), 
        std::make_pair( WaterParameters::Type::P,   QObject::tr("P")   ), 
        std::make_pair( WaterParameters::Type::Fe,  QObject::tr("Fe")  ), 
        std::make_pair( WaterParameters::Type::CO2, QObject::tr("CO₂") )
    };
}


MainWindow::MainWindow():
    QMainWindow(),
    m_ui(std::make_unique<Ui_MainWindow>()),
    m_eventsModel(),
    m_editors(),
    m_timeEdit(nullptr)
{
    m_ui->setupUi(this);

    // finish ui construction
    QWidget* waterParametricsWidget = new QWidget(this);
    QWidget* waterReplacementWidget = new QWidget(this);

    QGridLayout* waterParametricsLayout = new QGridLayout(waterParametricsWidget);
    QHBoxLayout* waterReplacementLayout = new QHBoxLayout(waterReplacementWidget);
    m_ui->eventStackedWidget->addWidget(waterParametricsWidget);
    m_ui->eventStackedWidget->addWidget(waterReplacementWidget);

    int r = 0;
    m_timeEdit = new QDateTimeEdit(this);
    waterParametricsLayout->addWidget(new QLabel(tr("Data pomiaru:"), this), r, 0);
    waterParametricsLayout->addWidget(m_timeEdit, r, 1);

    r++;
    
    for(const auto& parameter: parameterNames)
    {
        QLabel* l = new QLabel(parameter.second + ":", this);
        QLineEdit* e = new QLineEdit(this);

        waterParametricsLayout->addWidget(l, r, 0);
        waterParametricsLayout->addWidget(e, r, 1);
        
        m_editors.push_back(std::make_pair(parameter.first, e));

        r++;
    }

    QPushButton* applyParametricsButton = new QPushButton(tr("Dodaj"), this);
    connect(applyParametricsButton, &QPushButton::pressed, this, &MainWindow::addWaterParametrics);

    waterParametricsLayout->addWidget(applyParametricsButton, r, 1);
    waterParametricsLayout->addWidget(new QWidget(this));
}


MainWindow::~MainWindow()
{

}


void MainWindow::addWaterParametrics()
{
    WaterParameters::List parameters;
    
    for (const auto& editor: m_editors)
    {
        const QString value = editor.second->text();
        
        if (value.isEmpty() == false)
        {
            const double numeric = value.toDouble();
            const WaterParameters::Value parameterValue(numeric);
            parameters.emplace(editor.first, parameterValue);
        }
    }
    
    if (parameters.empty() == false)
    {
        const QDateTime time = m_timeEdit->dateTime();
        m_eventsModel.insert(time, parameters);
    }
}
