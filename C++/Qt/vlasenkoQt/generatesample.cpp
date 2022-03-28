#include "generatesample.h"
#include "ui_generatesample.h"

GenerateSample::GenerateSample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerateSample)
{
    ui->setupUi(this);
}

GenerateSample::~GenerateSample()
{
    delete ui;
}

void GenerateSample::on_OK_clicked()
{
    realProb = ui->probability->text().toDouble();
    sizeOfGeomSample = ui->size->text().toInt();
    method = ui->bernoulli ? "bernoulli" : "inverseFunction";
    isOK = true;
    close();
}


void GenerateSample::on_Cancel_clicked()
{
    close();
}

