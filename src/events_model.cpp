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


EventsModel::EventsModel(): m_events()
{
    
}


EventsModel::~EventsModel()
{

}


void EventsModel::insert(const QDateTime& time, const WaterParameters::List& parametrics)
{
    auto waterParameters = std::make_unique<WaterParameters>(parametrics);
    m_events.insert(std::make_pair(time, std::move(waterParameters)) );
}


void EventsModel::refreshData()
{
    /*
    m_decorationRoles.clear();

    const auto waterParametersDecorated = displayRoleFor(m_waterParametrics);
    m_decorationRoles.insert(m_decorationRoles.end(), waterParametersDecorated.begin(), waterParametersDecorated.end());

    std::sort(m_decorationRoles.begin(), m_decorationRoles.end(), [](const std::pair<QDateTime, QString>& lhs, const std::pair<QDateTime, QString>& rhs)
    {
        return lhs.first < rhs.first;
    });
    */
}
