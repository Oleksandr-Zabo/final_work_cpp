#ifndef NURSE_CONSOLE
#define NURSE_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/nurse.h"

class NurseConsole : public Nurse {
private:
	void loadNurseInfo() {
		std::ifstream file("users.txt");
		if (!file.is_open()) {
			std::cerr << "Unable to open users.txt" << std::endl;
			return;
		}

		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string uname, pwd, nname, nsurname;
			if (!(iss >> uname >> pwd >> nname >> nsurname)) { break; }
			if (uname == getUsername() && pwd == getPassword()) {
				setName(nname);
				setSurname(nsurname);
				break;
			}
		}
		file.close();
	}

public:
	NurseConsole(const string& uname, const string& pwd, const string& name, const string& surname) : Nurse(uname, pwd, name, surname) {
		loadNurseInfo();
	}

	void showNurseRecords() {
		ShowRecordsConsole showRecordsConsole;
		showRecordsConsole.showRecordsByNurse(this->getName(), this->getSurname());
	}

	void NurseMenu() {
		int choice;
		do {
			SetConsoleTextAttribute(hConsole, ProjectColors::labels);
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
			cout << "1. Show records" << endl;
			cout << "2. Exit" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
			cout << "Enter your choice: ";
			try {
				cin >> choice;
			}
			catch (ios_base::failure& fail) {
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
				cerr << "Invalid input. Please try again." << endl;
				cin.clear();
				cin.ignore();
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
			}
			
			switch (choice) {
			case 1:
				showNurseRecords();
				break;
			case 2:
				SetConsoleTextAttribute(hConsole, ProjectColors::labels);
				cout << "Exiting..." << endl;
				break;
			default:
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
				cout << "Invalid choice. Please try again." << endl;
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
				break;
			}
		} while (choice != 2);
	}
};

#endif // !NURSE_CONSOLE
