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


#include <memory>

#include "events.hpp"

class EventsModel
{
    public:
        EventsModel();
        EventsModel(const EventsModel &) = delete;
        ~EventsModel();

        EventsModel& operator=(const EventsModel &) = delete;
        
        void insert(const QDateTime &, const WaterParameters::List &);

    private:
        std::map<QDateTime, std::unique_ptr<IEvent>> m_events;

        void refreshData();
};

#endif // EVENTS_MODEL_HPP
