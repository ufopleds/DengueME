/********************************************************************************
** Form generated from reading UI file 'modelbuilder.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELBUILDER_H
#define UI_MODELBUILDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <workspaceview.h>
#include "editor.h"

QT_BEGIN_NAMESPACE

class Ui_ModelBuilder
{
public:
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionDelete;
    QAction *actionNew;
    QAction *actionEdit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    WorkspaceView *listView;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *modelFile;
    QToolButton *buttonHelp;
    QToolButton *buttonClose;
    Editor *editor;
    QMenuBar *menubar;
    QMenu *menuFile;
    QToolBar *toolBar;

    void setupUi(QMainWindow *ModelBuilder)
    {
        if (ModelBuilder->objectName().isEmpty())
            ModelBuilder->setObjectName(QStringLiteral("ModelBuilder"));
        ModelBuilder->setWindowModality(Qt::WindowModal);
        ModelBuilder->resize(900, 600);
        actionExit = new QAction(ModelBuilder);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        actionSave = new QAction(ModelBuilder);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionDelete = new QAction(ModelBuilder);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon2);
        actionNew = new QAction(ModelBuilder);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/model-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon3);
        actionEdit = new QAction(ModelBuilder);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/Resources/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon4);
        centralwidget = new QWidget(ModelBuilder);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        listView = new WorkspaceView(page);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listView->setIndentation(4);
        listView->setRootIsDecorated(false);
        listView->setSortingEnabled(true);
        listView->setHeaderHidden(true);

        verticalLayout_3->addWidget(listView);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_2 = new QVBoxLayout(page_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        modelFile = new QLabel(page_2);
        modelFile->setObjectName(QStringLiteral("modelFile"));

        horizontalLayout_2->addWidget(modelFile);

        buttonHelp = new QToolButton(page_2);
        buttonHelp->setObjectName(QStringLiteral("buttonHelp"));
        buttonHelp->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonHelp->setIcon(icon5);
        buttonHelp->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(buttonHelp);

        buttonClose = new QToolButton(page_2);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setStyleSheet(QStringLiteral("border: none;"));
        buttonClose->setIcon(icon);
        buttonClose->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(buttonClose);


        verticalLayout_2->addLayout(horizontalLayout_2);

        editor = new Editor(page_2);
        editor->setObjectName(QStringLiteral("editor"));

        verticalLayout_2->addWidget(editor);

        verticalLayout_2->setStretch(1, 1);
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        ModelBuilder->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ModelBuilder);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        ModelBuilder->setMenuBar(menubar);
        toolBar = new QToolBar(ModelBuilder);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        ModelBuilder->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionEdit);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionDelete);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(ModelBuilder);
        QObject::connect(actionExit, SIGNAL(triggered()), ModelBuilder, SLOT(close()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModelBuilder);
    } // setupUi

    void retranslateUi(QMainWindow *ModelBuilder)
    {
        ModelBuilder->setWindowTitle(QApplication::translate("ModelBuilder", "MainWindow", 0));
        actionExit->setText(QApplication::translate("ModelBuilder", "E&xit", 0));
        actionSave->setText(QApplication::translate("ModelBuilder", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("ModelBuilder", "Ctrl+S", 0));
        actionDelete->setText(QApplication::translate("ModelBuilder", "&Delete", 0));
        actionDelete->setShortcut(QApplication::translate("ModelBuilder", "Del", 0));
        actionNew->setText(QApplication::translate("ModelBuilder", "&New", 0));
        actionNew->setShortcut(QApplication::translate("ModelBuilder", "Ctrl+N", 0));
        actionEdit->setText(QApplication::translate("ModelBuilder", "&Open", 0));
        actionEdit->setShortcut(QApplication::translate("ModelBuilder", "Ctrl+P", 0));
        modelFile->setText(QApplication::translate("ModelBuilder", "TextLabel", 0));
        menuFile->setTitle(QApplication::translate("ModelBuilder", "Fi&le", 0));
        toolBar->setWindowTitle(QApplication::translate("ModelBuilder", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class ModelBuilder: public Ui_ModelBuilder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELBUILDER_H
