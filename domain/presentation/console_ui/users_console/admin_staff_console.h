#ifndef ADMIN_STAFF_CONSOLE
#define ADMIN_STAFF_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/admin_staff.h"

class AdminStaffConsole : public AdminStaff {
private:
    void loadAdminStaffInfo() {
        std::ifstream file("users.txt");
        if (!file.is_open()) {
            std::cerr << "Unable to open users.txt" << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string uname, pwd, fname, lname;
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
        ShowRecordsConsole* showRecordsConsole;
        showRecordsConsole->showShortRecordsForAdminStaff();
    }

public:
    AdminStaffConsole(const string& uname, const string& pwd, const string& fname, const string& lname)
        : AdminStaff(uname, pwd, fname, lname) {
        loadAdminStaffInfo();
    }

    void AdminStaffMenu() {
        int choice;
        do {
            cout << "1. Show short records" << endl;
            cout << "2. Add short record" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
            case 1:
                showAllShortRecords();
                break;
            case 2: {
                AddRecordConsole* addRecordConsole;
                addRecordConsole->addShortRecord();
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 3);
    }
};

#endif // !ADMIN_STAFF_CONSOLE
