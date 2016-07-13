/********************************************************************************
** Form generated from reading UI file 'colorbar.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORBAR_H
#define UI_COLORBAR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ColorBar
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpinBox *spinBox_attValue;
    QLabel *label_2;
    QLineEdit *lineEdit_color;
    QPushButton *pushButton_selectColor;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_insert;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QListWidget *listWidget;
    QPushButton *pushButton_del;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_OK;
    QPushButton *pushButton_cancel;

    void setupUi(QDialog *ColorBar)
    {
        if (ColorBar->objectName().isEmpty())
            ColorBar->setObjectName(QString::fromUtf8("ColorBar"));
        ColorBar->resize(479, 244);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ColorBar->sizePolicy().hasHeightForWidth());
        ColorBar->setSizePolicy(sizePolicy);
        ColorBar->setMinimumSize(QSize(479, 0));
        ColorBar->setMaximumSize(QSize(479, 244));
        verticalLayout_2 = new QVBoxLayout(ColorBar);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(ColorBar);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        spinBox_attValue = new QSpinBox(ColorBar);
        spinBox_attValue->setObjectName(QString::fromUtf8("spinBox_attValue"));
        spinBox_attValue->setMaximumSize(QSize(80, 16777215));
        spinBox_attValue->setMaximum(99999);
        spinBox_attValue->setSingleStep(1);

        verticalLayout->addWidget(spinBox_attValue);

        label_2 = new QLabel(ColorBar);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit_color = new QLineEdit(ColorBar);
        lineEdit_color->setObjectName(QString::fromUtf8("lineEdit_color"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_color->sizePolicy().hasHeightForWidth());
        lineEdit_color->setSizePolicy(sizePolicy1);
        lineEdit_color->setMinimumSize(QSize(0, 50));
        lineEdit_color->setMaximumSize(QSize(80, 50));
        lineEdit_color->setReadOnly(true);

        verticalLayout->addWidget(lineEdit_color);

        pushButton_selectColor = new QPushButton(ColorBar);
        pushButton_selectColor->setObjectName(QString::fromUtf8("pushButton_selectColor"));
        pushButton_selectColor->setMaximumSize(QSize(80, 16777215));

        verticalLayout->addWidget(pushButton_selectColor);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_insert = new QPushButton(ColorBar);
        pushButton_insert->setObjectName(QString::fromUtf8("pushButton_insert"));
        pushButton_insert->setMaximumSize(QSize(30, 16777215));

        verticalLayout_3->addWidget(pushButton_insert);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(ColorBar);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        listWidget = new QListWidget(ColorBar);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy1.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy1);
        listWidget->setMinimumSize(QSize(300, 150));
        listWidget->setMaximumSize(QSize(300, 150));
        listWidget->setSizeIncrement(QSize(300, 150));

        gridLayout->addWidget(listWidget, 1, 0, 1, 1);

        pushButton_del = new QPushButton(ColorBar);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setMaximumSize(QSize(23, 16777215));

        gridLayout->addWidget(pushButton_del, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_OK = new QPushButton(ColorBar);
        pushButton_OK->setObjectName(QString::fromUtf8("pushButton_OK"));

        horizontalLayout_2->addWidget(pushButton_OK);

        pushButton_cancel = new QPushButton(ColorBar);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout_2->addWidget(pushButton_cancel);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(ColorBar);

        QMetaObject::connectSlotsByName(ColorBar);
    } // setupUi

    void retranslateUi(QDialog *ColorBar)
    {
        ColorBar->setWindowTitle(QApplication::translate("ColorBar", "Creating a new ColorBar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ColorBar", "Attribute value:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ColorBar", "Color:", 0, QApplication::UnicodeUTF8));
        pushButton_selectColor->setText(QApplication::translate("ColorBar", "Select Color", 0, QApplication::UnicodeUTF8));
        pushButton_insert->setText(QApplication::translate("ColorBar", ">>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ColorBar", "Attribute color list:", 0, QApplication::UnicodeUTF8));
        pushButton_del->setText(QApplication::translate("ColorBar", "-", 0, QApplication::UnicodeUTF8));
        pushButton_OK->setText(QApplication::translate("ColorBar", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("ColorBar", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ColorBar: public Ui_ColorBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORBAR_H
