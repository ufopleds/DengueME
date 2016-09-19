/********************************************************************************
** Form generated from reading UI file 'group.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUP_H
#define UI_GROUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
            Group->setObjectName(QStringLiteral("Group"));
        Group->resize(450, 112);
        verticalLayout = new QVBoxLayout(Group);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLineEdit(Group);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        addField = new QToolButton(Group);
        addField->setObjectName(QStringLiteral("addField"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        addField->setIcon(icon);
        addField->setIconSize(QSize(15, 15));
        addField->setPopupMode(QToolButton::InstantPopup);
        addField->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addField->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(addField);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        removeGroup = new QToolButton(Group);
        removeGroup->setObjectName(QStringLiteral("removeGroup"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeGroup->setIcon(icon1);
        removeGroup->setPopupMode(QToolButton::InstantPopup);
        removeGroup->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        removeGroup->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(removeGroup);


        verticalLayout->addLayout(horizontalLayout);

        widgets = new QListWidget(Group);
        widgets->setObjectName(QStringLiteral("widgets"));
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
        Group->setWindowTitle(QApplication::translate("Group", "Form", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Group", "Group name", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("Group", "New group", 0));
        addField->setText(QApplication::translate("Group", "Add field", 0));
        removeGroup->setText(QApplication::translate("Group", "Remove group", 0));
    } // retranslateUi

};

namespace Ui {
    class Group: public Ui_Group {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUP_H
