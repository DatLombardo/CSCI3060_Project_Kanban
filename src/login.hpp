/*
Kanban
login.hpp
*/
#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"

class Login {
	private:
		std::string username;
		std::vector<std::string> userList;
	public:
		Login();
		User GenerateUser(std::string username);
		void ReadUsernames();
		bool Exists(std::string testName);
		std::string FillUsername(std::string username);
		std::string GetUser(std::string username);
};
