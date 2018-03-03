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
std::map<std::string, User> Parser::ReadCurrentUsers(std::string fileName) {
	std::map<std::string, User> users;

    //std::ifstream fileReader(fileName);
	std::ifstream fileReader;
	fileReader.open(fileName);
		std::string currentLine;
		//Testing the file open.
    if(fileReader.is_open()) {
			//Read file line by line
		while (std::getline(fileReader, currentLine)){
			std::string username = currentLine.substr(0, 15);
			std::string type = currentLine.substr(16, 2);
			std::string credits = currentLine.substr(19, 9);
			//std::cout << credits << std::endl << creditsDec << std::endl;
			
			boost::trim(username);
			// std::cout << finalVal << std::endl;

			User user = User(username, type, stof(credits));
			users[username] = user;
		}

	} else
		std::cout<<"Error opening users file"<< std::endl;

	

	fileReader.close();

	return users;
}

/*
Parser - ReadAvailItems
Reads the availiable items file into dedicated vector.
@params: fileName, passed file to be read.
@return: None
*/
std::map<std::string, Item> Parser::ReadAvailItems(std::string fileName) {
    std::map<std::string, Item> items;

    std::ifstream fileReader(fileName);
		std::string currentLine;
		//Testing the file open.
    if(!fileReader) {
        std::cout<<"Error opening item file"<< std::endl;
    }
		//Read file line by line
    while (std::getline(fileReader, currentLine)) {
		std::string itemname = currentLine.substr(0, 25);
		std::string seller = currentLine.substr(26, 15);
		std::string topBidUser = currentLine.substr(42, 15);
		std::string daysToExpiry = currentLine.substr(58, 3);
		std::string credits = currentLine.substr(62, 7);

		boost::trim(itemname);
		boost::trim(seller);
		boost::trim(topBidUser);

		// std::cout << itemname << seller << topBidUser << daysToExpiry << credits << creditsDec << std::endl;

		Item item = Item(itemname, seller, topBidUser, stoi(daysToExpiry), stof(credits));
		items[itemname] = item;
    }

	fileReader.close();

	return items;

	
}
