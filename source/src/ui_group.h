/********************************************************************************
** Form generated from reading UI file 'group.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_H
#define UI_GROUP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Group
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *label;
    QToolButton *addField;
    QSpacerItem *horizontalSpacer;
    QToolButton *removeGroup;
    QListWidget *widgets;

    void setupUi(QWidget *Group)
    {
        if (Group->objectName().isEmpty())
            Group->setObjectName(QString::fromUtf8("Group"));
        Group->resize(450, 112);
        verticalLayout = new QVBoxLayout(Group);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLineEdit(Group);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        addField = new QToolButton(Group);
        addField->setObjectName(QString::fromUtf8("addField"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        addField->setIcon(icon);
        addField->setIconSize(QSize(15, 15));
        addField->setPopupMode(QToolButton::InstantPopup);
        addField->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addField->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(addField);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        removeGroup = new QToolButton(Group);
        removeGroup->setObjectName(QString::fromUtf8("removeGroup"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeGroup->setIcon(icon1);
        removeGroup->setPopupMode(QToolButton::InstantPopup);
        removeGroup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        removeGroup->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(removeGroup);


        verticalLayout->addLayout(horizontalLayout);

        widgets = new QListWidget(Group);
        widgets->setObjectName(QString::fromUtf8("widgets"));
        widgets->setDragDropMode(QAbstractItemView::InternalMove);
        widgets->setSelectionMode(QAbstractItemView::ExtendedSelection);
        widgets->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        widgets->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);

        verticalLayout->addWidget(widgets);


        retranslateUi(Group);

        QMetaObject::connectSlotsByName(Group);
    } // setupUi

    void retranslateUi(QWidget *Group)
    {
        Group->setWindowTitle(QApplication::translate("Group", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Group", "Group name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Group", "New group", 0, QApplication::UnicodeUTF8));
        addField->setText(QApplication::translate("Group", "Add field", 0, QApplication::UnicodeUTF8));
        removeGroup->setText(QApplication::translate("Group", "Remove group", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Group: public Ui_Group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_H
