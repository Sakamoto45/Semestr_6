#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionGenerate_sample_triggered()
{
    GenerateSample window;
    window.setModal(true);
    window.exec();
    if(window.isOK) {
        auto dist = Distribution(window.realProb);
        std::map<int, int> *geomGroupedSample = dist.geomGroupedSample(window.sizeOfGeomSample, window.method);
        std::pair<double, int> chiSquare = dist.chiSquare(window.sizeOfGeomSample, *geomGroupedSample, window.realProb);

        QString output = "Geometric distribution with probability " + QString::number(window.realProb) +
                ". Size of smaple: " + QString::number(window.sizeOfGeomSample) + ". Chi-Square: " +
                QString::number(chiSquare.first) + ". Degree of Freedom: " + QString::number(chiSquare.second);
        ui->label->setText(output);
    }
}


void MainWindow::on_actionP_values_triggered()
{
    PValues window;
    window.setModal(true);
    window.exec();
    if(window.isOK) {
        auto dist = Distribution(window.realProb);
        std::vector<double> pValueSample = dist.pValueSample(window.sizeOfGeomSample, window.realProb,
                                                   window.hypotheticalProb,window.method, window.sizeOfPValueSample);
        std::sort(pValueSample.begin(), pValueSample.end(), std::less<double>());

        QString output = "Geometric distribution with probability " + QString::number(window.realProb) +
                ". Size of smaple: " + QString::number(window.sizeOfGeomSample) +
                ". Hypothetical probability: " + QString::number(window.hypotheticalProb) +
                ". Number of repeats: " + QString::number(window.sizeOfPValueSample);
        ui->label->setText(output);

//        double alpha{};
//        int i{};
//        std::cout << std::fixed << "signLevel" << '\t' << "pValue" << std::endl;
//        while((alpha += 0.05) <= 1.001) {
//            for(; i < sizeOfPValueSample && pValueSample[i] < alpha; ++i) {}
//            std::cout << std::setprecision(2) << alpha << std::setprecision(4)
//                      << '\t' << (double) i / sizeOfPValueSample << std::endl;
        }
}



void MainWindow::on_actionAbout_triggered()
{
    About window;
    window.setModal(true);
    window.exec();
}

