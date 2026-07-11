#include "Statistics.h"

int Statistics::sum(const std::vector<Account>& accounts)
{
	int total = 0;
	for (size_t i = 0; i < accounts.size(); i++)
		total += accounts[i].getBalance();
	return total;
}

int Statistics::average(const std::vector<Account>& accounts)
{
	if (accounts.empty())
		return 0;
	return sum(accounts) / (int)accounts.size();
}

int Statistics::max(const std::vector<Account>& accounts)
{
	int best = 0;
	for (size_t i = 0; i < accounts.size(); i++)
		if (accounts[i].getBalance() > best)
			best = accounts[i].getBalance();
	return best;
}
