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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *width_line;
    QLabel *label;
    QLineEdit *width_input;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *Red;
    QRadioButton *Green;
    QRadioButton *Blue;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        width_line = new QHBoxLayout();
        width_line->setObjectName(QString::fromUtf8("width_line"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        width_line->addWidget(label);

        width_input = new QLineEdit(Dialog);
        width_input->setObjectName(QString::fromUtf8("width_input"));

        width_line->addWidget(width_input);


        verticalLayout->addLayout(width_line);

        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setEnabled(true);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        Red = new QRadioButton(groupBox);
        Red->setObjectName(QString::fromUtf8("Red"));

        verticalLayout_2->addWidget(Red);

        Green = new QRadioButton(groupBox);
        Green->setObjectName(QString::fromUtf8("Green"));

        verticalLayout_2->addWidget(Green);

        Blue = new QRadioButton(groupBox);
        Blue->setObjectName(QString::fromUtf8("Blue"));

        verticalLayout_2->addWidget(Blue);


        verticalLayout->addWidget(groupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\250\320\270\321\200\320\270\320\275\320\260 \320\273\320\270\320\275\320\270\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "GroupBox", nullptr));
        Red->setText(QCoreApplication::translate("Dialog", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        Green->setText(QCoreApplication::translate("Dialog", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        Blue->setText(QCoreApplication::translate("Dialog", "\320\241\320\270\320\275\320\270\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
