/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralWidget;
    QLabel *display;
    QToolButton *toolButtonMultiply;
    QToolButton *toolButtonEight;
    QToolButton *toolButtonNine;
    QToolButton *toolButtonSeven;
    QToolButton *toolButtonMinus;
    QToolButton *toolButtonFive;
    QToolButton *toolButtonFour;
    QToolButton *toolButtonSix;
    QToolButton *toolButtonTwo;
    QToolButton *toolButtonPlus;
    QToolButton *toolButtonOne;
    QToolButton *toolButtonThree;
    QToolButton *toolButtonOK;
    QToolButton *toolButtonZero;
    QToolButton *toolButtonErase;
    QToolButton *toolButtonDivide;
    QToolButton *toolButtonParenthesisBegin;
    QToolButton *toolButtonClear;
    QToolButton *toolButtonParenthesisEnd;
    QLabel *result;
    QToolButton *toolButtonPoint;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QStringLiteral("Calculator"));
        Calculator->setEnabled(true);
        Calculator->resize(282, 382);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Calculator->sizePolicy().hasHeightForWidth());
        Calculator->setSizePolicy(sizePolicy);
        Calculator->setMouseTracking(false);
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(false);
        display = new QLabel(centralWidget);
        display->setObjectName(QStringLiteral("display"));
        display->setGeometry(QRect(0, 0, 282, 61));
        sizePolicy.setHeightForWidth(display->sizePolicy().hasHeightForWidth());
        display->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(15);
        display->setFont(font);
        display->setStyleSheet(QLatin1String("QLabel {\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"border: 1px solid gray;\n"
"background-color : white;\n"
"}\n"
"\n"
"\n"
""));
        toolButtonMultiply = new QToolButton(centralWidget);
        toolButtonMultiply->setObjectName(QStringLiteral("toolButtonMultiply"));
        toolButtonMultiply->setGeometry(QRect(210, 140, 72, 62));
        toolButtonMultiply->setFont(font);
        toolButtonMultiply->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #CEE891;\n"
"color: black; \n"
"border: 1px solid gray;\n"
"}\n"
"\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1F5C4, stop: 1 #E1F5C4);\n"
"}"));
        toolButtonEight = new QToolButton(centralWidget);
        toolButtonEight->setObjectName(QStringLiteral("toolButtonEight"));
        toolButtonEight->setGeometry(QRect(70, 140, 72, 62));
        toolButtonEight->setFont(font);
        toolButtonEight->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonNine = new QToolButton(centralWidget);
        toolButtonNine->setObjectName(QStringLiteral("toolButtonNine"));
        toolButtonNine->setGeometry(QRect(140, 140, 72, 62));
        toolButtonNine->setFont(font);
        toolButtonNine->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonSeven = new QToolButton(centralWidget);
        toolButtonSeven->setObjectName(QStringLiteral("toolButtonSeven"));
        toolButtonSeven->setGeometry(QRect(0, 140, 72, 62));
        toolButtonSeven->setFont(font);
        toolButtonSeven->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonMinus = new QToolButton(centralWidget);
        toolButtonMinus->setObjectName(QStringLiteral("toolButtonMinus"));
        toolButtonMinus->setGeometry(QRect(210, 200, 72, 62));
        toolButtonMinus->setFont(font);
        toolButtonMinus->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #CEE891;\n"
