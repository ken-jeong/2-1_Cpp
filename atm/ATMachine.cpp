#include <iostream>
#include "ATMachine.h"
#include "Statistics.h"
using namespace std;

// 숫자가 아닌 입력이 들어와도 무한루프에 빠지지 않게 처리
static int readInt(const string& prompt)
{
	int value;
	cout << prompt;
	while (!(cin >> value))
	{
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "숫자를 입력하세요: ";
	}
	return value;
}

ATMachine::ATMachine(int size, int balance, const string& password)
	: nMachineBalance(balance), nMaxAccountNum(size), strManagerPassword(password)
{
	accounts.reserve(size);
}

void ATMachine::displayMenu()
{
	cout << "-------------------------" << endl;
	cout << "-       TUK bank        -" << endl;
	cout << "-------------------------" << endl;
	cout << " 1. 계좌 개설" << endl;
	cout << " 2. 계좌 조회" << endl;
	cout << " 3. 계좌 입금" << endl;
	cout << " 4. 계좌 출금" << endl;
	cout << " 5. 계좌 이체" << endl;
	cout << " 6. 고객 관리" << endl;
	cout << " 9. 업무 종료" << endl;
}

Account* ATMachine::findAccount()
{
	int id = readInt("계좌번호 입력 : ");
	string passwd;
	cout << "비밀번호 입력 : ";
	cin >> passwd;

	int index = id - BASE_ACCOUNT_ID;
	if (index < 0 || index >= (int)accounts.size() || !accounts[index].authenticate(id, passwd))
	{
		cout << "계좌번호 또는 비밀번호가 다릅니다." << endl;
		return nullptr;
	}
	return &accounts[index];
}

void ATMachine::createAccount()
{
	cout << "---------- 개설 ----------" << endl;
	if ((int)accounts.size() >= nMaxAccountNum)
	{
		cout << "더 이상 계좌를 개설할 수 없습니다." << endl;
		return;
	}

	string name, passwd;
	cout << "이름 입력 : ";
	cin >> name;
	cout << "암호 입력 : ";
	cin >> passwd;

	int id = BASE_ACCOUNT_ID + (int)accounts.size();
	accounts.push_back(Account(id, name, passwd));
	cout << "\n" << name << "님 " << id << " 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;
}

void ATMachine::checkMoney()
{
	cout << "---------- 조회 ----------" << endl;
	Account* acct = findAccount();
	if (acct)
		cout << "현재 잔액 : " << acct->getBalance() << endl;
}

void ATMachine::depositMoney()
{
	cout << "---------- 입금 ----------" << endl;
	Account* acct = findAccount();
	if (!acct)
		return;

	int money = readInt("입금액   입력 : ");
	if (money <= 0)
	{
		cout << "잘못된 금액입니다." << endl;
		return;
	}
	acct->deposit(money);
	nMachineBalance += money;
	cout << "현재 잔액 : " << acct->getBalance() << endl;
	cout << "입금 완료" << endl;
}

void ATMachine::withdrawMoney()
{
	cout << "---------- 출금 ----------" << endl;
	Account* acct = findAccount();
	if (!acct)
		return;

	int money = readInt("출금액   입력 : ");
	if (money <= 0)
	{
		cout << "잘못된 금액입니다." << endl;
		return;
	}
	if (money > nMachineBalance)
	{
		cout << "ATM 잔액이 부족합니다." << endl;
		return;
	}
	if (!acct->withdraw(money))
	{
		cout << "계좌 잔액이 부족합니다." << endl;
		return;
	}
	nMachineBalance -= money;
	cout << "현재 잔액 : " << acct->getBalance() << endl;
	cout << "출금 완료" << endl;
}

void ATMachine::transfer()
{
	cout << "---------- 이체 ----------" << endl;
	Account* from = findAccount();
	if (!from)
		return;

	int toIndex = readInt("이체계좌 입력 : ") - BASE_ACCOUNT_ID;
	if (toIndex < 0 || toIndex >= (int)accounts.size())
	{
		cout << "이체할 계좌가 없습니다." << endl;
		return;
	}

	int money = readInt("이체금액 입력 : ");
	if (money <= 0)
	{
		cout << "잘못된 금액입니다." << endl;
		return;
	}
	if (!from->withdraw(money))
	{
		cout << "계좌 잔액이 부족합니다." << endl;
		return;
	}
	accounts[toIndex].deposit(money);
	cout << "현재 잔액 : " << from->getBalance() << endl;
	cout << "이체 완료" << endl;
}

void ATMachine::managerMode()
{
	cout << "---------- 관리 ----------" << endl;
	string passwd;
	cout << "관리자 비밀번호 입력 : ";
	cin >> passwd;
	if (passwd != strManagerPassword)
	{
		cout << "관리자가 아닙니다." << endl;
		return;
	}
	cout << "관리자 입니다.\n" << endl;
	displayReport();
}

void ATMachine::displayReport()
{
	Statistics s;
	cout << " ATM 현금 잔고 : " << nMachineBalance << endl;
	cout << "고객 잔고 총액 : " << s.sum(accounts) << "(총 " << accounts.size() << "명)" << endl;
	cout << "고객 잔고 평균 : " << s.average(accounts) << endl;
	cout << "고객 잔고 최고 : " << s.max(accounts) << endl;
	cout << endl;

	cout << "-------- 계좌 현황--------" << endl;
	cout << "--------------------------" << endl;
	for (size_t i = 0; i < accounts.size(); i++)
		cout << accounts[i].getName() << "\t" << accounts[i].getID() << "\t" << accounts[i].getBalance() << endl;
	cout << endl;
}
