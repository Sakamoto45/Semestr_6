#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    width(3),
    color(Qt::black),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_buttonBox_rejected()
{
    hide();
}


void Dialog::on_buttonBox_accepted()
{
    width = ui->width_input->text().toInt();
    if (ui->Red->isChecked()) color = Qt::red;
    if (ui->Green->isChecked()) color = Qt::green;
    if (ui->Blue->isChecked()) color = Qt::blue;
    hide();
}


void Dialog::on_Green_clicked()
{
    ui->Red->setChecked(false);
    ui->Blue->setChecked(false);
}


void Dialog::on_Red_clicked()
{
    ui->Green->setChecked(false);
    ui->Blue->setChecked(false);
}


void Dialog::on_Blue_clicked()
{
    ui->Red->setChecked(false);
    ui->Green->setChecked(false);
}

