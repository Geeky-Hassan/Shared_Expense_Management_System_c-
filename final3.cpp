#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void addMember(vector<string> &members, vector<vector<float>> &expenses);
void addExpense(vector<string> &members, vector<vector<float>> &expenses);
void printExpenses(vector<string> &members, vector<vector<float>> &expenses);
void calculateDebts(vector<string> &members, vector<vector<float>> &expenses);

int main()
{
    vector<string> members;
    vector<vector<float>> expenses;

    int choice;
    do
    {
        cout << "\n1. Add member" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Show expenses" << endl;
        cout << "4. Calculate debts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addMember(members, expenses);
            break;
        case 2:
            addExpense(members, expenses);
            break;
        case 3:
            printExpenses(members, expenses);
            break;
        case 4:
            calculateDebts(members, expenses);
            break;
        case 5:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}

void addMember(vector<string> &members, vector<vector<float>> &expenses)
{
    string name;
    cout << "Enter member name: ";
    cin >> name;
    members.push_back(name);

    // Initialize the expenses vector for the new member
    vector<float> newExpenses(members.size(), 0);
    expenses.push_back(newExpenses);

    // set the values for the previous rows as new columns are generated
    for (int i = 0; i < members.size() - 1; i++)
    {
        expenses[i][members.size() - 1] = 0;
    }

    cout << "Member added successfully." << endl;
}

void addExpense(vector<string> &members, vector<vector<float>> &expenses)
{
    if (members.empty())
    {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    // Prompt user for payer and expense amount
    string payer;
    float amount;
    cout << "Enter name of payer: ";
    cin >> payer;
    cout << "Enter expense amount: ";
    cin >> amount;

    // Find the index of the payer in the members vector
    int payerIndex = -1;
    for (int i = 0; i < members.size(); i++)
    {
        if (members[i] == payer)
        {
            payerIndex = i;
            break;
        }
    }
    if (payerIndex == -1)
    {
        cout << "Invalid member name. Please try again." << endl;
        return;
    }

    // Divide the expense equally among all members
    float perPersonAmount = amount / members.size();
    for (int i = 0; i < members.size(); i++)
    {
        if (i == payerIndex)
        {
            // expenses[payerIndex][i] += perPersonAmount; //wrong. You can't owe money to yourself
            continue;
        }
        else
        {
            expenses[i][payerIndex] -= perPersonAmount; 
            expenses[payerIndex][i] += perPersonAmount; 
        }
    }

    cout << "Expense added successfully." << endl;
}

void printExpenses(vector<string> &members, vector<vector<float>> &expenses)
{
    if (members.empty())
    {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    // Print the header row
    cout << "    ";
    // Print the names of the members as the header row
    for (int i = 0; i < members.size(); i++)
    {
        cout << members[i] << " ";
    }
    cout << endl; // Print the expenses for each member
//     for (int i = 0; i < members.size(); i++)
//     {
//         cout << members[i] << "  ";
//         for (int j = 0; j < members.size(); j++)
//         {
//             cout << expenses[i][j] << "  ";
//         }
//         cout << endl;
//     }
// }

void calculateDebts(vector<string> &members, vector<vector<float>> &expenses)
{
    if (members.empty())
    {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    for (int i = 0; i < members.size(); i++)
    {
        cout<<members[i]<<" owes:"<<endl;
        for(int j = 0; j < members.size(); j++)
        {
            if(expenses[i][j] < 0)
            {
                cout<<"\t"<<members[j]<<": "<<-expenses[i][j]<<endl;
            }
        }
    }
    
}
