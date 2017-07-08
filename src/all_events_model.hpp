/*
 * Qt based model for all events
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

#ifndef ALLEVENTSMODEL_HPP
#define ALLEVENTSMODEL_HPP


#include <memory>

#include <QAbstractTableModel>

#include "events.hpp"

class AllEventsModel: public QAbstractTableModel
{
    public:
        AllEventsModel();
        AllEventsModel(const AllEventsModel &) = delete;
        ~AllEventsModel();

        AllEventsModel& operator=(const AllEventsModel &) = delete;
        
        void insert(const QDateTime &, const WaterParameters::List &);

        // QAbstractTableModel:
        QVariant data(const QModelIndex &, int) const override;
        int rowCount(const QModelIndex &) const override;
        int columnCount(const QModelIndex &) const override;

    private:
        std::map<QDateTime, std::unique_ptr<IEvent>> m_events;
        std::deque< std::pair<QDateTime, QString> > m_decorationRoles;

        void refreshData();
};


#endif // ALLEVENTSMODEL_HPP
