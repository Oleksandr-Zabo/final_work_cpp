#ifndef ADMIN_CONSOLE
#define ADMIN_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_user_console.h"
#include "../delete_console/delete_user_console.h"
#include "../change_console/change_user_console.h"
#include "../show_console/show_all_users_console.h"
#include "../../../data/Users/admin.h"

class AdminConsole : public Admin{
private:

	void getAdminInfo() {
		std::ifstream file("users.txt");
		if (!file.is_open()) {
            Console_colors::errors_color();
			std::cerr << "Unable to open users.txt" << std::endl;
			return;
		}
		std::string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string uname, pwd, fname, lname;
			if (!(iss >> uname >> pwd >> fname >> lname)) { break; }
			if (uname == getUsername() && pwd == getPassword()) {
				setName(fname);
				setSurname(lname);
				break;
			}
		}
		file.close();
	}
public:
	// Default constructor
	AdminConsole() = default;

	AdminConsole(const string& username, const string& password) : Admin(username, password){
		setUsername(username);
		setPassword(password);
		getAdminInfo();
	}
    void adminMenu() {
        int choice;
        do
        {
            Console_colors::labels_color();
            cout << "1. Add user" << endl;
            cout << "2. Delete user" << endl;
            cout << "3. Change user" << endl;
            cout << "4. Show all users" << endl;
            cout << "0. Exit" << endl;
            
            Console_colors::inputs_color();
            try {
                
                do
                {
                    cout << "Enter your choice: ";
					cin >> choice;

					if (choice < 0 || choice > 4)
					{
                        Console_colors::errors_color();
						cout << "Invalid choice" << endl;
                        Console_colors::inputs_color();
					}
                } while (choice < 0 || choice > 4);
            }
            catch (const exception&)
            {
                Console_colors::errors_color();
                cout << "Invalid choice" << endl;
            }
            switch (choice)
            {
            case 1:
                    
            {
                system("pause");
                system("cls");
                AddUserConsole addUserConsole;
                addUserConsole.addUser();
                break;
            }
            case 2:
            {
                Console_colors::labels_color();
                cout << "How do you want to delete user?" << endl;
                cout << "1. By username and password" << endl;
                cout << "2. By name, surname and role" << endl;
                Console_colors::inputs_color();
                cout << "Enter your choice: ";
                int choice_1;
                try {
                    cin >> choice_1;
                }
                catch (const exception&)
                {
                    Console_colors::errors_color();
                    cout << "Invalid choice" << endl;
                }
                switch (choice_1)
                {
                case 1:
                {
                    system("pause");
                    system("cls");
                    DeleteUserConsole deleteUserConsole;
                    deleteUserConsole.deleteUserByUsernamePassword();
                    break;
                }
                case 2:
                {
                    DeleteUserConsole deleteUserConsole_1;
                    deleteUserConsole_1.deleteUserByNameSurnameRole();
                    system("pause");
                    system("cls");
                    break;
                }
                default:
                    Console_colors::errors_color();
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            }
            case 3:
            {
                Console_colors::labels_color();
                cout << "How do you want to change user?" << endl;
                cout << "1. By username and password" << endl;
                cout << "2. By name, surname and role" << endl;
                Console_colors::inputs_color();
                cout << "Enter your choice: ";
                int choice_2;
                try {
                    cin >> choice_2;
                }
                catch (const std::exception&)
                {
                    Console_colors::errors_color();
                    cout << "Invalid choice" << endl;
                }

                ChangeUserConsole changeUserConsole;
                switch (choice_2)
                {
                case 1:
                    system("pause");
                    system("cls");
                    changeUserConsole.changeUserByUsernamePassword();
                    break;
                case 2:
                    system("pause");
                    system("cls");
                    changeUserConsole.changeUserByNameSurnameRole();
                    break;
                default:
                    Console_colors::errors_color();
                    cout << "Invalid choice" << endl;
                    break;
                }
                break;
            }
            case 4:
            {
                system("pause");
                system("cls");
                ShowAllUsersConsole showAllUsersConsole;
                showAllUsersConsole.showAllUsers();
                break;
            }
            case 0:
                system("pause");
                system("cls");
				Console_colors::labels_color();
				cout << "Exiting..." << endl;
				Console_colors::default_color();
                exit(0);
            default:
                Console_colors::errors_color();
                cout << "Invalid choice" << endl;
                break;
            }
        } while (choice != 0);
    }

};
#endif // !ADMIN_CONSOLE
