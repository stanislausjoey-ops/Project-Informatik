#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QMessageBox>
#include "map.h"
#include "mapio.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionInfo_triggered();

    void on_test_DrawCity_clicked();

    void on_test_DrawMap_clicked();

    void on_test_DrawStreet_clicked();

    void on_test_DrawStreet2_clicked();

    void on_checkBox_clicked();

    void on_add_City_clicked();

    void on_fill_Map_clicked();


    void on_test_Map_clicked();

    void on_actionClear_Scene_2_triggered();

    void on_actionAbout_triggered();

    /**
     * @brief slot function Djikstra find shortest path
     *
     */
    void on_test_Djikstra_clicked();

    void on_find_Path_clicked();

    virtual void populateComboBox();

    void on_add_Street_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    Map map;
    MapIo *mapIo;
    QVector<QGraphicsItem*>drawnStreets;
};
#endif // MAINWINDOW_H
