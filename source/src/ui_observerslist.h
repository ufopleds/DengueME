/********************************************************************************
** Form generated from reading UI file 'observerslist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBSERVERSLIST_H
#define UI_OBSERVERSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObserversList
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *panel;
    QHBoxLayout *horizontalLayout;
    QToolButton *addObserver;
    QSpacerItem *horizontalSpacer;
    QListWidget *widgets;

    void setupUi(QFrame *ObserversList)
    {
        if (ObserversList->objectName().isEmpty())
            ObserversList->setObjectName(QStringLiteral("ObserversList"));
        ObserversList->resize(450, 112);
        ObserversList->setAutoFillBackground(true);
        ObserversList->setFrameShape(QFrame::StyledPanel);
        ObserversList->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(ObserversList);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        panel = new QWidget(ObserversList);
        panel->setObjectName(QStringLiteral("panel"));
        horizontalLayout = new QHBoxLayout(panel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addObserver = new QToolButton(panel);
        addObserver->setObjectName(QStringLiteral("addObserver"));
        addObserver->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(addObserver);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(panel);

        widgets = new QListWidget(ObserversList);
        widgets->setObjectName(QStringLiteral("widgets"));
        widgets->setFrameShape(QFrame::NoFrame);
        widgets->setDragDropMode(QAbstractItemView::InternalMove);
        widgets->setAlternatingRowColors(true);
        widgets->setSelectionMode(QAbstractItemView::ExtendedSelection);
        widgets->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widgets->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(widgets);


        retranslateUi(ObserversList);

        QMetaObject::connectSlotsByName(ObserversList);
    } // setupUi

    void retranslateUi(QFrame *ObserversList)
    {
        ObserversList->setWindowTitle(QApplication::translate("ObserversList", "ObserverEditor", 0));
        addObserver->setText(QApplication::translate("ObserversList", "Add observer", 0));
    } // retranslateUi

};

namespace Ui {
    class ObserversList: public Ui_ObserversList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBSERVERSLIST_H
