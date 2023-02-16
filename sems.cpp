#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

struct owing {
    string member_name; 
    double owe_amount;
    int paying_id;
    string paying_name;
    double paying_amount;
};

struct member {
    string name;
    double amount;
    vector<owing> owe;
};

void add_members(vector<member> &m);
void add_expenses(vector<member> &m);
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
        
        double share = amount / m.size();
        vector<owing> d_owe(m.size());
        for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
            int index = it - m.begin();
            if (it->name == payer_name) {
                for(int j=0; j<m.size(); j++) {
                    if (m[j].name == payer_name) {
                       // m[j].owe[j].paying_amount -= share;
                    }else{

                        d_owe[j].paying_id = j;
                        d_owe[j].paying_name = payer_name;
                        d_owe[j].paying_amount = share;
                        m[j].owe.push_back(d_owe[j]);

                        
                        d_owe[j].member_name = m[j].name;
                        d_owe[j].owe_amount += share;
                        it->owe.push_back(d_owe[j]);                       
                    }
                }
            }
        }
    }
}




void read_user(vector<member> &m, string user) {
    cout << "Names" << "     " << "Amount" << "\n";
     for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->name == user) {
            int index = it - m.begin();
            for (std::vector<owing>::iterator itr = m[index].owe.begin(); itr != m[index].owe.end(); itr++){
                cout << "members owing me owing details\n";
                cout << itr->member_name << "       " << itr->owe_amount << "\n";
            }
        }
    }
}