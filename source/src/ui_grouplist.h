/********************************************************************************
** Form generated from reading UI file 'grouplist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPLIST_H
#define UI_GROUPLIST_H

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

class Ui_GroupEditor
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *panel;
    QHBoxLayout *horizontalLayout;
    QToolButton *addWidget;
    QToolButton *addGroup;
    QSpacerItem *horizontalSpacer;
    QListWidget *widgets;

    void setupUi(QFrame *GroupEditor)
    {
        if (GroupEditor->objectName().isEmpty())
            GroupEditor->setObjectName(QStringLiteral("GroupEditor"));
        GroupEditor->resize(450, 112);
        GroupEditor->setAutoFillBackground(true);
        GroupEditor->setFrameShape(QFrame::StyledPanel);
        GroupEditor->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(GroupEditor);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        panel = new QWidget(GroupEditor);
        panel->setObjectName(QStringLiteral("panel"));
        horizontalLayout = new QHBoxLayout(panel);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addWidget = new QToolButton(panel);
        addWidget->setObjectName(QStringLiteral("addWidget"));
        addWidget->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(addWidget);

        addGroup = new QToolButton(panel);
        addGroup->setObjectName(QStringLiteral("addGroup"));

        horizontalLayout->addWidget(addGroup);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(panel);

        widgets = new QListWidget(GroupEditor);
        widgets->setObjectName(QStringLiteral("widgets"));
        widgets->setFrameShape(QFrame::NoFrame);
        widgets->setDragDropMode(QAbstractItemView::InternalMove);
        widgets->setAlternatingRowColors(true);
        widgets->setSelectionMode(QAbstractItemView::ExtendedSelection);
        widgets->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widgets->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(widgets);


        retranslateUi(GroupEditor);

        QMetaObject::connectSlotsByName(GroupEditor);
    } // setupUi

    void retranslateUi(QFrame *GroupEditor)
    {
        GroupEditor->setWindowTitle(QApplication::translate("GroupEditor", "GroupEditor", 0));
        addWidget->setText(QApplication::translate("GroupEditor", "Add widget", 0));
        addGroup->setText(QApplication::translate("GroupEditor", "Add group", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupEditor: public Ui_GroupEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPLIST_H
