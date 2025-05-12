#pragma once
#include <QString>
#include <QList>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

using namespace rapidjson;

class User
{
public:
	User();
	void addUser(const QString& username, const QString& password);
	bool isUserExist(const QString& username);
	bool loginAuthen(const QString& username, const QString& password);

	rapidjson::Value to_json(rapidjson::Document::AllocatorType& allocator) const;
	void from_json(const rapidjson::Value& obj);
	void saveToFile(const QString& filename);
	void loadFromFile(const QString& filename);
	

private:
	QList<QPair<QString, QString>>users;



};

