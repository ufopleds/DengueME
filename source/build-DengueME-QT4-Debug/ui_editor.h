/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QStackedWidget>
#include <QtGui/QWidget>

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
            Editor->setObjectName(QString::fromUtf8("Editor"));
        Editor->resize(400, 300);
        horizontalLayout = new QHBoxLayout(Editor);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        list = new QListWidget(Editor);
        list->setObjectName(QString::fromUtf8("list"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(list->sizePolicy().hasHeightForWidth());
        list->setSizePolicy(sizePolicy);
        list->setMaximumSize(QSize(100, 16777215));
        list->setFrameShape(QFrame::NoFrame);
        list->setFrameShadow(QFrame::Plain);
        list->setLineWidth(0);
        list->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        list->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        list->setIconSize(QSize(48, 48));
        list->setMovement(QListView::Static);
        list->setFlow(QListView::TopToBottom);
        list->setProperty("isWrapping", QVariant(false));
        list->setViewMode(QListView::IconMode);

        horizontalLayout->addWidget(list);

        stack = new QStackedWidget(Editor);
        stack->setObjectName(QString::fromUtf8("stack"));
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
        Editor->setWindowTitle(QApplication::translate("Editor", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Editor: public Ui_Editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
