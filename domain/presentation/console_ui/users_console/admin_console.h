#ifndef ADMIN_CONSOLE
#define ADMIN_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_user_console.h"
#include "../delete_console/delete_user_console.h"
#include "../change_console/change_user_console.h"
#include "../show_console/show_all_users_console.h"

class AdminConsole : public AddUserConsole, public DeleteUserConsole, public ChangeUserConsole, public ShowAllUsersConsole {
public:
	void adminMenu() {
		int choice;
		do
		{
			cout << "1. Add user" << endl;
			cout << "2. Delete user" << endl;
			cout << "3. Change user" << endl;
			cout << "4. Show all users" << endl;
			cout << "0. Exit" << endl;
			cout << "Enter your choice: ";
			int choice;
			try{
				cin >> choice;
			}
			catch (const std::exception&)
			{
				cout << "Invalid choice" << endl;
			}
			switch (choice)
			{
			case 1:
				AddUserConsole::addUser();
				break;

			case 2:
				cout << "How do you want to delete user?" << endl;
				cout << "1. By username and password" << endl;
				cout << "2. By name, surname and role" << endl;
				cout << "Enter your choice: ";
				int choice_1;
				try {
					cin >> choice_1;
				}
				catch (const std::exception&)
				{
					cout << "Invalid choice" << endl;
				}
				switch (choice_1)
				{
				case 1:
					DeleteUserConsole::deleteUserByUsernamePassword();
					break;
				case 2:
					DeleteUserConsole::deleteUserByNameSurnameRole();
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
				break;

			case 3:
				cout << "How do you want to change user?" << endl;
				cout << "1. By username and password" << endl;
				cout << "2. By name, surname and role" << endl;
				cout << "Enter your choice: ";
				int choice_2;
				try {
					cin >> choice_2;
				}
				catch (const std::exception&)
				{
					cout << "Invalid choice" << endl;
				}
				switch (choice_2)
				{
				case 1:
					ChangeUserConsole::changeUserByUsernamePassword();
					break;
				case 2:
					ChangeUserConsole::changeUserByNameSurnameRole();
					break;
				default:
					cout << "Invalid choice" << endl;
					break;
				}
				break;

			case 4:
				ShowAllUsersConsole::showAllUsers();
				break;

			case 0:
				break;

			default:
				cout << "Invalid choice" << endl;
				break;
			}
		} while (choice != 0);
	}
};
#endif // !ADMIN_CONSOLE