"color: black; \n"
"border: 1px solid gray;\n"
"}\n"
"\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1F5C4, stop: 1 #E1F5C4);\n"
"}"));
        toolButtonFive = new QToolButton(centralWidget);
        toolButtonFive->setObjectName(QStringLiteral("toolButtonFive"));
        toolButtonFive->setGeometry(QRect(70, 200, 72, 62));
        toolButtonFive->setFont(font);
        toolButtonFive->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonFour = new QToolButton(centralWidget);
        toolButtonFour->setObjectName(QStringLiteral("toolButtonFour"));
        toolButtonFour->setGeometry(QRect(0, 200, 72, 62));
        toolButtonFour->setFont(font);
        toolButtonFour->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonSix = new QToolButton(centralWidget);
        toolButtonSix->setObjectName(QStringLiteral("toolButtonSix"));
        toolButtonSix->setGeometry(QRect(140, 200, 72, 62));
        toolButtonSix->setFont(font);
        toolButtonSix->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonTwo = new QToolButton(centralWidget);
        toolButtonTwo->setObjectName(QStringLiteral("toolButtonTwo"));
        toolButtonTwo->setGeometry(QRect(70, 260, 72, 62));
        toolButtonTwo->setFont(font);
        toolButtonTwo->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonPlus = new QToolButton(centralWidget);
        toolButtonPlus->setObjectName(QStringLiteral("toolButtonPlus"));
        toolButtonPlus->setGeometry(QRect(210, 260, 72, 62));
        toolButtonPlus->setFont(font);
        toolButtonPlus->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #CEE891;\n"
"color: black; \n"
"border: 1px solid gray;\n"
"}\n"
"\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1F5C4, stop: 1 #E1F5C4);\n"
"}"));
        toolButtonOne = new QToolButton(centralWidget);
        toolButtonOne->setObjectName(QStringLiteral("toolButtonOne"));
        toolButtonOne->setGeometry(QRect(0, 260, 72, 62));
        toolButtonOne->setFont(font);
        toolButtonOne->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonThree = new QToolButton(centralWidget);
        toolButtonThree->setObjectName(QStringLiteral("toolButtonThree"));
        toolButtonThree->setGeometry(QRect(140, 260, 72, 62));
        toolButtonThree->setFont(font);
        toolButtonThree->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonOK = new QToolButton(centralWidget);
        toolButtonOK->setObjectName(QStringLiteral("toolButtonOK"));
        toolButtonOK->setGeometry(QRect(210, 320, 72, 62));
        toolButtonOK->setFont(font);
        toolButtonOK->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #D1E751;\n"
"color: black; \n"
"border: 1px solid gray;\n"
"}\n"
"\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1F5C4, stop: 1 #E1F5C4);\n"
"}"));
        toolButtonZero = new QToolButton(centralWidget);
        toolButtonZero->setObjectName(QStringLiteral("toolButtonZero"));
        toolButtonZero->setGeometry(QRect(0, 320, 72, 62));
        toolButtonZero->setFont(font);
        toolButtonZero->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        toolButtonErase = new QToolButton(centralWidget);
        toolButtonErase->setObjectName(QStringLiteral("toolButtonErase"));
        toolButtonErase->setGeometry(QRect(140, 320, 72, 62));
        toolButtonErase->setFont(font);
        toolButtonErase->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #DCE3E2;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        toolButtonDivide = new QToolButton(centralWidget);
        toolButtonDivide->setObjectName(QStringLiteral("toolButtonDivide"));
        toolButtonDivide->setGeometry(QRect(210, 80, 72, 62));
        toolButtonDivide->setFont(font);
        toolButtonDivide->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #CEE891;\n"
