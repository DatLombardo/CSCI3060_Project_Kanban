/*
Kanban
User.cpp
*/
#include <iostream>
#include "user.hpp"
/*
User - User
General constructor for User class
@params: newUser - formatting from current user accounts file.
@return: none
*/
User::User(std::string newUser) {
	this->username = newUser.substr(0,14);
	this->type = newUser.substr(16,17);
	this->credit = newUser.substr(19,27);
}
