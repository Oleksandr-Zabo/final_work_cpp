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
        vector<string> updatedRecords;
        bool recordFound = false;

        for (const string& record : records) {
            if (!is_FindRecord(name, surname, date_of_visit, diagnos)) {
                updatedRecords.push_back(record);
            } else {
                recordFound = true;
            }
        }

        if (recordFound) {
            string updatedData;
            for (const string& record : updatedRecords) {
                updatedData += record + "\n";
            }
            SaveRecord saveRecordInstance = SaveRecord("records.txt");
            saveRecordInstance.saveData(updatedData);
        }
    }
};
#endif // !DELETE_RECORD
