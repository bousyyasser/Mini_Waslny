#pragma once
#include <QString>
#include <QList>
class User
{
public:
	User();
	void addUser(const QString& username, const QString& password);
	bool isUserExist(const QString& username);
	bool loginAuthen(const QString& username, const QString& password);
	

private:
	QList<QPair<QString, QString>>users;

};

