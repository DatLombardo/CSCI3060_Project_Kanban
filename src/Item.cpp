#include "item.hpp"

Item::Item(std::string name, std::string sellerName, std::string buyerName, std::string days, std::string bid) {
  this->itemName = name;
  this->seller = sellerName;
  this->buyer = buyerName;
  this->daysLeft = days;
  this->currentBid = bid;
}

std::string Item::getName() {
  return this->itemName;
}

std::string Item::getSeller() {
  return this->seller;
}

std::string Item::getBuyer() {
  return this->buyer;
}

std::string Item::getDaysLeft() {
  return this->daysLeft;
}

std::string Item::getBid() {
  return this->currentBid;
}
