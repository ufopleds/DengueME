/********************************************************************************
** Form generated from reading UI file 'vttsfield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTTSFIELD_H
#define UI_VTTSFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *upperLabel;
    QLabel *labelGeneral;
    QSpacerItem *horizontalSpacer;
    QLabel *labelToBeUse;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QToolButton *add;
    QToolButton *del;
    QSpacerItem *verticalSpacer;
    QListWidget *defaultVarList;
    QVBoxLayout *verticalLayout_3;
    QToolButton *rButton;
    QToolButton *lButton;
    QListWidget *useVarList;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_2;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_4;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(779, 277);
        horizontalLayout_6 = new QHBoxLayout(Form);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        container = new QWidget(Form);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_5->addWidget(container);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line = new QFrame(Form);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        upperLabel = new QLabel(Form);
        upperLabel->setObjectName(QStringLiteral("upperLabel"));

        verticalLayout->addWidget(upperLabel);

        labelGeneral = new QLabel(Form);
        labelGeneral->setObjectName(QStringLiteral("labelGeneral"));
        labelGeneral->setMargin(3);

        verticalLayout->addWidget(labelGeneral);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        labelToBeUse = new QLabel(Form);
        labelToBeUse->setObjectName(QStringLiteral("labelToBeUse"));

        horizontalLayout_4->addWidget(labelToBeUse);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        add = new QToolButton(Form);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout_4->addWidget(add);

        del = new QToolButton(Form);
        del->setObjectName(QStringLiteral("del"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout_4->addWidget(del);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_4);

        defaultVarList = new QListWidget(Form);
        defaultVarList->setObjectName(QStringLiteral("defaultVarList"));

        horizontalLayout->addWidget(defaultVarList);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        rButton = new QToolButton(Form);
        rButton->setObjectName(QStringLiteral("rButton"));
        rButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/rightDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        rButton->setIcon(icon2);
        rButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(rButton);

        lButton = new QToolButton(Form);
        lButton->setObjectName(QStringLiteral("lButton"));
        lButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/leftDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        lButton->setIcon(icon3);
        lButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(lButton);


        horizontalLayout->addLayout(verticalLayout_3);

        useVarList = new QListWidget(Form);
        useVarList->setObjectName(QStringLiteral("useVarList"));

        horizontalLayout->addWidget(useVarList);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_6);

        line_2 = new QFrame(Form);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(Form);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(Form);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        label_4 = new QLabel(Form);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        lineEdit_3 = new QLineEdit(Form);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        checkBox_2 = new QCheckBox(Form);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_2->addWidget(checkBox_2);

        label_2 = new QLabel(Form);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(Form);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        label_3 = new QLabel(Form);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        lineEdit_4 = new QLineEdit(Form);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        checkBox = new QCheckBox(Form);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_2->addWidget(checkBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout_6->addLayout(horizontalLayout_5);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", 0));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("Form", "Default value", 0));
#endif // QT_NO_TOOLTIP
        upperLabel->setText(QApplication::translate("Form", "Choose variables that the user can use", 0));
        labelGeneral->setText(QApplication::translate("Form", "All Variables", 0));
        labelToBeUse->setText(QApplication::translate("Form", "Use Variables", 0));
        add->setText(QApplication::translate("Form", "+", 0));
        del->setText(QApplication::translate("Form", "-", 0));
        rButton->setText(QApplication::translate("Form", "...", 0));
        lButton->setText(QApplication::translate("Form", "...", 0));
        label->setText(QApplication::translate("Form", "Visual Table ID:", 0));
        label_4->setText(QApplication::translate("Form", "Visual Table User  Label", 0));
        checkBox_2->setText(QApplication::translate("Form", "Use Visual Table", 0));
        label_2->setText(QApplication::translate("Form", "Text Screen ID:", 0));
        label_3->setText(QApplication::translate("Form", "Text Screen User Label", 0));
        checkBox->setText(QApplication::translate("Form", "Use Text Screen", 0));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTTSFIELD_H
