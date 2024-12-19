#ifndef ADMIN_STAFF_CONSOLE
#define ADMIN_STAFF_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/admin_staff.h"
#include "../console_colors.h"

class AdminStaffConsole : public AdminStaff {
private:
    void loadAdminStaffInfo() {
        std::ifstream file("users.txt");
        if (!file.is_open()) {
            Console_colors::errors_color();
            cerr << "Unable to open users.txt" << std::endl;
            Console_colors::default_color();
            return;
        }

        string line;
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

    void showAllShortRecords() {
        Console_colors::record_info_color();
        ShowRecordsConsole showRecordsConsole;
        showRecordsConsole.showShortRecordsForAdminStaff();
        Console_colors::default_color();
    }

public:
    AdminStaffConsole(const string& uname, const string& pwd, const string& fname, const string& lname)
        : AdminStaff(uname, pwd, fname, lname) {
        loadAdminStaffInfo();
    }

    void AdminStaffMenu() {
        int choice;
        do {
            Console_colors::labels_color();
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
            cout << "1. Show short records" << endl;
            cout << "2. Add short record" << endl;
            cout << "3. Exit" << endl;
            Console_colors::inputs_color();
            cout << "Enter your choice: ";
            try
            {
                cin >> choice;
            }
            catch (const exception& e)
            {
                Console_colors::errors_color();
				cout << e.what() << endl;
                Console_colors::default_color();
            }
            switch (choice) {
            case 1:
                system("pause");
                system("cls");
                showAllShortRecords();
                break;
            case 2: {
                system("pause");
                system("cls");
                AddRecordConsole addRecordConsole{};
                addRecordConsole.addShortRecord();
                break;
            }
            case 3: {
                system("pause");
                system("cls");
                Console_colors::labels_color();
                cout << "Exiting..." << endl;
                Console_colors::default_color();
                exit(0);
            }
            default:
                Console_colors::errors_color();
                cout << "Invalid choice. Please try again." << endl;
                Console_colors::default_color();
                break;
            }
        } while (choice != 3);
    }
};

#endif // !ADMIN_STAFF_CONSOLE
