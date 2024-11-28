#ifndef LOG_IN_CONSOLE
#define LOG_IN_CONSOLE
#include "../../../lib.h"
#include "../users_console/admin_console.h"
#include "../users_console/admin_staff_console.h"
#include "../users_console/doctor_console.h"
#include "../users_console/nurse_console.h"
#include "../../../data/FileStorage/load_user.h"

class LogInConsole {
private:
	LoadUser* loadUser;
	User* user;
	AdminStaffConsole* adminStaffConsole;
	DoctorConsole* doctorConsole;
	NurseConsole* nurseConsole;
	void loadUserFromStorage(const string& username, const string& password) {
		user = loadUser->findUser(username);
		if (user == nullptr) {
			SetConsoleTextAttribute(hConsole, ProjectColors::errors);
			cout << "User not found" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
			return;
		}
		if (user->getPassword() != password) {
			SetConsoleTextAttribute(hConsole, ProjectColors::errors);
			cout << "Invalid password" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
			return;
		}
	}
	void showMenu() {
		string role = user->getRole();
		if (role == "Admin") {
            adminConsole = new AdminConsole(user->getUsername(), user->getPassword());
			adminConsole->adminMenu();
		}
		else if (role == "Admin staff") {
			adminStaffConsole = new AdminStaffConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
			adminStaffConsole->AdminStaffMenu();
		}
		else if (role == "Doctor") {
			doctorConsole = new DoctorConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
			doctorConsole->DoctorMenu();
		}
		else if (role == "Nurse") {
			nurseConsole = new NurseConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
			nurseConsole->NurseMenu();
		}
		else {
			SetConsoleTextAttribute(hConsole, ProjectColors::errors);
			cout << "Invalid role" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
		}
	}
public:
    
	void logIn() {
		SetConsoleTextAttribute(hConsole, ProjectColors::labels);
		cout << "Log in to system: " << endl;
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
		system("pause");
		string username, password;
		SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
		cout << "Enter username: ";
		cin >> username;
		cout << "Enter password: ";
		cin >> password;
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
		loadUserFromStorage(username, password);
		if (user != nullptr) {
			showMenu();
		}
	}
};
#endif // !LOG_IN_CONSOLE

