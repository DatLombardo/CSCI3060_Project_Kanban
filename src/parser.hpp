/*
Kanban
parser.hpp
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "User.cpp"

class Parser {
	private:
		std::vector<std::string> dailyTrans;
		std::vector<std::string> currentUsers;
		std::vector<std::string> availItems;
	public:
		Parser();
		void ReadDailyTrans(std::string fileName);
		void ReadCurrentUsers(std::string fileName));
		void ReadAvailItems(std::string fileName));
		bool Exists(std::string testName);
		std::string FillUsername(std::string Username);
		std::string FillCredit(std::string credit);
		std::string FillItemName(std::string itemName);
		std::string FillNumOfDays(std::string numDays);
		std::string FillBid(std::string bid);
		std::vector<std::string> GetDailyTrans();
		std::vector<std::string> GetCurrentUsers();
		std::vector<std::string> GetAvailItems();
		std::string ParseCredit(std::string credit);
};
