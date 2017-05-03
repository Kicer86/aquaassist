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

#include <QLineEdit>
#include <QGridLayout>
#include <QStackedLayout>

#include "main_window.hpp"


MainWindow::MainWindow(): 
    QMainWindow(),
    m_ui(std::make_unique<Ui_MainWindow>())
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
    for(const char* parameter: {"pH", "TwO", "TwW", "NH3", "NO2", "NO3", "K", "P", "Fe", "CO2"})
    {
        QLabel* l = new QLabel(parameter, this);
        QLineEdit* e = new QLineEdit(this);
        
        waterParametricsLayout->addWidget(l, r, 0);
        waterParametricsLayout->addWidget(e, r, 1);
        
        r++;
    }
}


MainWindow::~MainWindow()
{
    
}