"color: black; \n"
"border: 1px solid gray;\n"
"}\n"
"\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #E1F5C4, stop: 1 #E1F5C4);\n"
"}"));
        toolButtonParenthesisBegin = new QToolButton(centralWidget);
        toolButtonParenthesisBegin->setObjectName(QStringLiteral("toolButtonParenthesisBegin"));
        toolButtonParenthesisBegin->setGeometry(QRect(70, 80, 72, 62));
        toolButtonParenthesisBegin->setFont(font);
        toolButtonParenthesisBegin->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #DCE3E2;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        toolButtonClear = new QToolButton(centralWidget);
        toolButtonClear->setObjectName(QStringLiteral("toolButtonClear"));
        toolButtonClear->setGeometry(QRect(0, 80, 72, 62));
        toolButtonClear->setFont(font);
        toolButtonClear->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #DCE3E2;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        toolButtonParenthesisEnd = new QToolButton(centralWidget);
        toolButtonParenthesisEnd->setObjectName(QStringLiteral("toolButtonParenthesisEnd"));
        toolButtonParenthesisEnd->setGeometry(QRect(140, 80, 72, 62));
        toolButtonParenthesisEnd->setFont(font);
        toolButtonParenthesisEnd->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #DCE3E2;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}"));
        result = new QLabel(centralWidget);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(0, 60, 282, 21));
        result->setStyleSheet(QLatin1String("QLabel {\n"
"qproperty-alignment: 'AlignVCenter | AlignRight';\n"
"border: 1px solid gray;\n"
"background-color : #F8F8F8;\n"
"}\n"
"\n"
"\n"
""));
        toolButtonPoint = new QToolButton(centralWidget);
        toolButtonPoint->setObjectName(QStringLiteral("toolButtonPoint"));
        toolButtonPoint->setGeometry(QRect(71, 320, 72, 62));
        toolButtonPoint->setFont(font);
        toolButtonPoint->setStyleSheet(QLatin1String("QToolButton {\n"
"background-color: #E9E9E9;\n"
"color: black;\n"
"border: 1px solid gray;\n"
"}\n"
"QToolButton:pressed { background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #dadbde, stop: 1 #fcfcfc);\n"
"}"));
        Calculator->setCentralWidget(centralWidget);
        display->raise();
        toolButtonMultiply->raise();
        toolButtonEight->raise();
        toolButtonNine->raise();
        toolButtonSeven->raise();
        toolButtonMinus->raise();
        toolButtonFive->raise();
        toolButtonFour->raise();
        toolButtonSix->raise();
        toolButtonTwo->raise();
        toolButtonPlus->raise();
        toolButtonOne->raise();
        toolButtonThree->raise();
        toolButtonOK->raise();
        toolButtonZero->raise();
        toolButtonDivide->raise();
        toolButtonParenthesisBegin->raise();
        toolButtonClear->raise();
        toolButtonParenthesisEnd->raise();
        result->raise();
        toolButtonPoint->raise();
        toolButtonErase->raise();

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Equation specifier", 0));
        display->setText(QApplication::translate("Calculator", "0", 0));
        toolButtonMultiply->setText(QApplication::translate("Calculator", "*", 0));
        toolButtonEight->setText(QApplication::translate("Calculator", "8", 0));
        toolButtonNine->setText(QApplication::translate("Calculator", "9", 0));
        toolButtonSeven->setText(QApplication::translate("Calculator", "7", 0));
        toolButtonMinus->setText(QApplication::translate("Calculator", "-", 0));
        toolButtonFive->setText(QApplication::translate("Calculator", "5", 0));
        toolButtonFour->setText(QApplication::translate("Calculator", "4", 0));
        toolButtonSix->setText(QApplication::translate("Calculator", "6", 0));
        toolButtonTwo->setText(QApplication::translate("Calculator", "2", 0));
        toolButtonPlus->setText(QApplication::translate("Calculator", "+", 0));
        toolButtonOne->setText(QApplication::translate("Calculator", "1", 0));
        toolButtonThree->setText(QApplication::translate("Calculator", "3", 0));
        toolButtonOK->setText(QApplication::translate("Calculator", "OK", 0));
        toolButtonZero->setText(QApplication::translate("Calculator", "0", 0));
        toolButtonErase->setText(QApplication::translate("Calculator", "\342\206\220", 0));
        toolButtonDivide->setText(QApplication::translate("Calculator", "/", 0));
        toolButtonParenthesisBegin->setText(QApplication::translate("Calculator", "(", 0));
        toolButtonClear->setText(QApplication::translate("Calculator", "C", 0));
        toolButtonParenthesisEnd->setText(QApplication::translate("Calculator", ")", 0));
        result->setText(QString());
        toolButtonPoint->setText(QApplication::translate("Calculator", ".", 0));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
