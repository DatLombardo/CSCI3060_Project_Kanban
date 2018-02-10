/*
Kanban
Login.cpp
*/
#include "login.hpp"

/*
Login - Login
General Login constructor, prompts for user input and builds User instance.
@params: None
@return: None
*/
Login::Login() {
	std::cout << "Username: ";
	std::cin >> this->username;

	//Read in username list from information file.
	Login::ReadUsernames();

	if (Login::Exists(this->username)) {
		std::cout << "Welcome, " << this->username << "!" << std::endl;
	}
	// TODO: Add functionality for incorrect username input & username DNE.

	//Build User instance to be passed back to main
	Login::GenerateUser(Login::FillUsername(this->username));
}

/*
Login - GenerateUser
Declares User instance of existing username.
@params: None
@return: User instance
*/
User Login::GenerateUser(std::string username) {
	User* newUser = new User(Login::GetUser(username));
	return *newUser;
}

/*
Login - ReadUsernames
Read current user accounts file, store user list within userList
@params: None
@return: None
*/
void Login::ReadUsernames() {
	// TODO: Need to read username list
		//File read in, store into array variable.
	this->userList = {"test"};
}

/*
Login - Exists
Iterate through userList, determine if a match is found
@params: testName
@return: boolean
*/
bool Login::Exists(std::string testName) {
	for (int i = 0; i < this->userList.size(); i++) {
		if (testName == this->userList[i]) {
			return true;
		}
	}
	return false;
}

/*
Login - FillUsername
Parse username inputted by user to meet system's username and formatting requirements
@params: username
@return: String value of 'username' + remaining filled space
*/
std::string Login::FillUsername(std::string username) {

	// TODO: Check length of username, add required amount of _'s to equal 15.

	return username;
}

/*
Login - GetUser
Define passed user information using Username class.
@params: username
@return: String value of user's information from current user accounts file.
*/
std::string Login::GetUser(std::string username) {
	int userVal;

	//Iterate through userlist to find current username
	for (int i = 0; i < this->userList.size(); i++) {
		if (username == userList[i]) {
			userVal = i;
		}
	}
	//Define instance to be used following login
	return userList[userVal];
}
