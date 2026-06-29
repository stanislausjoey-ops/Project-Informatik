#include "addcitydialog.h"
#include "ui_addcitydialog.h"
#include "city.h"

addCityDialog::addCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addCityDialog)
{
    ui->setupUi(this);
}

addCityDialog::~addCityDialog()
{
    delete ui;
}

City* addCityDialog::createCity() const
{
    QString name = ui->cityName->text();
    QString posX = ui->posX->text();
    QString posY = ui->posY->text();
    bool ok1;
    bool ok2;
    int x = posX.toInt(&ok1,10);
    int y = posY.toInt(&ok2,10);
    if (ok1 == true && ok2 == true && !ui->cityName->text().isEmpty())
    {
        qDebug() << "Creating city:" << name << "at" << x << "," << y;
        return new City(name, x, y);
    }
    else
    {
        return nullptr;
    }
}


bool addCityDialog::validInput()
{
    QString posX = ui->posX->text();
    QString posY = ui->posY->text();
    bool ok1;
    bool ok2;
    posX.toInt(&ok1,10);
    posY.toInt(&ok2,10);
    if (ok1 == true && ok2 == true && !ui->cityName->text().isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void addCityDialog::on_buttonBox_accepted()
{
    if (validInput())
    {
        QString Beschreibung = "Input valid! City created";
        QMessageBox AboutBox;
        QString AboutTitle ="Info!";
        AboutBox.about(this,AboutTitle,Beschreibung);
        done(QDialog::Accepted);
    }
    else
    {
        QString Beschreibung = "Input not accepted! Bitte nochmal versuchen.";
        QMessageBox AboutBox;
        QString AboutTitle ="Info!";
        AboutBox.about(this,AboutTitle,Beschreibung);
        done(QDialog::Accepted);
    }
}

void addCityDialog::on_buttonBox_rejected()
{
    QString Beschreibung = "Input Rejected!";
    QMessageBox AboutBox;
    QString AboutTitle ="Info!";
    AboutBox.about(this,AboutTitle,Beschreibung);
    done(QDialog::Rejected);
}

