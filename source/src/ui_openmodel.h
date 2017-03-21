/********************************************************************************
** Form generated from reading UI file 'openmodel.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENMODEL_H
#define UI_OPENMODEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <workspaceview.h>

QT_BEGIN_NAMESPACE

class Ui_OpenModel
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    WorkspaceView *treeView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *OpenModel)
    {
        if (OpenModel->objectName().isEmpty())
            OpenModel->setObjectName(QStringLiteral("OpenModel"));
        OpenModel->setWindowModality(Qt::NonModal);
        OpenModel->resize(532, 402);
        OpenModel->setMinimumSize(QSize(532, 402));
        OpenModel->setMaximumSize(QSize(532, 402));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        OpenModel->setWindowIcon(icon);
        OpenModel->setModal(true);
        verticalLayout = new QVBoxLayout(OpenModel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(OpenModel);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        treeView = new WorkspaceView(OpenModel);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setContextMenuPolicy(Qt::CustomContextMenu);
        treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeView->setSortingEnabled(true);
        treeView->setAnimated(true);
        treeView->setHeaderHidden(true);

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ok = new QPushButton(OpenModel);
        ok->setObjectName(QStringLiteral("ok"));

        horizontalLayout->addWidget(ok);

        cancel = new QPushButton(OpenModel);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(OpenModel);

        QMetaObject::connectSlotsByName(OpenModel);
    } // setupUi

    void retranslateUi(QDialog *OpenModel)
    {
        OpenModel->setWindowTitle(QApplication::translate("OpenModel", "Open Model", 0));
        label->setText(QApplication::translate("OpenModel", "<html><head/><body><p><span style=\" font-size:xx-large; font-weight:600;\">Personal library of models</span><br/>Select the model to be opened</p></body></html>", 0));
        ok->setText(QApplication::translate("OpenModel", "Open", 0));
        cancel->setText(QApplication::translate("OpenModel", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class OpenModel: public Ui_OpenModel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENMODEL_H
