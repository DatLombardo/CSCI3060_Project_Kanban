/*
Kanban
delete.hpp
*/
#include <iostream>
#include <string>
#include "user.cpp"

class Delete {
	public:
		std::string username;
		Delete(User user);
		std::string ParseRequest();
		void CancelSales();
		void RemoveUser();
};
