/*
Kanban
refund.hpp
*/

#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"

class Refund {
  private:
    std::string buyer;
    std::string seller;
    float credit;
	std::vector<std::string> userList;
  public:
    Refund(User user);
    std::string ParseRequest();
    bool Exists(std::string testName);
	void ReadUsernames();
};
