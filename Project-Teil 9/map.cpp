#include "map.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>
#include <cmath>

Map::Map() {}

void Map::addCity(City *city)
{
    staedte.append(city);
    qDebug()<<"Added City: " << city->getName();
}

bool Map::addStreet(Street *street)
{
        if (staedte.contains(street->getcity1()) && staedte.contains(street->getcity2()))
        {
        streets.append(street);
        qDebug() << "Added street from" << street->getcity1()->getName() << "to" << street->getcity2()->getName();
        return true;
        }
        else
        {
        qDebug() << "Cannot add street: One or both cities not found in the map";
        return false;
        }

}

void Map::draw(QGraphicsScene& scene)
{
    for(City* city : staedte)
    {
        city->draw(scene);
    }
    for(Street* street : streets)
    {
        street->draw(scene);
    }
}

City* Map::findCity(const QString cityName) const
{
    for (City* city:staedte)
    {
        if (city->getName() == cityName)
        {
            return city;
        }
    }
    return nullptr;
}

Street* Map::findStreet(Street* street) const
{
    for (Street* found:streets)
    {
        if (found == street)
        {
            return found;
        }
    }
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> streetlist;
    for (Street* street : streets)
    {
        if (street->getcity1()==city || street->getcity2()==city)
        {
            streetlist.append(street);
        }
    }
    return streetlist;
}

QVector<City*> Map::getCityList() const
{
    return staedte;
}

City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getcity1() == city)
    {
        return street -> getcity2();
    }
    else if (street-> getcity2() == city)
    {
        return street-> getcity1();
    }
    else
    {
        return nullptr;
    }
}

double Map::getLength(const Street* street) const
{
    int dx = street->getcity1()->getX() - street->getcity2()->getX();
    int dy = street->getcity1()->getY() - street->getcity2()->getY();
    return std::sqrt(dx*dx + dy*dy);
}
