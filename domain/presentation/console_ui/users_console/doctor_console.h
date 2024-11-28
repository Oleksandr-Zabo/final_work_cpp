#ifndef DOCTOR_CONSOLE
#define DOCTOR_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/doctor.h"
#include "../show_console/show_records_console.h"

class DoctorConsole :  public Doctor {
private:
    void loadDoctorInfo() {
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
            string uname, pwd, dname, dsurname;
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
	//Constructor
    DoctorConsole(const string& uname, const string& pwd, const string& name, const string& surname): Doctor(uname, pwd, name, surname)
    {
        loadDoctorInfo();
    }

	void showDoctorRecords() {
		SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
        ShowRecordsConsole showRecordsConsole;
        showRecordsConsole.showRecordsByDoctor(this->getName(), this->getSurname());
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

    void DoctorMenu() {
        int choice;
        do {
            SetConsoleTextAttribute(hConsole, ProjectColors::labels);
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
            cout << "1. Show records" << endl;
            cout << "2. Add record" << endl;
            cout << "3. Change record" << endl;
            cout << "4. Delete record" << endl;
            cout << "5. Exit" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    showDoctorRecords();
                    break;
                case 2: {
                    AddRecordConsole addRecordConsole;
                    addRecordConsole.addRecord();
                    break;
                }
                case 3: {
                    ChangeRecordConsole changeRecordConsole;
                    changeRecordConsole.changeRecord();
                    break;
                }
                case 4: {
                    DeleteRecordConsole deleteRecordConsole;
                    deleteRecordConsole.deleteRecordConsole();
                    break;
                }
                case 5:
                    SetConsoleTextAttribute(hConsole, ProjectColors::labels);
                    cout << "Exiting..." << endl;
                    SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
                    break;
                default:
					SetConsoleTextAttribute(hConsole, ProjectColors::errors);
                    cout << "Invalid choice. Please try again." << endl;
					SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
                    break;
                }
        } while (choice != 5);
    }

};

#endif // !DOCTOR_CONSOLE
