#ifndef NURSE_CONSOLE
#define NURSE_CONSOLE

#include "../../../lib.h"
#include "../adds_console/add_record_console.h"
#include "../delete_console/delete_record_console.h"
#include "../change_console/change_record_console.h"
#include "../show_console/show_records_console.h"
#include "../../../data/Users/nurse.h"
#include "../console_colors.h"

class NurseConsole : public Nurse {
private:
	void loadNurseInfo() {
		std::ifstream file("users.txt");
		if (!file.is_open()) {
			Console_colors::errors_color();
			std::cerr << "Unable to open users.txt" << std::endl;
			return;
		}

		string line;
		while (getline(file, line)) {
			istringstream iss(line);
			string uname, pwd, nname, nsurname;
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
			Console_colors::labels_color();
			cout << "Welcome, " << getName() << " " << getSurname() << "!" << endl;
			cout << "1. Show records" << endl;
			cout << "2. Exit" << endl;
			Console_colors::default_color();
			cout << "Enter your choice: ";
			try {
				cin >> choice;
			}
			catch (ios_base::failure& fail) {
				Console_colors::errors_color();
				cerr << "Invalid input. Please try again." << endl;
				cin.clear();
				cin.ignore();
				Console_colors::default_color();
			}
			
			switch (choice) {
			case 1:
				showNurseRecords();
				break;
			case 2:
				Console_colors::labels_color();
				cout << "Exiting..." << endl;
				Console_colors::default_color();
				exit(0);
			default:
				Console_colors::errors_color();
				cout << "Invalid choice. Please try again." << endl;
				Console_colors::default_color();
				break;
			}
		} while (choice != 2);
	}
};

#endif // !NURSE_CONSOLE
