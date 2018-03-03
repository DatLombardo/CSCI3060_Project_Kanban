#include "item.hpp"

Item::Item() {}

Item::Item(std::string name, std::string sellerName, std::string buyerName, int days, float bid) {
  this->itemName = name;
  this->seller = sellerName;
  this->buyer = buyerName;
  this->daysToExpiry = days;
  this->currentBid = bid;
}
