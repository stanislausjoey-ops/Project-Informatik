#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "addcitydialog.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include "mapionrw.h"
#include "dijkstra.h"
#include "createstreetdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) //pass parent to base-class constructor
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene(this)) //this: pass by reference as parent (Mainwd)
    , map()
    , mapIo(new MapIoNrw)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene); //connect graphics scene to View to handle drawing
    ui->pushButton_teste_was->hide(); //hide(): invisible at runtime
    ui->test_DrawCity->hide();
    ui->test_DrawStreet->hide();
    ui->test_DrawStreet2->hide();
    ui->test_DrawMap->hide();
    ui->test_Djikstra->hide();
    ui->test_Map->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
    delete mapIo;
}


/**
 * @brief slot function test clicked() signal
 *
 */
void MainWindow::on_pushButton_teste_was_clicked()
{
    QString wiederGabe;
    wiederGabe = ui->lineEdit_teste_was->text(); //read input from lineEdit to variable wiederGabe
    int wiederZahl; //store converted number
    bool ok;
    QString Pushed; //message string
    wiederZahl = wiederGabe.toInt(&ok,10)+4; //if input a number raise by 4
    if (ok == true)
    {
        Pushed = QString("Ihre Eingabe ist: %1.").arg(wiederZahl);
    }
    else
    {
        Pushed = QString("Ihre Eingabe ist: %1.").arg(wiederGabe);
    }
    qDebug()<< Pushed; //print message to console or debugger
    QMessageBox msgBox;
    msgBox.setText(Pushed);
    msgBox.exec();
    //scene.addRect(rand()*9/RAND_MAX,rand()*9/RAND_MAX,40,50);

}

/**
 * @brief slot function exit
 *
 */
void MainWindow::on_actionExit_triggered()
{
    close();
}

/**
 * @brief slot function clear drawn scene
 *
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}

/**
 * @brief slot function show info description in about box
 *
 */
void MainWindow::on_actionInfo_triggered()
{
    QString Beschreibung = "kurze Beschreibung !";
    QMessageBox AboutBox;
    QString AboutTitle ="Info!";
    AboutBox.about(this,AboutTitle,Beschreibung); //this = parent widget (Mainwd) -> About appears on main window
}

/**
 * @brief slot function draw 2 cities
 *
 */
void MainWindow::on_test_DrawCity_clicked()
{
    City city1 ("city1",50,100);
    City city2 ("city2",20,50);
    city1.draw(scene);
    city2.draw(scene);
}

/**
 * @brief slot function add city and then draw map
 *
 */
void MainWindow::on_test_DrawMap_clicked()
{
    City c1("city c1", 20,50);
    map.addCity(&c1);
    map.draw(scene);
}

/**
 * @brief slot function add street
 *
 */
void MainWindow::on_test_DrawStreet_clicked()
{
    City city1 ("city1",50,100);
    City city2 ("city2",20,50);
    Street street(&city1,&city2);
    street.draw(scene);
}

/**
 * @brief slot function add cities and creat street connecting these 2 cities
 *
 */
void MainWindow::on_test_DrawStreet2_clicked()
{
    City city1 ("city1",50,100);
    City city2 ("city2",20,50);
    map.addCity(&city1);
    map.addCity(&city2);
    Street street(&city1,&city2);
    if (map.addStreet(&street))
    {
        map.draw(scene);
    }
}

/**
 * @brief slot function check status of checkbox
 *
 */
void MainWindow::on_checkBox_clicked()
{
    bool ticked = ui->checkBox->isChecked();
    if (ticked)
    {
        ui->pushButton_teste_was->show();
        ui->test_DrawCity->show();
        ui->test_DrawStreet->show();
        ui->test_DrawStreet2->show();
        ui->test_DrawMap->show();
        ui->test_Djikstra->show();
        ui->test_Map->show();
    }
    else if(!ticked)
    {
        ui->pushButton_teste_was->hide();
        ui->test_DrawCity->hide();
        ui->test_DrawStreet->hide();
        ui->test_DrawStreet2->hide();
        ui->test_DrawMap->hide();
        ui->test_Djikstra->hide();
        ui->test_Map->hide();
    }

}

/**
 * @brief slot function check if add a valid city
 *
 */
