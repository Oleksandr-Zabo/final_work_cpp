#ifndef SHOW_ALL_USERS_CONSOLE
#define SHOW_ALL_USERS_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/user.h"
#include "../../../data/FileStorage/load_user.h"
#include "../console_colors.h"

class ShowAllUsersConsole : public LoadUser {
public:
	ShowAllUsersConsole() = default;

	void showAllUsers() {
		vector<User*> users = LoadUser::readAllUsers();
		
		int i = 1;
		for (User* user : users) {
			Console_colors::users_info_num();
			cout << "User " << i << " :" << endl;
			Console_colors::users_info_color();
			cout << "Username: " << user->getUsername() << "\nName: " << user->getName() << "\nSurname: " << user->getSurname() << "\nRole: " << user->getRole() << endl;
			i += 1;
		}
		Console_colors::default_color();
		system("pause");
		system("cls");
	}
};
#endif // !SHOW_ALL_USERS_CONSOLE
