#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , doc(new Document)
{
    ui->setupUi(this);
    ui->label->setGeometry(100, 100, 300, 50);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_LeftButton_clicked()
{
    ui->label->setText(doc->SomeFunctionFromDocument());

}


void MainWindow::on_RighrButton_clicked()
{
    ui->label->setText("Right Button Pressed");
}

void MainWindow::on_actionopen_dialog_triggered()
{

    dialog = new Dialog;
    dialog->show();
    dialog->setModal(true);
    dialog->exec();
    ui->label_2->setText(dialog->text);
}


void MainWindow::on_actionabout_triggered()
{
    QMessageBox::about(this, "Help", "Ткаченко Егор \n2022");
}

