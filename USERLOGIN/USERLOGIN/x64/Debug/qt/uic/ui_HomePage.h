/********************************************************************************
** Form generated from reading UI file 'HomePage.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "graphview.h"

QT_BEGIN_NAMESPACE

class Ui_HomePageClass
{
public:
    QWidget *centralWidget;
    QWidget *leftPanel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *homeButton;
    QPushButton *addGraphButton;
    QPushButton *traverseButton;
    QPushButton *shortestPathButton;
    QPushButton *logoutButton;
    QStackedWidget *rightPanel;
    QWidget *HomePageWidget;
    QLabel *welcomeLabel;
    QFrame *frame;
    QLabel *desLabel;
    QWidget *addGraphWidget;
    QPushButton *back;
    QPushButton *addCityBtn;
    QPushButton *addEdgeBtn;
    QPushButton *deleteCityBtn;
    QPushButton *deleteEdgeBtn;
    GraphView *graphView;

    void setupUi(QMainWindow *HomePageClass)
    {
        if (HomePageClass->objectName().isEmpty())
            HomePageClass->setObjectName("HomePageClass");
        HomePageClass->resize(841, 493);
        centralWidget = new QWidget(HomePageClass);
        centralWidget->setObjectName("centralWidget");
        leftPanel = new QWidget(centralWidget);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setEnabled(true);
        leftPanel->setGeometry(QRect(-1, -10, 201, 511));
        verticalLayoutWidget = new QWidget(leftPanel);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 10, 191, 501));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        homeButton = new QPushButton(verticalLayoutWidget);
        homeButton->setObjectName("homeButton");

        verticalLayout->addWidget(homeButton);

        addGraphButton = new QPushButton(verticalLayoutWidget);
        addGraphButton->setObjectName("addGraphButton");

        verticalLayout->addWidget(addGraphButton);

        traverseButton = new QPushButton(verticalLayoutWidget);
        traverseButton->setObjectName("traverseButton");

        verticalLayout->addWidget(traverseButton);

        shortestPathButton = new QPushButton(verticalLayoutWidget);
        shortestPathButton->setObjectName("shortestPathButton");

        verticalLayout->addWidget(shortestPathButton);

        logoutButton = new QPushButton(verticalLayoutWidget);
        logoutButton->setObjectName("logoutButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logoutButton->sizePolicy().hasHeightForWidth());
        logoutButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(logoutButton);

        rightPanel = new QStackedWidget(centralWidget);
        rightPanel->setObjectName("rightPanel");
        rightPanel->setGeometry(QRect(200, 0, 641, 501));
        HomePageWidget = new QWidget();
        HomePageWidget->setObjectName("HomePageWidget");
        welcomeLabel = new QLabel(HomePageWidget);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setGeometry(QRect(30, 30, 381, 51));
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        frame = new QFrame(HomePageWidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(20, 130, 471, 241));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        desLabel = new QLabel(frame);
        desLabel->setObjectName("desLabel");
        desLabel->setGeometry(QRect(10, 10, 441, 221));
        rightPanel->addWidget(HomePageWidget);
        addGraphWidget = new QWidget();
        addGraphWidget->setObjectName("addGraphWidget");
        back = new QPushButton(addGraphWidget);
        back->setObjectName("back");
        back->setGeometry(QRect(0, 0, 101, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8("images/back.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        back->setIcon(icon);
        addCityBtn = new QPushButton(addGraphWidget);
        addCityBtn->setObjectName("addCityBtn");
        addCityBtn->setGeometry(QRect(695, 60, 121, 51));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("images/add.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addCityBtn->setIcon(icon1);
        addEdgeBtn = new QPushButton(addGraphWidget);
        addEdgeBtn->setObjectName("addEdgeBtn");
        addEdgeBtn->setGeometry(QRect(695, 120, 121, 51));
        addEdgeBtn->setIcon(icon1);
        deleteCityBtn = new QPushButton(addGraphWidget);
        deleteCityBtn->setObjectName("deleteCityBtn");
        deleteCityBtn->setGeometry(QRect(695, 190, 121, 51));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("images/delete.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        deleteCityBtn->setIcon(icon2);
        deleteEdgeBtn = new QPushButton(addGraphWidget);
        deleteEdgeBtn->setObjectName("deleteEdgeBtn");
        deleteEdgeBtn->setGeometry(QRect(695, 260, 121, 51));
        deleteEdgeBtn->setIcon(icon2);
        graphView = new GraphView(addGraphWidget);
        graphView->setObjectName("graphView");
        graphView->setGeometry(QRect(0, 0, 691, 491));
        rightPanel->addWidget(addGraphWidget);
        HomePageClass->setCentralWidget(centralWidget);

        retranslateUi(HomePageClass);

        QMetaObject::connectSlotsByName(HomePageClass);
    } // setupUi

    void retranslateUi(QMainWindow *HomePageClass)
    {
        HomePageClass->setWindowTitle(QCoreApplication::translate("HomePageClass", "HomePage", nullptr));
        homeButton->setText(QCoreApplication::translate("HomePageClass", "Home", nullptr));
        addGraphButton->setText(QCoreApplication::translate("HomePageClass", "Add Graph", nullptr));
        traverseButton->setText(QCoreApplication::translate("HomePageClass", "Traverse Graph", nullptr));
        shortestPathButton->setText(QCoreApplication::translate("HomePageClass", "Shortest Path", nullptr));
        logoutButton->setText(QCoreApplication::translate("HomePageClass", "logout", nullptr));
        welcomeLabel->setText(QString());
        desLabel->setText(QString());
        back->setText(QString());
        addCityBtn->setText(QCoreApplication::translate("HomePageClass", "Add City", nullptr));
        addEdgeBtn->setText(QCoreApplication::translate("HomePageClass", "Add Edge", nullptr));
        deleteCityBtn->setText(QCoreApplication::translate("HomePageClass", "Delete City", nullptr));
        deleteEdgeBtn->setText(QCoreApplication::translate("HomePageClass", "Delete Edge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePageClass: public Ui_HomePageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
