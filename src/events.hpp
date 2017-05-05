/*
 * List of event
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

#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <deque>
#include <map>
#include <ratio>

#include <QDateTime>
#include <QObject>


namespace WaterParametrics
{
    enum class Type
    {
        pH  = 1,
        GH  = 2,
        KH  = 3,
        NH3 = 4,
        NO2 = 5,
        NO3 = 6,
        K   = 7,
        P   = 9,
        Fe  = 10,
        CO2 = 11,
    };

    typedef std::milli Value;
    typedef std::map<Type, Value> List;
}


class EventsContainerBase: public QObject
{
        Q_OBJECT

    public:
        EventsContainerBase();
        virtual ~EventsContainerBase();

    signals:
        void changed();
};


template<typename T>
class EventsContainer: public EventsContainerBase
{
    public:
        EventsContainer(): EventsContainerBase()
        {
        }

        EventsContainer(const EventsContainer &) = delete;

        virtual ~EventsContainer()
        {

        }

        EventsContainer& operator=(const EventsContainer &) = delete;

        void insert(const QDateTime& time, const T& data)
        {
            m_events.emplace_back(time, data);
        }

        const std::deque< std::pair<QDateTime, T> >& list() const
        {
            return m_events;
        }

    private:
        std::deque<std::pair<QDateTime, T> > m_events;
};

typedef EventsContainer<WaterParametrics::List> WaterParametricsContainer;

extern template class EventsContainer<WaterParametrics::List>;

#endif // EVENTS_HPP
