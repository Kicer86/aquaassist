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

#include "events_model.hpp"

#include <cassert>


namespace
{
    /*
    QString displayRoleFor(const Event& event)
    {
        QString text;

        switch(event.type())
        {
            case Event::Type::Parametrics:
            {
                const Event::Parametrics* parametrics = boost::any_cast<Event::Parametrics>(&event.data());

                for(const std::pair<Event::Parameter, Event::ParameterValue>& param: *parametrics)
                {

                }

                break;
            }

            case Event::Type::Replacement:
                break;
        }

        return text;
    }
    */
}


EventsModel::EventsModel(): m_events()
{

}


EventsModel::~EventsModel()
{

}


QVariant EventsModel::data(const QModelIndex& idx, int role) const
{
    /*
    const std::deque< std::pair<QDateTime, Event> >& events = m_events.events();

    assert(idx.isValid());
    assert(idx.column() < 2);
    assert(idx.row() < static_cast<int>(events.size()));

    const std::pair<QDateTime, Event>& event = events[idx.row()];

    QVariant result;

    if (role == Qt::DisplayRole)
    {
        if (idx.column() == 0)
            result = event.first;
        else
        {

        }
    }

    return result;
    */
}


int EventsModel::rowCount(const QModelIndex& parent) const
{
    const int rows = parent.isValid()? 0 : m_events.list().size();

    return rows;
}


int EventsModel::columnCount(const QModelIndex& parent) const
{
    const int columns = parent.isValid()? 0: 2;

    return columns;
}
