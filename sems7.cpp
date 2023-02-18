#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Member {
    string name;
    float balance;
};

vector<Member> members;

void addMember(string name) {
    Member m = { name, 0 };
    members.push_back(m);
    cout << "Added member: " << name << endl;
}

void showMembers() {
    cout << "Members:" << endl;
    for (int i = 0; i < members.size(); i++) {
        cout << i+1 << ". " << members[i].name << endl;
    }
}

void addExpense(float amount, string payer) {
    int numMembers = members.size();
    float splitAmount = amount / numMembers;
    for (int i = 0; i < numMembers; i++) {
        if (members[i].name != payer) {
            members[i].balance += splitAmount;
        }
    }
    cout << "Added expense of " << amount << " paid by " << payer << endl;
}

void calculateNetBalance() {
    int numMembers = members.size();
    for (int i = 0; i < numMembers; i++) {
        for (int j = 0; j < numMembers; j++) {
            if (i != j) {
                float amountOwed = members[j].balance - members[i].balance;
                if (amountOwed > 0) {
                    cout << members[i].name << " owes " << amountOwed << " to " << members[j].name << endl;
                    members[i].balance += amountOwed;
                    members[j].balance -= amountOwed;
                }
            }
        }
    }
}

void showExpenses() {
    ofstream outFile("expenses.txt");
    outFile << "Expense history:" << endl;
    for (int i = 0; i < members.size(); i++) {
        outFile << members[i].name << ": " << members[i].balance << endl;
    }
    outFile.close();

    cout << "Expense history:" << endl;
    for (int i = 0; i < members.size(); i++) {
        cout << members[i].name << ": " << members[i].balance << endl;
    }
}

int main() {
    addMember("Member 1");
    addMember("Member 2");
    addMember("Member 3");
    addMember("Member 4");

    showMembers();

    addExpense(200, "Member 1");
    addExpense(80, "Member 2");

    calculateNetBalance();

    showExpenses();

    return 0;
}
