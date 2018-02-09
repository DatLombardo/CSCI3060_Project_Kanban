/*
Kanban
advertise.cpp
*/
#include "advertise.hpp"

/*
Advertise - Advertise
General constructor, gets input to create new auction.
@params: user
@return: None
*/
Advertise::Advertise(User user){
	Advertise::ReadAuctions();

	std::cout << "Item Name: ";
	std::cin >> this->itemName;

	//FillItemName used for Exists function

	std::cout << "Minimum Bid: ";
	std::cin >> this->minBid;

	std::cout << "Auction Length (Days): ";
	std::cin >> this->auctionLength;

	// TODO: Error checking for all input

	std::cout << this->itemName << " is up for auction!" << std::endl;

	//Call in main
	//Advertise::ParseRequest(user);
}

/*
Advertise - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string Advertise::ParseRequest(User user){
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
std::string Advertise::FillItemName(std::string itemName) {

	// TODO: Check length of username, add required amount of _'s to equal 15.

	return itemName;
}


/*
Advertise - ReadAuctions
Read availiable items file, store item list within auctionList
@params: None
@return: None
*/
void Advertise::ReadAuctions() {
	// TODO: Need to read item list

	this->auctionList = {"test"};
}

/*
Advertise - Exists
Iterate through auctionList, determine if a match is found
@params: testName
@return: boolean
*/
bool Advertise::Exists(std::string testName) {
	for (int i = 0; i < this->auctionList.size(); i++) {
		if (testName == this->auctionList[i]) {
			return true;
		}
	}
	return false;
}
