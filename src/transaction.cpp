#include "transaction.hpp"

Transaction::Transaction(std::string input, std::map<std::string, User> &userList,
      std::map<std::string, Item> &itemList) {
    this->userList = userList;
    this->itemList = itemList;
    if (input == "login"){
        this->transactionCode = "10";
        CreateLoginTransaction();
    } else{
        std::cout << "\t\t\tnot a transaction l0ser" << std::endl;
    }
}

Transaction::Transaction(std::string input, user currentUser) {
    // check and see if transaction input is valid

    // if it is, call respective transaction function to gather input

    if (input == "logout")
        this->transactionCode = "00";
        CreateLogoutTransaction();

    else if (input == "bid")
        this->transactionCode = "04";
        CreateBidTransaction();

    else if (input == "advertise")
        this->transactionCode = "03";
        CreateAdvertiseTransaction();

    else if (input == "addcredit")
        this->transactionCode = "06";
        CreateAddCreditTransaction();

    else if (input == "create")
        this->transactionCode = "01";
        CreateCreateTransaction();

    else if (input == "refund")
        this->transactionCode = "05";
        CreateRefundTransaction();

    else if (input == "delete")
        this->transactionCode = "02";
        CreateDeleteTransaction();

    else
        std::cout << "\t\t\tnot a transaction l0ser" << std::endl;

}

//Transaction Code 10
void Transaction::CreateLoginTransaction(){
  std::string username;
  std::cout << "Username: ";
	std::cin >>  username;
  
  if (username.length() > 15){
    std::cout << "ERROR: Username above limit (15 characters)" << std::endl;
    this->valid = false;
  }
  else {
    // Check if username exists in userList
    if (this->userList.count(username) == 0){
      std::cout << "ERROR: Entered username does not exist." << std::endl;
      this->valid = false;
    }
    else{
      //Create valid transaction here
    	this->currentUser = this->userList[username];
      this->valid = true;
    }
  }
}

//Transaction Code 00
void Transaction::CreateLogoutTransaction(){
  std::cout << "Logging out." << std::endl;
  this->valid = true;
  //Create valid transaction here
}


void Transaction::CreateBidTransaction(){
  std::string itemName, numDays, sellerName, bidAmount;
  std::cout << "Item Name: ";
	std::cin >>  itemName;

  std::cout
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
  std::string username
  float credit;
  User userAdd;
  std::cout << "Username: ";
  std::cin >>  username;

  if (this->currentUser.type == "AA"){
    
    //Check if user exists
    if (this->userList.count(username) > 0){
      credit = GetCreditInput();
      newCredit = this->userList[username].credits + credit;

      //Check if new credit amount exceeds limit
      if (newCredit > 999999.00){
        std::cout << "ERROR: New credit amount exceeds limit." << std::endl;
        this->valid = false;
      } else if (credit > 1000.00){ 
      //Check if user is adding more than 1000 credits
        std::cout << "ERROR: Cannot add more than 1000 credits in one session." << std::endl;
        this->valid = false;
      }else{
        //Create valid transaction here
        this->targetUser = this->userList[username];
        this->credit = credit;
        this->valid = true;
      }
    } else{
      std::cout << "ERROR: Entered username does not exist." << std::endl;
      this->valid = false;
    }
  }

  //Standard user attempts to add credit.
  else{
    credit = GetCreditInput();

    //Check if new credit amount exceeds limit
      if (newCredit > 999999.00){
        std::cout << "ERROR: New credit amount exceeds limit." << std::endl;
        this->valid = false;
      } else if (credit > 1000.00){ 
        //Check if user is adding more than 1000 credits
        std::cout << "ERROR: Cannot add more than 1000 credits in one session." << std::endl;
        this->valid = false;
      } else{
        //Create valid transaction here
        this->targetUser = this->userList[username];
        this->credit = credit;
        this->valid = true;
      }

  }
}

