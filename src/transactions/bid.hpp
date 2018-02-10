/*
Kanban
bid.hpp
*/

#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"

class Bid {
  private:
    std::string itemName;
    std::string sellerName;
    float bidAmount;
    std::vector<std::string> auctionList;
  public:
    Bid(User user);
    std::string ParseRequest();
    void ReadAuctions();
    bool Exists(std::string testItem, int numDays, std::string testSeller);
    float GetMinimumBid(std::string item, int numDays, std::string seller);
};
