#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "User.cpp"
#include "item.cpp"
#include "parser.cpp"

class Transaction {
  public:
      bool valid = false;
      std::string transactionCode;
      Transaction(std::string input, User currentUser,
            std::map<std::string, User> &UserList, std::map<std::string, Item> &itemList);
      Transaction(std::string input, std::map<std::string, User> &UserList);
      void CreateLoginTransaction();
      void CreateLogoutTransaction();
      void CreateBidTransaction();
      void CreateAdvertiseTransaction();
      void CreateAddCreditTransaction();
      void CreateCreateTransaction();
      void CreateRefundTransaction();
      void CreateDeleteTransaction();
  private:
      User currentUser;
      std::map<std::string, User> UserList;
      std::map<std::string, Item> itemList;
      std::string transactionType = "";
};
