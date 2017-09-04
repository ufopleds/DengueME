/********************************************************************************
** Form generated from reading UI file 'field.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD_H
#define UI_FIELD_H

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

class Ui_Field
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

    void setupUi(QWidget *Field)
    {
        if (Field->objectName().isEmpty())
            Field->setObjectName(QStringLiteral("Field"));
        Field->resize(540, 52);
        horizontalLayout = new QHBoxLayout(Field);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        var = new QLineEdit(Field);
        var->setObjectName(QStringLiteral("var"));
        var->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        var->setFrame(false);

        horizontalLayout->addWidget(var);

        line = new QFrame(Field);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLineEdit(Field);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        line_2 = new QFrame(Field);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        descript = new QLineEdit(Field);
        descript->setObjectName(QStringLiteral("descript"));
        descript->setStyleSheet(QStringLiteral("QLineEdit { background-color:transparent; }"));
        descript->setFrame(false);

        horizontalLayout->addWidget(descript);

        container = new QWidget(Field);
        container->setObjectName(QStringLiteral("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(container);

        toolCalculator = new QToolButton(Field);
        toolCalculator->setObjectName(QStringLiteral("toolCalculator"));
        toolCalculator->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/calc_icon_gray.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolCalculator->setIcon(icon);
        toolCalculator->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(toolCalculator);

        options = new QToolButton(Field);
        options->setObjectName(QStringLiteral("options"));
        options->setPopupMode(QToolButton::InstantPopup);
        options->setToolButtonStyle(Qt::ToolButtonTextOnly);
        options->setAutoRaise(true);
        options->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(options);

        toolClone = new QToolButton(Field);
        toolClone->setObjectName(QStringLiteral("toolClone"));
        toolClone->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Resources/clone.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolClone->setIcon(icon1);
        toolClone->setIconSize(QSize(24, 24));
        toolClone->setPopupMode(QToolButton::InstantPopup);
        toolClone->setAutoRaise(true);

        horizontalLayout->addWidget(toolClone);

        toolOptions = new QToolButton(Field);
        toolOptions->setObjectName(QStringLiteral("toolOptions"));
        toolOptions->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Resources/configure.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolOptions->setIcon(icon2);
        toolOptions->setIconSize(QSize(24, 24));
        toolOptions->setPopupMode(QToolButton::InstantPopup);
        toolOptions->setAutoRaise(true);

        horizontalLayout->addWidget(toolOptions);

        toolDelete = new QToolButton(Field);
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

        retranslateUi(Field);

        QMetaObject::connectSlotsByName(Field);
    } // setupUi

    void retranslateUi(QWidget *Field)
    {
        Field->setWindowTitle(QApplication::translate("Field", "Form", 0));
#ifndef QT_NO_TOOLTIP
        var->setToolTip(QApplication::translate("Field", "Variable name", 0));
#endif // QT_NO_TOOLTIP
        var->setPlaceholderText(QApplication::translate("Field", "Variable...", 0));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Field", "Label", 0));
#endif // QT_NO_TOOLTIP
        label->setPlaceholderText(QApplication::translate("Field", "Label...", 0));
#ifndef QT_NO_TOOLTIP
        descript->setToolTip(QApplication::translate("Field", "description", 0));
#endif // QT_NO_TOOLTIP
        descript->setPlaceholderText(QApplication::translate("Field", "Description...", 0));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("Field", "Default value", 0));
#endif // QT_NO_TOOLTIP
        toolCalculator->setText(QApplication::translate("Field", "...", 0));
        options->setText(QApplication::translate("Field", "Type", 0));
        toolClone->setText(QApplication::translate("Field", "...", 0));
        toolClone->setShortcut(QApplication::translate("Field", "Ctrl++", 0));
        toolOptions->setText(QApplication::translate("Field", "...", 0));
        toolDelete->setText(QApplication::translate("Field", "...", 0));
        toolDelete->setShortcut(QApplication::translate("Field", "Ctrl+Del", 0));
    } // retranslateUi

};

namespace Ui {
    class Field: public Ui_Field {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD_H
