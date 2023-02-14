#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct owing {
    string member_name; 
    double owe_amount;
};

struct member {
    string name;
    double amount;
    vector<owing> owe;
};

void add_members(vector<member> &m);
void add_expenses(vector<member> &m);
//void do_expenses(vector<member> &m, string payer_name, double amount, int num_expenses);
void read_user(vector<member> &m, string user);
//void net_balance(vector<member> &m);

int main() {
    int num;
    cout << "How many members would you like to add\n";
    cin >> num;
    vector<member> m(num);
    
    add_members(m);
    add_expenses(m);

    string user;
    cout << "which user expenses would like to see\n";
    cin >> user;

    read_user(m, user);
}


void add_members(vector<member> &m) {
    int checker = m.size();
    int counter = 0;
    cout << "Enter member names (click Enter when you are done):\n";
        while (true){
            if (checker == 0) {
               break;
            }
            cout << "Member " << counter+ 1 << ": ";
            cin >> m[counter].name;

            counter += 1;
            checker -= 1;
        }
}


void add_expenses(vector<member> &m) {
    int num_expenses;
    string payer_name;
    double amount;

    cout << "How many expenses would you like to add\n";
    cin >> num_expenses;
    for (int i=0; i<num_expenses; i++) {
        cout << "Enter Payer Name" << "(" << i+1 << ")\n";
        cin >> payer_name;
        cout << "Enter Payer Amount" << "(" << i+1 << ")\n";
        cin >> amount;

        //do_expenses(m, payer_name, amount, num_expenses);
    double share = amount / m.size();
    int length = m.size();

    //cout << length << "\n";


    vector<owing> owe(num_expenses);
    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {

        int index = it - m.begin();

        if (it->name == payer_name) {
            for(int j=0; j<num_expenses-1; j++) {
                //it[index].owe[j].owe_amount += share;
                owe[j].owe_amount += share;

                if (m[j].name == payer_name) {
                    continue;
                }

                owe[j].member_name = m[j].name;
                //owe[j].owe_amount += share;
                //it[index].owe[j].member_name = m[j].name;

                it->owe.push_back(owe[j]);
            }
        }  

    }
    }
}




void read_user(vector<member> &m, string user) {
     for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->name << "\n";
        cout << it->amount << "\n";
        //cout << it->owe[0].owe_amount << "\n";
        if (it->name == user) {
            int index = it - m.begin();
            for (std::vector<owing>::iterator itr = m[index].owe.begin(); itr != m[index].owe.end(); itr++){
                cout << m[index].name;
                cout << "==========================\n";
                cout << itr->member_name << "\n";
                cout << itr->owe_amount << "\n";
                cout << "==========================\n";
            }
        }
    }
}



/*

void do_expenses(vector<member> &m, string payer_name, double amount, int num_expenses) {

    double share = amount / m.size();
    int length = m.size();

    cout << length << "\n";


    vector<owing> owe(num_expenses);
    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {

        int index = it - m.begin();

        if (it->name == payer_name) {
            for(int j=0; j<length; j++) {
                //it[index].owe[j].owe_amount += share;
                owe[j].owe_amount += share;

                if (m[j].name == payer_name) {
                    continue;
                }

                owe[j].member_name = m[j].name;
                //owe[j].owe_amount += share;
                //it[index].owe[j].member_name = m[j].name;

                it->owe.push_back(owe[j]);
            }
        }  

    }

    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->name << "\n";
        cout << it->amount << "\n";
        //cout << it->owe[0].owe_amount << "\n";
        if (it->name == "ade") {
            int index = it - m.begin();
            for (std::vector<owing>::iterator itr = m[index].owe.begin(); itr != m[index].owe.end(); itr++){
                cout << m[index].name;
                cout << "==========================\n";
                cout << itr->member_name << "\n";
                cout << itr->owe_amount << "\n";
                cout << "==========================\n";
            }
        }
    }

*/

/*
void net_balance(vector<member> m) {
    //cout << m;
}7


for (std::vector<owing>::iterator itr = m[index].owe.begin(); itr != m[index].owe.end(); itr++){
                int i_index = itr - m[index].owe.begin();

                owe[i_index].member_name = itr[i_index].member_name;
                owe[i_index].owe_amount += share;

                it->owe = owe;
            }

*/
