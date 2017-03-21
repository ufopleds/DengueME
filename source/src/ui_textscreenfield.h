/********************************************************************************
** Form generated from reading UI file 'textscreenfield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTSCREENFIELD_H
#define UI_TEXTSCREENFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TextScreenField
{
public:
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *upperLabel;
    QLabel *labelGeneral;
    QSpacerItem *horizontalSpacer;
    QLabel *labelToBeUse;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *selectDefault;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *selectUse;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_4;
    QToolButton *add;
    QToolButton *del;
    QSpacerItem *verticalSpacer;
    QTableWidget *defaultVarList;
    QVBoxLayout *verticalLayout_3;
    QToolButton *rButton;
    QToolButton *lButton;
    QTableWidget *useVarList;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *TextScreenField)
    {
        if (TextScreenField->objectName().isEmpty())
            TextScreenField->setObjectName(QStringLiteral("TextScreenField"));
        TextScreenField->resize(748, 347);
        horizontalLayout_6 = new QHBoxLayout(TextScreenField);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        line = new QFrame(TextScreenField);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);


        verticalLayout_6->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        upperLabel = new QLabel(TextScreenField);
        upperLabel->setObjectName(QStringLiteral("upperLabel"));

        verticalLayout->addWidget(upperLabel);

        labelGeneral = new QLabel(TextScreenField);
        labelGeneral->setObjectName(QStringLiteral("labelGeneral"));
        labelGeneral->setMargin(3);

        verticalLayout->addWidget(labelGeneral);


        horizontalLayout_4->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(65, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        labelToBeUse = new QLabel(TextScreenField);
        labelToBeUse->setObjectName(QStringLiteral("labelToBeUse"));

        horizontalLayout_4->addWidget(labelToBeUse);


        verticalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        selectDefault = new QCheckBox(TextScreenField);
        selectDefault->setObjectName(QStringLiteral("selectDefault"));

        horizontalLayout_5->addWidget(selectDefault);

        horizontalSpacer_4 = new QSpacerItem(35, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        selectUse = new QCheckBox(TextScreenField);
        selectUse->setObjectName(QStringLiteral("selectUse"));

        horizontalLayout_5->addWidget(selectUse);


        verticalLayout_6->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        add = new QToolButton(TextScreenField);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout_4->addWidget(add);

        del = new QToolButton(TextScreenField);
        del->setObjectName(QStringLiteral("del"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout_4->addWidget(del);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_4);

        defaultVarList = new QTableWidget(TextScreenField);
        if (defaultVarList->columnCount() < 2)
            defaultVarList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        defaultVarList->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        defaultVarList->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        defaultVarList->setObjectName(QStringLiteral("defaultVarList"));
        defaultVarList->setSelectionMode(QAbstractItemView::MultiSelection);
        defaultVarList->setSelectionBehavior(QAbstractItemView::SelectRows);
        defaultVarList->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(defaultVarList);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        rButton = new QToolButton(TextScreenField);
        rButton->setObjectName(QStringLiteral("rButton"));
        rButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/rightDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        rButton->setIcon(icon2);
        rButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(rButton);

        lButton = new QToolButton(TextScreenField);
        lButton->setObjectName(QStringLiteral("lButton"));
        lButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/leftDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        lButton->setIcon(icon3);
        lButton->setIconSize(QSize(24, 24));

        verticalLayout_3->addWidget(lButton);


        horizontalLayout->addLayout(verticalLayout_3);

        useVarList = new QTableWidget(TextScreenField);
        if (useVarList->columnCount() < 2)
            useVarList->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        useVarList->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        useVarList->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        useVarList->setObjectName(QStringLiteral("useVarList"));
        useVarList->setSelectionMode(QAbstractItemView::MultiSelection);
        useVarList->setSelectionBehavior(QAbstractItemView::SelectRows);
        useVarList->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout->addWidget(useVarList);


        verticalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_6->addLayout(verticalLayout_6);

        container = new QWidget(TextScreenField);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_6->addWidget(container);


        retranslateUi(TextScreenField);

        QMetaObject::connectSlotsByName(TextScreenField);
    } // setupUi

    void retranslateUi(QWidget *TextScreenField)
    {
        TextScreenField->setWindowTitle(QApplication::translate("TextScreenField", "Form", 0));
        upperLabel->setText(QApplication::translate("TextScreenField", "Add variables that the user may use for this observer", 0));
        labelGeneral->setText(QApplication::translate("TextScreenField", "Default variables", 0));
        labelToBeUse->setText(QApplication::translate("TextScreenField", "Variables to be used:", 0));
        selectDefault->setText(QApplication::translate("TextScreenField", "Select All", 0));
        selectUse->setText(QApplication::translate("TextScreenField", "Select All", 0));
        add->setText(QApplication::translate("TextScreenField", "+", 0));
        del->setText(QApplication::translate("TextScreenField", "-", 0));
        QTableWidgetItem *___qtablewidgetitem = defaultVarList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TextScreenField", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = defaultVarList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TextScreenField", "Label", 0));
        rButton->setText(QApplication::translate("TextScreenField", "...", 0));
        lButton->setText(QApplication::translate("TextScreenField", "...", 0));
        QTableWidgetItem *___qtablewidgetitem2 = useVarList->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("TextScreenField", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem3 = useVarList->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("TextScreenField", "Label", 0));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("TextScreenField", "Default value", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class TextScreenField: public Ui_TextScreenField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTSCREENFIELD_H
