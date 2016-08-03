/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <workspaceview.h>
#include "editor.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionRun;
    QAction *actionProject;
    QAction *actionModel;
    QAction *actionNewProject;
    QAction *actionEpidemiological;
    QAction *actionCoupled;
    QAction *actionIntegrated;
    QAction *actionTemporal;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionOptions;
    QAction *actionClose;
    QAction *actionRunByStep;
    QAction *actionSetWorkspace;
    QAction *actionRename;
    QAction *actionRemove;
    QAction *actionNewModel;
    QAction *actionModelBuilder;
    QAction *actionResetViews;
    QAction *actionBuilder;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *editorView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *modelFile;
    QPushButton *buttonDefault;
    QToolButton *buttonHelp;
    QToolButton *buttonClose;
    Editor *editor;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuProject;
    QMenu *menuEdit;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QDockWidget *explorerDock;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_6;
    WorkspaceView *treeView;
    QDockWidget *outputDock;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *outputBrowser;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QPushButton *run_stopButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(706, 534);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        actionRun->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/Resources/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon3);
        actionProject = new QAction(MainWindow);
        actionProject->setObjectName(QString::fromUtf8("actionProject"));
        actionModel = new QAction(MainWindow);
        actionModel->setObjectName(QString::fromUtf8("actionModel"));
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionNewProject->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/Resources/folder-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewProject->setIcon(icon4);
        actionEpidemiological = new QAction(MainWindow);
        actionEpidemiological->setObjectName(QString::fromUtf8("actionEpidemiological"));
        actionCoupled = new QAction(MainWindow);
        actionCoupled->setObjectName(QString::fromUtf8("actionCoupled"));
        actionIntegrated = new QAction(MainWindow);
        actionIntegrated->setObjectName(QString::fromUtf8("actionIntegrated"));
        actionTemporal = new QAction(MainWindow);
        actionTemporal->setObjectName(QString::fromUtf8("actionTemporal"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QString::fromUtf8("actionOptions"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon5);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Resources/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon6);
        actionRunByStep = new QAction(MainWindow);
        actionRunByStep->setObjectName(QString::fromUtf8("actionRunByStep"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/Resources/run-step.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRunByStep->setIcon(icon7);
        actionSetWorkspace = new QAction(MainWindow);
        actionSetWorkspace->setObjectName(QString::fromUtf8("actionSetWorkspace"));
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QString::fromUtf8("actionRename"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/Resources/rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRename->setIcon(icon8);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QString::fromUtf8("actionRemove"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon9);
        actionNewModel = new QAction(MainWindow);
        actionNewModel->setObjectName(QString::fromUtf8("actionNewModel"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/Resources/model-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewModel->setIcon(icon10);
        actionModelBuilder = new QAction(MainWindow);
        actionModelBuilder->setObjectName(QString::fromUtf8("actionModelBuilder"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/Resources/builderTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModelBuilder->setIcon(icon11);
        actionResetViews = new QAction(MainWindow);
        actionResetViews->setObjectName(QString::fromUtf8("actionResetViews"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/Resources/Synchronize-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetViews->setIcon(icon12);
        actionBuilder = new QAction(MainWindow);
        actionBuilder->setObjectName(QString::fromUtf8("actionBuilder"));
        actionBuilder->setCheckable(false);
        actionBuilder->setEnabled(true);
        actionBuilder->setIcon(icon11);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editorView = new QWidget(centralWidget);
        editorView->setObjectName(QString::fromUtf8("editorView"));
        verticalLayout_2 = new QVBoxLayout(editorView);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        modelFile = new QLabel(editorView);
        modelFile->setObjectName(QString::fromUtf8("modelFile"));
        modelFile->setMargin(6);
        modelFile->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(modelFile);

        buttonDefault = new QPushButton(editorView);
        buttonDefault->setObjectName(QString::fromUtf8("buttonDefault"));
        buttonDefault->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonDefault->sizePolicy().hasHeightForWidth());
        buttonDefault->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonDefault);

        buttonHelp = new QToolButton(editorView);
        buttonHelp->setObjectName(QString::fromUtf8("buttonHelp"));
        buttonHelp->setStyleSheet(QString::fromUtf8("border: none;"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonHelp->setIcon(icon13);
        buttonHelp->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(buttonHelp);

        buttonClose = new QToolButton(editorView);
        buttonClose->setObjectName(QString::fromUtf8("buttonClose"));
        buttonClose->setStyleSheet(QString::fromUtf8("border: none;"));
        buttonClose->setIcon(icon6);
        buttonClose->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(buttonClose);


        verticalLayout_2->addLayout(horizontalLayout_2);

        editor = new Editor(editorView);
        editor->setObjectName(QString::fromUtf8("editor"));

        verticalLayout_2->addWidget(editor);

        verticalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(editorView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 706, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QString::fromUtf8("menuProject"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        explorerDock = new QDockWidget(MainWindow);
        explorerDock->setObjectName(QString::fromUtf8("explorerDock"));
        explorerDock->setFloating(false);
        explorerDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        treeView = new WorkspaceView(dockWidgetContents);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSortingEnabled(true);
        treeView->setAnimated(true);
        treeView->setHeaderHidden(true);

        verticalLayout_6->addWidget(treeView);

        explorerDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), explorerDock);
        outputDock = new QDockWidget(MainWindow);
        outputDock->setObjectName(QString::fromUtf8("outputDock"));
        outputDock->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        outputBrowser = new QTextBrowser(dockWidgetContents_4);
        outputBrowser->setObjectName(QString::fromUtf8("outputBrowser"));

        verticalLayout_3->addWidget(outputBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(dockWidgetContents_4);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout->addWidget(clearButton);

        run_stopButton = new QPushButton(dockWidgetContents_4);
        run_stopButton->setObjectName(QString::fromUtf8("run_stopButton"));
        run_stopButton->setEnabled(false);

        horizontalLayout->addWidget(run_stopButton);


        verticalLayout_3->addLayout(horizontalLayout);

        outputDock->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), outputDock);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuProject->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewModel);
        menuFile->addAction(actionNewProject);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionRename);
        menuFile->addAction(actionRemove);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuProject->addAction(actionRun);
        menuProject->addAction(actionRunByStep);
        menuEdit->addAction(actionOptions);
        menuEdit->addAction(actionSetWorkspace);
        menuEdit->addAction(actionModelBuilder);
        menuView->addAction(actionResetViews);
        mainToolBar->addAction(actionNewProject);
        mainToolBar->addAction(actionNewModel);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionRename);
        mainToolBar->addAction(actionRemove);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionBuilder);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionRunByStep);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DengueME", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionRun->setText(QApplication::translate("MainWindow", "&Run", 0, QApplication::UnicodeUTF8));
        actionRun->setShortcut(QApplication::translate("MainWindow", "F9, Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionProject->setText(QApplication::translate("MainWindow", "Project", 0, QApplication::UnicodeUTF8));
        actionModel->setText(QApplication::translate("MainWindow", "Model", 0, QApplication::UnicodeUTF8));
        actionNewProject->setText(QApplication::translate("MainWindow", "New &project", 0, QApplication::UnicodeUTF8));
        actionNewProject->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionEpidemiological->setText(QApplication::translate("MainWindow", "E&pidemiological", 0, QApplication::UnicodeUTF8));
        actionCoupled->setText(QApplication::translate("MainWindow", "&Coupled", 0, QApplication::UnicodeUTF8));
        actionIntegrated->setText(QApplication::translate("MainWindow", "&Integrated", 0, QApplication::UnicodeUTF8));
        actionTemporal->setText(QApplication::translate("MainWindow", "&Temporal", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionOptions->setText(QApplication::translate("MainWindow", "&Options", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "&Close model ", 0, QApplication::UnicodeUTF8));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionRunByStep->setText(QApplication::translate("MainWindow", "Run &step by step", 0, QApplication::UnicodeUTF8));
        actionRunByStep->setShortcut(QApplication::translate("MainWindow", "F10", 0, QApplication::UnicodeUTF8));
        actionSetWorkspace->setText(QApplication::translate("MainWindow", "Change &workspace", 0, QApplication::UnicodeUTF8));
        actionRename->setText(QApplication::translate("MainWindow", "&Rename", 0, QApplication::UnicodeUTF8));
        actionRename->setShortcut(QApplication::translate("MainWindow", "F2", 0, QApplication::UnicodeUTF8));
        actionRemove->setText(QApplication::translate("MainWindow", "R&emove", 0, QApplication::UnicodeUTF8));
        actionRemove->setShortcut(QApplication::translate("MainWindow", "Del", 0, QApplication::UnicodeUTF8));
        actionNewModel->setText(QApplication::translate("MainWindow", "New &model", 0, QApplication::UnicodeUTF8));
        actionNewModel->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionModelBuilder->setText(QApplication::translate("MainWindow", "&Model builder", 0, QApplication::UnicodeUTF8));
        actionModelBuilder->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        actionResetViews->setText(QApplication::translate("MainWindow", "Reset views", 0, QApplication::UnicodeUTF8));
        actionBuilder->setText(QApplication::translate("MainWindow", "Model Builder", 0, QApplication::UnicodeUTF8));
        modelFile->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
        buttonDefault->setText(QApplication::translate("MainWindow", "Default Values", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menuProject->setTitle(QApplication::translate("MainWindow", "&Project", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Tools", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "Window", 0, QApplication::UnicodeUTF8));
        explorerDock->setWindowTitle(QApplication::translate("MainWindow", "Projects", 0, QApplication::UnicodeUTF8));
        outputDock->setWindowTitle(QApplication::translate("MainWindow", "Console", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("MainWindow", "Clear Console", 0, QApplication::UnicodeUTF8));
        run_stopButton->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
