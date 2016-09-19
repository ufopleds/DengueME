/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QRadioButton *radioButton_mysql;
    QRadioButton *radioButton_access;
    QRadioButton *radioButton_virtual;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_mysql;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_6;
    QLabel *label_32;
    QLineEdit *lineEdit_password;
    QLabel *label_28;
    QLineEdit *lineEdit_user;
    QLabel *label_23;
    QLineEdit *lineEdit_layer;
    QLineEdit *lineEdit_theme;
    QLabel *label_30;
    QLineEdit *lineEdit_select;
    QLineEdit *lineEdit_host;
    QLineEdit *lineEdit_db;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_29;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_access;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_22;
    QLineEdit *lineEdit_access;
    QPushButton *pushButton_access;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_33;
    QLineEdit *lineEdit_layerAccess;
    QLabel *label_31;
    QLineEdit *lineEdit_themeAccess;
    QLabel *label_34;
    QLineEdit *lineEdit_selectAccess;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget_virtual;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_xdim;
    QLabel *label_2;
    QSpinBox *spinBox_ydim;
    QSpacerItem *horizontalSpacer_2;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName(QStringLiteral("Database"));
        Database->resize(653, 294);
        verticalLayout_2 = new QVBoxLayout(Database);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(Database);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        radioButton_mysql = new QRadioButton(Database);
        buttonGroup = new QButtonGroup(Database);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_mysql);
        radioButton_mysql->setObjectName(QStringLiteral("radioButton_mysql"));
        radioButton_mysql->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_mysql);

        radioButton_access = new QRadioButton(Database);
        buttonGroup->addButton(radioButton_access);
        radioButton_access->setObjectName(QStringLiteral("radioButton_access"));
        radioButton_access->setEnabled(true);

        horizontalLayout_2->addWidget(radioButton_access);

        radioButton_virtual = new QRadioButton(Database);
        buttonGroup->addButton(radioButton_virtual);
        radioButton_virtual->setObjectName(QStringLiteral("radioButton_virtual"));

        horizontalLayout_2->addWidget(radioButton_virtual);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout_2->addLayout(horizontalLayout_2);

        widget_mysql = new QWidget(Database);
        widget_mysql->setObjectName(QStringLiteral("widget_mysql"));
        verticalLayout_4 = new QVBoxLayout(widget_mysql);
#ifndef Q_OS_MAC
        verticalLayout_4->setSpacing(6);
