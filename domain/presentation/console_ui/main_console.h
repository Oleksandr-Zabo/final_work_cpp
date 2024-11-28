#ifndef MAIN_CONSOLE
#define MAIN_CONSOLE

#include "../../lib.h"
#include "users_console/log_in_console.h"

//temporary include
#include "../../data/FileStorage/save_user.h"
#include "../../data/Users/admin.h"

// MainConsole class

class MainConsole {
private:
	LogInConsole* logInConsole;

public:
	MainConsole() {
		logInConsole = new LogInConsole();
	}
	void start() {
		cout << "Welcome to the Hospital Management System" << endl;
		system("pause");
		system("cls");
		logInConsole->logIn();
	}

	~MainConsole() {
		delete logInConsole;
	}

	//temporary function
	void addAdminUser() {
		SaveUser* saveUser = new SaveUser();
		User* admin = new Admin("Admin", "password1");
		saveUser->saveUser(*admin);
		delete saveUser;
	}
};

#endif // !MAIN_CONSOLE
