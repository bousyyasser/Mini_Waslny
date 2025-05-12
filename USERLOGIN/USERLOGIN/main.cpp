#include "USERLOGIN.h"
#include "FileHandling.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    //file handling
    User loadedUser;
    Graph loadedGraph;
    FileHandling fileHandler;
    QString userFilename = "Files/users.json";
    QString graphFilename = "Files/graph.json";
    fileHandler.loadAll(userFilename, graphFilename, loadedUser, loadedGraph);
    

    // GUI 
    a.setWindowIcon(QIcon(":/images/icon.png"));
    a.setApplicationName("Mini Waslny");

    USERLOGIN w;
    w.setuser(loadedUser);
    w.setgraph(loadedGraph);

    w.setWindowTitle("Mini Waslny");
    w.show();


    w.getuser(loadedUser);
    loadedGraph = w.getgraph();
    fileHandler.saveAll(userFilename, graphFilename, loadedUser, loadedGraph);

    return a.exec();
}
