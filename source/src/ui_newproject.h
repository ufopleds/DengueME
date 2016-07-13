/********************************************************************************
** Form generated from reading UI file 'newproject.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECT_H
#define UI_NEWPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QWizard>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_NewProject
{
public:
    QWizardPage *wizardPage1;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_newProject;
    QRadioButton *radioButton_newModel;
    QWizardPage *wizardPage;
    QVBoxLayout *verticalLayout_8;
    QWidget *widget_newProject;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_projectName;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_newModel;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QListView *listView_projects;
    QWizardPage *wizardPage_2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_modelName;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QListWidget *listWidget_modelType;
    QButtonGroup *buttonGroup;

    void setupUi(QWizard *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QString::fromUtf8("NewProject"));
        NewProject->resize(497, 300);
        NewProject->setWizardStyle(QWizard::ClassicStyle);
        wizardPage1 = new QWizardPage();
        wizardPage1->setObjectName(QString::fromUtf8("wizardPage1"));
        verticalLayout_2 = new QVBoxLayout(wizardPage1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButton_newProject = new QRadioButton(wizardPage1);
        buttonGroup = new QButtonGroup(NewProject);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(radioButton_newProject);
        radioButton_newProject->setObjectName(QString::fromUtf8("radioButton_newProject"));
        radioButton_newProject->setChecked(true);

        verticalLayout->addWidget(radioButton_newProject);

        radioButton_newModel = new QRadioButton(wizardPage1);
        buttonGroup->addButton(radioButton_newModel);
        radioButton_newModel->setObjectName(QString::fromUtf8("radioButton_newModel"));

        verticalLayout->addWidget(radioButton_newModel);


        verticalLayout_2->addLayout(verticalLayout);

        NewProject->addPage(wizardPage1);
        wizardPage = new QWizardPage();
        wizardPage->setObjectName(QString::fromUtf8("wizardPage"));
        verticalLayout_8 = new QVBoxLayout(wizardPage);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        widget_newProject = new QWidget(wizardPage);
        widget_newProject->setObjectName(QString::fromUtf8("widget_newProject"));
        verticalLayout_4 = new QVBoxLayout(widget_newProject);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_newProject);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit_projectName = new QLineEdit(widget_newProject);
        lineEdit_projectName->setObjectName(QString::fromUtf8("lineEdit_projectName"));
        lineEdit_projectName->setMaximumSize(QSize(250, 300));

        horizontalLayout->addWidget(lineEdit_projectName);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_8->addWidget(widget_newProject);

        widget_newModel = new QWidget(wizardPage);
        widget_newModel->setObjectName(QString::fromUtf8("widget_newModel"));
        verticalLayout_7 = new QVBoxLayout(widget_newModel);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(widget_newModel);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        listView_projects = new QListView(widget_newModel);
        listView_projects->setObjectName(QString::fromUtf8("listView_projects"));

        verticalLayout_3->addWidget(listView_projects);


        verticalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_8->addWidget(widget_newModel);

        NewProject->addPage(wizardPage);
        wizardPage_2 = new QWizardPage();
        wizardPage_2->setObjectName(QString::fromUtf8("wizardPage_2"));
        verticalLayout_6 = new QVBoxLayout(wizardPage_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(wizardPage_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_modelName = new QLineEdit(wizardPage_2);
        lineEdit_modelName->setObjectName(QString::fromUtf8("lineEdit_modelName"));
        lineEdit_modelName->setMaximumSize(QSize(300, 300));

        horizontalLayout_2->addWidget(lineEdit_modelName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_6->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(wizardPage_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        listWidget_modelType = new QListWidget(wizardPage_2);
        new QListWidgetItem(listWidget_modelType);
        new QListWidgetItem(listWidget_modelType);
        new QListWidgetItem(listWidget_modelType);
        new QListWidgetItem(listWidget_modelType);
        listWidget_modelType->setObjectName(QString::fromUtf8("listWidget_modelType"));

        verticalLayout_5->addWidget(listWidget_modelType);


        verticalLayout_6->addLayout(verticalLayout_5);

        NewProject->addPage(wizardPage_2);

        retranslateUi(NewProject);

        QMetaObject::connectSlotsByName(NewProject);
    } // setupUi

    void retranslateUi(QWizard *NewProject)
    {
        NewProject->setWindowTitle(QApplication::translate("NewProject", "Wizard", 0, QApplication::UnicodeUTF8));
        radioButton_newProject->setText(QApplication::translate("NewProject", "Create a new Project", 0, QApplication::UnicodeUTF8));
        radioButton_newModel->setText(QApplication::translate("NewProject", "Create a new Model in an existing Project", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewProject", "Project name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewProject", "Select a project to create a new Model:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewProject", "Model name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewProject", "Model type:", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget_modelType->isSortingEnabled();
        listWidget_modelType->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_modelType->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("NewProject", "Coupled", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget_modelType->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("NewProject", "Epidemiological", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget_modelType->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("NewProject", "Integrated", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget_modelType->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("NewProject", "Temporal", 0, QApplication::UnicodeUTF8));
        listWidget_modelType->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
