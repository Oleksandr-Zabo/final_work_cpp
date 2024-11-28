#ifndef ADD_USER_CONSOLE
#define ADD_USER_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/admin_staff.h"
#include "../../../data/Users/doctor.h"
#include "../../../data/Users/nurse.h"
#include "../../../data/FileStorage/load_user.h"
#include "../../../data/FileStorage/save_user.h"

class AddUserConsole: public SaveUser, public LoadUser{
public:
	AddUserConsole() = default;

	// Method to add a new user
	void addUser() {
		string username, password, role, name, surname;
		cout << "Enter the username: ";
		cin >> username;
		cout << "Enter the password: ";
		cin >> password;
		cout << "Enter the role (AdminStaff, Doctor, Nurse): ";
		cin >> role;
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the surname: ";
		cin >> surname;

		bool is_find_user = LoadUser::is_findUser(username);
		if (is_find_user) {
			cout << "User already exists" << endl;
			return;
		}

		else {
			if (role == "AdminStaff") {
				AdminStaff adminStaff(username, password, name, surname);

				saveUser(adminStaff);
			}
			else if (role == "Doctor") {
				Doctor doctor(username, password, name, surname);
				saveUser(doctor);
			}
			else if (role == "Nurse") {
				Nurse nurse(username, password, name, surname);
				saveUser(nurse);
			}
			else {
				cout << "Invalid role" << endl;
			}
		}

		
	}
};
#endif // !ADD_USER_CONSOLE

