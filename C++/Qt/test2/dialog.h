#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
//    QString text;
    int width;
    QColor color;

private slots:
    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_Green_clicked();

    void on_Red_clicked();

    void on_Blue_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
