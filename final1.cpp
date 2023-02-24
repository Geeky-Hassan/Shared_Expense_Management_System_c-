#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void addMember(vector<string>& members, vector<vector<float>>& expenses);
void addExpense(vector<string>& members, vector<vector<float>>& expenses);
void printExpenses(vector<string>& members, vector<vector<float>>& expenses);
void calculatePayables(vector<string>& members, vector<vector<float>>& expenses);

int main() {
    vector<string> members;
    vector<vector<float>> expenses;

    int choice;
    do {
        cout << "\n1. Add member" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Show expenses" << endl;
        cout << "4. Calculate payables" << endl;
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
                calculatePayables(members, expenses);
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
    vector<float> newExpenses;
    for(int i = 0; i < members.size() - 1; i++) {
        newExpenses.push_back(0);
        expenses[i].push_back(0);
    }
    newExpenses.push_back(0);
    expenses.push_back(newExpenses);

    cout << "Member added successfully." << endl;
}

void addExpense(vector<string>& members, vector<vector<float>>& expenses) {
    if(members.empty()) {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    // Prompt user for member names
    string payer, payee;
    cout << "Enter name of payer: ";
    cin >> payer;
    cout << "Enter name of payee: ";
    cin >> payee;

    // Find the indexes of the payer and payee in the members vector
    int payerIndex = -1, payeeIndex = -1;
    for(int i = 0; i < members.size(); i++) {
        if(members[i] == payer) {
            payerIndex = i;
        }
        if(members[i] == payee) {
            payeeIndex = i;
        }
    }
    if(payerIndex == -1 || payeeIndex == -1) {
        cout << "Invalid member names. Please try again." << endl;
        return;
    }

    // Prompt user for expense amount
    float amount;
    cout << "Enter expense amount: ";
    cin >> amount;

    // Update the expenses matrix
    expenses[payerIndex][payeeIndex] += amount;
    expenses[payeeIndex][payerIndex] -= amount;

    cout << "Expense added successfully." << endl;
}

void printExpenses(vector<string>& members, vector<vector<float>>&expenses) {
if(members.empty()) {
cout << "No members found." << endl;
return;
}// Print the expenses matrix
cout << "Expenses:" << endl;
for(int i = 0; i < members.size(); i++) {
    cout << members[i] << ":\t";
    for(int j = 0; j < members.size(); j++) {
        cout << expenses[i][j] << "\t";
    }
    cout << endl;
}
}

void calculatePayables(vector<string>& members, vector<vector<float>>& expenses) {
if(members.empty()) {
cout << "No members found. Please add a member first." << endl;
return;
}// Calculate the total expenses for each member
vector<float> totalExpenses(members.size(), 0);
for(int i = 0; i < members.size(); i++) {
    for(int j = 0; j < members.size(); j++) {
        totalExpenses[i] += expenses[i][j];
    }
}

// Calculate the average expense per member
float total = 0;
for(int i = 0; i < members.size(); i++) {
    total += totalExpenses[i];
}
float average = total / members.size();

// Calculate the payable amount for each member
vector<float> payables(members.size(), 0);
for(int i = 0; i < members.size(); i++) {
    payables[i] = totalExpenses[i] - average;
}

// Adjust the payable amount for each member against every other member
for(int i = 0; i < members.size(); i++) {
    for(int j = 0; j < members.size(); j++) {
        if(i != j) {
            float amount = payables[j] / (members.size() - 1);
            if(expenses[i][j] > 0) {
                amount -= expenses[i][j];
            }
            payables[i] -= amount;
            payables[j] += amount;
        }
    }
}

// Print the payable amount for each member
cout << "Payable amounts:" << endl;
for(int i = 0; i < members.size(); i++) {
    cout << members[i] << ":\t" << payables[i] << endl;
}
}
