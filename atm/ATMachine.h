#ifndef ATMACHINE_H
#define ATMACHINE_H

#include <string>
#include <vector>
#include "Account.h"

class ATMachine
{
private:
	std::vector<Account> accounts;   // 개설된 고객 계좌
	int nMachineBalance;             // ATM 잔고
	int nMaxAccountNum;              // 최대 계좌 수
	std::string strManagerPassword;  // 관리자 비밀번호

	Account* findAccount();  // 계좌번호/비밀번호를 입력받아 인증된 계좌 반환, 실패 시 nullptr
	void displayReport();    // 통계 화면 처리

public:
	ATMachine(int size, int balance, const std::string& password);

	void displayMenu();     // ATM 기능 선택 화면
	void createAccount();   // 계좌 개설
	void checkMoney();      // 계좌 조회
	void depositMoney();    // 계좌 입금
	void withdrawMoney();   // 계좌 출금
	void transfer();        // 계좌 이체
	void managerMode();     // 고객 관리
};

#endif
