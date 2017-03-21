/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Editor
{
public:
    QHBoxLayout *horizontalLayout;
    QListWidget *list;
    QStackedWidget *stack;

    void setupUi(QWidget *Editor)
    {
        if (Editor->objectName().isEmpty())
            Editor->setObjectName(QStringLiteral("Editor"));
        Editor->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Editor);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        list = new QListWidget(Editor);
        list->setObjectName(QStringLiteral("list"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(list->sizePolicy().hasHeightForWidth());
        list->setSizePolicy(sizePolicy);
        list->setMaximumSize(QSize(100, 16777215));
        list->setFrameShape(QFrame::StyledPanel);
        list->setFrameShadow(QFrame::Sunken);
        list->setLineWidth(1);
        list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        list->setIconSize(QSize(48, 48));
        list->setMovement(QListView::Static);
        list->setFlow(QListView::TopToBottom);
        list->setProperty("isWrapping", QVariant(false));
        list->setViewMode(QListView::IconMode);

        horizontalLayout->addWidget(list);

        stack = new QStackedWidget(Editor);
        stack->setObjectName(QStringLiteral("stack"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(stack->sizePolicy().hasHeightForWidth());
        stack->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(stack);


        retranslateUi(Editor);

        stack->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Editor);
    } // setupUi

    void retranslateUi(QWidget *Editor)
    {
        Editor->setWindowTitle(QApplication::translate("Editor", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
