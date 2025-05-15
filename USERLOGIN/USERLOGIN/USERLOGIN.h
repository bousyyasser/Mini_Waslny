#pragma once
#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "User.h"
#include "HomePage.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
using namespace rapidjson;
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
    void setuser(const User& user) { this->user = user; }
    void getuser(User& user) { user = this->user; }

    // Modified method to preserve the undo history
    void setgraph(const Graph& graph)
    {
        this->tempGraph = graph;

        if (homePage != nullptr) {
            homePage->setGraph(tempGraph);
        }
    }

    Graph getgraph() const {
        return (homePage != nullptr) ? homePage->getGraph() : tempGraph;
    }
private slots:
    void on_loginButton_clicked();
private:
    Ui::USERLOGINClass* ui;
    User user;
    Graph tempGraph;
    HomePage* homePage;
    void setupUI();
    void showAlert(const QString& title, const QString& message, QMessageBox::Icon icon);
    void showStatus(const QString& message, const QString& color);
    void handleLogin(const QString& username, const QString& password);
};