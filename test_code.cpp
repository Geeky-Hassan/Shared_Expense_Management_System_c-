#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void add_members(vector<string> &member_names);
void add_expense(vector<double> &balances, int num_members, const vector<string> &member_names);
void print_balances(const vector<string> &member_names, const vector<double> &balances);
void calculate_net_balances(const vector<string> &member_names, const vector<double> &balances);

int main()
{
    vector<string> member_names;
    vector<double> balances;

    add_members(member_names);
    add_expense(balances, member_names.size(), member_names);
    print_balances(member_names, balances);
    calculate_net_balances(member_names, balances);

    return 0;
}

void add_members(vector<string> &member_names)
{
    cout << "Enter member names (type finish when you are done):\n";
    while (true)
    {
        string name;
        cout << "Member " << member_names.size() + 1 << ": ";
        cin >> name;
        if (name == "finish")
        {
            break;
        }
        member_names.push_back(name);
    }
}

void add_expense(vector<double> &balances, int num_members, const vector<string> &member_names)
{
    double amount;
    string payer;

    cout << "Enter expense details (payer name): ";
    cin >> payer;
    cout << "Enter expense details (amount): ";
    cin >> amount;

    if (balances.size() == 0)
    {
        balances.resize(num_members);
    }

    double per_member_amount = amount / num_members;

    for (int i = 0; i < num_members; i++)
    {
        if (member_names[i] == payer)
        {
            balances[i] += amount - per_member_amount;
        }
        else
        {
            balances[i] += per_member_amount;
        }
    }
}

void print_balances(const vector<string> &member_names, const vector<double> &balances)
{
    cout << "Balances:\n";
    for (int i = 0; i < member_names.size(); i++)
    {
        cout << member_names[i] << ": " << balances[i] << endl;
    }
}

void calculate_net_balances(const vector<string> &member_names, const vector<double> &balances)
{
    vector<double> net_balances(balances.size(), 0.0);

    for (int i = 0; i < member_names.size(); i++) {
    for (int j = 0; j < member_names.size(); j++) {
        if (i != j) {
            double borrowed_amount = balances[j] - balances[i];
            if (borrowed_amount > 0) {
                net_balances[i] -= borrowed_amount;
                net_balances[j] += borrowed_amount;
            }
        }
    }
}

cout << "Net balances:\n";
for (int i = 0; i < member_names.size(); i++) {
    cout << member_names[i] << " owes ";

    double min_net_balance = 0.0;
    double max_net_balance = 0.0;
    int min_index = -1;
    int max_index = -1;

    for (int j = 0; j < member_names.size(); j++) {
        if (i != j) {
            double net_balance = net_balances[j] - net_balances[i];
            if (net_balance > max_net_balance) {
                max_net_balance = net_balance;
                max_index = j;
            } else if (net_balance < min_net_balance) {
                min_net_balance = net_balance;
                min_index = j;
            }
        }
    }

    if (max_net_balance == 0 && min_net_balance == 0) {
        cout << "nothing." << endl;
    } else if (max_net_balance >= -min_net_balance) {
        cout << member_names[max_index] << " " << abs(min_net_balance) << endl;
        net_balances[i] -= min_net_balance;
        net_balances[max_index] += min_net_balance;
    } else {
        cout << member_names[min_index] << " " << max_net_balance << endl;
        net_balances[i] += max_net_balance;
        net_balances[min_index] -= max_net_balance;
    }
}
}