/********************************************************************************
** Form generated from reading UI file 'equationspecifier.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUATIONSPECIFIER_H
#define UI_EQUATIONSPECIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquationSpecifier
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *var;
    QFrame *line;
    QLineEdit *label;
    QFrame *line_2;
    QLineEdit *descript;
    QWidget *container;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolCalculator;
    QToolButton *options;
    QToolButton *toolClone;
    QToolButton *toolOptions;
    QToolButton *toolDelete;

    void setupUi(QWidget *EquationSpecifier)
    {
        if (EquationSpecifier->objectName().isEmpty())
            EquationSpecifier->setObjectName(QStringLiteral("EquationSpecifier"));
        EquationSpecifier->resize(540, 58);
        horizontalLayout = new QHBoxLayout(EquationSpecifier);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        var = new QLineEdit(EquationSpecifier);
        var->setObjectName(QStringLiteral("var"));
        var->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        var->setFrame(false);

        horizontalLayout->addWidget(var);

        line = new QFrame(EquationSpecifier);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLineEdit(EquationSpecifier);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        line_2 = new QFrame(EquationSpecifier);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        descript = new QLineEdit(EquationSpecifier);
        descript->setObjectName(QStringLiteral("descript"));
        descript->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        descript->setFrame(false);

        horizontalLayout->addWidget(descript);

        container = new QWidget(EquationSpecifier);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(container);

        toolCalculator = new QToolButton(EquationSpecifier);
        toolCalculator->setObjectName(QStringLiteral("toolCalculator"));
        toolCalculator->setAutoFillBackground(false);
        toolCalculator->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/calculator-dengueme.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolCalculator->setIcon(icon);
        toolCalculator->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(toolCalculator);

        options = new QToolButton(EquationSpecifier);
        options->setObjectName(QStringLiteral("options"));
        options->setPopupMode(QToolButton::InstantPopup);
        options->setToolButtonStyle(Qt::ToolButtonTextOnly);
        options->setAutoRaise(true);
        options->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(options);

        toolClone = new QToolButton(EquationSpecifier);
        toolClone->setObjectName(QStringLiteral("toolClone"));
        toolClone->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/clone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolClone->setIcon(icon1);
        toolClone->setIconSize(QSize(24, 24));
        toolClone->setPopupMode(QToolButton::InstantPopup);
        toolClone->setAutoRaise(true);

        horizontalLayout->addWidget(toolClone);

        toolOptions = new QToolButton(EquationSpecifier);
        toolOptions->setObjectName(QStringLiteral("toolOptions"));
        toolOptions->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolOptions->setIcon(icon2);
        toolOptions->setIconSize(QSize(24, 24));
        toolOptions->setPopupMode(QToolButton::InstantPopup);
        toolOptions->setAutoRaise(true);

        horizontalLayout->addWidget(toolOptions);

        toolDelete = new QToolButton(EquationSpecifier);
        toolDelete->setObjectName(QStringLiteral("toolDelete"));
        toolDelete->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/Resources/Trash-52 (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        toolDelete->setIcon(icon3);
        toolDelete->setIconSize(QSize(24, 24));
        toolDelete->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolDelete->setAutoRaise(true);

        horizontalLayout->addWidget(toolDelete);

        horizontalLayout->setStretch(0, 2);

        retranslateUi(EquationSpecifier);

        QMetaObject::connectSlotsByName(EquationSpecifier);
    } // setupUi

    void retranslateUi(QWidget *EquationSpecifier)
    {
        EquationSpecifier->setWindowTitle(QApplication::translate("EquationSpecifier", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        var->setToolTip(QApplication::translate("EquationSpecifier", "Variable name", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        var->setPlaceholderText(QApplication::translate("EquationSpecifier", "Variable...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("EquationSpecifier", "Label", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setPlaceholderText(QApplication::translate("EquationSpecifier", "Label...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        descript->setToolTip(QApplication::translate("EquationSpecifier", "description", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        descript->setPlaceholderText(QApplication::translate("EquationSpecifier", "Description...", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("EquationSpecifier", "Default value", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolCalculator->setText(QApplication::translate("EquationSpecifier", "...", Q_NULLPTR));
        options->setText(QApplication::translate("EquationSpecifier", "Type", Q_NULLPTR));
        toolClone->setText(QApplication::translate("EquationSpecifier", "...", Q_NULLPTR));
        toolClone->setShortcut(QApplication::translate("EquationSpecifier", "Ctrl++", Q_NULLPTR));
        toolOptions->setText(QApplication::translate("EquationSpecifier", "...", Q_NULLPTR));
        toolDelete->setText(QApplication::translate("EquationSpecifier", "...", Q_NULLPTR));
        toolDelete->setShortcut(QApplication::translate("EquationSpecifier", "Ctrl+Del", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EquationSpecifier: public Ui_EquationSpecifier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUATIONSPECIFIER_H
