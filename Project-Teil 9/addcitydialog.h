#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include "city.h"
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class addCityDialog;
}

class addCityDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief addCityDialog Konstruktor
     * @param parent
     */
    explicit addCityDialog(QWidget *parent = nullptr);
    ~addCityDialog();
    /**
     * @brief function to take input and create city based on input
     * @return city created
     */
    City* createCity() const;
    /**
     * @brief Funktion to check if input is valid
     * @return true if input fulfills all the requirements
     */
    bool validInput();


private slots:
    /**
     * @brief ok box
     */
    void on_buttonBox_accepted();
    /**
     * @brief cancel box
     */
    void on_buttonBox_rejected();

private:
    Ui::addCityDialog *ui;
};

#endif // ADDCITYDIALOG_H
