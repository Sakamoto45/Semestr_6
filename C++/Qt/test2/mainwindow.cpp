#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dialog(new Dialog)
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


    dialog->show();
    dialog->setModal(true);
    dialog->exec();

//    ui->label_2->setText(dialog->text);
    repaint();
}


void MainWindow::on_actionabout_triggered()
{
    QMessageBox::about(this, "Help", "Ткаченко Егор \n2022");
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    QBrush brush;
    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;
    pen.setColor(dialog->color);
    pen.setWidth(dialog->width);
    painter.setPen(pen);


    painter.drawLine(0, 0, width(), height());

    painter.drawRect(width() / 2 + 10, height() / 2 + 10, width() / 2 - 20, height() / 2 - 20);

    painter.drawPolyline(polyline);

    painter.end();
}

