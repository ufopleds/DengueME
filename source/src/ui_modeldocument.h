/********************************************************************************
** Form generated from reading UI file 'modeldocument.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELDOCUMENT_H
#define UI_MODELDOCUMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelDocument
{
public:
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *saveButton;
    QPushButton *helpSyntax;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_2;
    QLabel *filenameLabel;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *modelName;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QLineEdit *modelType;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QTextEdit *descriptionBox;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *ModelDocument)
    {
        if (ModelDocument->objectName().isEmpty())
            ModelDocument->setObjectName(QStringLiteral("ModelDocument"));
        ModelDocument->resize(691, 435);
        horizontalLayout_9 = new QHBoxLayout(ModelDocument);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        saveButton = new QPushButton(ModelDocument);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_5->addWidget(saveButton);

        helpSyntax = new QPushButton(ModelDocument);
        helpSyntax->setObjectName(QStringLiteral("helpSyntax"));

        horizontalLayout_5->addWidget(helpSyntax);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);


        verticalLayout_5->addLayout(horizontalLayout_5);

        line_2 = new QFrame(ModelDocument);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_2);


        verticalLayout_4->addLayout(verticalLayout_5);

        filenameLabel = new QLabel(ModelDocument);
        filenameLabel->setObjectName(QStringLiteral("filenameLabel"));

        verticalLayout_4->addWidget(filenameLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(ModelDocument);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        modelName = new QLineEdit(ModelDocument);
        modelName->setObjectName(QStringLiteral("modelName"));
        modelName->setFrame(false);
        modelName->setReadOnly(true);

        horizontalLayout_6->addWidget(modelName);

        horizontalSpacer_6 = new QSpacerItem(480, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(ModelDocument);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        modelType = new QLineEdit(ModelDocument);
        modelType->setObjectName(QStringLiteral("modelType"));
        modelType->setFrame(false);
        modelType->setReadOnly(true);

        horizontalLayout_7->addWidget(modelType);

        horizontalSpacer_7 = new QSpacerItem(480, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(ModelDocument);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        descriptionBox = new QTextEdit(ModelDocument);
        descriptionBox->setObjectName(QStringLiteral("descriptionBox"));

        verticalLayout_6->addWidget(descriptionBox);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);


        verticalLayout_6->addLayout(horizontalLayout_8);


        verticalLayout_4->addLayout(verticalLayout_6);


        horizontalLayout_9->addLayout(verticalLayout_4);


        retranslateUi(ModelDocument);

        QMetaObject::connectSlotsByName(ModelDocument);
    } // setupUi

    void retranslateUi(QDialog *ModelDocument)
    {
        ModelDocument->setWindowTitle(QApplication::translate("ModelDocument", "Model Desicription", 0));
        saveButton->setText(QApplication::translate("ModelDocument", "Save", 0));
        helpSyntax->setText(QApplication::translate("ModelDocument", "Syntax Help", 0));
        filenameLabel->setText(QApplication::translate("ModelDocument", "Filename:", 0));
        label_6->setText(QApplication::translate("ModelDocument", "Model name:", 0));
        label_7->setText(QApplication::translate("ModelDocument", "Model type: ", 0));
        label_8->setText(QApplication::translate("ModelDocument", "Model Description:", 0));
    } // retranslateUi

};

namespace Ui {
    class ModelDocument: public Ui_ModelDocument {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELDOCUMENT_H
