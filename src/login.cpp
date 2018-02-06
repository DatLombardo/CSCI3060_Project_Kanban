/*
Kanban
Login.cpp
*/
#include <iostream>
using namespace std;

class Login {
	private:
		string username;
		string[] usernameList;
	public:
		Login();
		ReadUsernames();
		Exists();
		FillUsername();
		GetUser();
};

Login::Login() {
	cout << "Username: ";
	getline(cin, this.username);

	//Read in username list from information file.
	ReadUsernames();

	if (Exists(this.username)) {
		cout << "Welcome, " << this.username << "!" << endl;
	}
	// TODO: Add functionality for incorrect username input & username DNE.

	return GetUser(FillUsername(this.username));
}

/*
Login - ReadUsernames
@params: None
@return: Array of usernames
*/
Login::ReadUsernames() {
	this.usernameList = [];
	// TODO: Need to read username list
		//File read in, store into array variable.

}

/*
Login - Exists
Iterate through usernameList, determine if a match is found

@params: testName
@return: Array of usernames
*/
Login::Exists(string testName) {
	for (int i = 0; i < this.usernameList.size(); i++) {
		if (testName == this.usernameList[i]) {
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
Login::FillUsername(string username) {

	// TODO: Check length of username, add required amount of _'s to equal 15.

	return filledName;
}

/*
Login - GetUser
Define passed user information using Username class.

@params: username
@return: Username instance
*/
Login::GetUser(string username) {
	int userVal;

	//Iterate through userlist to find current username
	for (int i = 0; i < usernameList.size(); i++) {
		if (username == usernameList[i]) {
			userVal = i;
		}
	}
	//Define instance to be used following login
	userInstance = Username(usernameList[i]);
	return userInstance;
}
