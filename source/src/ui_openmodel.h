/********************************************************************************
** Form generated from reading UI file 'openmodel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENMODEL_H
#define UI_OPENMODEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <workspaceview.h>

QT_BEGIN_NAMESPACE

class Ui_OpenModel
{
public:
    QPushButton *ok;
    WorkspaceView *treeView;
    QPushButton *cancel;
    QLabel *label;

    void setupUi(QDialog *OpenModel)
    {
        if (OpenModel->objectName().isEmpty())
            OpenModel->setObjectName(QString::fromUtf8("OpenModel"));
        OpenModel->setWindowModality(Qt::NonModal);
        OpenModel->resize(535, 402);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenModel->setWindowIcon(icon);
        OpenModel->setModal(true);
        ok = new QPushButton(OpenModel);
        ok->setObjectName(QString::fromUtf8("ok"));
        ok->setGeometry(QRect(350, 370, 75, 23));
        treeView = new WorkspaceView(OpenModel);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 20, 511, 341));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSortingEnabled(true);
        treeView->setAnimated(true);
        treeView->setHeaderHidden(true);
        cancel = new QPushButton(OpenModel);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(440, 370, 75, 23));
        label = new QLabel(OpenModel);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 511, 20));

        retranslateUi(OpenModel);

        QMetaObject::connectSlotsByName(OpenModel);
    } // setupUi

    void retranslateUi(QDialog *OpenModel)
    {
        OpenModel->setWindowTitle(QApplication::translate("OpenModel", "Open Model", 0, QApplication::UnicodeUTF8));
        ok->setText(QApplication::translate("OpenModel", "Ok", 0, QApplication::UnicodeUTF8));
        cancel->setText(QApplication::translate("OpenModel", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("OpenModel", "Select one model.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OpenModel: public Ui_OpenModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENMODEL_H
