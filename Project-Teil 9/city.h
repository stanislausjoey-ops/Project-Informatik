#ifndef CITY_H
#define CITY_H

#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>

class City
{
public:
    /**
     * @brief City Konstruktor
     * @param name
     * @param pos x
     * @param pos y
     */
    City(QString pname, int px, int py);
    /**
     * @brief draw function to put red dot in map
     * @param scene where we need to draw in
     */
    void draw(QGraphicsScene& scene);
    /**
     * @brief getName
     * @return Name of city
     */
    QString getName();
    /**
     * @brief getX
     * @return pos X
     */
    int getX();
    /**
     * @brief getY
     * @return pos Y
     */
    int getY();

private:
    QString name;
    int x;
    int y;

};

#endif // CITY_H
