/*
Kanban
parser.cpp
*/
#include "parser.hpp"

/*
Parser - Parser
General Parser constructor
@params: None
@return: None
*/
Parser::Parser() {

	//Daily transaction File
	Parser::ReadDailyTrans("Daily Transactions.txt");
	//Current user accounts
	Parser::ReadCurrentUsers("Current User Acocunts.txt");
	//Availiable items file
	Parser::ReadAvailItems("Availiable Items.txt");

}

/*
Parser - ReadDailyTrans
Reads the daily transaction file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
void Parser::ReadDailyTrans(std::string fileName) {
    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening output file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)){
        this->dailyTrans.push_back(currentLine);
    }

		fileReader.close();
}

/*
Parser - ReadCurrentUsers
Reads the current user accounts file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
void Parser::ReadCurrentUsers(std::string fileName) {
    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening output file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)){
        this->currentUsers.push_back(currentLine);
    }

		fileReader.close();
}

/*
Parser - ReadAvailItems
Reads the availiable items file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
void Parser::ReadAvailItems(std::string fileName) {
    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening output file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)){
        this->availItems.push_back(currentLine);
    }

		fileReader.close();
}

/*
Parser - GetDailyTrans
Return the vector of elements in the daily transaction file.
@params: none
@return: String value of 'username' + remaining filled space
*/
std::vector<std::string> Parser::GetDailyTrans() {
	return this->dailyTrans;
}

/*
Parser - GetDailyTrans
Return the vector of elements in the current user accounts file.
@params: none
@return: String value of 'username' + remaining filled space
*/
std::vector<std::string> Parser::GetCurrentUsers() {
	return this->currentUsers;
}

/*
Parser - GetDailyTrans
Return the vector of elements in the availiable items file.
@params: none
@return: String value of 'username' + remaining filled space
*/
std::vector<std::string> Parser::GetAvailItems() {
	return this->availItems;
}

/*
Parser - FillUsername
Parse username inputted by user to meet system's username and formatting requirements
Maximum username length = 15
@params: username
@return: String value of 'username' + remaining filled space
*/
std::string Parser::FillUsername(std::string username) {
	int nameLength = username.length();
	std::string newUser;
	//username is less than required length, fill with empty spaces.
	if(nameLength < 15){
		newUser = username + (" " * (15 - nameLength));
		return newUser;
	} else{
		return username;
	}
}

/*
Parser - FillCredit
Parse credit inputted by user to meet system's credit formatting requirements
Maximum credit length = 9
@params: credit
@return: String value of remaining 0's + 'credit'
*/
std::string Parser::FillCredit(std::string credit) {
	int creditLength = username.length();
	std::string newCredit;
	//username is less than required length, fill with empty spaces.
	if(creditLength < 9){
		newCredit = ((9 - creditLength) * "0") + credit;
		return newCredit;
	} else{
		return credit;
	}
}

/*
Parser - FillItemName
Parse credit inputted by user to meet system's item name formatting requirements
Maximum item name length = 25
@params: itemName
@return: String value of 'itemName' + remaining filled space
*/
std::string Parser::FillItemName(std::string itemName) {
	int itemLength = itemName.length();
	std::string newItemName;
	//username is less than required length, fill with empty spaces.
	if(itemLength < 25){
		newItemName = itemName + (" " * (25 - itemLength)) ;
		return newItemName;
	} else{
		return itemName;
	}
}

/*
Parser - FillNumOfDays
Parse number of days inputted by user to meet system's numDays formatting requirements
Maximum nubmer of days length = 3
@params: numDays
@return: String value of remaining 0's + 'numDays'
*/
std::string Parser::FillNumOfDays(std::string numDays) {
	int daysLength = numDays.length();
	std::string newNumDays;
	//username is less than required length, fill with empty spaces.
	if(daysLength < 3){
		newNumDays = ((3 - daysLength) * "0") + numDays;
		return newNumDays;
	} else{
		return numDays;
	}
}

/*
Parser - FillBid
Parse bid inputted by user to meet system's bid formatting requirements
Maximum bid length = 6
@params: bid
@return: String value of remaining 0's + 'bid'
*/
std::string Parser::FillBid(std::string bid) {
	int bidLength = bid.length();
	std::string newBid;
	//username is less than required length, fill with empty spaces.
	if(bidLength < 6){
		newBid = ((6 - bidLength) * "0") + bid;
		return newBid;
	} else{
		return bid;
	}
}
