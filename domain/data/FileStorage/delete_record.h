#ifndef DELETE_RECORD
#define DELETE_RECORD

#include "../../lib.h"

#include "file_storage.h"
#include "save_record.h"
#include "load_record.h"

class DeleteRecord : public SaveRecord, public LoadRecord {
public:
    void deleteRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
        vector<string> records = readAllRecords();
        bool recordFound = false;

        if (!is_FindRecord(name, surname, date_of_visit, diagnos)) {
			Console_colors::errors_color();
			cout << "Record not found" << endl;
			Console_colors::default_color();
			return;
        }

		string record_to_find = FindRecord(name, surname, date_of_visit, diagnos);

        int i = 0;
        for (const string& record : records) {
            if (isFindRecordByRecord(record_to_find)) {
                recordFound = true;
				records.erase(records.begin() + i);
				break;
            }
            i++;
        }

        if (recordFound) {
            string updatedData;
            for (const string& record : records) {
                updatedData += record + "\n";
            }
            SaveRecord saveRecordInstance("records.txt");
            saveRecordInstance.saveDataClear(updatedData);
        }
    }
};
#endif // !DELETE_RECORD
