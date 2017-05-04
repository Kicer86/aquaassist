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

#include <map>

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

        Event();
        ~Event();

    private:
        boost::any m_data;

};


class Events
{
    public:
        Events();
        Events(const Events &) = delete;
        ~Events();

        Events& operator=(const Events &) = delete;

    private:
        std::map<QDateTime, Event> m_events;
};

#endif // EVENTS_HPP
