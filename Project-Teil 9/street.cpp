#include "street.h"
#include "city.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>


Street::Street(City *pcity1, City *pcity2) : city1(pcity1), city2(pcity2){}

void Street::draw(QGraphicsScene& scene)
{
    scene.addLine(city1->getX(),city1->getY(),city2->getX(),city2->getY(),QPen(Qt::black));
}

City* Street::getcity1() const
{
    return city1;
}

City* Street::getcity2() const
{
    return city2;
}

QGraphicsItem *Street::drawRed(QGraphicsScene& scene)
{
    QPen pen(Qt::red);
    pen.setWidth(2);
    QGraphicsLineItem* drawing = scene.addLine(city1->getX(), city1->getY(), city2->getX(), city2->getY(), pen);
    return drawing;
}
