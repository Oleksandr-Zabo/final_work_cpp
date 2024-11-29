#ifndef DOCTOR_CONSOLE
#define DOCTOR_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/doctor.h"
#include "../console_colors.h"

class DoctorConsole :  public Doctor {
private:
    void loadDoctorInfo() {
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
        Console_colors::record_info_color();
        ShowRecordsConsole showRecordsConsole;
        showRecordsConsole.showRecordsByDoctor(this->getName(), this->getSurname());
        Console_colors::default_color();
    }

    void DoctorMenu() {
        int choice;
        do {
            Console_colors::labels_color();
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
            cout << "1. Show records" << endl;
            cout << "2. Add record" << endl;
            cout << "3. Change record" << endl;
            cout << "4. Delete record" << endl;
            cout << "5. Exit" << endl;
            Console_colors::inputs_color();
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    showDoctorRecords();
                    break;
                case 2: {
                    system("pause");
                    system("cls");
                    AddRecordConsole addRecordConsole;
                    addRecordConsole.addRecord();
                    break;
                }
                case 3: {
                    system("pause");
                    system("cls");
                    ChangeRecordConsole changeRecordConsole;
                    changeRecordConsole.changeRecord();
                    break;
                }
                case 4: {
                    system("pause");
                    system("cls");
                    DeleteRecordConsole deleteRecordConsole;
                    deleteRecordConsole.deleteRecordConsole();
                    break;
                }
                case 5:
                    system("pause");
                    system("cls");
                    Console_colors::labels_color();
                    cout << "Exiting..." << endl;
                    Console_colors::default_color();
                    exit(0);
                    break;
                default:
                    Console_colors::errors_color();
                    cout << "Invalid choice. Please try again." << endl;
                    Console_colors::default_color();
                    break;
                }
        } while (choice != 5);
    }

};

#endif // !DOCTOR_CONSOLE
