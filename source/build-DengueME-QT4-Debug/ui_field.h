/********************************************************************************
** Form generated from reading UI file 'field.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIELD_H
#define UI_FIELD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>

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
    QToolButton *options;

    void setupUi(QWidget *Field)
    {
        if (Field->objectName().isEmpty())
            Field->setObjectName(QString::fromUtf8("Field"));
        Field->resize(399, 41);
        horizontalLayout = new QHBoxLayout(Field);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        var = new QLineEdit(Field);
        var->setObjectName(QString::fromUtf8("var"));
        var->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        var->setFrame(false);

        horizontalLayout->addWidget(var);

        line = new QFrame(Field);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLineEdit(Field);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        label->setFrame(false);

        horizontalLayout->addWidget(label);

        line_2 = new QFrame(Field);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        descript = new QLineEdit(Field);
        descript->setObjectName(QString::fromUtf8("descript"));
        descript->setStyleSheet(QString::fromUtf8("QLineEdit { background-color:transparent; }"));
        descript->setFrame(false);

        horizontalLayout->addWidget(descript);

        container = new QWidget(Field);
        container->setObjectName(QString::fromUtf8("container"));
        horizontalLayout_2 = new QHBoxLayout(container);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);

        horizontalLayout->addWidget(container);

        options = new QToolButton(Field);
        options->setObjectName(QString::fromUtf8("options"));
        options->setPopupMode(QToolButton::InstantPopup);
        options->setToolButtonStyle(Qt::ToolButtonTextOnly);
        options->setAutoRaise(true);
        options->setArrowType(Qt::DownArrow);

        horizontalLayout->addWidget(options);

        horizontalLayout->setStretch(0, 2);

        retranslateUi(Field);

        QMetaObject::connectSlotsByName(Field);
    } // setupUi

    void retranslateUi(QWidget *Field)
    {
        Field->setWindowTitle(QApplication::translate("Field", "Form", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        var->setToolTip(QApplication::translate("Field", "Variable name", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        var->setPlaceholderText(QApplication::translate("Field", "Variable...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("Field", "Label", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setPlaceholderText(QApplication::translate("Field", "Label...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        descript->setToolTip(QApplication::translate("Field", "description", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        descript->setPlaceholderText(QApplication::translate("Field", "Description...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        container->setToolTip(QApplication::translate("Field", "Default value", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class Field: public Ui_Field {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIELD_H
