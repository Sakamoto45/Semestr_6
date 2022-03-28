#include "pvalues.h"
#include "ui_pvalues.h"

PValues::PValues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PValues)
{
    ui->setupUi(this);
}

PValues::~PValues()
{
    delete ui;
}

void PValues::on_OK_clicked()
{
    realProb = ui->realProbability->text().toDouble();
    sizeOfGeomSample = ui->sizeOfGeomSample->text().toInt();
    method = ui->bernoulli ? "bernoulli" : "inverseFunction";
    hypotheticalProb = ui->hypotheticalProp->text().toDouble();
    sizeOfPValueSample = ui->sizeOfPValueSample->text().toInt();
    isOK = true;
    close();
}


void PValues::on_Cancel_clicked()
{
    close();
}

