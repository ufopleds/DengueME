/********************************************************************************
** Form generated from reading UI file 'syncmodels.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYNCMODELS_H
#define UI_SYNCMODELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SyncModels
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QProgressBar *progressBar;
    QListView *listView;
    QHBoxLayout *horizontalLayout;
    QPushButton *downloadButton;
    QPushButton *updateButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SyncModels)
    {
        if (SyncModels->objectName().isEmpty())
            SyncModels->setObjectName(QStringLiteral("SyncModels"));
        SyncModels->resize(375, 271);
        verticalLayoutWidget = new QWidget(SyncModels);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 361, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);

        listView = new QListView(verticalLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(listView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        downloadButton = new QPushButton(verticalLayoutWidget);
        downloadButton->setObjectName(QStringLiteral("downloadButton"));
        downloadButton->setEnabled(false);

        horizontalLayout->addWidget(downloadButton);

        updateButton = new QPushButton(verticalLayoutWidget);
        updateButton->setObjectName(QStringLiteral("updateButton"));

        horizontalLayout->addWidget(updateButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayoutWidget->raise();
        label->raise();

        retranslateUi(SyncModels);
        QObject::connect(cancelButton, SIGNAL(clicked()), SyncModels, SLOT(close()));

        QMetaObject::connectSlotsByName(SyncModels);
    } // setupUi

    void retranslateUi(QDialog *SyncModels)
    {
        SyncModels->setWindowTitle(QApplication::translate("SyncModels", "SyncModels", 0));
        label->setText(QApplication::translate("SyncModels", "Check and Download Model Updates.", 0));
        downloadButton->setText(QApplication::translate("SyncModels", "Download", 0));
        updateButton->setText(QApplication::translate("SyncModels", "Check Updates", 0));
        cancelButton->setText(QApplication::translate("SyncModels", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class SyncModels: public Ui_SyncModels {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYNCMODELS_H
