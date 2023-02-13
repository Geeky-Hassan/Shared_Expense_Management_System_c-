#ifndef EXPENSE_BALANCER_H_INCLUDED
#define EXPENSE_BALANCER_H_INCLUDED

#include <map>
#include <string>
#include <vector>

struct Account
{
    std::string name{};
    double balance{};
};

std::vector<Account> compute_min_balances(
        const std::vector<Account>& expenses);

#endif // EXPENSE_BLANCER_H_INCLUDED
