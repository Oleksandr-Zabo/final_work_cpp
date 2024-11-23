#ifndef DOCTOR_CONSOLE
#define DOCTOR_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/doctor.h"
#include <fstream>
#include <sstream>

class DoctorConsole :  public Doctor {
private:
    void loadDoctorInfo() {
        std::ifstream file("users.txt");
        if (!file.is_open()) {
            std::cerr << "Unable to open users.txt" << std::endl;
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string uname, pwd, dname, dsurname;
            if (!(iss >> uname >> pwd >> dname >> dsurname)) { break; }
            if (uname == getUsername() && pwd == getPassword()) {
                setName(dname);
                setSurname(dsurname);
                break;
            }
        }
        file.close();
    }

public:
    DoctorConsole(const string& uname, const string& pwd, const string& name, const string& surname): Doctor(uname, pwd, name, surname)
    {
        loadDoctorInfo();
    }

    void showDoctorRecords() {
		ShowRecordsConsole* showRecordsConsole;
        showRecordsConsole->showRecordsByDoctor(this->getName(), this->getSurname());
    }

	void DoctorMenu() {
		int choice;
		do {
			cout << "1. Show records" << endl;
			cout << "2. Add record" << endl;
			cout << "3. Change record" << endl;
			cout << "4. Delete record" << endl;
			cout << "5. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case 1:
				showDoctorRecords();
				break;
			case 2:
				AddRecordConsole * addRecordConsole;
				addRecordConsole->addRecord();
				break;
			case 3:
				ChangeRecordConsole * changeRecordConsole;
				changeRecordConsole->changeRecord();
				break;
			case 4:
				DeleteRecordConsole * deleteRecordConsole;
				deleteRecordConsole->deleteRecordConsole();
				break;
			case 5:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				break;
			}
		} while (choice != 5);
	}

};

#endif // !DOCTOR_CONSOLE
