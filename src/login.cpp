/*
Kanban
Login.cpp
*/
#include <iostream>
#include "login.hpp"

using namespace std;

/*
Login - Login
General Login constructor, prompts for user input and builds User instance.
@params: None
@return: User instance
*/
User Login::Login() {
	cout << "Username: ";
	getline(cin, this.username);

	//Read in username list from information file.
	this.ReadUsernames();

	if (this.Exists(this.username)) {
		cout << "Welcome, " << this.username << "!" << endl;
	}
	// TODO: Add functionality for incorrect username input & username DNE.

	//Build User instance to be passed back to main
	User newUser = new User(this.GetUser(this.FillUsername(this.username)));
	return newUser;
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
	this.userList = {"test"};
}

/*
Login - Exists
Iterate through userList, determine if a match is found
@params: testName
@return: boolean
*/
bool Login::Exists(string testName) {
	for (int i = 0; i < this.userList.size(); i++) {
		if (testName == this.userList[i]) {
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
string Login::FillUsername(string username) {

	// TODO: Check length of username, add required amount of _'s to equal 15.

	return username;
}

/*
Login - GetUser
Define passed user information using Username class.
@params: username
@return: String value of user's information from current user accounts file.
*/
string Login::GetUser(string username) {
	int userVal;

	//Iterate through userlist to find current username
	for (int i = 0; i < userList.size(); i++) {
		if (username == userList[i]) {
			userVal = i;
		}
	}
	//Define instance to be used following login
	return userList[i];
}
