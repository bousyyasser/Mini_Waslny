#pragma once
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "User.h"
#include "HomePage.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class USERLOGINClass;
}
QT_END_NAMESPACE

class USERLOGIN : public QMainWindow
{
    Q_OBJECT

public:
    USERLOGIN(QWidget* parent = nullptr);
    ~USERLOGIN();

private slots:
    void on_loginButton_clicked();

private:
    Ui::USERLOGINClass* ui;
    User user;
    HomePage homePage;


    void setupUI();
    void showAlert(const QString& title, const QString& message, QMessageBox::Icon icon);
    void showStatus(const QString& message, const QString& color);
    void handleLogin(const QString& username, const QString& password);
};