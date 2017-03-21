/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QLabel *textLabel;
    QLabel *versionLabel;
    QLabel *siteLabel;
    QLabel *licenseLabel;
    QLabel *sourceLabel;
    QLabel *authorLabel;
    QLabel *iconsLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QStringLiteral("About"));
        About->resize(420, 353);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(About->sizePolicy().hasHeightForWidth());
        About->setSizePolicy(sizePolicy);
        About->setMinimumSize(QSize(420, 353));
        About->setMaximumSize(QSize(420, 353));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        About->setWindowIcon(icon);
        About->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(About);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(About);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(380, 100));
        frame->setStyleSheet(QStringLiteral("image: url(:/img/Resources/dengueme.png);"));
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(frame);

        textLabel = new QLabel(About);
        textLabel->setObjectName(QStringLiteral("textLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textLabel->sizePolicy().hasHeightForWidth());
        textLabel->setSizePolicy(sizePolicy1);
        textLabel->setTextFormat(Qt::AutoText);
        textLabel->setScaledContents(false);
        textLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        textLabel->setWordWrap(true);
        textLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        verticalLayout->addWidget(textLabel);

        versionLabel = new QLabel(About);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));

        verticalLayout->addWidget(versionLabel);

        siteLabel = new QLabel(About);
        siteLabel->setObjectName(QStringLiteral("siteLabel"));
        siteLabel->setOpenExternalLinks(true);
        siteLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(siteLabel);

        licenseLabel = new QLabel(About);
        licenseLabel->setObjectName(QStringLiteral("licenseLabel"));

        verticalLayout->addWidget(licenseLabel);

        sourceLabel = new QLabel(About);
        sourceLabel->setObjectName(QStringLiteral("sourceLabel"));
        sourceLabel->setOpenExternalLinks(true);
        sourceLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(sourceLabel);

        authorLabel = new QLabel(About);
        authorLabel->setObjectName(QStringLiteral("authorLabel"));
        authorLabel->setOpenExternalLinks(true);
        authorLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(authorLabel);

        iconsLabel = new QLabel(About);
        iconsLabel->setObjectName(QStringLiteral("iconsLabel"));
        iconsLabel->setOpenExternalLinks(true);
        iconsLabel->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByMouse);

        verticalLayout->addWidget(iconsLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        closeButton = new QPushButton(About);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(About);
        QObject::connect(closeButton, SIGNAL(clicked()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About", 0));
        textLabel->setText(QApplication::translate("About", "<b> DengueME</b> is a software framework designed to support modeling and simulation of the spatiotemporal dynamics of dengue transmission and vector ecology.", 0));
        versionLabel->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Version</span>: 0.65. <span style=\" font-weight:600;\">Date: </span>9/27/2016</p></body></html>", 0));
        siteLabel->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Site :</span><a href=\"http://www.leds.ufop.br/\"><span style=\" text-decoration: underline; color:#0000ff;\">http://www.leds.ufop.br/dengueme </span></a></p></body></html>", 0));
        licenseLabel->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">License</span>: BSD - 2 Clause</p></body></html>", 0));
        sourceLabel->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Source Code:</span><a href=\"https://github.com/ufopleds/dengueme\"><span style=\" text-decoration: underline; color:#0000ff;\">https://github.com/ufopleds/dengueme </span></a></p></body></html>", 0));
        authorLabel->setText(QApplication::translate("About", "<html><head/><body><p><span style=\" font-weight:600;\">Author: LEDS/UFOP  </span><a href=\"http://www.leds.ufop.br/\"><span style=\" text-decoration: underline; color:#0000ff;\">http://www.leds.ufop.br/</span></a></p></body></html>", 0));
        iconsLabel->setText(QApplication::translate("About", "<b>Icons:</b> <a href=\" https://icons8.com/web-app/\">https://icons8.com</a>", 0));
        closeButton->setText(QApplication::translate("About", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
