#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setup(Document* doc) {
    setModal(true);
    document = doc;

    ui->H1_input_p->setValue(document->p_1);
    ui->H1_input_k->setValue(document->k_1);
    ui->H1_input_sample_size->setValue(document->sample_size);

    switch (document->method) {
    case Document::Method::Bernulli:
        ui->H1_radio_Bernulli->setChecked(true);
        ui->H1_radio_Table->setChecked(false);
        break;
    case Document::Method::Table:
        ui->H1_radio_Bernulli->setChecked(false);
        ui->H1_radio_Table->setChecked(true);
        break;
    default:
        break;
    }
}

void Dialog::on_buttonBox_accepted()
{
    if (ui->H0->isEnabled()) {

    }
    if (ui->H1->isEnabled()) {
        document->p_1 = ui->H1_input_p->value();
        document->k_1 = ui->H1_input_k->value();
        document->sample_size = ui->H1_input_sample_size->value();
        if (ui->H1_radio_Bernulli->isChecked()) {
            document->method = Document::Method::Bernulli;
        } else if (ui->H1_radio_Table->isChecked()) {
            document->method = Document::Method::Table;
        } else {
            document->method = Document::Method::None;
        }
        document->resetGenerator();
        document->generateEmpericalDencity();
    }
    if (ui->Pvalue->isEnabled()) {

    }
    hide();
}


void Dialog::on_buttonBox_rejected()
{
    if (ui->H0->isEnabled()) {

    }
    if (ui->H1->isEnabled()) {
        ui->H1_input_p->setValue(document->p_1);
        ui->H1_input_k->setValue(document->k_1);
        ui->H1_input_sample_size->setValue(document->sample_size);

        switch (document->method) {
        case Document::Method::Bernulli:
            ui->H1_radio_Bernulli->setChecked(true);
            ui->H1_radio_Table->setChecked(false);
            break;
        case Document::Method::Table:
            ui->H1_radio_Bernulli->setChecked(false);
            ui->H1_radio_Table->setChecked(true);
            break;
        default:
            break;
        }
    }
    if (ui->Pvalue->isEnabled()) {

    }
    hide();
}

