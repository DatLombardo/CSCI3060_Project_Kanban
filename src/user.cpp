/*
Kanban
User.cpp
*/
#include <iostream>
#include "user.hpp"

/*
User - User
General constructor for User class
@params: newUser - formatting from current User accounts file.
@return: none
*/

User::User() {}

User::User(std::string username, std::string userType, float credits) {
	this->username = username;
	this->type = userType;
	this->credits = credits;
}
