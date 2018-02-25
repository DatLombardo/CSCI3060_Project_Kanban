#include "Item.hpp"

Item::Item(std::string name, std::string sellerName, std::string buyerName, int days, float bid) {
  itemName = name;
  seller = sellerName;
  buyer = buyerName;
  daysLeft = days;
  currentBid = bid;
}

std::string Item::getName() {
  return itemName;
}

std::string Item::getSeller() {
  return seller;
}

std::string Item::getBuyer() {
  return buyer;
}

int Item::getDaysLeft() {
  return daysLeft;
}

float Item::getBid() {
  return currentBid;
}
