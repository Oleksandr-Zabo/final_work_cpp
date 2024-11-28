#ifndef DELETE_USER_CONSOLE
#define DELETE_USER_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/admin_staff.h"
#include "../../../data/Users/doctor.h"
#include "../../../data/Users/nurse.h"
#include "../../../data/FileStorage/delete_user.h"

class DeleteUserConsole : public DeleteUser {
public:
	DeleteUserConsole() = default;

    void deleteUserByUsernamePassword() {
		SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
		cout << "Enter username: ";
		string username;
		cin >> username;
		cout << "Enter password: ";
		string password;
		cin >> password;

        if (is_findUser(username)) {
            delete_user_by_username_password(username, password);
			if (username == "Admin" || username == "admin") {
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
				cout << "Admin cannot be deleted." << endl;
				return;
			}
			SetConsoleTextAttribute(hConsole, ProjectColors::labels);
            cout << "User deleted successfully." << endl;
        } else {
			SetConsoleTextAttribute(hConsole, ProjectColors::errors);
            cout << "User not found." << endl;
        }
    }

    void deleteUserByNameSurnameRole() {
		SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
		cout << "Enter name: ";
		string name;
		cin >> name;
		cout << "Enter surname: ";
		string surname;
		cin >> surname;
		string role;
		do
		{
			cout << "Enter role(Doctor, Nurse, Admin staff): ";
			cin >> role;
		} while (role != "Doctor" && role != "Nurse" && role != "Admin staff");
		
        if (is_findUserNameSurname(name, surname)) {
            if (role == "Admin") {
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
				cout << "Admin cannot be deleted." << endl;
				return;
			}
            delete_user_by_name_surname_role(name, surname, role);
			SetConsoleTextAttribute(hConsole, ProjectColors::labels);
            cout << "User deleted successfully." << endl;
        } else {
			SetConsoleTextAttribute(hConsole, ProjectColors::errors);
            cout << "User not found." << endl;
        }
    }
};
#endif // !DELETE_USER_CONSOLE

