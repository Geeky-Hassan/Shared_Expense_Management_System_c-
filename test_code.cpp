#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Member {
    string name;
    double balance;
};

void addMember(vector<Member>& members) {
    string name;
    cout << "Enter member name: ";
    cin >> name;

    Member member = {name, 0.0};
    members.push_back(member);

    cout << "Member added successfully." << endl;
}

void showMembers(const vector<Member>& members) {
    cout << "Members:" << endl;
    for (const auto& member : members) {
        cout << member.name << " (balance: " << member.balance << ")" << endl;
    }
}

void addExpense(vector<Member>& members) {
    string payerName;
    double amount;
    cout << "Enter payer name: ";
    cin >> payerName;
    cout << "Enter expense amount: ";
    cin >> amount;

    int size_tnumMembers = members.size();
    double splitAmount = amount / size_tnumMembers;

    for (auto& member : members) {
        if (member.name != payerName) {
            member.balance += splitAmount;
        } else {
            member.balance -= amount - splitAmount;
        }
    }

    cout << "Expense added successfully." << endl;
}

void calculateNetBalance(vector<Member>& members) {
    for (auto& member : members) {
        for (auto& otherMember : members) {
            if (member.name != otherMember.name) {
                double amount = min(member.balance, -otherMember.balance);
                member.balance -= amount;
                otherMember.balance += amount;
            }
        }
    }

    cout << "Net balance calculated successfully." << endl;
}

void showMinBalances(const vector<Member>& members) {
    vector<Member> expenses = members;
    sort(expenses.begin(), expenses.end(), [](const Member& a, const Member& b) {
        return a.balance < b.balance;
    });

    vector<Member> creditors;
    vector<Member> debtors;

    for (const auto& expense : expenses) {
        if (expense.balance > 0) {
            creditors.push_back(expense);
        } else if (expense.balance < 0) {
            debtors.push_back(expense);
        }
    }

    vector<pair<string, double>> minBalances;

    for ( auto& creditor : creditors) {
        for ( auto& debtor : debtors) {
            double amount = min(creditor.balance, -debtor.balance);
            if (amount > 0) {
                creditor.balance -= amount;
                debtor.balance += amount;
                minBalances.push_back({creditor.name + " -> " + debtor.name, amount});
                if (creditor.balance == 0) {
                    break;
                }
            }
        }
    }

    cout << "Minimum balances per person:" << endl;
    for (const auto& minBalance : minBalances) {
        cout << minBalance.first << " (balance: " << minBalance.second << ")" << endl;
    }
}


int main() {
    vector<Member> members;

    while (true) {
        cout << endl;
        cout << "SEMS - Shared Expense Management System" << endl;
        cout << "1. Add member" << endl;
        cout << "2. Show members" << endl;
        cout << "3. Add expense" << endl;
        cout << "4. Calculate net balance" << endl;
        cout << "5. Show minimum balances" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addMember(members);
                break;
            case 2:
                showMembers(members);
                break;
            case 3:
                addExpense(members);
                break;
            case 4:
                calculateNetBalance(members);
                break;
            case 5:
                showMinBalances(members);
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
