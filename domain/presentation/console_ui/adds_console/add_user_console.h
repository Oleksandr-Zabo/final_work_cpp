#ifndef ADD_USER_CONSOLE
#define ADD_USER_CONSOLE

#include "../../../lib.h"
#include "../../../data/Users/admin_staff.h"
#include "../../../data/Users/doctor.h"
#include "../../../data/Users/nurse.h"
#include "../../../data/FileStorage/load_user.h"
#include "../../../data/FileStorage/save_user.h"
#include "../console_colors.h"

class AddUserConsole: public SaveUser, public LoadUser{
public:
	// Default constructor
	AddUserConsole() :SaveUser(), LoadUser() {};
	AddUserConsole(const AddUserConsole&) = delete; // Prevent copying
	AddUserConsole& operator=(const AddUserConsole&) = delete; // Prevent assignment

	// Method to add a new user
	void addUser() {
		int role;
		string username, password, name, surname;
		Console_colors::inputs_color();
		cout << "Enter the username: ";
		cin >> username;
		cout << "Enter the password: ";
		cin >> password;
		
		do
		{
			cout << "Enter the role (1- AdminStaff, 2- Doctor, 3- Nurse): ";
			cin >> role;
			try {
				if (cin.fail()) {
					throw "Invalid role";
				}
			}
			catch (const char* message) {
				Console_colors::errors_color();
				cerr << message << endl;
				cin.clear();
				cin.ignore(10000, '\n');
			}
		} while (role < 1 || role > 3);
		
		cout << "Enter the name: ";
		cin >> name;
		cout << "Enter the surname: ";
		cin >> surname;

		bool is_find_user = LoadUser::is_findUser(username);
		if (is_find_user) {
			Console_colors::errors_color();
			cout << "User already exists" << endl;
			system("pause");
			system("cls");
			return;
		}

		else {
			if (role == 1) {
				AdminStaff adminStaff(username, password, name, surname);

				saveUser(adminStaff);
			}
			else if (role == 2) {
				Doctor doctor(username, password, name, surname);
				saveUser(doctor);
			}
			else if (role == 3) {
				Nurse nurse(username, password, name, surname);
				saveUser(nurse);
			}
			else {
				Console_colors::errors_color();
				cout << "Invalid role" << endl;
			}
		}
		Console_colors::default_color();

	}
};
#endif // !ADD_USER_CONSOLE

