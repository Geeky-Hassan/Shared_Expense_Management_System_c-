#ifndef EXPENSE_BALANCER_H_INCLUDED
#define EXPENSE_BALANCER_H_INCLUDED

#include <map>
#include <ostream>
#include <string>

void print_balances(const std::map<std::string, double>& members,
                    std::ostream& os);

#endif // EXPENSE_BLANCER_H_INCLUDED
