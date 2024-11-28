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
		cout << "Enter username: ";
		string username;
		cin >> username;
		cout << "Enter password: ";
		string password;
		cin >> password;

        if (is_findUser(username)) {
            delete_user_by_username_password(username, password);
			if (username == "admin") {
				cout << "Admin cannot be deleted." << endl;
				return;
			}
            cout << "User deleted successfully." << endl;
        } else {
            cout << "User not found." << endl;
        }
    }

    void deleteUserByNameSurnameRole() {
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
				cout << "Admin cannot be deleted." << endl;
				return;
			}
            delete_user_by_name_surname_role(name, surname, role);
            cout << "User deleted successfully." << endl;
        } else {
            cout << "User not found." << endl;
        }
    }
};
#endif // !DELETE_USER_CONSOLE

