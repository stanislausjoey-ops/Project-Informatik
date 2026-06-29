#include "city.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>

City::City(QString pname, int px, int py):name(pname),x(px),y(py) {}

void City::draw(QGraphicsScene& scene)
{
    scene.addEllipse(x,y,5,5,QPen(Qt::red),QBrush(Qt::red,Qt::SolidPattern));
    qDebug() << name;
    QGraphicsTextItem* label = new QGraphicsTextItem;
    label -> setPos(x,y);
    label -> setPlainText(name);
    scene.addItem(label);
}

QString City::getName()
{
    return name;
}

int City::getX()
{
    return x;
}

int City::getY()
{
    return y;
}
