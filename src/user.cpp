/*
Kanban
User.cpp
*/
#include <iostream>

using namespace std;

class User {
	public:
		void User();
		string username;
		string type;
		float credit;
};

/*
User - User
General constructor for User class
@params: newUser - formatting from current user accounts file.
@return: none
*/
void User::User(string newUser) {
	this.username = newUser.substr(0,14);
	this.type = newUser.substr(16,17);
	this.credit = newUser.substr(19,27);
}
