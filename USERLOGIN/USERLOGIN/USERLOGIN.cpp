#include "USERLOGIN.h"
#include "ui_USERLOGIN.h"
#include <QMessageBox>
#include <QVBoxLayout>
#include <QTimer>

USERLOGIN::USERLOGIN(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::USERLOGINClass), homePage(nullptr)
{
    ui->setupUi(this);
    setupUI();
}

USERLOGIN::~USERLOGIN()
{
    delete ui;
}

void USERLOGIN::setupUI()
{
   
    ui->loginContainer->raise();
    ui->usernameLineEdit->raise();
    ui->passwordLineEdit->raise();
    ui->loginButton->raise();
    ui->statusLabel->raise();
    ui->titleLabel->raise();

   
    ui->usernameLineEdit->setPlaceholderText("Enter Username");
    ui->passwordLineEdit->setPlaceholderText("Enter Password");
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

   
    ui->titleLabel->setStyleSheet(R"(
        QLabel {
            color: #808080; 
            background-color: transparent;
            font-family: 'Lucida Calligraphy', cursive;
            font-size: 20px; 
            font-weight: bold;
            padding: 15px 30px;
            qproperty-alignment: AlignCenter;
        }
    )");

    
    ui->widget->setStyleSheet(R"(
        #widget {
            background-image: url(:/images/bg.jpg);
            background-repeat: no-repeat;
            background-position: center;
            background-attachment: fixed;
            background-size: cover;
            min-width: 200px;  
            min-height: 800px; 
        }
    )");

   
    ui->loginContainer->setStyleSheet(R"(
        QWidget {
            background-color: rgba(255, 255, 255, 0.98);
            border-radius: 15px;
            padding: 30px;
            background-position: center;
        }
    )");

    
    QString inputStyle = R"(
        QLineEdit {
            background-color: rgba(255, 255, 255, 0.8);
            border: none;
            border-radius: 8px;
            padding: 5px 10px;
            font-size: 14px;
            color: #333;
            font-family: 'Segoe UI', sans-serif;
        }

        QLineEdit:focus {
            border: 2px solid #005aa7;
            background-color: white;
        }
    )";

    ui->usernameLineEdit->setStyleSheet(inputStyle);
    ui->passwordLineEdit->setStyleSheet(inputStyle);

    
    ui->loginButton->setStyleSheet(R"(
        QPushButton {
            background-color: #1c3b6f;  
            color: white;
            font-size: 16px;
            font-weight: bold;
            font-family: 'Segoe UI', sans-serif;
            border: none;
            border-radius: 8px;
            padding: 8px 20px;
        }

        QPushButton:hover {
            background-color: #162e59;
        }

        QPushButton:pressed {
            background-color: #0f2244;
        }
    )");
}

void USERLOGIN::on_loginButton_clicked()
{
    QString username = ui->usernameLineEdit->text().trimmed();
    QString password = ui->passwordLineEdit->text().trimmed();

    
    ui->loginButton->setEnabled(false);

    if (username.isEmpty() || password.isEmpty()) {
        showAlert("Error", "Enter a valid username or password.", QMessageBox::Critical);
        ui->loginButton->setEnabled(true);
        return;
    }

    handleLogin(username, password);


}
void USERLOGIN::handleLogin(const QString& username, const QString& password)
{
    
    if (user.isUserExist(username)) {
        
        if (user.loginAuthen(username, password)) {
            showStatus("Login Successfully!", "green");
            QTimer::singleShot(1000, this, [this, username]() {
                homePage = new HomePage(username);
                homePage->show();
                this->hide();
                });
        }
        else {
            showStatus("Wrong password for existing user.", "red");
            QTimer::singleShot(3600, this, [this]() {
                ui->statusLabel->clear();
                });
            ui->loginButton->setEnabled(true);
        }
    }
    else {
        user.addUser(username, password);
        showStatus("User Registered and Logged in Successfully!", "green");

        QTimer::singleShot(1000, this, [this, username]() {
            homePage = new HomePage(username);
            homePage->show();
            this->hide();
            });
    }
}

void USERLOGIN::showAlert(const QString& title, const QString& message, QMessageBox::Icon icon)
{
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setIcon(icon);
    msgBox.setWindowTitle(title);

    msgBox.setStyleSheet(R"(
        QMessageBox {
            background-color: #f5f5f5;
            border-radius: 10px;
            padding: 20px;
            font-family: 'Segoe UI', sans-serif;
        }

        QMessageBox QPushButton {
            background-color: #1c3b6f;
            color: white;
            font-size: 14px;
            font-family: 'Segoe UI', sans-serif;
            border-radius: 8px;
            padding: 8px 20px;
        }

        QMessageBox QPushButton:hover {
            background-color: #162e59;
        }

        QMessageBox QPushButton:pressed {
            background-color: #0f2244;
        }
    )");

    msgBox.exec();
}

void USERLOGIN::showStatus(const QString& message, const QString& color)
{
    ui->statusLabel->setStyleSheet(
        QString("color: %1; font-weight: bold; font-size: 10px; "
            "background-color: rgba(255,255,255,0.8); "
            "padding: 5px; border-radius: 5px;").arg(color));
    ui->statusLabel->setText(message);
}