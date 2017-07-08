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

struct IEventVisitor;

struct IEvent
{
    virtual ~IEvent() = default;
    
    virtual void visit(IEventVisitor *) = 0;
};

class WaterParameters: public IEvent
{
    public:
        enum class Type
        {
            pH,
            GH,
            KH,
            NH3,
            NO2,
            NO3,
            K,
            P,
            Fe,
            CO2,
        };

        typedef double Value;
        typedef std::map<Type, Value> List;
        
        WaterParameters(const List &);
        virtual ~WaterParameters() = default;
        
        virtual void visit(IEventVisitor *);
        
        const List& get() const;
        
    private:
        List m_values;
};

struct IEventVisitor
{
    virtual ~IEventVisitor() = default;
    
    virtual void accept(WaterParameters *) = 0;
};


#endif // EVENTS_HPP
