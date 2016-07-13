/********************************************************************************
** Form generated from reading UI file 'modelview.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELVIEW_H
#define UI_MODELVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *modelInfo;
    QLabel *modelType;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAdd;
    QListWidget *list;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_3;
    QComboBox *interpreter;
    QComboBox *mainFile;

    void setupUi(QFrame *ModelView)
    {
        if (ModelView->objectName().isEmpty())
            ModelView->setObjectName(QString::fromUtf8("ModelView"));
        ModelView->resize(451, 282);
        ModelView->setAutoFillBackground(true);
        ModelView->setFrameShape(QFrame::StyledPanel);
        ModelView->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(ModelView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(ModelView);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        modelInfo = new QLabel(ModelView);
        modelInfo->setObjectName(QString::fromUtf8("modelInfo"));
        modelInfo->setEnabled(false);
        modelInfo->setMargin(5);

        horizontalLayout->addWidget(modelInfo);

        modelType = new QLabel(ModelView);
        modelType->setObjectName(QString::fromUtf8("modelType"));
        modelType->setEnabled(false);
        modelType->setMargin(5);

        horizontalLayout->addWidget(modelType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonAdd = new QPushButton(ModelView);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);


        verticalLayout->addLayout(horizontalLayout);

        list = new QListWidget(ModelView);
        list->setObjectName(QString::fromUtf8("list"));
        list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list->setAlternatingRowColors(true);
        list->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout->addWidget(list);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(-1, 6, -1, -1);
        label = new QLabel(ModelView);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_3 = new QLabel(ModelView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        interpreter = new QComboBox(ModelView);
        interpreter->setObjectName(QString::fromUtf8("interpreter"));

        formLayout->setWidget(1, QFormLayout::FieldRole, interpreter);

        mainFile = new QComboBox(ModelView);
        mainFile->setObjectName(QString::fromUtf8("mainFile"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mainFile);


        verticalLayout->addLayout(formLayout);


        retranslateUi(ModelView);

        QMetaObject::connectSlotsByName(ModelView);
    } // setupUi

    void retranslateUi(QFrame *ModelView)
    {
        ModelView->setWindowTitle(QApplication::translate("ModelView", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ModelView", "Model files", 0, QApplication::UnicodeUTF8));
        modelInfo->setText(QApplication::translate("ModelView", "Type", 0, QApplication::UnicodeUTF8));
        modelType->setText(QApplication::translate("ModelView", "Category", 0, QApplication::UnicodeUTF8));
        buttonAdd->setText(QApplication::translate("ModelView", "Add", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ModelView", "Main file:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ModelView", "Interpreter:", 0, QApplication::UnicodeUTF8));
        interpreter->clear();
        interpreter->insertItems(0, QStringList()
         << QApplication::translate("ModelView", "TerraME", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ModelView", "Rscript", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class ModelView: public Ui_ModelView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELVIEW_H
