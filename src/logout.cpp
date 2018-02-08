/*
Kanban
logout.cpp
*/
#include <iostream>
#include "logout.hpp"

using namespace std;

/*
Logout - Logout
General constructor, prompts user for logout and calls daily transaction writing.
@params: user, transactionList
@return:
*/
string Logout::Logout(User user) {

	cout << "Logging out: " << user.username << endl;
	return this.ParseRequest(user);
}

string Logout::ParseRequest(User user){
	// TODO: Generate daily transaction file object for current logout
	return "test";
}
