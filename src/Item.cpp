#include "item.hpp"

Item::Item(std::string name, std::string sellerName, std::string buyerName, std::string days, float bid) {
  this->itemName = name;
  this->seller = sellerName;
  this->buyer = buyerName;
  this->daysLeft = days;
  this->currentBid = bid;
}
