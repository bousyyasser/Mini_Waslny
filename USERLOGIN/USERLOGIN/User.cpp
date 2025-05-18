#include "User.h"

User::User()
{
}

bool User::loginAuthen(const QString& username, const QString& password)
{
	for (const auto& user : users)
	{
		if (user.first == username && user.second == password)
		{
			return true;
		}
	}
	return false;
}

void User::addUser(const QString& username, const QString& password)
{
	users.append(qMakePair(username, password));
}

bool User::isUserExist(const QString& username)
{
	for (const auto& user : users)
	{
		if (user.first == username)
		{
			return true;
		}
	}

	return false;
}