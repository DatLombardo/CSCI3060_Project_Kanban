/*
Kanban
delete.cpp
*/
#include <iostream>
#include <string>
#include "delete.hpp"

/*
Delete - Delete
General constructor, deletes user specified by admin.
@params: None
@return: None
*/
Delete::Delete(User user){
	std::cout << "Username: " << std::endl;
	std::cin >> this->username;

	Delete::CancelSales();
	Delete::RemoveUser();
	std::cout << "Account " << this->username  << " Deleted." << std::endl;
	//Call in main
	//Delete::ParseRequest();
}

/*
Delete - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string Delete::ParseRequest(){
	// TODO: Generate daily transaction file object for current create
	//			 transaction.
	return "test";
}

/*
Delete - CancelSales
Remove all outstanding items for sale
@params: None
@return: None
*/
void Delete::CancelSales() {
	// TODO: Delete all of the desired user's outstanding items

}

/*
Delete - RemoveUser
Delete user from the current user accounts file.
@params: None
@return: None
*/
void Delete::RemoveUser() {
	// TODO: Delete user
}
