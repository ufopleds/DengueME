/********************************************************************************
** Form generated from reading UI file 'grouplist.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPLIST_H
#define UI_GROUPLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

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
            GroupEditor->setObjectName(QString::fromUtf8("GroupEditor"));
        GroupEditor->resize(450, 112);
        GroupEditor->setAutoFillBackground(true);
        GroupEditor->setFrameShape(QFrame::StyledPanel);
        GroupEditor->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(GroupEditor);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        panel = new QWidget(GroupEditor);
        panel->setObjectName(QString::fromUtf8("panel"));
        horizontalLayout = new QHBoxLayout(panel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        addWidget = new QToolButton(panel);
        addWidget->setObjectName(QString::fromUtf8("addWidget"));
        addWidget->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(addWidget);

        addGroup = new QToolButton(panel);
        addGroup->setObjectName(QString::fromUtf8("addGroup"));

        horizontalLayout->addWidget(addGroup);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addWidget(panel);

        widgets = new QListWidget(GroupEditor);
        widgets->setObjectName(QString::fromUtf8("widgets"));
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
        GroupEditor->setWindowTitle(QApplication::translate("GroupEditor", "GroupEditor", 0, QApplication::UnicodeUTF8));
        addWidget->setText(QApplication::translate("GroupEditor", "Add widget", 0, QApplication::UnicodeUTF8));
        addGroup->setText(QApplication::translate("GroupEditor", "Add group", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GroupEditor: public Ui_GroupEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPLIST_H
