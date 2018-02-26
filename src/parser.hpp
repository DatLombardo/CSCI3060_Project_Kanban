/*
Kanban
parser.hpp
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "user.cpp"

class Parser {
	private:
		std::vector<std::string> dailyTrans;
		std::vector<std::string> currentUsers;
		std::vector<std::string> availItems;
	public:
		Parser();
		void ReadDailyTrans();
		void ReadCurrentUsers();
		void ReadAvailItems();
		bool Exists(std::string testName);
		std::string FillUsername(std::string username);
		std::string FillCredit(std::string credit);
		std::string FillItemName(std::string itemName);
		std::string FillNumOfDays(std::string numDays);
		std::string FillBid(std::string bid);
		std::vector<std::string> GetDailyTrans();
		std::vector<std::string> GetCurrentUsers();
		std::vector<std::string> GetAvailItems();
		std::string ParseCredit(std::string credit);
};
