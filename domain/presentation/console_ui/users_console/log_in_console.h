// domain/presentation/console_ui/users_console/log_in_console.h

#ifndef LOG_IN_CONSOLE_H
#define LOG_IN_CONSOLE_H

#include "../users_console/admin_console.h"

class LogInConsole {
private:
    LoadUser* loadUser;
    User* user;
    AdminConsole* adminConsole;
    AdminStaffConsole* adminStaffConsole;
    DoctorConsole* doctorConsole;
    NurseConsole* nurseConsole;
    void loadUserFromStorage(const string& username, const string& password) {
        user = loadUser->findUser(username);
        if (user == nullptr) {
            Console_colors::errors_color();
            cout << "User not found" << endl;
            Console_colors::default_color();
            //exit from program
            system("pause");
            system("cls");
            Console_colors::labels_color();
            cout << "Exiting..." << endl;
            Console_colors::default_color();
            exit(0);
            
        }
        if (user->getPassword() != password) {
            Console_colors::errors_color();
            cout << "Invalid password" << endl;
            Console_colors::default_color();
            //exit from program
            system("pause");
            system("cls");
            Console_colors::labels_color();
            cout << "Exiting..." << endl;
            Console_colors::default_color();
            exit(0);
        }
    }
    void showMenu() {
        string role = user->getRole();
        if (role == "Admin") {
            system("pause");
            system("cls");
            adminConsole = new AdminConsole(user->getUsername(), user->getPassword());
            adminConsole->adminMenu();
        }
        else if (role == "AdminStaff") {
            system("pause");
            system("cls");
            adminStaffConsole = new AdminStaffConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
            adminStaffConsole->AdminStaffMenu();
        }
        else if (role == "Doctor") {
            system("pause");
            system("cls");
            doctorConsole = new DoctorConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
            doctorConsole->DoctorMenu();
        }
        else if (role == "Nurse") {
            system("pause");
            system("cls");
            nurseConsole = new NurseConsole(user->getUsername(), user->getPassword(), user->getName(), user->getSurname());
            nurseConsole->NurseMenu();
        }
        else {
            Console_colors::errors_color();
            cout << "Invalid role" << endl;
            Console_colors::default_color();
        }
    }
public:
    LogInConsole() {
        loadUser = new LoadUser();
        user = nullptr;
        adminConsole = nullptr;
        adminStaffConsole = nullptr;
        doctorConsole = nullptr;
        nurseConsole = nullptr;
    }

    ~LogInConsole() {
        delete loadUser;
        delete user;
        delete adminConsole;
        delete adminStaffConsole;
        delete doctorConsole;
        delete nurseConsole;
    }

    void logIn() {
        Console_colors::labels_color();
        cout << "Log in to system: " << endl;
        Console_colors::default_color();
        string username, password;
        Console_colors::inputs_color();
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        Console_colors::default_color();
        loadUserFromStorage(username, password);
        if (user != nullptr) {
            showMenu();
        }
    }
};

#endif // LOG_IN_CONSOLE_H
