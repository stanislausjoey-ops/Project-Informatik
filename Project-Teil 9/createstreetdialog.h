#ifndef CREATESTREETDIALOG_H
#define CREATESTREETDIALOG_H

#include <QDialog>
#include <QString>
#include <Qdebug>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class createStreet;
}

class createStreet : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief createStreet Konstruktor
     * @param parent
     */
    explicit createStreet(QWidget *parent = nullptr);
    ~createStreet();
    /**
     * @brief get input from the combobox
     * @return city choice
     */
    QString getfrom() const;
    /**
     * @brief get input from other combobox
     * @return city choice
     */
    QString getto() const;
    /**
     * @brief function to populate the combobox
     * @param value
     */
    void populateChoice(const QString &value);

private:
    Ui::createStreet *ui;
};

#endif // CREATESTREETDIALOG_H
