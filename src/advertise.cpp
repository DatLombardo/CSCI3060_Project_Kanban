/*
Kanban
advertise.cpp
*/
#include <iostream>
#include "advertise.hpp"

using namespace std;

/*
Advertise - Advertise
General constructor, gets input to create new auction.
@params: user
@return: None
*/
string Advertise::Advertise(User user){
	this.ReadAuctions();

	cout << "Item Name: ";
	getline(cin, this.itemName);

	//FillItemName used for Exists function

	cout << "Minimum Bid: ";
	getline(cin, this.minBid);

	cout << "Auction Length (Days): ";
	getline(cin, this.auctionLength);

	// TODO: Error checking for all input

	cout << this.itemName << " is up for auction!" << endl;

	return this.ParseRequest(user);
}

/*
Advertise - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
string Advertise::ParseRequest(User user){
	// TODO: Generate daily transaction file object for current advertise
	//			 transaction.
	return "test";
}

/*
Advertise - FillItemName
Parse item name inputted by user to meet system's item name and formatting requirements
@params: itemName
@return: String value of 'itemName' + remaining filled space
*/
string Advertise::FillItemName(string itemName) {

	// TODO: Check length of username, add required amount of _'s to equal 15.

	return itemName;
}


/*
Advertise - ReadAuctions
Read availiable items file, store item list within itemList
@params: None
@return: None
*/
void Advertise::ReadAuctions() {
	// TODO: Need to read item list

	this.itemList = {"test"};
}

/*
Advertise - Exists
Iterate through itemList, determine if a match is found
@params: testName
@return: boolean
*/
bool Advertise::Exists(string testName) {
	for (int i = 0; i < this.itemList.size(); i++) {
		if (testName == this.itemList[i]) {
			return true;
		}
	}
	return false;
}
