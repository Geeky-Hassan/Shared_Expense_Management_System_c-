# Shared_Expense_Management_System_c++
# Description
The task consists of programming a C++ implementation of an application that split the expenses of
multiple users.
# The functionalities of SEMS
## 1- Adding Members
The initial task is to add a number of members with their names and show all members when
requested.
**Example:** There are 4 members with the name Member 1, Member 2, Member 3, and Member 4 you
need to add them to your members’ array.
## 2 - Adding Expenses
You need to implement a functionality that takes the input from the user in the form of float
(expense amount) and string (Payer Name), divides it equally between each member, and adds the
amount to each member’s balance to pay the payer except the payer itself. You can add expenses as
much as you like.
**Example**: if Member 1 pays 200 Rs it will be divided by the total number of members so in above
discussed scenario it will be divided by 4 and each member will have to pay 50 Rs to Member 1;
therefore, 50 Rs will be added into the balance sheet of each member against Member 1
## 3- Calculate Net Balance
You need to adjust the payable amount of each member against every other member. If there is a
liability on any member it’ll be adjusted.
**Example:** if Member 2 pays 80 Rs it’ll add 20 to each other member except Member 1 as Member 2
is already responsible to pay 50 Rs to Member 1; hence Member 2 will have to pay 30 (50 – 20) to
Member 1 but Member 3 and 4 need to pay 70 overs 50 to Member 1 and 20 to Member 2
respectively. Whereas Member 1 needs to collect 50 from Member 3 and Member 4 and 30 from
Member 2, likewise Member 2 needs to collect 20 from Member 3 and Member 4 while he has to
pay 30 to Member 1. Members 3 and Member 4 have to pay 20 and 50 to Member 1 and Member 2
Respectively.2
## 4- Expense History
At the end of each month, the application will show the overall expenses of each member and store
the history in a file. You need to retrieve the file to show expenses.
**Example:** This will show the total payable expenses or you can say the balance of each person
against all other members separately

# Expected Output:
![pf project output](https://user-images.githubusercontent.com/93768672/218338108-589658be-606d-44e9-819a-2fffc0b79cf0.png)

# My Thoughts:
I have coded first 3 parts but can't able to get desired result.. You can check my code and fork the repo/commit it.
