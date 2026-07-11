#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "Account.h"

class Statistics
{
public:
	int sum(const std::vector<Account>& accounts);      // 계좌 잔고 총합
	int average(const std::vector<Account>& accounts);  // 계좌 잔고 평균 (계좌 없으면 0)
	int max(const std::vector<Account>& accounts);      // 계좌 잔고 최고 (계좌 없으면 0)
};

#endif
