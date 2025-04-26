/********************************************************************************
** Form generated from reading UI file 'USERLOGIN.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLOGIN_H
#define UI_USERLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_USERLOGINClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *loginContainer;
    QPushButton *loginButton;
    QLineEdit *passwordLineEdit;
    QLineEdit *usernameLineEdit;
    QLabel *statusLabel;
    QLabel *titleLabel;

    void setupUi(QMainWindow *USERLOGINClass)
    {
        if (USERLOGINClass->objectName().isEmpty())
            USERLOGINClass->setObjectName("USERLOGINClass");
        USERLOGINClass->resize(656, 528);
        centralWidget = new QWidget(USERLOGINClass);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        widget = new QWidget(centralWidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(-220, -20, 1111, 571));
        loginContainer = new QWidget(widget);
        loginContainer->setObjectName("loginContainer");
        loginContainer->setGeometry(QRect(410, 110, 281, 351));
        loginButton = new QPushButton(loginContainer);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(90, 220, 91, 41));
        passwordLineEdit = new QLineEdit(loginContainer);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(70, 140, 131, 31));
        usernameLineEdit = new QLineEdit(loginContainer);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(70, 70, 131, 31));
        statusLabel = new QLabel(loginContainer);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(0, 270, 291, 61));
        QFont font;
        font.setPointSize(22);
        statusLabel->setFont(font);
        statusLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        titleLabel = new QLabel(loginContainer);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(-10, 0, 291, 65));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Trebuchet MS")});
        font1.setPointSize(16);
        font1.setBold(true);
        titleLabel->setFont(font1);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        USERLOGINClass->setCentralWidget(centralWidget);

        retranslateUi(USERLOGINClass);

        QMetaObject::connectSlotsByName(USERLOGINClass);
    } // setupUi

    void retranslateUi(QMainWindow *USERLOGINClass)
    {
        USERLOGINClass->setWindowTitle(QCoreApplication::translate("USERLOGINClass", "USERLOGIN", nullptr));
        loginButton->setText(QCoreApplication::translate("USERLOGINClass", "Login", nullptr));
        statusLabel->setText(QString());
        titleLabel->setText(QCoreApplication::translate("USERLOGINClass", "Mini Wasalny", nullptr));
    } // retranslateUi

};

namespace Ui {
    class USERLOGINClass: public Ui_USERLOGINClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLOGIN_H
