#ifndef DELETE_USER_CONSOLE
#define DELETE_USER_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/admin_staff.h"
#include "../../../data/Users/doctor.h"
#include "../../../data/Users/nurse.h"
#include "../../../data/FileStorage/delete_user.h"
#include "../console_colors.h"

class DeleteUserConsole : public DeleteUser {
public:
	DeleteUserConsole() = default;

    void deleteUserByUsernamePassword() {
		Console_colors::inputs_color();
		cout << "Enter username: ";
		string username;
		cin >> username;
		cout << "Enter password: ";
		string password;
		cin >> password;

        if (is_findUser(username)) {
            delete_user_by_username_password(username, password);
			if (username == "Admin" || username == "admin") {
				Console_colors::errors_color();
				cout << "Admin cannot be deleted." << endl;
				return;
			}
			Console_colors::labels_color();
            cout << "User deleted successfully." << endl;
			system("pause");
			system("cls");
        } else {
			Console_colors::errors_color();
            cout << "User not found." << endl;
			system("pause");
			system("cls");
        }
    }

    void deleteUserByNameSurnameRole() {
		Console_colors::inputs_color();
		cout << "Enter name: ";
		string name;
		cin >> name;
		cout << "Enter surname: ";
		string surname;
		cin >> surname;
		int role;
		do
		{
			cout << "Enter role(1- Doctor, 2- Nurse, 3- Admin staff): ";
			try {
				cin >> role;

				if (cin.fail())
				{
					throw runtime_error("Invalid input. Please enter a number.");
				}
			}
			catch (const exception& e)
			{
				cin.clear();
				cin.ignore();
				Console_colors::errors_color();
				cout << e.what() << endl;
				Console_colors::default_color();
				continue;
			}
		} while (role < 1 || role > 3);
		
        if (is_findUserNameSurname(name, surname)) {
            if (role == 0) {
				Console_colors::errors_color();
				cout << "Admin cannot be deleted." << endl;
				return;
			}
			delete_user_by_name_surname_role(name, surname, role);
			Console_colors::labels_color();
            cout << "User deleted successfully." << endl;
			system("pause");
			system("cls");
        } else {
			Console_colors::errors_color();
            cout << "User not found." << endl;
			system("pause");
			system("cls");
        }
    }
};
#endif // !DELETE_USER_CONSOLE

