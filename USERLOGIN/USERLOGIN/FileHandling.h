#ifndef FILEHANDLING_H
#define FILEHANDLING_H

#include <QString>
#include <QPair>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <rapidjson/document.h>

#include "User.h" // Include the User class definition
#include "Graph.h" // Include the Graph class definition

class FileHandling {
public:
    FileHandling();
    void writeToFile(const QString& filename, const QString& content);
    QString readFromFile(const QString& filename);
    void deleteFile(const QString& filename);
    bool fileExists(const QString& filename);
    void createDirectory(const QString& dirName);
    bool directoryExists(const QString& dirName);
    void deleteDirectory(const QString& dirName);
    void saveAll(const QString& userFilename, const QString& graphFilename, User& user, Graph& graph);
    void loadAll(const QString& userFilename, const QString& graphFilename, User& user, Graph& graph);
};

#endif // FILEHANDLING_H