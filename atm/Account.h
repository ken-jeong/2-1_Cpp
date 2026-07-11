#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

const int BASE_ACCOUNT_ID = 100;  // 계좌번호는 100번부터

class Account
{
private:
	int nID;                  // 계좌 번호
	int nBalance;             // 잔고
	std::string strName;      // 고객 명
	std::string strPassword;  // 계좌 비밀번호

public:
	Account(int id, const std::string& name, const std::string& password)
		: nID(id), nBalance(0), strName(name), strPassword(password) {}

	int getID() const { return nID; }
	int getBalance() const { return nBalance; }
	const std::string& getName() const { return strName; }

	bool authenticate(int id, const std::string& password) const;
	void deposit(int money) { nBalance += money; }
	bool withdraw(int money);  // 잔액 부족이면 false
};

#endif
