#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

// Define a struct to represent each member of the group
struct member
{
    string name;
    double expenses;
    double debt;
    vector<double> expenses_history;
    vector<double> debt_history;
};
// Function to add a new member to the group
void add_member(vector<member> &m, string name);

// Function to add expenses for a member
void add_expenses(vector<member> &m, string name, double amount);

// Function to calculate the net balance for a member
void net_balance(vector<member> &m, string name);

// Function to display the expense and debt history for a member
void history(vector<member> &m, string name);

int main()
{
    vector<member> m;

    // Get the number of members in the group from the user
    int num_members;
    cout << "How many members are in the group?" << endl;
    cin >> num_members;

    // Ask for the name of each member and add them to the group
    for (int i = 0; i < num_members; i++)
    {
        string name;
        cout << "Enter the name of member " << i + 1 << ":" << endl;
        cin >> name;
        add_member(m, name);
    }

// Loop to display the menu and process user input
    int choice;
    string name;
    double amount;
    do
    {
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Add expenses" << endl;
        cout << "2. View net balance" << endl;
        cout << "3. View history" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the name of the member who paid the expenses:" << endl;
            cin >> name;
            cout << "Enter the amount paid:" << endl;
            cin >> amount;
            add_expenses(m, name, amount);
            break;

        case 2:
            cout << "Enter the name of the member to view net balance:" << endl;
            cin >> name;
            net_balance(m, name);
            break;

        case 3:
            cout << "Enter the name of the member to view history:" << endl;
            cin >> name;
            history(m, name);
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

// Function to add a new member to the group
void add_member(vector<member> &m, string name)
{
    // Create a new member and add them to the vector
    member new_member;
    new_member.name = name;
    new_member.expenses = 0;
    new_member.debt = 0;
    m.push_back(new_member);
}

void add_expenses(vector<member> &m, string name, double amount)
{
    double per_person_cost = amount / m.size();
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i].name == name)
        {
            m[i].expenses += amount;
            m[i].expenses_history.push_back(amount);
        }
        else
        {
            m[i].debt += per_person_cost;
            m[i].debt_history.push_back(per_person_cost);
        }
    }
}

void net_balance(vector<member> &m, string name)
{
    double balance = 0;
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i].name == name)
        {
            balance -= m[i].debt;
        }
        else
        {
            for (int j = 0; j < m[i].debt_history.size(); j++)
            {
                if (m[i].debt_history[j] > 0 && m[i].debt_history[j] <= m[i].debt)
                {
                    balance += m[i].debt_history[j];
                    m[i].debt -= m[i].debt_history[j];
                }
            }
        }
    }
    cout << "Net balance for " << name << " is " << balance << endl;
}

 void history(vector<member> & m, string name)
                    {
                        for (int i = 0; i < m.size(); i++)
                        {
                            if (m[i].name == name)
                            {
                                cout << "Expense history for " << name << ":" << endl;
                                for (int j = 0; j < m[i].expenses_history.size(); j++)
                                {
                                    cout << "Expense " << j + 1 << ": " << m[i].expenses_history[j] << endl;
                                }
                                cout << endl;
                                cout << "Debt history for " << name << ":" << endl;
                                for (int j = 0; j < m[i].debt_history.size(); j++)
                                {
                                    cout << "Debt " << j + 1 << ": " << m[i].debt_history[j] << endl;
                                }
                                return;
                            }
                        }
                        cout << "Member not found." << endl;
                    }

// When i add second expense of any member.. program is not adding their expense and not even counting that as an expense or subtracting debt from others.
