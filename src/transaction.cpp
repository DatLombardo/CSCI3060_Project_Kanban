#include "transaction.hpp"

Transaction::Transaction(std::string input, std::map<std::string, User> &userList,
      std::map<std::string, Item> &itemList) {
    this->userList = userList;
    this->itemList = itemList;
    if (input == "login")
        CreateLoginTransaction();
    else
        std::cout << "\t\t\tnot a transaction l0ser" << std::endl;
}

Transaction::Transaction(std::string input, user currentUser) {
    // check and see if transaction input is valid

    // if it is, call respective transaction function to gather input

    if (input == "logout")
        CreateLogoutTransaction();

    else if (input == "bid")
        CreateBidTransaction();

    else if (input == "advertise")
        CreateAdvertiseTransaction();

    else if (input == "addcredit")
        CreateAddCreditTransaction();

    else if (input == "create")
        CreateCreateTransaction();

    else if (input == "refund")
        CreateRefundTransaction();

    else if (input == "delete")
        CreateDeleteTransaction();

    else
        std::cout << "\t\t\tnot a transaction l0ser" << std::endl;

}

//Transaction Code 10
void Transaction::CreateLoginTransaction(){
  std::string username;
  Parser parse = new Parser();

  std::cout << "Username: ";
	std::cin >>  username;
  if (username.length() > 15){
    std::cout << "ERROR: Username above limit (15 characters)" << std::endl;
    this->valid = false;
  }
  else {
    username = parse.FillUserame(username);
    // Check if username exists in userList
    if (this->userList.find(username) == this->userList.end()){
      std::cout << "ERROR: Entered username does not exist." << std::endl;
      this->valid = false;
    }
    else{
      //Get the user instance at the found key.
    	this->currentUser = this->userList[username]
      this->transactionCode = "10_" + this->currentUser.username + "_" +
                              this->currentUser.type + "_" + this->currentUser.credit;
      this->valid = true;
    }
  }
}


void Transaction::CreateLogoutTransaction(){
  std::cout << "Logging out." << std::endl;
  //Generate transaction code
}

void Transaction::CreateBidTransaction(){
  std::string itemName, numDays, sellerName, bidAmount;
  std::cout << "Item Name: ";
	std::cin >>  itemName;

  std::cout << "Number of Days Remaining: ";
  std::cin >> numDays;

	std::cout << "Seller Name: ";
	std::cin  >>  sellerName;

  //Check if item & seller name's exists

  //Get Minimum bid of item and display the minimum bid

  std::cout << "Bid Amount: ";
  std::cin >>  bidAmount;

  // Constraints
  /*
  • Semi-privileged transaction - only accepted when logged in any type of account except standard-sell.
  • item name must be an existing item
  • new bid must be greater than the previous highest bid
  • new bid must be at least 5% higher than the previous highest bid (this restriction does not apply in privileged mode)
  */

  //Check if bid is more than 5% of current bid amount, unless user is admin.

  //Generate transaction code

  std::cout << "Bid placed on " <<  itemName << "!" << std::endl;
}

void Transaction::CreateAdvertiseTransaction(){
  std::string itemName, minBid, auctionLength;
  std::cout << "Item Name: ";
	std::cin >>  itemName;

	//FillItemName used for Exists function

	std::cout << "Minimum Bid: ";
	std::cin >>  minBid;

	std::cout << "Auction Length (Days): ";
	std::cin >>  auctionLength;

  //Constraints
  /*
  • Semi-privileged transaction - only accepted when logged in any type of account except standard-buy.
  • the maximum price for an item is 999.99
  • the maximum length of an item name is 25 characters
  • the maximum number of days to auction is 100
  */

	// TODO: Error checking for all input
  //Generate transaction code

	std::cout <<  itemName << " is up for auction!" << std::endl;
}

void Transaction::CreateAddCreditTransaction(){
  std::string username, credit;
  std::cout << "Username: ";
  std::cin >>  username;

  //Check to see if the user is an admin

  std::cout << "Credit: ";
  std::cin  >>  credit;
  //Constraints
  /*
  • In admin mode, the username has to be an existing username in the system.
  • A maximum of $1000.00 can be added to an account in a given session.
  */
  //Generate transaction code
}

void Transaction::CreateCreateTransaction(){
  std::string username, type, credit;
  std::cout << "Username: ";
	std::cin >> username;

	std::cout << "Account Type: ";
	std::cin >> type;

	std::cout << "Credit: ";
	std::cin >> credit;
  //Constraints
  /*
  • privileged transaction - only accepted when logged in as admin user
  • new user name is limited to at most 15 characters
  • new user names must be different from all other current users
  • maximum credit can be 999,999
  */
  // Generate transaction code

	std::cout << "Account Created." << std::endl;
}

void Transaction::CreateRefundTransaction(){
  std::string buyer, seller, credit;
  //Check if user is admin

	std::cout << "Buyer Name: ";
	std::cin >> buyer;

  std::cout << "Seller Name: ";
  std::cin  >> seller;

  //Constraints
  /*
  • Buyer and seller both must be current users
  */

	std::cout << "Credit: ";
 	std::cin  >> credit;

	//Check if credit exists in seller's balance
}

void Transaction::CreateDeleteTransaction(){
    std::string username;
    std::cout << "Username: " << std::endl;
    std::cin >> username;

    //Delete::CancelSales();
    //Delete::RemoveUser();

    //Constraints
    /*
     • privileged transaction - only accepted when logged in as admin user
     • username must be the name of an existing user but not the name of the current user
     • no further transactions should be accepted on a deleted user’s available inventory of items for sale.
     */
    std::cout << "Account " << username  << " Deleted." << std::endl;
}