void MainWindow::on_add_City_clicked()
{
    addCityDialog addcitydialog(this);
    while(addcitydialog.exec() == 1) //ask user for input
    {
        if (City* toaddCity = addcitydialog.createCity())
        {
            if(!map.findCity(toaddCity->getName()))
                {
                map.addCity(toaddCity);
                populateComboBox(); //refresh GUI elements listing cities
                map.draw(scene);
                qDebug()<< "Dialog is accepted!";
                break;
                }
            else
                {
                delete toaddCity;
                QString Beschreibung = "City already exist !";
                QMessageBox Duplicate;
                QString AboutTitle ="Error!";
                Duplicate.about(this,AboutTitle,Beschreibung);
                }
        }
        else
        {
            qDebug()<<"Nochmal versuchen!";
        }
    }
}

/**
 * @brief slot function fill map on main screen
 *
 */
void MainWindow::on_fill_Map_clicked()
{

    mapIo->fillMap(map);
    populateComboBox();
    map.draw(scene);
    qDebug() << "Map filled and drawn.";

}

/**
 * @brief slot function test if interface AbstractMap implemented correctly
 *
 */
void MainWindow::on_test_Map_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }
    testMap.draw(scene);
    qDebug() << "MapTest: End Test of the Map.";
}




void MainWindow::on_actionClear_Scene_2_triggered()
{
    scene.clear();
}



void MainWindow::on_actionAbout_triggered()
{
    QString Beschreibung = "kurze Beschreibung !";
    QMessageBox AboutBox;
    QString AboutTitle ="Info!";
    AboutBox.about(this,AboutTitle,Beschreibung);
}
/**
 * @brief test Djikstra shortest path
 */
void MainWindow::on_test_Djikstra_clicked()
{
    QString startCityName = ui->startCity->currentText(); //"Aachen";
    //QString targetCityName = "Koeln"
    QString targetCityName = ui->endCity->currentText();//"Bonn";

    if (startCityName == targetCityName)
    {
        qDebug() << "Start and target cities are the same. No path needed.";
        QMessageBox::information(this, "Path Info", "Start and target cities are the same.");
        return;
    }

    QVector<Street*> shortestPath = Dijkstra::search(map, startCityName, targetCityName);

    for (Street* street : shortestPath)
    {
        street->drawRed(scene);
        qDebug() << "Street from" << street->getcity1()->getName() << "to" << street->getcity2()->getName();
    }

    if (shortestPath.isEmpty())
    {
        qDebug() << "No path found between" << startCityName << "and" << targetCityName;
    }
}



/**
 * @brief recommendation find best path
 */
void MainWindow::on_find_Path_clicked()
{
    QString firstCity = ui->startCity->currentText();
    QString secondCity = ui->endCity->currentText();
    if (firstCity == secondCity)
    {
        qDebug() << "Start and target cities are the same. No path needed.";
        QMessageBox::information(this, "Path Info", "Start and target cities are the same. No path needed.");
        return;
    }

    for (QGraphicsItem* drawings : drawnStreets)
    {
        scene.removeItem(drawings);
        delete drawings;
    }
    drawnStreets.clear();

    QVector<Street*> Path = Dijkstra::search(map, firstCity, secondCity);

    for (Street* street : Path)
    {
        QGraphicsItem* drawing = street->drawRed(scene);
        drawnStreets.append(drawing);
        qDebug() << "Street from" << street->getcity1()->getName() << "to" << street->getcity2()->getName();
    }
    if (Path.isEmpty())
    {
        qDebug() << "No path found between" << firstCity << "and" << secondCity;
    }
}

void MainWindow::populateComboBox()
{
    ui->startCity->clear();
    ui->endCity->clear();
    for(City* city: map.getCityList() )
    {
    QString name = city->getName();
    ui->startCity->addItem(name);
    ui->endCity->addItem(name);
    }
}


/**
 * @brief add street
 */

void MainWindow::on_add_Street_clicked()
{
    bool inputValid = false;
    while (!inputValid)
    {
        createStreet streetDialog(this);
        for(City* city: map.getCityList() )
        {
            QString name = city->getName();
            streetDialog.populateChoice(name);
        }
        if (streetDialog.exec()==1)
        {
            QString from = streetDialog.getfrom();
            QString to = streetDialog.getto();
            if(from==to)
            {
                QMessageBox::warning(this, "Error", "Same city cannot be chosen");
            }
            else
            {
            City* fromCity = map.findCity(from);
            City* toCity = map.findCity(to);
            Street* newstreet = new Street(fromCity,toCity);
            map.addStreet(newstreet);
            map.draw(scene);
            QMessageBox::information(this, "Info", "Street created");
            inputValid = true;
            }
        }
        else
        {
            inputValid = true;
        }
    }
}


