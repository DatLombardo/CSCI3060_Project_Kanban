/*
Kanban
User.cpp
*/
#include <iostream>

class User {
	public:
		User(std::string newUser);
		std::string username;
		std::string type;
		float credit;
};

/*
User - User
General constructor for User class
@params: newUser - formatting from current user accounts file.
@return: none
*/
User::User(std::string newUser) {
	this->username = newUser.substr(0,14);
	this->type = newUser.substr(16,17);
	//this->credit = std::strtof(newUser.substr(19,27));
}
