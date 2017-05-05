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

#include <QDateTimeEdit>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QStackedLayout>

#include "main_window.hpp"


MainWindow::MainWindow():
    QMainWindow(),
    m_ui(std::make_unique<Ui_MainWindow>()),
    m_eventsModel()
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
    waterParametricsLayout->addWidget(new QLabel(tr("Data pomiaru:"), this), r, 0);
    waterParametricsLayout->addWidget(new QDateTimeEdit(this), r, 1);

    r++;

    for(const QString& parameter: {tr("pH"), tr("TwO"), tr("TwW"), tr("NH3"), tr("NO2"),
                                   tr("NO3"), tr("K"), tr("P"), tr("Fe"), tr("CO2")})
    {
        QLabel* l = new QLabel(parameter + ":", this);
        QLineEdit* e = new QLineEdit(this);

        waterParametricsLayout->addWidget(l, r, 0);
        waterParametricsLayout->addWidget(e, r, 1);

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

}
