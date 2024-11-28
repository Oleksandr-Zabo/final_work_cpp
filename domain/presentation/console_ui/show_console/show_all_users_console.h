#ifndef SHOW_ALL_USERS_CONSOLE
#define SHOW_ALL_USERS_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/user.h"
#include "../../../data/FileStorage/load_user.h"

class ShowAllUsersConsole : public LoadUser {
public:
	ShowAllUsersConsole() = default;

	void showAllUsers() {
		vector<User*> users = LoadUser::readAllUsers();
		for (User* user : users) {
			cout << user->getUsername() << " " << user->getName() << " " << user->getSurname() << " " << user->getRole() << endl;
		}
	}
};
#endif // !SHOW_ALL_USERS_CONSOLE
