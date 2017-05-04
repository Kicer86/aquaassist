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

#include "events.hpp"


Event::Event(const Event::Type& type, const Parametrics& data): m_type(type), m_data(data)
{

}


Event::~Event()
{

}


///////////////////////////////////////////////////////////////////////////////


Events::Events()
{

}


Events::~Events()
{

}


void Events::insert(const QDateTime& time, const Event& event)
{
    m_events.emplace_back(time, event);
}


const std::deque< std::pair<QDateTime, Event> >& Events::events() const
{
    return m_events;
}

