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

#include <boost/any.hpp>


class Event final
{
    public:
        enum class Type
        {
            Parametrics,
            Replacement,
        };

        enum class Parameter
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

        typedef std::milli ParameterValue;
        typedef std::map<Parameter, ParameterValue> Parametrics;

        Event(const Event::Type &, const Parametrics &);
        ~Event();

    private:
        boost::any m_data;
        Type m_type;
};


class Events
{
    public:
        Events();
        Events(const Events &) = delete;
        ~Events();

        Events& operator=(const Events &) = delete;

        void insert(const QDateTime &, const Event &);

        const std::deque< std::pair<QDateTime, Event> >& events() const;

    private:
        std::deque< std::pair<QDateTime, Event> > m_events;
};

#endif // EVENTS_HPP
