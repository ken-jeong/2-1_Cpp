#include "Account.h"

bool Account::authenticate(int id, const std::string& password) const
{
	return id == nID && password == strPassword;
}

bool Account::withdraw(int money)
{
	if (money > nBalance)
		return false;
	nBalance -= money;
	return true;
}
