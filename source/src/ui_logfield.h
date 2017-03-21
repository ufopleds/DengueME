/********************************************************************************
** Form generated from reading UI file 'logfield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGFIELD_H
#define UI_LOGFIELD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogField
{
public:
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *vertical3;
    QLabel *labelFilename;
    QLineEdit *fileName;
    QVBoxLayout *vertical5;
    QLabel *labelSeparator;
    QComboBox *separator;
    QVBoxLayout *vertical4;
    QCheckBox *overwrite;
    QVBoxLayout *vertical1;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *upperLabel;
    QLabel *labelGeneral;
    QSpacerItem *horizontalSpacer;
    QLabel *labelToBeUse;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *selectDefault;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *selectUse;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QToolButton *add;
    QToolButton *del;
    QSpacerItem *verticalSpacer;
    QTableWidget *defaultVarList;
    QVBoxLayout *verticalLayout_4;
    QToolButton *rButton;
    QToolButton *lButton;
    QTableWidget *useVarList;
    QFrame *line1;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QWidget *LogField)
    {
        if (LogField->objectName().isEmpty())
            LogField->setObjectName(QStringLiteral("LogField"));
        LogField->resize(712, 399);
        horizontalLayout_7 = new QHBoxLayout(LogField);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        vertical3 = new QVBoxLayout();
        vertical3->setObjectName(QStringLiteral("vertical3"));
        vertical3->setContentsMargins(6, 6, 6, 6);
        labelFilename = new QLabel(LogField);
        labelFilename->setObjectName(QStringLiteral("labelFilename"));

        vertical3->addWidget(labelFilename);

        fileName = new QLineEdit(LogField);
        fileName->setObjectName(QStringLiteral("fileName"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fileName->sizePolicy().hasHeightForWidth());
        fileName->setSizePolicy(sizePolicy);
        fileName->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        fileName->setFrame(false);

        vertical3->addWidget(fileName);


        horizontalLayout_3->addLayout(vertical3);

        vertical5 = new QVBoxLayout();
        vertical5->setObjectName(QStringLiteral("vertical5"));
        vertical5->setContentsMargins(6, 6, 6, 6);
        labelSeparator = new QLabel(LogField);
        labelSeparator->setObjectName(QStringLiteral("labelSeparator"));

        vertical5->addWidget(labelSeparator);

        separator = new QComboBox(LogField);
        separator->setObjectName(QStringLiteral("separator"));

        vertical5->addWidget(separator);


        horizontalLayout_3->addLayout(vertical5);

        vertical4 = new QVBoxLayout();
        vertical4->setObjectName(QStringLiteral("vertical4"));
        vertical4->setContentsMargins(6, 6, 6, 6);
        overwrite = new QCheckBox(LogField);
        overwrite->setObjectName(QStringLiteral("overwrite"));

        vertical4->addWidget(overwrite);


        horizontalLayout_3->addLayout(vertical4);


        verticalLayout->addLayout(horizontalLayout_3);

        vertical1 = new QVBoxLayout();
        vertical1->setObjectName(QStringLiteral("vertical1"));
        vertical1->setContentsMargins(6, 6, 6, 6);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_2 = new QSpacerItem(25, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        upperLabel = new QLabel(LogField);
        upperLabel->setObjectName(QStringLiteral("upperLabel"));
        upperLabel->setMargin(2);

        verticalLayout_5->addWidget(upperLabel);

        labelGeneral = new QLabel(LogField);
        labelGeneral->setObjectName(QStringLiteral("labelGeneral"));

        verticalLayout_5->addWidget(labelGeneral);


        horizontalLayout_5->addLayout(verticalLayout_5);

        horizontalSpacer = new QSpacerItem(45, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        labelToBeUse = new QLabel(LogField);
        labelToBeUse->setObjectName(QStringLiteral("labelToBeUse"));

        horizontalLayout_5->addWidget(labelToBeUse);


        vertical1->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(27, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        selectDefault = new QCheckBox(LogField);
        selectDefault->setObjectName(QStringLiteral("selectDefault"));

        horizontalLayout_4->addWidget(selectDefault);

        horizontalSpacer_3 = new QSpacerItem(34, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        selectUse = new QCheckBox(LogField);
        selectUse->setObjectName(QStringLiteral("selectUse"));

        horizontalLayout_4->addWidget(selectUse);


        vertical1->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        add = new QToolButton(LogField);
        add->setObjectName(QStringLiteral("add"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/plus"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon);

        verticalLayout_2->addWidget(add);

        del = new QToolButton(LogField);
        del->setObjectName(QStringLiteral("del"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        del->setIcon(icon1);

        verticalLayout_2->addWidget(del);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        defaultVarList = new QTableWidget(LogField);
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

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        rButton = new QToolButton(LogField);
        rButton->setObjectName(QStringLiteral("rButton"));
        rButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/Resources/rightDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        rButton->setIcon(icon2);
        rButton->setIconSize(QSize(24, 24));

        verticalLayout_4->addWidget(rButton);

        lButton = new QToolButton(LogField);
        lButton->setObjectName(QStringLiteral("lButton"));
        lButton->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/leftDArrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        lButton->setIcon(icon3);
        lButton->setIconSize(QSize(24, 24));

        verticalLayout_4->addWidget(lButton);


        horizontalLayout->addLayout(verticalLayout_4);

        useVarList = new QTableWidget(LogField);
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


        vertical1->addLayout(horizontalLayout);


        verticalLayout->addLayout(vertical1);

        line1 = new QFrame(LogField);
        line1->setObjectName(QStringLiteral("line1"));
        line1->setFrameShape(QFrame::VLine);
        line1->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line1);


        horizontalLayout_7->addLayout(verticalLayout);

        container = new QWidget(LogField);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_7->addWidget(container);


        retranslateUi(LogField);

        separator->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LogField);
    } // setupUi

    void retranslateUi(QWidget *LogField)
    {
        LogField->setWindowTitle(QApplication::translate("LogField", "Form", 0));
        labelFilename->setText(QApplication::translate("LogField", "File name:", 0));
#ifndef QT_NO_TOOLTIP
        fileName->setToolTip(QApplication::translate("LogField", "label", 0));
#endif // QT_NO_TOOLTIP
        fileName->setText(QString());
        fileName->setPlaceholderText(QApplication::translate("LogField", "File name...", 0));
        labelSeparator->setText(QApplication::translate("LogField", "Separator", 0));
        separator->clear();
        separator->insertItems(0, QStringList()
         << QApplication::translate("LogField", ",", 0)
         << QApplication::translate("LogField", ".", 0)
         << QApplication::translate("LogField", "|", 0)
         << QApplication::translate("LogField", ";", 0)
        );
        overwrite->setText(QApplication::translate("LogField", "Overwrite?", 0));
        upperLabel->setText(QApplication::translate("LogField", "Add variables that the user may use for this observer", 0));
        labelGeneral->setText(QApplication::translate("LogField", "Default variables:", 0));
        labelToBeUse->setText(QApplication::translate("LogField", "Variables to be used:", 0));
        selectDefault->setText(QApplication::translate("LogField", "Select all", 0));
        selectUse->setText(QApplication::translate("LogField", "Select all", 0));
        add->setText(QApplication::translate("LogField", "+", 0));
        del->setText(QApplication::translate("LogField", "-", 0));
        QTableWidgetItem *___qtablewidgetitem = defaultVarList->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LogField", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = defaultVarList->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LogField", "Label", 0));
        rButton->setText(QApplication::translate("LogField", "...", 0));
        lButton->setText(QApplication::translate("LogField", "...", 0));
        QTableWidgetItem *___qtablewidgetitem2 = useVarList->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("LogField", "ID", 0));
        QTableWidgetItem *___qtablewidgetitem3 = useVarList->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("LogField", "Label", 0));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("LogField", "Default value", 0));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class LogField: public Ui_LogField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFIELD_H
