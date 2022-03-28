/********************************************************************************
** Form generated from reading UI file 'pvalues.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVALUES_H
#define UI_PVALUES_H

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

class Ui_PValues
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *realProbability;
    QLineEdit *sizeOfGeomSample;
    QLabel *label_3;
    QRadioButton *bernoulli;
    QLabel *label;
    QRadioButton *inverseFunction;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QLineEdit *hypotheticalProp;
    QLabel *label_4;
    QLineEdit *sizeOfPValueSample;
    QHBoxLayout *horizontalLayout;
    QPushButton *OK;
    QPushButton *Cancel;

    void setupUi(QDialog *PValues)
    {
        if (PValues->objectName().isEmpty())
            PValues->setObjectName(QString::fromUtf8("PValues"));
        PValues->resize(417, 369);
        gridLayout_3 = new QGridLayout(PValues);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(PValues);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        realProbability = new QLineEdit(groupBox);
        realProbability->setObjectName(QString::fromUtf8("realProbability"));

        gridLayout->addWidget(realProbability, 1, 1, 1, 1);

        sizeOfGeomSample = new QLineEdit(groupBox);
        sizeOfGeomSample->setObjectName(QString::fromUtf8("sizeOfGeomSample"));

        gridLayout->addWidget(sizeOfGeomSample, 2, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        bernoulli = new QRadioButton(groupBox);
        bernoulli->setObjectName(QString::fromUtf8("bernoulli"));
        bernoulli->setAutoFillBackground(false);
        bernoulli->setAutoRepeat(false);

        gridLayout->addWidget(bernoulli, 0, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        inverseFunction = new QRadioButton(groupBox);
        inverseFunction->setObjectName(QString::fromUtf8("inverseFunction"));

        gridLayout->addWidget(inverseFunction, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(PValues);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        hypotheticalProp = new QLineEdit(groupBox_2);
        hypotheticalProp->setObjectName(QString::fromUtf8("hypotheticalProp"));

        gridLayout_2->addWidget(hypotheticalProp, 0, 1, 1, 2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 2);

        sizeOfPValueSample = new QLineEdit(groupBox_2);
        sizeOfPValueSample->setObjectName(QString::fromUtf8("sizeOfPValueSample"));

        gridLayout_2->addWidget(sizeOfPValueSample, 1, 2, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        OK = new QPushButton(PValues);
        OK->setObjectName(QString::fromUtf8("OK"));

        horizontalLayout->addWidget(OK);

        Cancel = new QPushButton(PValues);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));

        horizontalLayout->addWidget(Cancel);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(PValues);

        QMetaObject::connectSlotsByName(PValues);
    } // setupUi

    void retranslateUi(QDialog *PValues)
    {
        PValues->setWindowTitle(QCoreApplication::translate("PValues", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("PValues", "Set parameters for sample", nullptr));
        realProbability->setText(QCoreApplication::translate("PValues", "0.2", nullptr));
        sizeOfGeomSample->setText(QCoreApplication::translate("PValues", "100", nullptr));
        label_3->setText(QCoreApplication::translate("PValues", "Size", nullptr));
        bernoulli->setText(QCoreApplication::translate("PValues", "Bernoulli", nullptr));
        label->setText(QCoreApplication::translate("PValues", "Probability", nullptr));
        inverseFunction->setText(QCoreApplication::translate("PValues", "Inverse function", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("PValues", "Set parameters for hypothesis", nullptr));
        label_2->setText(QCoreApplication::translate("PValues", "Probability", nullptr));
        hypotheticalProp->setText(QCoreApplication::translate("PValues", "0.2", nullptr));
        label_4->setText(QCoreApplication::translate("PValues", "Size of sample of p-values", nullptr));
        sizeOfPValueSample->setText(QCoreApplication::translate("PValues", "500", nullptr));
        OK->setText(QCoreApplication::translate("PValues", "OK", nullptr));
        Cancel->setText(QCoreApplication::translate("PValues", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PValues: public Ui_PValues {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVALUES_H
