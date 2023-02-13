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

std::vector<Account> alt_compute_min_balances(
        const std::vector<Account>& expenses);

std::map<std::string, double> compute_min_balances(
        const std::map<std::string, double>& expenses);

#endif // EXPENSE_BLANCER_H_INCLUDED
