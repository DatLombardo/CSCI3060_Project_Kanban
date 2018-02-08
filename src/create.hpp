/*
Kanban
create.hpp
*/
#include "user.cpp"

class Create {
	private:
		string username;
		string type;
		float credit;
		string userList[];

	public:
		string Create(User);
		string ParseRequest();
		void ReadUsernames();
		bool Exists(string);
};
