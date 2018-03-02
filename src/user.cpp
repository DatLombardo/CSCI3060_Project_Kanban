/*
Kanban
User.cpp
*/
#include <iostream>
#include "User.hpp"
#pragma once
/*
User - User
General constructor for User class
@params: newUser - formatting from current User accounts file.
@return: none
*/
User::User(std::string username, std::string userType, float credits) {
	this->userName = username;
	this->userType = userType;
	this->credits = credits;
}
