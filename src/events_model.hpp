/*
 * Model for list of events
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

#ifndef EVENTS_MODEL_HPP
#define EVENTS_MODEL_HPP

#include <QAbstractTableModel>

#include "events.hpp"

class EventsModel: public QAbstractTableModel
{
    public:
        EventsModel();
        EventsModel(const EventsModel &) = delete;
        ~EventsModel();

        EventsModel& operator=(const EventsModel &) = delete;
        
        void insert(const QDateTime &, const WaterParametrics::List &);

        // QAbstractTableModel:
        QVariant data(const QModelIndex &, int) const override;
        int rowCount(const QModelIndex &) const override;
        int columnCount(const QModelIndex &) const override;

    private:
        WaterParametricsContainer m_waterParametrics;

        std::deque< std::pair<QDateTime, QString> > m_decorationRoles;

        void refreshData();
};

#endif // EVENTS_MODEL_HPP
