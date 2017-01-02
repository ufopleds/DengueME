/********************************************************************************
** Form generated from reading UI file 'visualtablefield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALTABLEFIELD_H
#define UI_VISUALTABLEFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualTableField
{
public:
    QHBoxLayout *horizontalLayout_5;
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
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *VisualTableField)
    {
        if (VisualTableField->objectName().isEmpty())
            VisualTableField->setObjectName(QStringLiteral("VisualTableField"));
        VisualTableField->resize(748, 347);
        horizontalLayout_5 = new QHBoxLayout(VisualTableField);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line = new QFrame(VisualTableField);
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
        upperLabel = new QLabel(VisualTableField);
        upperLabel->setObjectName(QStringLiteral("upperLabel"));

        verticalLayout->addWidget(upperLabel);

        labelGeneral = new QLabel(VisualTableField);
        labelGeneral->setObjectName(QStringLiteral("labelGeneral"));
        labelGeneral->setMargin(3);

        verticalLayout->addWidget(labelGeneral);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        labelToBeUse = new QLabel(VisualTableField);
        labelToBeUse->setObjectName(QStringLiteral("labelToBeUse"));

        horizontalLayout_4->addWidget(labelToBeUse);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        add = new QToolButton(VisualTableField);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout_4->addWidget(add);

        del = new QToolButton(VisualTableField);
        del->setObjectName(QStringLiteral("del"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout_4->addWidget(del);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_4);

        defaultVarList = new QListWidget(VisualTableField);
        defaultVarList->setObjectName(QStringLiteral("defaultVarList"));

        horizontalLayout->addWidget(defaultVarList);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        rButton = new QToolButton(VisualTableField);
        rButton->setObjectName(QStringLiteral("rButton"));
        rButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/rightDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        rButton->setIcon(icon2);
        rButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(rButton);

        lButton = new QToolButton(VisualTableField);
        lButton->setObjectName(QStringLiteral("lButton"));
        lButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/leftDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        lButton->setIcon(icon3);
        lButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(lButton);


        horizontalLayout->addLayout(verticalLayout_3);

        useVarList = new QListWidget(VisualTableField);
        useVarList->setObjectName(QStringLiteral("useVarList"));

        horizontalLayout->addWidget(useVarList);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(verticalLayout_6);

        container = new QWidget(VisualTableField);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_5->addWidget(container);


        retranslateUi(VisualTableField);

        QMetaObject::connectSlotsByName(VisualTableField);
    } // setupUi

    void retranslateUi(QWidget *VisualTableField)
    {
        VisualTableField->setWindowTitle(QApplication::translate("VisualTableField", "Form", 0));
        upperLabel->setText(QApplication::translate("VisualTableField", "Choose variables that the user can use", 0));
        labelGeneral->setText(QApplication::translate("VisualTableField", "All Variables", 0));
        labelToBeUse->setText(QApplication::translate("VisualTableField", "Use Variables", 0));
        add->setText(QApplication::translate("VisualTableField", "+", 0));
        del->setText(QApplication::translate("VisualTableField", "-", 0));
        rButton->setText(QApplication::translate("VisualTableField", "...", 0));
        lButton->setText(QApplication::translate("VisualTableField", "...", 0));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("VisualTableField", "Default value", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class VisualTableField: public Ui_VisualTableField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALTABLEFIELD_H
