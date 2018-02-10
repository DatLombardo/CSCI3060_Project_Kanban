/*
Kanban
addcredit.cpp
*/

#include "addcredit.hpp"

/*
AddCredit - AddCredit
General constructor, gets input for add credit transaction.
@params: User user
@return: None
*/
AddCredit::AddCredit(User user){
	AddCredit::ReadUsernames();

	//Check if user is admin
	std::string testInput = "admin";

	if (testInput == "admin"){
		std::cout << "Username: ";
		std::cin >> this->username;
	}

	std::cout << "Credit: ";
  	std::cin  >> this->credit;

	//Call in main
	//AddCredit::ParseRequest(user);
}

/*
AddCredit - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string AddCredit::ParseRequest(){
	// TODO: Generate daily transaction file object for current refund
	//			 transaction.

	return "test";
}


/*
AddCredit - ReadUsernames
Read current user accounts file, store user list within userList
@params: None
@return: None
*/
void AddCredit::ReadUsernames() {
	// TODO: Need to read username list
		//File read in, store into array variable.
	this->userList = {"test"};
}

/*
AddCredit - Exists
Iterate through userList, determine if a match is found
@params: testName
@return: boolean
*/
bool AddCredit::Exists(std::string testName) {
	for (int i = 0; i < this->userList.size(); i++) {
		if (testName == this->userList[i]) {
			return true;
		}
	}
	return false;
}
