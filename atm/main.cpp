#include <iostream>
#include "ATMachine.h"
using namespace std;

int main()
{
	ATMachine atm(100, 50000, "password");  // 최대 계좌 수, ATM 잔고, 관리자 암호

	while (true)
	{
		atm.displayMenu();
		cout << "메뉴를 선택하세요: ";

		int select;
		if (!(cin >> select))
		{
			cin.clear();
			cin.ignore(1024, '\n');
			select = 0;  // 잘못된 입력은 default로 처리
		}
		cout << endl;

		switch (select)
		{
		case 1: atm.createAccount(); break;
		case 2: atm.checkMoney();    break;
		case 3: atm.depositMoney();  break;
		case 4: atm.withdrawMoney(); break;
		case 5: atm.transfer();      break;
		case 6: atm.managerMode();   break;
		case 9:
			cout << "\n\n\n안녕히 가세요" << endl;
			return 0;
		default:
			cout << "번호 확인 후 다시 입력하세요." << endl;
			break;
		}
	}
}
