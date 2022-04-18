#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , document(new Document)
{
    ui->setupUi(this);
    document->setup();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete document;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter;
    painter.begin(this);

    painter.drawText(10, 20, "Hello");
    painter.drawRect(30, 30, 130, 130);
    painter.drawEllipse(30, 30, 130, 130);

    int i = document->getI();

    painter.drawText(i, i, "Hello");

    painter.end();
}

void MainWindow::on_actionH_i_triggered()
{
    QMessageBox::about(this, "Title", "Hello!");
}

void MainWindow::on_actionChange_triggered()
{
    document->setI(300);
    repaint();
}

