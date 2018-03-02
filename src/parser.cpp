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
	Parser::ReadDailyTrans("data/Daily Transactions.txt");
	//Current User accounts
	Parser::ReadCurrentUsers("../data/Current User Acocunts.txt");
	//Availiable items file
	Parser::ReadAvailItems("../data/Availiable Items.txt");

}

/*
Parser - ReadDailyTrans
Reads the daily transaction file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
// void Parser::ReadDailyTrans(std::string fileName) {
//     std::ifstream fileReader(fileName);
// 		std::string currentLine;
// 		//Testing the file open.
//     if(!fileReader) {
//         std::cout<<"Error opening output file"<< std::endl;
//     }
// 		//Read file line by line
//     while (std::getline(fileReader, currentLine)){
//         this->dailyTrans.push_back(currentLine);
//     }

// 		fileReader.close();
// }

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

/*
Parser - ReadCurrentUsers
Reads the current User accounts file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
void Parser::ReadCurrentUsers(std::string fileName) {
	std::map<std::string, User> users;

    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening output file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)){
		std::string username = currentLine.substr(0, 15);
		std::string type = currentLine.substr(16, 2);
		std::string credits = currentLine.substr(19, 7);
		std::string creditsDec = currentLine.substr(26, 2);

		User user = User(username, type, stof(credits) + stof(creditsDec) /100);
		users[username] = user;
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
    std::map<std::string, User> items;

    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening output file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)) {
		std::string itemname = currentLine.substr(0, 25);
		std::string seller = currentLine.substr(26, 15);
		std::string topBidUser = currentLine.substr(42, 15);
		std::string daysToExpiry = currentLine.substr(57, 3);
		std::string credits = currentLine.substr(61, 4);
		std::string creditsDec = currentLine.substr(65, 2);

		item item = Item(itemname, seller, topBidUser, daysToExpiry, stof(credits) + stof(creditsDec) / 100);
		items[itemname] = user;
    }

	

	fileReader.close();
}
