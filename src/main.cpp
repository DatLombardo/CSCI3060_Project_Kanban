/*
    Kanban

    This c++ file will control the main input loop, and
    deal with user input appropriately.
*/

#include <iostream>
#include <vector>

void main() {
    std::cout << "Welcome to TerribleAuction\nBy: Kanban Group™\n" << std::endl;
    
    bool loggedIn = false;
    user currentUser = null;
    
    std::vector<transaction> transactions;
    
    while (true) {
        std::string userInput;

        std::cout << "Please enter a transaction code: ";
        std::cin >> userInput;
        
        if (loggedIn) {
            transaction t = transaction(userInput, currentUser); // transaction data input lookp
            
            if (t.valid)
                transactions.append(t);
            else
                continue; // transaction failed; class will print error
        } else if (userInput == "logout" && loggedIn) {
            // user has chose to logout, write transactions to appropriate file(s)
            
            fileout f = new fileout();
            
            tranasctions.append(transaction(userInput));
            f.writetransactions(transactions);
        
        } else {
            if (userInput == "login") {
                transaction t = transaction(userInput);
                
                loggedIn = true;
                user = t.currentUser;
            } else {
                std::cout << "Error: please login before attempting other transaction" << std::endl;
            }
            
        }
    }

}
