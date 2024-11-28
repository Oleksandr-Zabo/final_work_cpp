#ifndef MAIN_CONSOLE
#define MAIN_CONSOLE

#include "../../lib.h"
#include "users_console/log_in_console.h"


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

};

#endif // !MAIN_CONSOLE
