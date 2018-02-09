/*
Kanban
addcredit.hpp
*/

#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"

class AddCredit {
  private:
    std::string username;
    float credit;
    std::vector<std::string> userList;
  public:
    AddCredit(User user);
    std::string ParseRequest();
    bool Exists(std::string testName);
    void ReadUsernames();

};