/********************************************************************************
** Form generated from reading UI file 'chartfield.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHARTFIELD_H
#define UI_CHARTFIELD_H

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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChartField
{
public:
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkUse;
    QFrame *line1;
    QVBoxLayout *verticalLayout;
    QLabel *labelSelect;
    QLineEdit *selectId;
    QFrame *line2;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelUserLabel;
    QLineEdit *userLabel;
    QFrame *line3;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelChartLabel;
    QLineEdit *chartLabel;
    QFrame *line4;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelStyle;
    QComboBox *style;
    QFrame *line5;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelColor;
    QComboBox *color;
    QFrame *line6;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolClone;
    QToolButton *toolDelete;

    void setupUi(QWidget *ChartField)
    {
        if (ChartField->objectName().isEmpty())
            ChartField->setObjectName(QStringLiteral("ChartField"));
        ChartField->resize(953, 97);
        horizontalLayout = new QHBoxLayout(ChartField);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkUse = new QCheckBox(ChartField);
        checkUse->setObjectName(QStringLiteral("checkUse"));
        checkUse->setEnabled(true);

        horizontalLayout->addWidget(checkUse);

        line1 = new QFrame(ChartField);
        line1->setObjectName(QStringLiteral("line1"));
        line1->setFrameShape(QFrame::VLine);
        line1->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        labelSelect = new QLabel(ChartField);
        labelSelect->setObjectName(QStringLiteral("labelSelect"));

        verticalLayout->addWidget(labelSelect);

        selectId = new QLineEdit(ChartField);
        selectId->setObjectName(QStringLiteral("selectId"));
        selectId->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        selectId->setFrame(false);

        verticalLayout->addWidget(selectId);


        horizontalLayout->addLayout(verticalLayout);

        line2 = new QFrame(ChartField);
        line2->setObjectName(QStringLiteral("line2"));
        line2->setFrameShape(QFrame::VLine);
        line2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(6, 6, 6, 6);
        labelUserLabel = new QLabel(ChartField);
        labelUserLabel->setObjectName(QStringLiteral("labelUserLabel"));
        labelUserLabel->setEnabled(true);

        verticalLayout_5->addWidget(labelUserLabel);

        userLabel = new QLineEdit(ChartField);
        userLabel->setObjectName(QStringLiteral("userLabel"));
        userLabel->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        userLabel->setFrame(false);

        verticalLayout_5->addWidget(userLabel);


        horizontalLayout->addLayout(verticalLayout_5);

        line3 = new QFrame(ChartField);
        line3->setObjectName(QStringLiteral("line3"));
        line3->setFrameShape(QFrame::VLine);
        line3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        labelChartLabel = new QLabel(ChartField);
        labelChartLabel->setObjectName(QStringLiteral("labelChartLabel"));

        verticalLayout_2->addWidget(labelChartLabel);

        chartLabel = new QLineEdit(ChartField);
        chartLabel->setObjectName(QStringLiteral("chartLabel"));
        chartLabel->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        chartLabel->setFrame(true);

        verticalLayout_2->addWidget(chartLabel);


        horizontalLayout->addLayout(verticalLayout_2);

        line4 = new QFrame(ChartField);
        line4->setObjectName(QStringLiteral("line4"));
        line4->setFrameShape(QFrame::VLine);
        line4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        labelStyle = new QLabel(ChartField);
        labelStyle->setObjectName(QStringLiteral("labelStyle"));

        verticalLayout_3->addWidget(labelStyle);

        style = new QComboBox(ChartField);
        style->setObjectName(QStringLiteral("style"));

        verticalLayout_3->addWidget(style);


        horizontalLayout->addLayout(verticalLayout_3);

        line5 = new QFrame(ChartField);
        line5->setObjectName(QStringLiteral("line5"));
        line5->setFrameShape(QFrame::VLine);
        line5->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        labelColor = new QLabel(ChartField);
        labelColor->setObjectName(QStringLiteral("labelColor"));

        verticalLayout_4->addWidget(labelColor);

        color = new QComboBox(ChartField);
        color->setObjectName(QStringLiteral("color"));

        verticalLayout_4->addWidget(color);


        horizontalLayout->addLayout(verticalLayout_4);

        line6 = new QFrame(ChartField);
        line6->setObjectName(QStringLiteral("line6"));
        line6->setFrameShape(QFrame::VLine);
        line6->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line6);

        container = new QWidget(ChartField);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(container);

        toolClone = new QToolButton(ChartField);
        toolClone->setObjectName(QStringLiteral("toolClone"));
        toolClone->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Resources/clone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolClone->setIcon(icon);
        toolClone->setIconSize(QSize(24, 24));
        toolClone->setPopupMode(QToolButton::InstantPopup);
        toolClone->setAutoRaise(true);

        horizontalLayout->addWidget(toolClone);

        toolDelete = new QToolButton(ChartField);
        toolDelete->setObjectName(QStringLiteral("toolDelete"));
        toolDelete->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/Resources/Trash-52 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolDelete->setIcon(icon1);
        toolDelete->setIconSize(QSize(24, 24));
        toolDelete->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolDelete->setAutoRaise(true);

        horizontalLayout->addWidget(toolDelete);

        QWidget::setTabOrder(checkUse, toolClone);
        QWidget::setTabOrder(toolClone, toolDelete);

        retranslateUi(ChartField);

        QMetaObject::connectSlotsByName(ChartField);
    } // setupUi

    void retranslateUi(QWidget *ChartField)
    {
        ChartField->setWindowTitle(QApplication::translate("ChartField", "Form", 0));
        checkUse->setText(QApplication::translate("ChartField", "Plot this variable", 0));
        labelSelect->setText(QApplication::translate("ChartField", "Select(ID):", 0));
#ifndef QT_NO_TOOLTIP
        selectId->setToolTip(QApplication::translate("ChartField", "select", 0));
#endif // QT_NO_TOOLTIP
        selectId->setText(QString());
        selectId->setPlaceholderText(QApplication::translate("ChartField", "Select...", 0));
        labelUserLabel->setText(QApplication::translate("ChartField", "User Label:", 0));
#ifndef QT_NO_TOOLTIP
        userLabel->setToolTip(QApplication::translate("ChartField", "id", 0));
#endif // QT_NO_TOOLTIP
        userLabel->setText(QString());
        userLabel->setPlaceholderText(QApplication::translate("ChartField", "User label...", 0));
        labelChartLabel->setText(QApplication::translate("ChartField", "Chart Variable Label:", 0));
#ifndef QT_NO_TOOLTIP
        chartLabel->setToolTip(QApplication::translate("ChartField", "label", 0));
#endif // QT_NO_TOOLTIP
        chartLabel->setText(QString());
        chartLabel->setPlaceholderText(QApplication::translate("ChartField", "Label...", 0));
        labelStyle->setText(QApplication::translate("ChartField", "Style:", 0));
        style->clear();
        style->insertItems(0, QStringList()
         << QApplication::translate("ChartField", "none", 0)
         << QApplication::translate("ChartField", "lines", 0)
         << QApplication::translate("ChartField", "dots", 0)
         << QApplication::translate("ChartField", "steps", 0)
         << QApplication::translate("ChartField", "sticks", 0)
        );
        labelColor->setText(QApplication::translate("ChartField", "Color:", 0));
        color->clear();
        color->insertItems(0, QStringList()
         << QApplication::translate("ChartField", "blue", 0)
         << QApplication::translate("ChartField", "darkBlue", 0)
         << QApplication::translate("ChartField", "cyan", 0)
         << QApplication::translate("ChartField", "lightCyan", 0)
         << QApplication::translate("ChartField", "darkCyan", 0)
         << QApplication::translate("ChartField", "magenta", 0)
         << QApplication::translate("ChartField", "lightMagenta", 0)
         << QApplication::translate("ChartField", "darkMagenta", 0)
         << QApplication::translate("ChartField", "purple", 0)
         << QApplication::translate("ChartField", "lightPurple", 0)
         << QApplication::translate("ChartField", "darkPurple", 0)
         << QApplication::translate("ChartField", "green", 0)
         << QApplication::translate("ChartField", "lightGreen", 0)
         << QApplication::translate("ChartField", "darkGreen", 0)
         << QApplication::translate("ChartField", "yellow", 0)
         << QApplication::translate("ChartField", "red", 0)
         << QApplication::translate("ChartField", "lightRed", 0)
         << QApplication::translate("ChartField", "darkRed", 0)
         << QApplication::translate("ChartField", "black", 0)
         << QApplication::translate("ChartField", "orange", 0)
         << QApplication::translate("ChartField", "lightOrange", 0)
         << QApplication::translate("ChartField", "darkOrange", 0)
         << QApplication::translate("ChartField", "brown", 0)
         << QApplication::translate("ChartField", "lightBrown", 0)
         << QApplication::translate("ChartField", "darkBrown", 0)
         << QApplication::translate("ChartField", "gray", 0)
         << QApplication::translate("ChartField", "lightGray", 0)
         << QApplication::translate("ChartField", "darkGray", 0)
        );
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("ChartField", "Default value", 0));
#endif // QT_NO_TOOLTIP
        toolClone->setText(QApplication::translate("ChartField", "...", 0));
        toolClone->setShortcut(QApplication::translate("ChartField", "Ctrl++", 0));
        toolDelete->setText(QApplication::translate("ChartField", "...", 0));
        toolDelete->setShortcut(QApplication::translate("ChartField", "Ctrl+Del", 0));
    } // retranslateUi

};

namespace Ui {
    class ChartField: public Ui_ChartField {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHARTFIELD_H
