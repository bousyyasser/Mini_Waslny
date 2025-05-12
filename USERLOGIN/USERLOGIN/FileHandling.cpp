#include "FileHandling.h"
#include "User.h"
#include"Edge.h"
#include"Graph.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

FileHandling::FileHandling() {}

void FileHandling::writeToFile(const QString& filename, const QString& content) {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << content;
        file.close();
    }
}

QString FileHandling::readFromFile(const QString& filename) {
    QFile file(filename);
    QString content;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        content = in.readAll();
        file.close();
    }
    return content;
}

void FileHandling::deleteFile(const QString& filename) {
    QFile::remove(filename);
}

bool FileHandling::fileExists(const QString& filename) {
    return QFile::exists(filename);
}

void FileHandling::createDirectory(const QString& dirName) {
    QDir().mkdir(dirName);
}

bool FileHandling::directoryExists(const QString& dirName) {
    return QDir(dirName).exists();
}

void FileHandling::deleteDirectory(const QString& dirName) {
    QDir dir(dirName);
    if (dir.exists()) {
        dir.removeRecursively();
    }
}

void User::saveToFile(const QString& filename) {
    QJsonArray userArray;
    for (const auto& user : users) {
        QJsonObject obj;
        obj["username"] = user.first;
        obj["password"] = user.second;
        userArray.append(obj);
    }

    QJsonDocument doc(userArray);
    FileHandling fh;
    fh.writeToFile(filename, doc.toJson());
}

void User::loadFromFile(const QString& filename) {
    FileHandling fh;
    if (!fh.fileExists(filename)) return;

    QString content = fh.readFromFile(filename);
    QJsonDocument doc = QJsonDocument::fromJson(content.toUtf8());

    if (!doc.isArray()) return;
    QJsonArray userArray = doc.array();

    users.clear(); // Reset current list

    for (const auto& item : userArray) {
        QJsonObject obj = item.toObject();
        users.append(qMakePair(obj["username"].toString(), obj["password"].toString()));
    }
}

Value Edge::to_json(Document::AllocatorType& allocator) const {
    Value Edgeobj(kObjectType);
    Edgeobj.AddMember("destination", Value(destination.c_str(), allocator), allocator);
    Edgeobj.AddMember("distance", distance, allocator);
    return Edgeobj;
}

Edge Edge::from_json(const rapidjson::Value& obj) {
    Edge edge;
    if (obj.HasMember("destination") && obj["destination"].IsString()) {
        edge.destination = obj["destination"].GetString();
    }

    if (obj.HasMember("distance") && obj["distance"].IsInt()) {
        edge.distance = obj["distance"].GetInt();
    }

    return edge;
}


Value Graph::to_json(Document::AllocatorType& allocator) const {
    Value graphObj(kObjectType);

    for (const auto& pair : adjacencyList) {
        Value cityName(pair.first.c_str(), allocator);
        Value edgesArr(kArrayType);

        for (const Edge& edge : pair.second) {
            edgesArr.PushBack(edge.to_json(allocator), allocator);
        }

        graphObj.AddMember(cityName, edgesArr, allocator);
    }

    return graphObj;
}

Graph Graph::from_json(const rapidjson::Value& obj) {
    Graph graph;

    for (auto it = obj.MemberBegin(); it != obj.MemberEnd(); ++it) {
        std::string city = it->name.GetString();
        const rapidjson::Value& edgesArr = it->value;

        for (rapidjson::SizeType i = 0; i < edgesArr.Size(); ++i) {
            Edge edge = Edge::from_json(edgesArr[i]);
            graph.adjacencyList[city].push_back(edge);
        }
    }

    return graph;
}

void FileHandling::saveAll(const QString& userFilename, const QString& graphFilename, User& user, Graph& graph) {
    user.saveToFile(userFilename);

    rapidjson::Document graphDoc;
    graphDoc.SetObject();
    graphDoc.AddMember("graph", graph.to_json(graphDoc.GetAllocator()), graphDoc.GetAllocator());

    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    graphDoc.Accept(writer);

    QString graphJson = QString::fromStdString(buffer.GetString());
    writeToFile(graphFilename, graphJson);
}

void FileHandling::loadAll(const QString& userFilename, const QString& graphFilename, User& user, Graph& graph) {
    user.loadFromFile(userFilename);
    if (fileExists(graphFilename)) {
        QString content = readFromFile(graphFilename);
        rapidjson::Document doc;
        doc.Parse(content.toUtf8().data());
        if (doc.IsObject()) {
            graph = Graph::from_json(doc["graph"]);
        }
    }
}
