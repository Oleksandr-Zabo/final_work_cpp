#ifndef SHOW_RECORDS_CONSOLE
#define SHOW_RECORDS_CONSOLE


#include "../../../lib.h"
#include "../../../data/MedicalRecord/medical_record.h"
#include "../../../data/MedicalRecord/visit_record.h"
#include "../../../data/MedicalRecord/diagnostic_record.h"
#include "../../../data/MedicalRecord/treatment_record.h"
#include "../../../data/FileStorage/save_record.h"
#include "../../../data/FileStorage/load_record.h"
#include "../../../data/FileStorage/delete_record.h"

class ShowRecordsConsole : public LoadRecord {
public:
    ShowRecordsConsole() = default;
    void showAllRecords() {
        vector<string> records = LoadRecord::readAllRecords();
        SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
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
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

    void showRecordsByDoctor(const string& doctorName, const string& doctorSurname) {
        vector<string> records = LoadRecord::readAllRecords();
        SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
        for (const string& record : records) {
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (visitRecord->getDoctorName() == doctorName && visitRecord->getDoctorSurname() == doctorSurname) {
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();
            }
        }
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

    void showRecordsByNurse(const string& nurseName, const string& nurseSurname) {
        vector<string> records = LoadRecord::readAllRecords();
		SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
        for (const string& record : records) {
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (visitRecord->getNurseName() == nurseName && visitRecord->getNurseSurname() == nurseSurname) {
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();
            }
        }
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

    void showShortRecordsForAdminStaff() {
        vector<string> records = LoadRecord::readAllRecords();
        SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            medicalRecord->displayRecord();
            visitRecord->displayRecord();
        }
		SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
    }

    void showRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
        string record = LoadRecord::FindRecord(name, surname, date_of_visit, diagnos);
        if (record != "Record not found") {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
            medicalRecord->displayRecord();
            diagnosticRecord->displayRecord();
            treatmentRecord->displayRecord();
            visitRecord->displayRecord();
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
        }
        else {
            SetConsoleTextAttribute(hConsole, ProjectColors::errors);
            cout << "Record not found" << endl;
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
        }
    }

    void showRecordsByThree() {
        vector<string> records = LoadRecord::readAllRecords();
        int totalRecords = records.size();
        int currentIndex = 0;

        while (true) {
            SetConsoleTextAttribute(hConsole, ProjectColors::record_info);
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
			SetConsoleTextAttribute(hConsole, ProjectColors::defoult);

            if (currentIndex >= totalRecords) {
                SetConsoleTextAttribute(hConsole, ProjectColors::errors);
                cout << "End of records." << endl;
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
                break;
            }

            SetConsoleTextAttribute(hConsole, ProjectColors::inputs);
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
				SetConsoleTextAttribute(hConsole, ProjectColors::errors);
                cout << "Invalid option. Exiting." << endl;
				SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
                break;
            }
            SetConsoleTextAttribute(hConsole, ProjectColors::defoult);
        }
    }
};

#endif // !SHOW_RECORDS_CONSOLE