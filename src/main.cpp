/*
    Kanban

    This c++ file will control the main input loop, and
    deal with User input appropriately.
*/

#include <iostream>
#include <vector>
#include "transaction.cpp"

void main() {
    std::cout << "Welcome to TerribleAuction\nBy: Kanban Group™\n" << std::endl;

    bool loggedIn = false;
    User currentUser = null;

    std::vector<Transaction> transactions;

    while (true) {
        std::string UserInput;

        std::cout << "Please enter a transaction code: ";
        std::cin >> UserInput;

        if (UserInput == "logout" && loggedIn) {
            // User has chose to logout, write transactions to appropriate file(s)

            fileout f = new Fileout();

            tranasctions.append(Transaction(UserInput));
            f.writetransactions(transactions);

        } else if (loggedIn) {
            Transaction t = Transaction(UserInput, currentUser); // transaction data input lookp

            if (t.valid)
                transactions.append(t);
            else
                continue; // transaction failed; class will print error
        } else {
            if (UserInput == "login") {
                Transaction t = Transaction(UserInput);

                loggedIn = true;
                User = t.currentUser;

                transactions.append(t);
            } else {
                std::cout << "Error: please login before attempting other transaction" << std::endl;
            }

        }
    }

}
