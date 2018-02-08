/*
Kanban
advertise.hpp
*/
#include "user.cpp"

class Advertise {
	private:
		string itemName;
		float minBid;
		int auctionLength;
		string itemList[];

	public:
		string Advertise(User);
		string ParseRequest(User);
		string FillItemName(string);
		void ReadAuctions();
		bool Exists(string);
};
