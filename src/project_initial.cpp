#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Account
{
    string name{};
    double balance{};
};

// Given a vector of accounts and a name, return the balance of the account
// with the given name, along with a flag indicating whether the account
// was found.
pair<double, bool> find_account_balance(const vector<Account>& accounts, const string& name) {
    for (const auto& account : accounts) {
        if (account.name == name) {
            return { account.balance, true };
        }
    }
    return { 0.0, false };
}

// Given a vector of expenses, compute the minimum balance required for each member
// to keep their account from going negative, and return a vector of the resulting
// Account objects.
vector<Account> compute_min_balances(const vector<pair<string, double>>& expenses) {
    // Create a map of account names to balances
    map<string, double> balances;

    // Compute the total expenses for each account and store in the balances map
    for (const auto& expense : expenses) {
        balances[expense.first] -= expense.second;
    }

    // Compute the minimum balance required for each account and store in the resulting vector
    vector<Account> min_balances;
    for (const auto& [name, balance] : balances) {
        min_balances.push_back({ name, -balance });
    }
    return min_balances;
}

int main() {
    // Define the test cases
    vector<vector<pair<string, double>>> test_cases = {
        {}, // empty case
        {{"Bob", 0.0}}, // single member with no expenses
        {{"Alice", 0.0}, {"Bob Yays", 6.4}}, // two members, one with expenses
        {{"Alice", 0.1}, {"Bob", 9.9}, {"Charlie", 0.6}} // three members with expenses
    };

    // Loop over the test cases and print the results for each one
    for (const auto& expenses : test_cases) {
        const auto min_balances = compute_min_balances(expenses);

        cout << "Input expenses:" << endl;
        for (const auto& expense : expenses) {
            cout << expense.first << ": " << expense.second << endl;
        }

        for (const auto& account : min_balances) {
            cout << account.name << "'s minimum balance: ";
            auto [balance, ok] = find_account_balance(min_balances, account.name);
            if (ok) {
                cout << balance << endl;
            } else {
                cout << "not found" << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
