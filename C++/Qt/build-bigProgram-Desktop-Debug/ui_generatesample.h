/********************************************************************************
** Form generated from reading UI file 'generatesample.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATESAMPLE_H
#define UI_GENERATESAMPLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_GenerateSample
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QRadioButton *bernoulli;
    QLineEdit *size;
    QLabel *label;
    QRadioButton *inverseFunction;
    QLabel *label_3;
    QLineEdit *probability;
    QHBoxLayout *horizontalLayout;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *GenerateSample)
    {
        if (GenerateSample->objectName().isEmpty())
            GenerateSample->setObjectName(QString::fromUtf8("GenerateSample"));
        GenerateSample->resize(322, 212);
        gridLayout_2 = new QGridLayout(GenerateSample);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(GenerateSample);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        bernoulli = new QRadioButton(groupBox);
        bernoulli->setObjectName(QString::fromUtf8("bernoulli"));
        bernoulli->setAutoFillBackground(false);
        bernoulli->setAutoRepeat(false);

        gridLayout->addWidget(bernoulli, 0, 0, 1, 1);

        size = new QLineEdit(groupBox);
        size->setObjectName(QString::fromUtf8("size"));

        gridLayout->addWidget(size, 2, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        inverseFunction = new QRadioButton(groupBox);
        inverseFunction->setObjectName(QString::fromUtf8("inverseFunction"));

        gridLayout->addWidget(inverseFunction, 0, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        probability = new QLineEdit(groupBox);
        probability->setObjectName(QString::fromUtf8("probability"));

        gridLayout->addWidget(probability, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OK = new QPushButton(GenerateSample);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout->addWidget(OK);

        Cancel = new QPushButton(GenerateSample);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout->addWidget(Cancel);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(GenerateSample);

        QMetaObject::connectSlotsByName(GenerateSample);
    } // setupUi

    void retranslateUi(QDialog *GenerateSample)
    {
        GenerateSample->setWindowTitle(QCoreApplication::translate("GenerateSample", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("GenerateSample", "Set parameters", nullptr));
        bernoulli->setText(QCoreApplication::translate("GenerateSample", "Bernoulli", nullptr));
        size->setText(QCoreApplication::translate("GenerateSample", "100", nullptr));
        label->setText(QCoreApplication::translate("GenerateSample", "Probability", nullptr));
        inverseFunction->setText(QCoreApplication::translate("GenerateSample", "Inverse function", nullptr));
        label_3->setText(QCoreApplication::translate("GenerateSample", "Size", nullptr));
        probability->setText(QCoreApplication::translate("GenerateSample", "0.2", nullptr));
        OK->setText(QCoreApplication::translate("GenerateSample", "OK", nullptr));
        Cancel->setText(QCoreApplication::translate("GenerateSample", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GenerateSample: public Ui_GenerateSample {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATESAMPLE_H
