/********************************************************************************
** Form generated from reading UI file 'descriptionwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESCRIPTIONWINDOW_H
#define UI_DESCRIPTIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DescriptionWindow
{
public:
    QPushButton *pushButton;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *DescriptionWindow)
    {
        if (DescriptionWindow->objectName().isEmpty())
            DescriptionWindow->setObjectName(QStringLiteral("DescriptionWindow"));
        DescriptionWindow->resize(484, 364);
        DescriptionWindow->setMinimumSize(QSize(484, 364));
        DescriptionWindow->setMaximumSize(QSize(484, 364));
        QFont font;
        font.setPointSize(9);
        DescriptionWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        DescriptionWindow->setWindowIcon(icon);
        pushButton = new QPushButton(DescriptionWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 330, 75, 23));
        textBrowser = new QTextBrowser(DescriptionWindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 481, 321));

        retranslateUi(DescriptionWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), DescriptionWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(DescriptionWindow);
    } // setupUi

    void retranslateUi(QDialog *DescriptionWindow)
    {
        DescriptionWindow->setWindowTitle(QApplication::translate("DescriptionWindow", "Help", 0));
        pushButton->setText(QApplication::translate("DescriptionWindow", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class DescriptionWindow: public Ui_DescriptionWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESCRIPTIONWINDOW_H
