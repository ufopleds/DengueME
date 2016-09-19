/********************************************************************************
** Form generated from reading UI file 'observer.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSERVER_H
#define UI_OBSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Observer
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_33;
    QLineEdit *legendScale_lineEdit;
    QLabel *label_34;
    QLineEdit *type_lineEdit;
    QLabel *label_35;
    QLineEdit *grouping_lineEdit;
    QLabel *label_36;
    QLineEdit *slices_lineEdit;
    QLabel *label_37;
    QLineEdit *precision_lineEdit;
    QLabel *label_38;
    QLabel *label_39;
    QLineEdit *maximum_lineEdit;
    QLabel *label_40;
    QLineEdit *minimum_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLineEdit *stdDeviation_lineEdit;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_47;
    QTextEdit *colorBar_textEdit;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButton_ColoBar;
    QPushButton *getColorBarButton;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_10;
    QCheckBox *viewExec_checkBox;
    QCheckBox *map_checkBox;

    void setupUi(QWidget *Observer)
    {
        if (Observer->objectName().isEmpty())
            Observer->setObjectName(QStringLiteral("Observer"));
        Observer->resize(739, 372);
        verticalLayout = new QVBoxLayout(Observer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_33 = new QLabel(Observer);
        label_33->setObjectName(QStringLiteral("label_33"));

        gridLayout->addWidget(label_33, 0, 0, 1, 1);

        legendScale_lineEdit = new QLineEdit(Observer);
        legendScale_lineEdit->setObjectName(QStringLiteral("legendScale_lineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(legendScale_lineEdit->sizePolicy().hasHeightForWidth());
        legendScale_lineEdit->setSizePolicy(sizePolicy);
        legendScale_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(legendScale_lineEdit, 0, 1, 1, 1);

        label_34 = new QLabel(Observer);
        label_34->setObjectName(QStringLiteral("label_34"));

        gridLayout->addWidget(label_34, 1, 0, 1, 1);

        type_lineEdit = new QLineEdit(Observer);
        type_lineEdit->setObjectName(QStringLiteral("type_lineEdit"));
        sizePolicy.setHeightForWidth(type_lineEdit->sizePolicy().hasHeightForWidth());
        type_lineEdit->setSizePolicy(sizePolicy);
        type_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(type_lineEdit, 1, 1, 1, 1);

        label_35 = new QLabel(Observer);
        label_35->setObjectName(QStringLiteral("label_35"));

        gridLayout->addWidget(label_35, 1, 2, 1, 1);

        grouping_lineEdit = new QLineEdit(Observer);
        grouping_lineEdit->setObjectName(QStringLiteral("grouping_lineEdit"));
        sizePolicy.setHeightForWidth(grouping_lineEdit->sizePolicy().hasHeightForWidth());
        grouping_lineEdit->setSizePolicy(sizePolicy);
        grouping_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(grouping_lineEdit, 1, 3, 1, 1);

        label_36 = new QLabel(Observer);
        label_36->setObjectName(QStringLiteral("label_36"));

        gridLayout->addWidget(label_36, 1, 4, 1, 1);

        slices_lineEdit = new QLineEdit(Observer);
        slices_lineEdit->setObjectName(QStringLiteral("slices_lineEdit"));
        sizePolicy.setHeightForWidth(slices_lineEdit->sizePolicy().hasHeightForWidth());
        slices_lineEdit->setSizePolicy(sizePolicy);
        slices_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(slices_lineEdit, 1, 5, 1, 1);

        label_37 = new QLabel(Observer);
        label_37->setObjectName(QStringLiteral("label_37"));

        gridLayout->addWidget(label_37, 2, 0, 1, 1);

        precision_lineEdit = new QLineEdit(Observer);
        precision_lineEdit->setObjectName(QStringLiteral("precision_lineEdit"));
        sizePolicy.setHeightForWidth(precision_lineEdit->sizePolicy().hasHeightForWidth());
        precision_lineEdit->setSizePolicy(sizePolicy);
        precision_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(precision_lineEdit, 2, 1, 1, 1);

        label_38 = new QLabel(Observer);
        label_38->setObjectName(QStringLiteral("label_38"));

        gridLayout->addWidget(label_38, 2, 2, 1, 1);

        label_39 = new QLabel(Observer);
        label_39->setObjectName(QStringLiteral("label_39"));

        gridLayout->addWidget(label_39, 2, 4, 1, 1);

        maximum_lineEdit = new QLineEdit(Observer);
        maximum_lineEdit->setObjectName(QStringLiteral("maximum_lineEdit"));
        sizePolicy.setHeightForWidth(maximum_lineEdit->sizePolicy().hasHeightForWidth());
        maximum_lineEdit->setSizePolicy(sizePolicy);
        maximum_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(maximum_lineEdit, 2, 5, 1, 1);

        label_40 = new QLabel(Observer);
        label_40->setObjectName(QStringLiteral("label_40"));

        gridLayout->addWidget(label_40, 3, 0, 1, 1);

        minimum_lineEdit = new QLineEdit(Observer);
        minimum_lineEdit->setObjectName(QStringLiteral("minimum_lineEdit"));
        sizePolicy.setHeightForWidth(minimum_lineEdit->sizePolicy().hasHeightForWidth());
        minimum_lineEdit->setSizePolicy(sizePolicy);
        minimum_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(minimum_lineEdit, 3, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 0, 5, 1, 1);

        stdDeviation_lineEdit = new QLineEdit(Observer);
        stdDeviation_lineEdit->setObjectName(QStringLiteral("stdDeviation_lineEdit"));
        sizePolicy.setHeightForWidth(stdDeviation_lineEdit->sizePolicy().hasHeightForWidth());
        stdDeviation_lineEdit->setSizePolicy(sizePolicy);
        stdDeviation_lineEdit->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(stdDeviation_lineEdit, 2, 3, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_47 = new QLabel(Observer);
        label_47->setObjectName(QStringLiteral("label_47"));

        verticalLayout_2->addWidget(label_47);

        colorBar_textEdit = new QTextEdit(Observer);
        colorBar_textEdit->setObjectName(QStringLiteral("colorBar_textEdit"));

        verticalLayout_2->addWidget(colorBar_textEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_16 = new QSpacerItem(558, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_16);

        pushButton_ColoBar = new QPushButton(Observer);
        pushButton_ColoBar->setObjectName(QStringLiteral("pushButton_ColoBar"));

        horizontalLayout_3->addWidget(pushButton_ColoBar);

        getColorBarButton = new QPushButton(Observer);
        getColorBarButton->setObjectName(QStringLiteral("getColorBarButton"));

        horizontalLayout_3->addWidget(getColorBarButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(verticalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_10 = new QSpacerItem(468, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 0, 3, 1, 1);

        viewExec_checkBox = new QCheckBox(Observer);
        viewExec_checkBox->setObjectName(QStringLiteral("viewExec_checkBox"));
        viewExec_checkBox->setChecked(false);

        gridLayout_2->addWidget(viewExec_checkBox, 0, 2, 1, 1);

        map_checkBox = new QCheckBox(Observer);
        map_checkBox->setObjectName(QStringLiteral("map_checkBox"));
        map_checkBox->setChecked(false);

        gridLayout_2->addWidget(map_checkBox, 0, 0, 1, 2);


        verticalLayout->addLayout(gridLayout_2);

        QWidget::setTabOrder(legendScale_lineEdit, type_lineEdit);
        QWidget::setTabOrder(type_lineEdit, grouping_lineEdit);
        QWidget::setTabOrder(grouping_lineEdit, slices_lineEdit);
        QWidget::setTabOrder(slices_lineEdit, precision_lineEdit);
        QWidget::setTabOrder(precision_lineEdit, stdDeviation_lineEdit);
        QWidget::setTabOrder(stdDeviation_lineEdit, maximum_lineEdit);
        QWidget::setTabOrder(maximum_lineEdit, minimum_lineEdit);
        QWidget::setTabOrder(minimum_lineEdit, colorBar_textEdit);
        QWidget::setTabOrder(colorBar_textEdit, pushButton_ColoBar);
        QWidget::setTabOrder(pushButton_ColoBar, getColorBarButton);
        QWidget::setTabOrder(getColorBarButton, map_checkBox);
        QWidget::setTabOrder(map_checkBox, viewExec_checkBox);

        retranslateUi(Observer);

        QMetaObject::connectSlotsByName(Observer);
    } // setupUi

    void retranslateUi(QWidget *Observer)
    {
        Observer->setWindowTitle(QApplication::translate("Observer", "Form", 0));
        label_33->setText(QApplication::translate("Observer", "Legend Scale:", 0));
        legendScale_lineEdit->setText(QString());
        label_34->setText(QApplication::translate("Observer", "Type:", 0));
        type_lineEdit->setText(QString());
        label_35->setText(QApplication::translate("Observer", "Grouping:", 0));
        grouping_lineEdit->setText(QString());
        label_36->setText(QApplication::translate("Observer", "Slices:", 0));
        slices_lineEdit->setText(QString());
        label_37->setText(QApplication::translate("Observer", "Precision:", 0));
        precision_lineEdit->setText(QString());
        label_38->setText(QApplication::translate("Observer", "StdDeviation:", 0));
        label_39->setText(QApplication::translate("Observer", "Maximum:", 0));
        maximum_lineEdit->setText(QString());
        label_40->setText(QApplication::translate("Observer", "Minimum:", 0));
        minimum_lineEdit->setText(QString());
        stdDeviation_lineEdit->setText(QString());
        label_47->setText(QApplication::translate("Observer", "ColorBar", 0));
        colorBar_textEdit->setHtml(QApplication::translate("Observer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Oxygen-Sans'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8pt;\"><br /></p></body></html>", 0));
        pushButton_ColoBar->setText(QApplication::translate("Observer", "New ColorBar", 0));
        getColorBarButton->setText(QApplication::translate("Observer", "Import from CSV", 0));
        viewExec_checkBox->setText(QApplication::translate("Observer", "View Execution", 0));
        map_checkBox->setText(QApplication::translate("Observer", "Generate Map", 0));
    } // retranslateUi

};

namespace Ui {
    class Observer: public Ui_Observer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSERVER_H
