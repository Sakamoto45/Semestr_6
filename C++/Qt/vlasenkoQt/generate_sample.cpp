#include "generate_sample.h"
#include "ui_generate_sample.h"

Generate_sample::Generate_sample(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generate_sample)
{
    ui->setupUi(this);
}

Generate_sample::~Generate_sample()
{
    delete ui;
}
