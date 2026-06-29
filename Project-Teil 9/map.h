#ifndef MAP_H
#define MAP_H


#include "abstractmap.h"
#include "city.h"
#include "street.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>

class Map : public AbstractMap
{
public:
    /**
     * @brief Map Konstruktor
     */
    Map();

    /**
     * @brief Function to store city into a Container
     * @param city
     */
    void addCity(City *city);

    /**
     * @brief Function to store street into a Container and if street meets requirements
     * @param street
     * @return
     */
    bool addStreet(Street *street);

    /**
     * @brief function to draw cities and streets from the containers into a scene
     * @param scene
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief Function to find a city from its name
     * @param cityName
     * @return found City
     */
    City* findCity(const QString cityName) const;

    /**
     * @brief Function to find a street from its name
     * @param street
     * @return found Street
     */
    Street* findStreet(Street *street) const;

    /**
     * @brief get a list of streets that is connected to a city
     * @param city
     * @return Container containing all available streets
     */
    QVector<Street*> getStreetList(const City* city) const;

    /**
     * @brief get City on the opposite end of the street
     * @param street
     * @param city
     * @return opposite city
     */
    City* getOppositeCity(const Street* street, const City* city) const;

    /**
     * @brief get lenght of the street
     * @param street
     * @return
     */
    double getLength(const Street* street) const;

    /**
     * @brief get List of all Cities
     * @return
     */
    QVector<City*> getCityList() const;

private:
    QVector <City*> staedte;
    QVector <Street*> streets;
};

#endif // MAP_H