#endif
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        label_32 = new QLabel(widget_mysql);
        label_32->setObjectName(QStringLiteral("label_32"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_32->sizePolicy().hasHeightForWidth());
        label_32->setSizePolicy(sizePolicy);
        label_32->setMargin(0);
        label_32->setIndent(4);

        gridLayout_6->addWidget(label_32, 2, 2, 1, 2);

        lineEdit_password = new QLineEdit(widget_mysql);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_password->sizePolicy().hasHeightForWidth());
        lineEdit_password->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_password, 2, 4, 1, 1);

        label_28 = new QLabel(widget_mysql);
        label_28->setObjectName(QStringLiteral("label_28"));
        sizePolicy.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_28, 3, 0, 1, 1);

        lineEdit_user = new QLineEdit(widget_mysql);
        lineEdit_user->setObjectName(QStringLiteral("lineEdit_user"));
        sizePolicy1.setHeightForWidth(lineEdit_user->sizePolicy().hasHeightForWidth());
        lineEdit_user->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_user, 2, 1, 1, 1);

        label_23 = new QLabel(widget_mysql);
        label_23->setObjectName(QStringLiteral("label_23"));
        sizePolicy.setHeightForWidth(label_23->sizePolicy().hasHeightForWidth());
        label_23->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_23, 2, 0, 1, 1);

        lineEdit_layer = new QLineEdit(widget_mysql);
        lineEdit_layer->setObjectName(QStringLiteral("lineEdit_layer"));
        sizePolicy1.setHeightForWidth(lineEdit_layer->sizePolicy().hasHeightForWidth());
        lineEdit_layer->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_layer, 3, 1, 1, 1);

        lineEdit_theme = new QLineEdit(widget_mysql);
        lineEdit_theme->setObjectName(QStringLiteral("lineEdit_theme"));
        sizePolicy1.setHeightForWidth(lineEdit_theme->sizePolicy().hasHeightForWidth());
        lineEdit_theme->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_theme, 3, 4, 1, 1);

        label_30 = new QLabel(widget_mysql);
        label_30->setObjectName(QStringLiteral("label_30"));
        sizePolicy.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_30, 3, 5, 1, 1);

        lineEdit_select = new QLineEdit(widget_mysql);
        lineEdit_select->setObjectName(QStringLiteral("lineEdit_select"));
        sizePolicy1.setHeightForWidth(lineEdit_select->sizePolicy().hasHeightForWidth());
        lineEdit_select->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_select, 3, 6, 1, 1);

        lineEdit_host = new QLineEdit(widget_mysql);
        lineEdit_host->setObjectName(QStringLiteral("lineEdit_host"));
        sizePolicy1.setHeightForWidth(lineEdit_host->sizePolicy().hasHeightForWidth());
        lineEdit_host->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_host, 1, 1, 1, 1);

        lineEdit_db = new QLineEdit(widget_mysql);
        lineEdit_db->setObjectName(QStringLiteral("lineEdit_db"));
        sizePolicy1.setHeightForWidth(lineEdit_db->sizePolicy().hasHeightForWidth());
        lineEdit_db->setSizePolicy(sizePolicy1);

        gridLayout_6->addWidget(lineEdit_db, 1, 4, 1, 1);

        label_26 = new QLabel(widget_mysql);
        label_26->setObjectName(QStringLiteral("label_26"));
        sizePolicy.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(label_26, 1, 0, 1, 1);

        label_27 = new QLabel(widget_mysql);
        label_27->setObjectName(QStringLiteral("label_27"));
        sizePolicy.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy);
        label_27->setMargin(0);
        label_27->setIndent(4);

        gridLayout_6->addWidget(label_27, 1, 2, 1, 2);

        label_29 = new QLabel(widget_mysql);
        label_29->setObjectName(QStringLiteral("label_29"));
        sizePolicy.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy);
        label_29->setMargin(0);
        label_29->setIndent(4);

        gridLayout_6->addWidget(label_29, 3, 2, 1, 2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 3, 7, 1, 1);


        verticalLayout_4->addLayout(gridLayout_6);


        verticalLayout_2->addWidget(widget_mysql);

        widget_access = new QWidget(Database);
        widget_access->setObjectName(QStringLiteral("widget_access"));
        verticalLayout = new QVBoxLayout(widget_access);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_22 = new QLabel(widget_access);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_4->addWidget(label_22);

        lineEdit_access = new QLineEdit(widget_access);
        lineEdit_access->setObjectName(QStringLiteral("lineEdit_access"));
        lineEdit_access->setEnabled(true);

        horizontalLayout_4->addWidget(lineEdit_access);

        pushButton_access = new QPushButton(widget_access);
        pushButton_access->setObjectName(QStringLiteral("pushButton_access"));
        pushButton_access->setEnabled(true);

        horizontalLayout_4->addWidget(pushButton_access);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_33 = new QLabel(widget_access);
        label_33->setObjectName(QStringLiteral("label_33"));
        sizePolicy.setHeightForWidth(label_33->sizePolicy().hasHeightForWidth());
        label_33->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_33);

        lineEdit_layerAccess = new QLineEdit(widget_access);
        lineEdit_layerAccess->setObjectName(QStringLiteral("lineEdit_layerAccess"));
        sizePolicy1.setHeightForWidth(lineEdit_layerAccess->sizePolicy().hasHeightForWidth());
        lineEdit_layerAccess->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_layerAccess);

        label_31 = new QLabel(widget_access);
        label_31->setObjectName(QStringLiteral("label_31"));
        sizePolicy.setHeightForWidth(label_31->sizePolicy().hasHeightForWidth());
        label_31->setSizePolicy(sizePolicy);
        label_31->setMargin(0);
        label_31->setIndent(4);

        horizontalLayout_3->addWidget(label_31);

        lineEdit_themeAccess = new QLineEdit(widget_access);
        lineEdit_themeAccess->setObjectName(QStringLiteral("lineEdit_themeAccess"));
        sizePolicy1.setHeightForWidth(lineEdit_themeAccess->sizePolicy().hasHeightForWidth());
        lineEdit_themeAccess->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_themeAccess);

        label_34 = new QLabel(widget_access);
        label_34->setObjectName(QStringLiteral("label_34"));
        sizePolicy.setHeightForWidth(label_34->sizePolicy().hasHeightForWidth());
        label_34->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_34);

        lineEdit_selectAccess = new QLineEdit(widget_access);
        lineEdit_selectAccess->setObjectName(QStringLiteral("lineEdit_selectAccess"));
        sizePolicy1.setHeightForWidth(lineEdit_selectAccess->sizePolicy().hasHeightForWidth());
        lineEdit_selectAccess->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit_selectAccess);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(widget_access);

        widget_virtual = new QWidget(Database);
        widget_virtual->setObjectName(QStringLiteral("widget_virtual"));
        verticalLayout_3 = new QVBoxLayout(widget_virtual);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget_virtual);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox_xdim = new QSpinBox(widget_virtual);
        spinBox_xdim->setObjectName(QStringLiteral("spinBox_xdim"));
        spinBox_xdim->setMaximum(999999999);

        horizontalLayout->addWidget(spinBox_xdim);

        label_2 = new QLabel(widget_virtual);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        spinBox_ydim = new QSpinBox(widget_virtual);
        spinBox_ydim->setObjectName(QStringLiteral("spinBox_ydim"));
        spinBox_ydim->setMaximum(999999999);

        horizontalLayout->addWidget(spinBox_ydim);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(widget_virtual);

        QWidget::setTabOrder(radioButton_mysql, radioButton_access);
        QWidget::setTabOrder(radioButton_access, radioButton_virtual);
        QWidget::setTabOrder(radioButton_virtual, lineEdit_host);
        QWidget::setTabOrder(lineEdit_host, lineEdit_db);
        QWidget::setTabOrder(lineEdit_db, lineEdit_user);
        QWidget::setTabOrder(lineEdit_user, lineEdit_password);
        QWidget::setTabOrder(lineEdit_password, lineEdit_layer);
        QWidget::setTabOrder(lineEdit_layer, lineEdit_theme);
        QWidget::setTabOrder(lineEdit_theme, lineEdit_select);
        QWidget::setTabOrder(lineEdit_select, lineEdit_access);
        QWidget::setTabOrder(lineEdit_access, pushButton_access);
        QWidget::setTabOrder(pushButton_access, lineEdit_layerAccess);
        QWidget::setTabOrder(lineEdit_layerAccess, lineEdit_themeAccess);
        QWidget::setTabOrder(lineEdit_themeAccess, lineEdit_selectAccess);
        QWidget::setTabOrder(lineEdit_selectAccess, spinBox_xdim);
        QWidget::setTabOrder(spinBox_xdim, spinBox_ydim);

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QWidget *Database)
    {
        Database->setWindowTitle(QApplication::translate("Database", "Form", 0));
        label_3->setText(QApplication::translate("Database", "Type:", 0));
        radioButton_mysql->setText(QApplication::translate("Database", "MySQL", 0));
        radioButton_access->setText(QApplication::translate("Database", "Access", 0));
        radioButton_virtual->setText(QApplication::translate("Database", "Virtual", 0));
        label_32->setText(QApplication::translate("Database", "Password:", 0));
        label_28->setText(QApplication::translate("Database", "Layer:", 0));
        lineEdit_user->setText(QString());
        label_23->setText(QApplication::translate("Database", "User:", 0));
        lineEdit_layer->setText(QString());
        lineEdit_theme->setText(QString());
        label_30->setText(QApplication::translate("Database", "Select:", 0));
        lineEdit_select->setText(QString());
        lineEdit_host->setText(QString());
        lineEdit_db->setText(QString());
        label_26->setText(QApplication::translate("Database", "Host:", 0));
        label_27->setText(QApplication::translate("Database", "Database:", 0));
        label_29->setText(QApplication::translate("Database", "Theme:", 0));
        label_22->setText(QApplication::translate("Database", "Access Database File:", 0));
        pushButton_access->setText(QApplication::translate("Database", "Browse", 0));
        label_33->setText(QApplication::translate("Database", "Layer:", 0));
        lineEdit_layerAccess->setText(QString());
        label_31->setText(QApplication::translate("Database", "Theme:", 0));
        lineEdit_themeAccess->setText(QString());
        label_34->setText(QApplication::translate("Database", "Select:", 0));
        lineEdit_selectAccess->setText(QString());
        label->setText(QApplication::translate("Database", "xdim", 0));
        label_2->setText(QApplication::translate("Database", "ydim", 0));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
