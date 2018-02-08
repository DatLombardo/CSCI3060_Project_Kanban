/*
Kanban
login.hpp
*/
#include "user.cpp"

class Login {
	private:
		string username;
		string userList[];
	public:
		User Login();
		void ReadUsernames();
		bool Exists(string);
		string FillUsername(string);
		string GetUser(string);
};
