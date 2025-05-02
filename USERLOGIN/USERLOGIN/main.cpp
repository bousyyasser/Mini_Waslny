#include "USERLOGIN.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/images/icon.png"));
    a.setApplicationName("Mini Waslny");

    USERLOGIN w;
    w.setWindowTitle("Mini Waslny"); 
    w.show();

    return a.exec();
}
