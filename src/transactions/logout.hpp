/*
Kanban
logout.hpp
*/
#include <iostream>
#include <string>
#include "user.cpp"

class Logout {
	public:
		Logout(User user);
		std::string ParseRequest(User user);
};
