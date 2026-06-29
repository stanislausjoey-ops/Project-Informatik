#include "createstreetdialog.h"
#include "ui_createstreetdialog.h"
createStreet::createStreet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::createStreet)
{
    ui->setupUi(this);
}

createStreet::~createStreet()
{
    delete ui;
}

QString createStreet::getfrom() const
{
    QString from = ui->fromCity->currentText();
    return from;
}

QString createStreet::getto() const
{
    QString to = ui->toCity->currentText();
    return to;
}

void createStreet::populateChoice(const QString &value)
{
    ui->fromCity->addItem(value);
    ui->toCity->addItem(value);
}


