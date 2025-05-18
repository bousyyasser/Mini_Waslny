#include "USERLOGIN.h"
#include "FileHandling.h"
#include <QtWidgets/QApplication>
#include <QDir>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    // File handling
    User loadedUser;
    Graph loadedGraph;
    FileHandling fileHandler;
    QString userFilename = "Files/users.json";
    QString graphFilename = "Files/graph.json";
    // Check directory exists
    if (!fileHandler.directoryExists("Files")) {
        fileHandler.createDirectory("Files");
    }

    fileHandler.loadAll(userFilename, graphFilename, loadedUser, loadedGraph);
    // GUI setup 
    a.setWindowIcon(QIcon(":/images/icon.png"));
    a.setApplicationName("Mini Waslny");
    USERLOGIN w;
    w.setuser(loadedUser);
    w.setgraph(loadedGraph);
    w.setWindowTitle("Mini Waslny");
    w.show();
    int res = a.exec();

    w.getuser(loadedUser);
    loadedGraph = w.getgraph();
    fileHandler.saveAll(userFilename, graphFilename, loadedUser, loadedGraph);
    return res;
}