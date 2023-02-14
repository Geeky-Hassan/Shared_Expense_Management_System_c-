#include "expense_balancer.h"

#include <string>

double max(const double a, const double b) {
    if (a > b) {
        return a;
    }
    return b;
}

std::vector<Account> compute_min_balances(
        const std::vector<Account>& expenses) {
    std::vector<Account> min_balances{};
    for (const auto& payer_expense : expenses) {
        double owed{0.0};
        for (const auto& expense : expenses) {
            if (expense.name != payer_expense.name) {
                auto we_owe = expense.balance / expenses.size();
                auto they_owe = payer_expense.balance / expenses.size();
                owed += max(we_owe - they_owe, 0.0);
            }
        }
        min_balances.push_back({payer_expense.name, owed});
    }

    return min_balances;
}
