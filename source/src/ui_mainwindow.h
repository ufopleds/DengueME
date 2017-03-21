/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
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
    QAction *actionSynchronize;
    QAction *actionOpenExplorer;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *editorView;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *modelFile;
    QPushButton *buttonDefault;
    QToolButton *buttonHelp;
    QToolButton *buttonClose;
    QSpacerItem *horizontalSpacer_2;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(706, 534);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/Resources/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionRun->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon3);
        actionProject = new QAction(MainWindow);
        actionProject->setObjectName(QStringLiteral("actionProject"));
        actionModel = new QAction(MainWindow);
        actionModel->setObjectName(QStringLiteral("actionModel"));
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QStringLiteral("actionNewProject"));
        actionNewProject->setEnabled(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/Resources/folder-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewProject->setIcon(icon4);
        actionEpidemiological = new QAction(MainWindow);
        actionEpidemiological->setObjectName(QStringLiteral("actionEpidemiological"));
        actionCoupled = new QAction(MainWindow);
        actionCoupled->setObjectName(QStringLiteral("actionCoupled"));
        actionIntegrated = new QAction(MainWindow);
        actionIntegrated->setObjectName(QStringLiteral("actionIntegrated"));
        actionTemporal = new QAction(MainWindow);
        actionTemporal->setObjectName(QStringLiteral("actionTemporal"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOptions->setIcon(icon5);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Resources/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon6);
        actionRunByStep = new QAction(MainWindow);
        actionRunByStep->setObjectName(QStringLiteral("actionRunByStep"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/Resources/run-step.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRunByStep->setIcon(icon7);
        actionSetWorkspace = new QAction(MainWindow);
        actionSetWorkspace->setObjectName(QStringLiteral("actionSetWorkspace"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/Resources/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetWorkspace->setIcon(icon8);
        actionRename = new QAction(MainWindow);
        actionRename->setObjectName(QStringLiteral("actionRename"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/Resources/rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRename->setIcon(icon9);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/Resources/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon10);
        actionNewModel = new QAction(MainWindow);
        actionNewModel->setObjectName(QStringLiteral("actionNewModel"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/Resources/model-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewModel->setIcon(icon11);
        actionModelBuilder = new QAction(MainWindow);
        actionModelBuilder->setObjectName(QStringLiteral("actionModelBuilder"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/Resources/builderTool.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModelBuilder->setIcon(icon12);
        actionResetViews = new QAction(MainWindow);
        actionResetViews->setObjectName(QStringLiteral("actionResetViews"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/img/Resources/Synchronize-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionResetViews->setIcon(icon13);
        actionBuilder = new QAction(MainWindow);
        actionBuilder->setObjectName(QStringLiteral("actionBuilder"));
        actionBuilder->setCheckable(false);
        actionBuilder->setEnabled(true);
        actionBuilder->setIcon(icon12);
        actionSynchronize = new QAction(MainWindow);
        actionSynchronize->setObjectName(QStringLiteral("actionSynchronize"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Resources/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSynchronize->setIcon(icon14);
        actionOpenExplorer = new QAction(MainWindow);
        actionOpenExplorer->setObjectName(QStringLiteral("actionOpenExplorer"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        editorView = new QWidget(centralWidget);
        editorView->setObjectName(QStringLiteral("editorView"));
        verticalLayout_2 = new QVBoxLayout(editorView);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        modelFile = new QLabel(editorView);
        modelFile->setObjectName(QStringLiteral("modelFile"));
        modelFile->setMargin(6);
        modelFile->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        horizontalLayout_2->addWidget(modelFile);

        buttonDefault = new QPushButton(editorView);
        buttonDefault->setObjectName(QStringLiteral("buttonDefault"));
        buttonDefault->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonDefault->sizePolicy().hasHeightForWidth());
        buttonDefault->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(buttonDefault);

        buttonHelp = new QToolButton(editorView);
        buttonHelp->setObjectName(QStringLiteral("buttonHelp"));
        buttonHelp->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/img/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonHelp->setIcon(icon15);
        buttonHelp->setIconSize(QSize(24, 24));

        horizontalLayout_2->addWidget(buttonHelp);

        buttonClose = new QToolButton(editorView);
        buttonClose->setObjectName(QStringLiteral("buttonClose"));
        buttonClose->setStyleSheet(QStringLiteral("border: none;"));
        buttonClose->setIcon(icon6);
        buttonClose->setIconSize(QSize(18, 18));

        horizontalLayout_2->addWidget(buttonClose);

        horizontalSpacer_2 = new QSpacerItem(5, 5, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        editor = new Editor(editorView);
        editor->setObjectName(QStringLiteral("editor"));

        verticalLayout_2->addWidget(editor);

        verticalLayout_2->setStretch(1, 1);

        verticalLayout->addWidget(editorView);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 706, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuProject = new QMenu(menuBar);
        menuProject->setObjectName(QStringLiteral("menuProject"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setMovable(false);
        mainToolBar->setAllowedAreas(Qt::TopToolBarArea);
        mainToolBar->setIconSize(QSize(24, 24));
        mainToolBar->setFloatable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        explorerDock = new QDockWidget(MainWindow);
        explorerDock->setObjectName(QStringLiteral("explorerDock"));
        explorerDock->setFloating(false);
        explorerDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        treeView = new WorkspaceView(dockWidgetContents);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSortingEnabled(true);
        treeView->setAnimated(true);
        treeView->setHeaderHidden(true);

        verticalLayout_6->addWidget(treeView);

        explorerDock->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), explorerDock);
        outputDock = new QDockWidget(MainWindow);
        outputDock->setObjectName(QStringLiteral("outputDock"));
        outputDock->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        outputBrowser = new QTextBrowser(dockWidgetContents_4);
        outputBrowser->setObjectName(QStringLiteral("outputBrowser"));

        verticalLayout_3->addWidget(outputBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(dockWidgetContents_4);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        horizontalLayout->addWidget(clearButton);

        run_stopButton = new QPushButton(dockWidgetContents_4);
        run_stopButton->setObjectName(QStringLiteral("run_stopButton"));
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
        menuEdit->addAction(actionModelBuilder);
        menuEdit->addAction(actionSetWorkspace);
        menuEdit->addAction(actionSynchronize);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "DengueME", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "&About", 0));
        actionAbout->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        actionExit->setText(QApplication::translate("MainWindow", "E&xit", 0));
        actionSave->setText(QApplication::translate("MainWindow", "&Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        actionRun->setText(QApplication::translate("MainWindow", "&Run", 0));
        actionRun->setShortcut(QApplication::translate("MainWindow", "F9, Ctrl+R", 0));
        actionProject->setText(QApplication::translate("MainWindow", "Project", 0));
        actionModel->setText(QApplication::translate("MainWindow", "Model", 0));
        actionNewProject->setText(QApplication::translate("MainWindow", "New &Project", 0));
        actionNewProject->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionEpidemiological->setText(QApplication::translate("MainWindow", "E&pidemiological", 0));
        actionCoupled->setText(QApplication::translate("MainWindow", "&Coupled", 0));
        actionIntegrated->setText(QApplication::translate("MainWindow", "&Integrated", 0));
        actionTemporal->setText(QApplication::translate("MainWindow", "&Temporal", 0));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "&Options", 0));
        actionClose->setText(QApplication::translate("MainWindow", "&Close Model ", 0));
        actionClose->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionRunByStep->setText(QApplication::translate("MainWindow", "Run &Step by Step", 0));
        actionRunByStep->setShortcut(QApplication::translate("MainWindow", "F10", 0));
        actionSetWorkspace->setText(QApplication::translate("MainWindow", "Change &Workspace", 0));
        actionRename->setText(QApplication::translate("MainWindow", "&Rename", 0));
        actionRename->setShortcut(QApplication::translate("MainWindow", "F2", 0));
        actionRemove->setText(QApplication::translate("MainWindow", "Delete", 0));
        actionRemove->setShortcut(QApplication::translate("MainWindow", "Del", 0));
        actionNewModel->setText(QApplication::translate("MainWindow", "New &Model", 0));
        actionNewModel->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionModelBuilder->setText(QApplication::translate("MainWindow", "&Model Builder", 0));
        actionModelBuilder->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0));
        actionResetViews->setText(QApplication::translate("MainWindow", "Reset Views", 0));
        actionBuilder->setText(QApplication::translate("MainWindow", "Model Builder", 0));
        actionSynchronize->setText(QApplication::translate("MainWindow", "Update Models Library", 0));
        actionSynchronize->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionOpenExplorer->setText(QApplication::translate("MainWindow", "Open in Explorer", 0));
        modelFile->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        buttonDefault->setText(QApplication::translate("MainWindow", "Default Values", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", 0));
        menuProject->setTitle(QApplication::translate("MainWindow", "&Project", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Tools", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "Window", 0));
        explorerDock->setWindowTitle(QApplication::translate("MainWindow", "Projects", 0));
        outputDock->setWindowTitle(QApplication::translate("MainWindow", "Console", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Clear Console", 0));
        run_stopButton->setText(QApplication::translate("MainWindow", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
