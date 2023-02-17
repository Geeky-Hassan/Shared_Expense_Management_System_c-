#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

struct member {
    std::string name;
    double expenses;
    double gbese;
    //double balance;
};

void add_member(std::vector<member> &m, std::string name);
void add_expenses(std::vector<member> &m, std::string name, double amount);
void net_balance(std::vector<member> &m, std::string name, double amount, int num_member);
void history(std::vector<member> &m, std::string name);

int main() {
    std::vector<member> m;

    add_member(m, "sam");
    add_member(m, "tom");
    add_member(m, "bob");
    add_member(m, "jack");
    add_expenses(m, "sam", 14);
    add_expenses(m, "tom", 2);
    add_expenses(m, "jack", 10);
    add_expenses(m, "bob", 12);
    history(m, "bob");
}

void add_member(std::vector<member> &m, std::string name){
    member mb = {name, 0.0, 0.0};
    m.push_back(mb);
}

void add_expenses(std::vector<member> &m, std::string name, double amount) {
    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->name == name) {
            it->expenses += amount;
            net_balance(m, name, it->expenses, 4);
        }
    }
}

void net_balance(std::vector<member> &m, std::string name, double amount, int num_member) {
    double share = amount / num_member;
    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->name == name) {
            if (it->gbese != 0) {
                double expenses = it->gbese;

                double temp = 0;
                it->gbese -= it->expenses;
                if (it->gbese <= 0) {
                    it->gbese = temp;
                }  

                it->expenses -= it->gbese;
                if (it->expenses > 0) {
                    double sh = it->expenses / num_member;
                    for (int i=0; i<m.size(); i++) {
                        if (m[i].name != it->name) {
                            m[i].gbese += sh;
                        }
                    }
                }  

            }

            for (int i=0; i<m.size(); i++) {
                if (m[i].name != name) {
                    m[i].gbese += share;
                }
            }
        }
    }
}

void history(std::vector<member> &m, std::string name) {
    for (std::vector<member>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->name == name){
            std::cout << it->gbese << "\n";
        }
    }
}