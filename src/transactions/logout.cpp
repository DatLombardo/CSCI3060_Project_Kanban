/*
Kanban
logout.cpp
*/
#include "logout.hpp"

/*
Logout - Logout
General constructor, prompts user for logout and calls daily transaction writing.
@params: user, transactionList
@return:
*/
Logout::Logout(User user) {

	std::cout << "Logging out: " << user.username << std::endl;
	//Call in main
	//Logout::ParseRequest(user);
}

std::string Logout::ParseRequest(User user){
	// TODO: Generate daily transaction file object for current logout
	return "test";
}
