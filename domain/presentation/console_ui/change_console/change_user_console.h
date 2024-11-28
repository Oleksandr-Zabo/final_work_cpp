#ifndef CHANGE_USER_CONSOLE
#define CHANGE_USER_CONSOLE


#include "../../../lib.h"
#include "../adds_console/add_user_console.h"
#include "../delete_console/delete_user_console.h"

class ChangeUserConsole : public AddUserConsole, public DeleteUserConsole {
public:
	ChangeUserConsole() = default;

    void changeUserByUsernamePassword() {
		SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
		cout << "Enter the old username: ";
		string oldUsername;
		cin >> oldUsername;
		cout << "Enter the old password: ";
		string oldPassword;
		cin >> oldPassword;

        if (DeleteUserConsole::is_findUser(oldUsername)) {
            delete_user_by_username_password(oldUsername, oldPassword);
			SetConsoleTextAttribute(hConsole, ProjectColors::labels);
			cout << "Enter new data:" << endl;
            AddUserConsole::addUser();
        }
    }



    void changeUserByNameSurnameRole() {
		SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
		cout << "Enter the old name: ";
		string oldName;
		cin >> oldName;
		cout << "Enter the old surname: ";
		string oldSurname;
		cin >> oldSurname;

		string oldRole;
		do
		{
			cout << "Enter the old role(Doctor, Nurse, Admin staff): ";
			cin >> oldRole;
		} while (oldRole != "Doctor" && oldRole != "Nurse" && oldRole != "Admin staff");

        if (DeleteUserConsole::is_findUserNameSurname(oldName, oldSurname)) {
            delete_user_by_name_surname_role(oldName, oldSurname, oldRole);
			SetConsoleTextAttribute(hConsole, ProjectColors::labels);
            cout << "Enter new data:" << endl;
            AddUserConsole::addUser();
        }
    }
};
#endif // !CHANGE_USER_CONSOLE

