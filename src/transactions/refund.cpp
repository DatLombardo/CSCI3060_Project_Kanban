/*
Kanban
refund.cpp
*/

#include "refund.hpp"

/*
Refund - Refund
General constructor, gets input to create new auction.
@params: User user
@return: None
*/
Refund::Refund(User user){
	Refund::ReadUsernames();

	//Check if user is admin

	std::cout << "Buyer Name: ";
	std::cin >> this->buyer;

  	std::cout << "Seller Name: ";
  	std::cin  >> this->seller;

	//Check if both buyer and seller exist

	std::cout << "Credit: ";
 	std::cin  >> this->credit;

	//Check if credit exists in seller's balance

	//Call in main
	//Refund::ParseRequest();
}

/*
Refund - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string Refund::ParseRequest(){
	// TODO: Generate daily transaction file object for current refund
	//			 transaction.

	return "test";
}

/*
Refund - ReadUsernames
Read current user accounts file, store user list within userList
@params: None
@return: None
*/
void Refund::ReadUsernames() {
	// TODO: Need to read username list
		//File read in, store into array variable.
	this->userList = {"test"};
}

/*
Refund - Exists
Iterate through userList, determine if a match is found
@params: testName
@return: boolean
*/
bool Refund::Exists(std::string testName) {
	for (int i = 0; i < this->userList.size(); i++) {
		if (testName == this->userList[i]) {
			return true;
		}
	}
	return false;
}
