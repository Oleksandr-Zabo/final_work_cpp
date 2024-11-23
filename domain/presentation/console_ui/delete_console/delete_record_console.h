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

class DeleteRecordConsole : public SaveRecord, public LoadRecord, public DeleteRecord {
public:
    void deleteRecordConsole() {
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
            cout << ex.what() << endl;
            return;
        }
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
            cout << "Record not found." << endl;
            return;
        }
        string updatedData;
        for (const string& record : updatedRecords) {
            updatedData += record + "\n";
        }
        LoadRecord::saveData(updatedData);
        cout << "Record deleted successfully." << endl;
    }
};
#endif // !DELETE_RECORD_CONSOLE_H
