#ifndef CHANGE_RECORD_CONSOLE
#define CHANGE_RECORD_CONSOLE

#include "../../../lib.h"
#include "../delete_console/delete_record_console.h"
#include "../adds_console/add_record_console.h"
#include "../console_colors.h"

class ChangeRecordConsole : public AddRecordConsole, public DeleteRecordConsole {
public:
	void changeRecord() {
		Console_colors::inputs_color();
		string name, surname, diagnos;
		Date date_of_visit;
		cout << "Enter the name of patient: ";
		cin >> name;
		cout << "Enter the surname of patient: ";
		cin >> surname;
		cout << "Enter the date of visit(dd/mm/yyyy): ";
		try {
			string date;
			cin >> date;
			date_of_visit = Date::fromString(date);
		}
		catch (const exception& ex) {
			Console_colors::errors_color();
			cout << ex.what() << endl;
			Console_colors::default_color();
			return;
		}
		Console_colors::inputs_color();
		cout << "Enter the diagnos: ";
		getline(cin, diagnos);

		if (LoadRecord::is_FindRecord(name, surname, date_of_visit, diagnos)) {
			DeleteRecord::deleteRecord(name, surname, date_of_visit, diagnos);
			Console_colors::labels_color();
			system("pause");
			system("cls");
			cout << "Enter new data:" << endl;
			addRecord();
		}
		else {
			Console_colors::errors_color();
			cout << "Record not found!" << endl;
			Console_colors::default_color();
			system("pause");
			system("cls");
		}
	}
};
#endif // !CHANGE_RECORD_CONSOLE

