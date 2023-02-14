#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Account {
    string name;
    double balance;
};

pair<double, bool> find_account_balance(const vector<Account>& accounts, const string& name) {
    for (const auto& account : accounts) {
        if (account.name == name) {
            return { account.balance, true };
        }
    }
    return { 0.0, false };
}

vector<Account> compute_min_balances(const vector<pair<string, double>>& expenses) {
    map<string, double> balances;

    for (const auto& expense : expenses) {
        balances[expense.first] -= expense.second;
    }

    vector<Account> min_balances;
    for (const auto& [name, balance] : balances) {
        min_balances.push_back({ name, -balance });
    }
    return min_balances;
}

int main() {
    vector<pair<string, double>> expenses;
    string name;
    double expense;

    while (true) {
        cout << "Enter the name of the member (or 'done' to finish): ";
        cin >> name;

        if (name == "done") {
            break;
        }

        cout << "Enter the expense for " << name << ": ";
        cin >> expense;

        expenses.push_back({name, expense});
    }

    auto min_balances = compute_min_balances(expenses);

    cout << "Minimum balances required:\n";
    for (const auto& account : min_balances) {
        cout << account.name << ": " << account.balance << endl;
    }

    return 0;
}
