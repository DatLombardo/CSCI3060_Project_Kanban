#include <iostream>
#include <string>
#include "user.cpp"
#include "item.cpp"
#include "parser.cpp"

class Transaction {
  public:
      bool valid = false;
      std::string transactionCode;
      Transaction(std::string input, user currentUser);
      Transaction(std::string input, std::map<std::string, User> &userList,
            std::map<std::string, Item> &itemList);
      void CreateLoginTransaction();
      void CreateLogoutTransaction();
      void CreateBidTransaction();
      void CreateAdvertiseTransaction();
      void CreateAddCreditTransaction();
      void CreateCreateTransaction();
      void CreateRefundTransaction();
      void CreateDeleteTransaction();
  private:
      user currentUser;
      std::map<user, std::string> userList;
      std::map<item, std::string> itemList;
      std::string transactionType = -1;
}
