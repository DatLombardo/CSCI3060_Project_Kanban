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
		std::map<std::string, User> ReadCurrentUsers(std::string fileName));
		std::map<std::string, Item> ReadAvailItems(std::string fileName));
};
