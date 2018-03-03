/*
    Kanban

    This c++ file will control the main input loop, and
    deal with User input appropriately.
*/

#include <iostream>
#include <vector>
#include "transaction.hpp"
#include "parser.hpp"
#include "fileout.hpp"
#include "item.hpp"
#include "user.hpp"

int main() {
    std::cout << "Welcome to TerribleAuction\nBy: Kanban Group™\n" << std::endl;

    bool loggedIn = false;
    User* currentUser = nullptr;

    std::vector<Transaction> transactions;

    Parser p = Parser();
    std::map<std::string, User> userList = p.ReadCurrentUsers("output/data/userlist.txt");
    std::map<std::string, Item> itemList = p.ReadAvailItems("output/data/itemlist.txt");

    while (true) {
        std::string userInput;

        std::cout << "Please enter a transaction code: ";
        std::cin >> userInput;

        if (userInput == "logout" && loggedIn) {
            // User has chose to logout, write transactions to appropriate file(s)

            Fileout f = Fileout();

            transactions.push_back(Transaction(userInput, *currentUser, userList, itemList));
            f.writeTransactions(transactions);

            return 1;

        } else if (loggedIn) {
            Transaction t = Transaction(userInput, *currentUser, userList, itemList); // transaction data input lookp

            if (t.valid)
                transactions.push_back(t);
            else
                continue; // transaction failed; class will print error
        } else {
            if (userInput == "login") {
                Transaction t = Transaction(userInput, userList);

                loggedIn = true;
                currentUser = &t.currentUser;

                transactions.push_back(t);
            } else {
                std::cout << "Error: please login before attempting other transaction" << std::endl;
            }

        }
    }

    return 0;
}
