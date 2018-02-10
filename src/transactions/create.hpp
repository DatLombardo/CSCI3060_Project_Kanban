/*
Kanban
create.hpp
*/
#include "user.cpp"
#include <iostream>
#include <string>
#include <vector>

class Create {
	private:
		std::string username;
		std::string type;
		float credit;
		std::vector<std::string> userList;

	public:
		Create(User user);
		std::string ParseRequest();
		void ReadUsernames();
		bool Exists(std::string testName);
};
