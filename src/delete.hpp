/*
Kanban
delete.hpp
*/
#include "user.cpp"

class Delete {
	private:
		string username;

	public:
		string Delete();
		string ParseRequest();
		void CancelSales();
		void RemoveUser();
};
