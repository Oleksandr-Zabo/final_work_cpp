#ifndef MAIN_CONSOLE
#define MAIN_CONSOLE

#include "../../lib.h"
#include "users_console/log_in_console.h"
#include "console_colors.h"


// MainConsole class

class MainConsole {
private:
	LogInConsole* logInConsole;

public:
	MainConsole() {
		logInConsole = new LogInConsole();
	}
	void start() {
		Console_colors::labels_color();
		cout << "Welcome to the Hospital Management System" << endl;
		Console_colors::default_color();
		system("pause");
		system("cls");
		logInConsole->logIn();
	}

	~MainConsole() {
		delete logInConsole;
	}

};

#endif // !MAIN_CONSOLE
