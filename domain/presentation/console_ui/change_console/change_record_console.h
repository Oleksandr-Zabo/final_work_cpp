#ifndef CHANGE_RECORD_CONSOLE
#define CHANGE_RECORD_CONSOLE

#include "../../../lib.h"
#include "../delete_console/delete_record_console.h"
#include "../adds_console/add_record_console.h"

class ChangeRecordConsole : public AddRecordConsole, public DeleteRecordConsole, public LoadRecord {
public:
	void changeRecord() {
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
			cout << ex.what() << endl;
			return;
		}
		cout << "Enter the diagnos: ";
		cin >> diagnos;

		if (LoadRecord::is_FindRecord(name, surname, date_of_visit, diagnos)) {
			DeleteRecord::deleteRecord(name, surname, date_of_visit, diagnos);
			cout << "Enter new data:" << endl;
			addRecord();
		}
	}
};
#endif // !CHANGE_RECORD_CONSOLE

