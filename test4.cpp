#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Member {
    string name;
    double balance;
};

void show_members(vector<Member>& members) {
    for (Member& member : members) {
        cout << member.name << ": " << member.balance << endl;
    }
}

void add_expense(vector<Member>& members, double total_expense, string payer_name) {
    double split_expense = total_expense / members.size();
    for (Member& member : members) {
        if (member.name != payer_name) {
            member.balance += split_expense;
        }
    }
    for (Member& member : members) {
        if (member.name == payer_name) {
            member.balance += total_expense;
            break;
        }
    }
}

void calculate_net_balance(vector<Member>& members) {
    for (Member& member : members) {
        for (Member& other_member : members) {
            if (member.name != other_member.name) {
                double net_balance = member.balance - other_member.balance;
                if (net_balance > 0) {
                    cout << member.name << " owes " << other_member.name << " Rs." << net_balance << endl;
                    member.balance -= net_balance;
                    other_member.balance += net_balance;
                }
                else if (net_balance < 0) {
                    cout << other_member.name << " owes " << member.name << " Rs." << -net_balance << endl;
                    member.balance -= net_balance;
                    other_member.balance += net_balance;
                }
            }
        }
    }
}

int main() {
    int num_members;
    cout << "Enter number of members: ";
    cin >> num_members;
    vector<Member> members(num_members);
    for (int i = 0; i < num_members; i++) {
        cout << "Enter name of member " << i+1 << ": ";
        cin >> members[i].name;
        members[i].balance = 0;
    }
    cout << "Members list:" << endl;
    show_members(members);

    int num_expenses;
    cout << "Enter number of expenses: ";
    cin >> num_expenses;
    for (int i = 0; i < num_expenses; i++) {
        double expense_amount;
        string payer_name;
        cout << "Enter amount of expense " << i+1 << ": ";
        cin >> expense_amount;
        cout << "Enter name of payer: ";
        cin >> payer_name;
        add_expense(members, expense_amount, payer_name);
        cout << "Expense added." << endl;
    }

    cout << "Final balances:" << endl;
    show_members(members);

    cout << "Net balance:" << endl;
    calculate_net_balance(members);

    return 0;
}
