#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void addMember(vector<string>& members, vector<vector<float>>& expenses);
void addExpense(vector<string>& members, vector<vector<float>>& expenses);
void printExpenses(vector<string>& members, vector<vector<float>>& expenses);
void calculateDebts(vector<string>& members, vector<vector<float>>& expenses);

int main() {
    vector<string> members;
    vector<vector<float>> expenses;

    int choice;
    do {
        cout << "\n1. Add member" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Show expenses" << endl;
        cout << "4. Calculate debts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
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
    } while(choice != 5);

    return 0;
}

void addMember(vector<string>& members, vector<vector<float>>& expenses) {
    string name;
    cout << "Enter member name: ";
    cin >> name;
    members.push_back(name);

    // Initialize the expenses vector for the new member
    vector<float> newExpenses(members.size(), 0);
    expenses.push_back(newExpenses);

    cout << "Member added successfully." << endl;
}

void addExpense(vector<string>& members, vector<vector<float>>& expenses) {
    if(members.empty()) {
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
    for(int i = 0; i < members.size(); i++) {
        if(members[i] == payer) {
            payerIndex = i;
            break;
        }
    }
    if(payerIndex == -1) {
        cout << "Invalid member name. Please try again." << endl;
        return;
    }

    // Divide the expense equally among all members
    float perPersonAmount = amount / members.size();
    for(int i = 0; i < members.size(); i++) {
        if(i == payerIndex) {
            expenses[payerIndex][i] += perPersonAmount;
        } else {
            expenses[i][payerIndex] -= perPersonAmount;
        }
    }

    cout << "Expense added successfully." << endl;
}

void printExpenses(vector<string>& members, vector<vector<float>>&expenses) {
    if(members.empty()) {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    // Print the header row
    cout << "    ";
    // Print the names of the members as the header row
for(int i = 0; i < members.size(); i++) {
cout << members[i] << " ";
}
cout << endl;// Print the expenses for each member
for(int i = 0; i < members.size(); i++) {
    cout << members[i] << "  ";
    for(int j = 0; j < members.size(); j++) {
        cout << expenses[i][j] << "  ";
    }
    cout << endl;
}
}

void calculateDebts(vector<string>& members, vector<vector<float>>& expenses) {
if(members.empty()) {
cout << "No members found. Please add a member first." << endl;
return;
}// Calculate the total balance for each member
vector<float> balances(members.size(), 0);
for(int i = 0; i < members.size(); i++) {
    for(int j = 0; j < members.size(); j++) {
        balances[i] += expenses[i][j];
    }
}

// Find the members who owe money and the members who are owed money
vector<int> debtors;
vector<int> creditors;
for(int i = 0; i < balances.size(); i++) {
    if(balances[i] > 0) {
        creditors.push_back(i);
    } else if(balances[i] < 0) {
        debtors.push_back(i);
    }
}

// Calculate the amount owed by each debtor to each creditor
vector<vector<float>> debts(debtors.size(), vector<float>(creditors.size(), 0));
for(int i = 0; i < debtors.size(); i++) {
    for(int j = 0; j < creditors.size(); j++) {
        if(balances[debtors[i]] + balances[creditors[j]] > 0) {
            debts[i][j] = -balances[debtors[i]];
            balances[creditors[j]] += balances[debtors[i]];
            balances[debtors[i]] = 0;
        } else {
            debts[i][j] = balances[creditors[j]];
            balances[debtors[i]] += balances[creditors[j]];
            balances[creditors[j]] = 0;
        }
    }
}

// Print the debts
for(int i = 0; i < debtors.size(); i++) {
    cout << members[debtors[i]] << " owes:" << endl;
    for(int j = 0; j < creditors.size(); j++) {
        if(debts[i][j] != 0) {
            cout << "  " << members[creditors[j]] << ": $" << debts[i][j] << endl;
        }
    }
}
}
