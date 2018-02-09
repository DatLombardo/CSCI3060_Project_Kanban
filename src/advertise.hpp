/*
Kanban
advertise.hpp
*/
#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"

class Advertise {
	private:
		std::string itemName;
		float minBid;
		int auctionLength;
		std::vector<std::string> auctionList;

	public:
		Advertise(User user);
		std::string ParseRequest(User user);
		std::string FillItemName(std::string itemName);
		void ReadAuctions();
		bool Exists(std::string testName);
};
