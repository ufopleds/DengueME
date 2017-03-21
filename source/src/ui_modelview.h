/********************************************************************************
** Form generated from reading UI file 'modelview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELVIEW_H
#define UI_MODELVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ModelView
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLineEdit *userIdText;
    QLabel *label_5;
    QLineEdit *nameText;
    QLabel *label_6;
    QComboBox *categoryCombo;
    QLabel *label_7;
    QComboBox *typeCombo;
    QLabel *label_8;
    QLineEdit *titleText;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *authorsList;
    QVBoxLayout *verticalLayout;
    QToolButton *add;
    QToolButton *del;
    QLabel *label_10;
    QTextEdit *descriptionText;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *modelInfo;
    QLabel *modelType;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonAdd;
    QListWidget *list;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *mainFile;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *interpreter;
    QLabel *label_11;
    QComboBox *versionCombo;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;

    void setupUi(QFrame *ModelView)
    {
        if (ModelView->objectName().isEmpty())
            ModelView->setObjectName(QStringLiteral("ModelView"));
        ModelView->resize(372, 630);
        ModelView->setAutoFillBackground(true);
        ModelView->setFrameShape(QFrame::StyledPanel);
        ModelView->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(ModelView);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(ModelView);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        userIdText = new QLineEdit(ModelView);
        userIdText->setObjectName(QStringLiteral("userIdText"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, userIdText);

        label_5 = new QLabel(ModelView);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        nameText = new QLineEdit(ModelView);
        nameText->setObjectName(QStringLiteral("nameText"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, nameText);

        label_6 = new QLabel(ModelView);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_6);

        categoryCombo = new QComboBox(ModelView);
        categoryCombo->setObjectName(QStringLiteral("categoryCombo"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, categoryCombo);

        label_7 = new QLabel(ModelView);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        typeCombo = new QComboBox(ModelView);
        typeCombo->setObjectName(QStringLiteral("typeCombo"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, typeCombo);

        label_8 = new QLabel(ModelView);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_8);

        titleText = new QLineEdit(ModelView);
        titleText->setObjectName(QStringLiteral("titleText"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, titleText);

        label_9 = new QLabel(ModelView);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_9);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        authorsList = new QListWidget(ModelView);
        authorsList->setObjectName(QStringLiteral("authorsList"));
        authorsList->setEditTriggers(QAbstractItemView::DoubleClicked);
        authorsList->setDragEnabled(true);
        authorsList->setDragDropMode(QAbstractItemView::DragDrop);
        authorsList->setDefaultDropAction(Qt::MoveAction);
        authorsList->setSelectionMode(QAbstractItemView::SingleSelection);

        horizontalLayout_2->addWidget(authorsList);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        add = new QToolButton(ModelView);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout->addWidget(add);

        del = new QToolButton(ModelView);
        del->setObjectName(QStringLiteral("del"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout->addWidget(del);


        horizontalLayout_2->addLayout(verticalLayout);


        formLayout_2->setLayout(5, QFormLayout::FieldRole, horizontalLayout_2);

        label_10 = new QLabel(ModelView);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_10);

        descriptionText = new QTextEdit(ModelView);
        descriptionText->setObjectName(QStringLiteral("descriptionText"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, descriptionText);


        verticalLayout_2->addLayout(formLayout_2);

        line = new QFrame(ModelView);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(ModelView);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        modelInfo = new QLabel(ModelView);
        modelInfo->setObjectName(QStringLiteral("modelInfo"));
        modelInfo->setEnabled(false);
        modelInfo->setMargin(5);

        horizontalLayout->addWidget(modelInfo);

        modelType = new QLabel(ModelView);
        modelType->setObjectName(QStringLiteral("modelType"));
        modelType->setEnabled(false);
        modelType->setMargin(5);

        horizontalLayout->addWidget(modelType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonAdd = new QPushButton(ModelView);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        horizontalLayout->addWidget(buttonAdd);


        verticalLayout_2->addLayout(horizontalLayout);

        list = new QListWidget(ModelView);
        list->setObjectName(QStringLiteral("list"));
        list->setMinimumSize(QSize(200, 200));
        list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        list->setAlternatingRowColors(true);
        list->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_2->addWidget(list);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(-1, 6, -1, -1);
        label = new QLabel(ModelView);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        mainFile = new QComboBox(ModelView);
        mainFile->setObjectName(QStringLiteral("mainFile"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mainFile);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        interpreter = new QComboBox(ModelView);
        interpreter->setObjectName(QStringLiteral("interpreter"));

        horizontalLayout_3->addWidget(interpreter);

        label_11 = new QLabel(ModelView);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_3->addWidget(label_11);

        versionCombo = new QComboBox(ModelView);
        versionCombo->setObjectName(QStringLiteral("versionCombo"));

        horizontalLayout_3->addWidget(versionCombo);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_3);

        label_3 = new QLabel(ModelView);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);


        verticalLayout_2->addLayout(formLayout);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(ModelView);

        QMetaObject::connectSlotsByName(ModelView);
    } // setupUi

    void retranslateUi(QFrame *ModelView)
    {
        ModelView->setWindowTitle(QApplication::translate("ModelView", "Form", 0));
        label_4->setText(QApplication::translate("ModelView", "User ID(FileName): ", 0));
        label_5->setText(QApplication::translate("ModelView", "Name: ", 0));
        label_6->setText(QApplication::translate("ModelView", "Category: ", 0));
        categoryCombo->clear();
        categoryCombo->insertItems(0, QStringList()
         << QApplication::translate("ModelView", "vector", 0)
         << QApplication::translate("ModelView", "transmission", 0)
        );
        label_7->setText(QApplication::translate("ModelView", "Type:", 0));
        typeCombo->clear();
        typeCombo->insertItems(0, QStringList()
         << QApplication::translate("ModelView", "Tipo1", 0)
         << QApplication::translate("ModelView", "Tipo2", 0)
        );
        label_8->setText(QApplication::translate("ModelView", "Title:", 0));
        label_9->setText(QApplication::translate("ModelView", "Authors:", 0));
        add->setText(QApplication::translate("ModelView", "...", 0));
        del->setText(QApplication::translate("ModelView", "...", 0));
        label_10->setText(QApplication::translate("ModelView", "Description:", 0));
        label_2->setText(QApplication::translate("ModelView", "Model files", 0));
        modelInfo->setText(QApplication::translate("ModelView", "Type", 0));
        modelType->setText(QApplication::translate("ModelView", "Category", 0));
        buttonAdd->setText(QApplication::translate("ModelView", "Add files", 0));
        label->setText(QApplication::translate("ModelView", "Main file:", 0));
        interpreter->clear();
        interpreter->insertItems(0, QStringList()
         << QApplication::translate("ModelView", "TerraME", 0)
         << QApplication::translate("ModelView", "Rscript", 0)
        );
        label_11->setText(QApplication::translate("ModelView", "Version:", 0));
        label_3->setText(QApplication::translate("ModelView", "Interpreter:", 0));
    } // retranslateUi

};

namespace Ui {
    class ModelView: public Ui_ModelView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELVIEW_H
