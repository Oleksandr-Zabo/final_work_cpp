#ifndef DELETE_RECORD_CONSOLE_H
#define DELETE_RECORD_CONSOLE_H

#include "../../../lib.h"
#include "../../../data/MedicalRecord/medical_record.h"
#include "../../../data/MedicalRecord/visit_record.h"
#include "../../../data/MedicalRecord/diagnostic_record.h"
#include "../../../data/MedicalRecord/treatment_record.h"
#include "../../../data/FileStorage/save_record.h"
#include "../../../data/FileStorage/load_record.h"
#include "../../../data/FileStorage/delete_record.h"
#include "../show_console/show_records_console.h"
#include "../console_colors.h"

class DeleteRecordConsole : public SaveRecord, public LoadRecord, public DeleteRecord {
public:
    void deleteRecordConsole() {
		ShowRecordsConsole showRecordsConsole;
		showRecordsConsole.showAllRecords();
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
        } catch (const exception& ex) {
            Console_colors::errors_color();
            cout << ex.what() << endl;
            Console_colors::default_color();
            return;
        }
        Console_colors::inputs_color();
        cout << "Enter the diagnos: ";
        cin >> diagnos;

        vector<string> records = LoadRecord::readAllRecords();
        vector<string> updatedRecords;
        bool recordFound = false;
        for (const string& record : records) {
            if (!LoadRecord::is_FindRecord(name, surname, date_of_visit, diagnos)) {
                updatedRecords.push_back(record);
            } else {
                recordFound = true;
            }
        }
        if (!recordFound) {
            Console_colors::errors_color();
            cout << "Record not found." << endl;
            Console_colors::default_color();
            system("pause");
            system("cls");
            return;
        }
        string updatedData;
        for (const string& record : updatedRecords) {
            updatedData += record + "\n";
        }
        LoadRecord::saveData(updatedData);
        Console_colors::labels_color();
        cout << "Record deleted successfully." << endl;
        system("pause");
        system("cls");
    }
};
#endif // !DELETE_RECORD_CONSOLE_H
