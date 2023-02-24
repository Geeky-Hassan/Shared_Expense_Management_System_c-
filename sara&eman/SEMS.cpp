#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Member {
    string name;
    vector<float> expenses;
};

// Function prototypes
void addMember(vector<Member>& members);
void addExpense(vector<Member>& members);
void printExpenses(vector<Member>& members);

int main() {
    vector<Member> members;

    int choice;
    do {
        cout << "\n1. Add member" << endl;
        cout << "2. Add expense" << endl;
        cout << "3. Show expenses" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addMember(members);
                break;
            case 2:
                addExpense(members);
                break;
            case 3:
                printExpenses(members);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while(choice != 4);

    return 0;
}

void addMember(vector<Member>& members) {
    Member newMember;
    cout << "Enter member name: ";
    cin.ignore(); // ignore the newline character left in the stream by cin
    getline(cin, newMember.name);
    members.push_back(newMember);
    cout << "Member added successfully." << endl;
}

void addExpense(vector<Member>& members) {
    if(members.empty()) {
        cout << "No members found. Please add a member first." << endl;
        return;
    }

    // Prompt user for member name
    cout << "Select a member:" << endl;
    for(int i = 0; i < members.size(); i++) {
        cout << i+1 << ". " << members[i].name << endl;
    }
    int choice;
    cin >> choice;

    if(choice < 1 || choice > members.size()) {
        cout << "Invalid choice. Please enter a number between 1 and " << members.size() << "." << endl;
        return;
    }

    // Prompt user for expense amount
    float amount;
    cout << "Enter expense amount: ";
    while(!(cin >> amount)) {
        cout << "Invalid input. Please enter a valid expense amount: ";
        cin.clear();
        cin.ignore(10000, '\n'); // ignore up to 10000 characters or until a newline is encountered
    }

    members[choice-1].expenses.push_back(amount);
    cout << "Expense added successfully." << endl;
}

void printExpenses(vector<Member>& members) {
    if(members.empty()) {
        cout << "No members found." << endl;
        return;
    }

    for(int i = 0; i < members.size(); i++) {
        cout << members[i].name << ": ";
        if(members[i].expenses.empty()) {
            cout << "No expenses found." << endl;
        } else {
            for(int j = 0; j < members[i].expenses.size(); j++) {
                cout << members[i].expenses[j] << " ";
            }
            cout << endl;
        }
    }
}
// Enter the error handling. 
