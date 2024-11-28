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
            SetConsoleTextAttribute(hConsole, ProjectColors::errors);
            cerr << "Unable to open users.txt" << std::endl;
            SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
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
        SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
        ShowRecordsConsole showRecordsConsole;
        showRecordsConsole.showShortRecordsForAdminStaff();
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

public:
    AdminStaffConsole(const string& uname, const string& pwd, const string& fname, const string& lname)
        : AdminStaff(uname, pwd, fname, lname) {
        loadAdminStaffInfo();
    }

    void AdminStaffMenu() {
        int choice;
        do {
            SetConsoleTextAttribute(hConsole, ProjectColors::labels);
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
            cout << "1. Show short records" << endl;
            cout << "2. Add short record" << endl;
            cout << "3. Exit" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
            cout << "Enter your choice: ";
            try
            {
                cin >> choice;
            }
            catch (const exception& e)
            {
                SetConsoleTextAttribute(hConsole, ProjectColors::errors);
				cout << e.what() << endl;
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
            }
            switch (choice) {
            case 1:
                showAllShortRecords();
                break;
            case 2: {
                AddRecordConsole addRecordConsole{};
                addRecordConsole.addShortRecord();
                break;
            }
            case 3:
				SetConsoleTextAttribute(hConsole, ProjectColors::labels);
                cout << "Exiting..." << endl;
                break;
            default:
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
                cout << "Invalid choice. Please try again." << endl;
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
                break;
            }
        } while (choice != 3);
    }
};

#endif // !ADMIN_STAFF_CONSOLE
