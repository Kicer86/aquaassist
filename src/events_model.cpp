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
    template<typename T> QString displayRoleFor(const T& event);

    template<>
    QString displayRoleFor<WaterParametrics::List>(const WaterParametrics::List& waterParameters)
    {
        QString text;

        for(const std::pair<WaterParametrics::Type, WaterParametrics::Value>& param: waterParameters)
        {

        }

        return text;
    }

    template<typename T> std::deque<std::pair<QDateTime, QString>> displayRoleFor(const EventsContainer<T>& event);

    template<>
    std::deque<std::pair<QDateTime, QString>> displayRoleFor<WaterParametrics::List>(const EventsContainer<WaterParametrics::List>& waterParameters)
    {
        std::deque<std::pair<QDateTime, QString>> result;

        for(const std::pair<QDateTime, WaterParametrics::List>& params: waterParameters.list())
            result.emplace_back(params.first, displayRoleFor(params.second));

        return result;
    }
}


EventsModel::EventsModel(): m_waterParametrics(), m_decorationRoles()
{
    connect(&m_waterParametrics, &WaterParametricsContainer::changed, this, &EventsModel::refreshData);
}


EventsModel::~EventsModel()
{

}


void EventsModel::insert(const QDateTime& time, const WaterParametrics::List& parametrics)
{
    m_waterParametrics.insert(time, parametrics);
}


QVariant EventsModel::data(const QModelIndex& idx, int role) const
{
    assert(idx.isValid());
    assert(idx.column() < 2);
    assert(idx.row() < static_cast<int>(m_decorationRoles.size()));

    QVariant result;

    if (role == Qt::DecorationRole)
        result = idx.column() == 0 ? QVariant(m_decorationRoles[idx.row()].first):
                                     QVariant(m_decorationRoles[idx.row()].second);

    return result;
}


int EventsModel::rowCount(const QModelIndex& parent) const
{
    const int rows = parent.isValid()? 0 : m_waterParametrics.list().size();

    return rows;
}


int EventsModel::columnCount(const QModelIndex& parent) const
{
    const int columns = parent.isValid()? 0: 2;

    return columns;
}


void EventsModel::refreshData()
{
    m_decorationRoles.clear();

    const auto waterParametersDecorated = displayRoleFor(m_waterParametrics);
    m_decorationRoles.insert(m_decorationRoles.end(), waterParametersDecorated.begin(), waterParametersDecorated.end());

    std::sort(m_decorationRoles.begin(), m_decorationRoles.end(), [](const std::pair<QDateTime, QString>& lhs, const std::pair<QDateTime, QString>& rhs)
    {
        return lhs.first < rhs.first;
    });
}
