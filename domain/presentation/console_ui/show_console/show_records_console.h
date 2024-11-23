#ifndef SHOW_RECORDS_CONSOLE
#define SHOW_RECORDS_CONSOLE

#include "../../../lib.h"
#include "../../../data/MedicalRecord/medical_record.h"
#include "../../../data/MedicalRecord/visit_record.h"
#include "../../../data/MedicalRecord/diagnostic_record.h"
#include "../../../data/MedicalRecord/treatment_record.h"
#include "../../../data/FileStorage/load_record.h"

class ShowRecordsConsole : public LoadRecord {
public:
	void showAllRecords() {
		vector<string> records = LoadRecord::readAllRecords();
		for (const string& record : records) {
			MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
			DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
			TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
			VisitRecord* visitRecord = createVisitRecordFromString(record);
			medicalRecord->displayRecord();
			diagnosticRecord->displayRecord();
			treatmentRecord->displayRecord();
			visitRecord->displayRecord();
		}
	}

    void showShortRecordsForAdminStaff() {
        vector<string> records = LoadRecord::readAllRecords();
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            medicalRecord->displayRecord();
            visitRecord->displayRecord();
        }
    }

	void showRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
		string record = LoadRecord::FindRecord(name, surname, date_of_visit, diagnos);
		if (record != "Record not found") {
			MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
			DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
			TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
			VisitRecord* visitRecord = createVisitRecordFromString(record);
			medicalRecord->displayRecord();
			diagnosticRecord->displayRecord();
			treatmentRecord->displayRecord();
			visitRecord->displayRecord();
		}
		else {
			cout << "Record not found" << endl;
		}
	}



    void showRecordsByThree() {
        vector<string> records = LoadRecord::readAllRecords();
        int totalRecords = records.size();
        int currentIndex = 0;

        while (true) {
            for (int i = 0; i < 3 && currentIndex < totalRecords; ++i, ++currentIndex) {
                string record = records[currentIndex];
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
                VisitRecord* visitRecord = createVisitRecordFromString(record);
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();
            }

            if (currentIndex >= totalRecords) {
                cout << "End of records." << endl;
                break;
            }

            cout << "Options: (n)ext, (p)revious, (c)ancel: ";
            char option;
            cin >> option;

            if (option == 'n') {
                continue;
            }
            else if (option == 'p' && currentIndex > 3) {
                currentIndex -= 6; // Move back to the previous set of 3 records
            }
            else if (option == 'c') {
                break;
            }
            else {
                cout << "Invalid option. Exiting." << endl;
                break;
            }
        }
    }
};
#endif // !SHOW_RECORDS_CONSOLE
