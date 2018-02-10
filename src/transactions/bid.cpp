/*
Kanban
bid.cpp
*/

#include "bid.hpp"

/*
Bid - Bid
General constructor, gets input to create new bid on auction.
@params: User user
@return: None
*/
Bid::Bid(User user){
	Bid::ReadAuctions();

	std::cout << "Item Name: ";
	std::cin >> this->itemName;

	std::cout << "Seller Name: ";
	std::cin  >> this->sellerName;

	Bid::ReadAuctions();

	//Bid::Exists(this->itemName, this->sellerName);
  //Check if item & seller name's exists

  //Get Minimum bid of item

  std::cout << "Bid Amount: ";
  std::cin >> this->bidAmount;

  //Check if bid is more than 5% of current bid amount, unless user is admin.

  std::cout << "Bid placed on " << this->itemName << "!" << std::endl;

  //Call in main
	//Create::ParseRequest(user);
}


/*
Bid - ReadAuctions
Read availiable items file, store item list within auctionList
@params: None
@return: None
*/
void Bid::ReadAuctions() {
	// TODO: Need to read item list

	this->auctionList = {"test"};
}

/*
Bid - Exists
Iterate through auctionList, determine if a match for item and seller is found
@params: testName
@return: boolean
*/
bool Bid::Exists(std::string testItem, int numDays, std::string testSeller) {
	for (int i = 0; i < this->auctionList.size(); i++) {
		//Need to parse
		if ((testItem == this->auctionList[i]) && (testSeller == this->auctionList[i])) {
      //ADD seller and item comparison
			return true;
		}
	}
	return false;
}


/*
Bid - ParseRequest
Parse current transaction's request into form for daily transaction file
@params: None
@return: string of request
*/
std::string Bid::ParseRequest() {
	// TODO: Generate daily transaction file object for current Bid
	//			 transaction.

	return "test";
}

/*
Bid - GetMinimumBid
Determine the minimum bid of the relevant information passed by
@params: testName
@return: boolean
*/
float Bid::GetMinimumBid(std::string item, int numDays, std::string seller){
	// TODO: Read from auctionList, find the location of the relevant data,
	//       and return the minimum bid.
	return 0.0;
}