void Transaction::CreateCreateTransaction(){
  std::string username, type;
  float credit;
  std::cout << "Username: ";
  std::cin >> username;
  std::cout << "Account Type: ";
  std::cin >> type;
  credit = GetCreditInput();
  //Checks if user is admin to proceed
  if (this->currentUser.type == "AA"){
    

    if (strlen(username) > 15){
    //Rejects overly long username
      std::cout << "ERROR: Username length cannot exceed 15 characters." << std::endl;
      this->valid = false;
    } else if(this->userList.find(username) != this->userList.end()){
    //Rejects existing username
      std::cout << "ERROR: Username already exists." << std::endl;
      this->valid = false;
    } else{
      if (credit > 999999.00){
      //Rejects credit value over max
        std::cout << "ERROR: Current user is not an admin." << std::endl;
        this->valid = false;
      } else{
        if (validTypes.count(type) > 0){
          //Create valid transaction here
          this->targetUser = User(username, type, credit);
          std::cout << "Account Created." << std::endl;
          this->valid = true;
        } else{
          this->valid = false;
        }
        
    }
  } else{
    std::cout << "ERROR: Current user is not an admin." << std::endl;
    this->valid = false;
  }
  //Constraints
  /*
  • privileged transaction - only accepted when logged in as admin user
  • new user name is limited to at most 15 characters
  • new user names must be different from all other current users
  • maximum credit can be 999,999
  */
  // Generate transaction code

}

void Transaction::CreateRefundTransaction(){
  std::string buyer, seller;
  float credit;
  std::cout << "Buyer Name: ";
  std::cin >> buyer;
  std::cout << "Seller Name: ";
  std::cin  >> seller;
  credit = GetCreditInput();

  if (this->currentUser.type == "AA"){
    //Check if user is admin

    //Checks that buyer exists
    if (this->userList.find(buyer) != this->userList.end()){
      
      //Checks that seller exists
      if (this->userList.find(seller) != this->userList.end()){

        User sellerUser = this->userList[seller];

        //Checks if seller has enough credits to refund
        if (sellerUser.credits < credit){
          std::cout << "ERROR: Seller does not have enough credits." << std::endl;
          this->valid = false;
        } else{
          this->buyer = this->userList[buyer];
          this->seller = this->userList[seller];
          this->credit = credit;

          this->valid = true;
        }

      } else{
        std::cout << "ERROR: Seller does not exist." << std::endl;
        this->valid = false;
      }
    } else{
      std::cout << "ERROR: Buyer does not exist." << std::endl;
      this->valid = false;
    }

  } else{
    std::cout << "ERROR: Current user is not an admin." << std::endl;
    this->valid = false;
  }
  

  //Constraints
  /*
  • Buyer and seller both must be current users
  */

	//Check if credit exists in seller's balance
}

void Transaction::CreateDeleteTransaction(){
  std::string username;
  std::cout << "Username: " << std::endl;
  std::cin >> username;

  //Checks that user is admin
  if (this->currentUser.type == "AA"){
    //Checks that user is not deleting itself
    if (strcmp(this.currentUser.name, username) == 0){
      //Checks that user to be deleted exists
      if (this->userList.count(username > 0)){
        //Designate deleted user here
        this->targetUser = this->userList[username];
        std::cout << "Account " << username  << " Deleted." << std::endl;
        this->valid = true;
      } else{
        std::cout << "ERROR: User does not exist." << std::endl;
        this->valid = false;
      }

    } else{
      std::cout << "ERROR: User cannot delete itself." << std::endl;
      this->valid = false;
    }

  } else{
    std::cout << "ERROR: Current user is not an admin." << std::endl;
    this->valid = false;
  }
    
    //Delete::CancelSales();
    //Delete::RemoveUser();

    //Constraints
    /*
     • privileged transaction - only accepted when logged in as admin user
     • username must be the name of an existing user but not the name of the current user
     • no further transactions should be accepted on a deleted user’s available inventory of items for sale.
     */
    
}

float Transaction::GetCreditInput(){
  float credit;
  bool validFloat = false;
  while(!validFloat){
  //Checks that user input is a valid value for credits
    std::cout << "Credit: ";
    std::cin >> credit;

    if (std::cin.fail()){
      std::cout << "Please enter a number." << endl;
      std::cin.clear();
      std::cin.ignore();
    } else {
      return credit;
    }
  }
}
