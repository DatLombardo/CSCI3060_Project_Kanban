/*
Kanban
create.cpp
*/
#include "create.hpp"

/*
Create - Create
General constructor, gets input from admin to create user.
@params: None
@return: string of daily transaction file request
*/
Create::Create(User user){
	std::cout << "Username: ";
	std::cin >> this->username;

	std::cout << "Account Type: ";
	std::cin >> this->type;

	std::cout << "Credit: ";
	std::cin >> this->credit;

	// TODO: Error checking for all input

	std::cout << "Account Created." << std::endl;
	//Call in main
	//Create::ParseRequest(user);
	
}

/*
Create - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string Create::ParseRequest(){
	// TODO: Generate daily transaction file object for current create
	//			 transaction.
	return "test";
}

/*
Create - ReadUsernames
Read current user accounts file, store user list within userList
@params: None
@return: None
*/
void Create::ReadUsernames() {
	// TODO: Need to read username list
		//File read in, store into array variable.
	this->userList = {"test"};
}

/*
Create - Exists
Iterate through userList, determine if a match is found
@params: testName
@return: boolean
*/
bool Create::Exists(std::string testName) {

	for (int i = 0; i < this->userList.size(); i++) {
		if (testName == this->userList[i]) {
			return true;
		}
	}
	return false;
}
