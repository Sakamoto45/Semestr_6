/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *H0;
    QGroupBox *H1;
    QGridLayout *gridLayout;
    QLabel *H1_label_k;
    QRadioButton *H1_radio_Bernulli;
    QRadioButton *H1_radio_Table;
    QLabel *H1_label_p;
    QLabel *H1_label_sample_size;
    QSpinBox *H1_input_sample_size;
    QSpinBox *H1_input_k;
    QDoubleSpinBox *H1_input_p;
    QGroupBox *Pvalue;
    QDialogButtonBox *buttonBox;
    QButtonGroup *method;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        H0 = new QGroupBox(Dialog);
        H0->setObjectName(QString::fromUtf8("H0"));
        H0->setEnabled(false);

        verticalLayout_2->addWidget(H0);

        H1 = new QGroupBox(Dialog);
        H1->setObjectName(QString::fromUtf8("H1"));
        gridLayout = new QGridLayout(H1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        H1_label_k = new QLabel(H1);
        H1_label_k->setObjectName(QString::fromUtf8("H1_label_k"));

        gridLayout->addWidget(H1_label_k, 1, 0, 1, 1);

        H1_radio_Bernulli = new QRadioButton(H1);
        method = new QButtonGroup(Dialog);
        method->setObjectName(QString::fromUtf8("method"));
        method->addButton(H1_radio_Bernulli);
        H1_radio_Bernulli->setObjectName(QString::fromUtf8("H1_radio_Bernulli"));
        H1_radio_Bernulli->setChecked(true);

        gridLayout->addWidget(H1_radio_Bernulli, 3, 0, 1, 1);

        H1_radio_Table = new QRadioButton(H1);
        method->addButton(H1_radio_Table);
        H1_radio_Table->setObjectName(QString::fromUtf8("H1_radio_Table"));

        gridLayout->addWidget(H1_radio_Table, 3, 1, 1, 1);

        H1_label_p = new QLabel(H1);
        H1_label_p->setObjectName(QString::fromUtf8("H1_label_p"));

        gridLayout->addWidget(H1_label_p, 0, 0, 1, 1);

        H1_label_sample_size = new QLabel(H1);
        H1_label_sample_size->setObjectName(QString::fromUtf8("H1_label_sample_size"));

        gridLayout->addWidget(H1_label_sample_size, 2, 0, 1, 1);

        H1_input_sample_size = new QSpinBox(H1);
        H1_input_sample_size->setObjectName(QString::fromUtf8("H1_input_sample_size"));
        H1_input_sample_size->setMinimum(1);
        H1_input_sample_size->setMaximum(10000);

        gridLayout->addWidget(H1_input_sample_size, 2, 1, 1, 1);

        H1_input_k = new QSpinBox(H1);
        H1_input_k->setObjectName(QString::fromUtf8("H1_input_k"));

        gridLayout->addWidget(H1_input_k, 1, 1, 1, 1);

        H1_input_p = new QDoubleSpinBox(H1);
        H1_input_p->setObjectName(QString::fromUtf8("H1_input_p"));
        H1_input_p->setMaximum(1.000000000000000);
        H1_input_p->setSingleStep(0.100000000000000);

        gridLayout->addWidget(H1_input_p, 0, 1, 1, 1);


        verticalLayout_2->addWidget(H1);

        Pvalue = new QGroupBox(Dialog);
        Pvalue->setObjectName(QString::fromUtf8("Pvalue"));
        Pvalue->setEnabled(false);

        verticalLayout_2->addWidget(Pvalue);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        H0->setTitle(QCoreApplication::translate("Dialog", "H0", nullptr));
        H1->setTitle(QCoreApplication::translate("Dialog", "H1", nullptr));
        H1_label_k->setText(QCoreApplication::translate("Dialog", "k", nullptr));
        H1_radio_Bernulli->setText(QCoreApplication::translate("Dialog", "Bernulli", nullptr));
        H1_radio_Table->setText(QCoreApplication::translate("Dialog", "Table", nullptr));
        H1_label_p->setText(QCoreApplication::translate("Dialog", "p", nullptr));
        H1_label_sample_size->setText(QCoreApplication::translate("Dialog", "Sample size", nullptr));
        Pvalue->setTitle(QCoreApplication::translate("Dialog", "P-value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
