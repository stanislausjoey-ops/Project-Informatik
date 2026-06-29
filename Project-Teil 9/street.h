#ifndef STREET_H
#define STREET_H

#include "city.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>


class Street
{
public:
    /**
     * @brief Street Konstruktor
     * @param pcity1
     * @param pcity2
     */
    Street(City* pcity1, City* pcity2);

    /**
     * @brief draw street
     * @param scene
     */
    void draw(QGraphicsScene& scene);

    /**
     * @brief get first city that is being connected by a street
     * @return
     */
    City* getcity1() const;

    /**
     * @brief get 2nd city that is being connected by a street
     * @return
     */
    City* getcity2() const;

    /**
     * @brief draw a street with red line representing a path/route
     * @param scene
     * @return
     */
    QGraphicsItem* drawRed(QGraphicsScene& scene);

private:
    City *city1;
    City *city2;

};

#endif // STREET_H
