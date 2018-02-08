/*
Kanban
delete.cpp
*/
#include <iostream>
#include "delete.hpp"

using namespace std;

/*
Delete - Delete
General constructor, deletes user specified by admin.
@params: None
@return: None
*/
string Delete::Delete(User user){
	cout << "Username: ";
	getline(cin, this.username);

	this.CancelSales();
	this.RemoveUser();
	cout << "Account " << this.username  << " Deleted." << endl;
	return this.ParseRequest();
}

/*
Delete - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
string Delete::ParseRequest(){
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
