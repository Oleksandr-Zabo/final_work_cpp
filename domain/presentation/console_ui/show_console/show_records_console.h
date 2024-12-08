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
#include "../console_colors.h"

class ShowRecordsConsole : public LoadRecord {
public:
    ShowRecordsConsole() = default;
    void showAllRecords() {
        vector<string> records = LoadRecord::readAllRecords();
        int i = 1;
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);

            Console_colors::record_info_num();
            cout << "Record " << i << " :" << endl;
            Console_colors::record_info_color();
            medicalRecord->displayRecord();
            diagnosticRecord->displayRecord();
            treatmentRecord->displayRecord();
            visitRecord->displayRecord();

            i++;
        }
        Console_colors::default_color();
        system("pause");
        system("cls");
    }

    void showRecordsByDoctor(const string& doctorName, const string& doctorSurname) {
        system("cls");
        vector<string> records = LoadRecord::readAllRecords();
        int i = 1;
        for (const string& record : records) {
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (visitRecord->getDoctorName() == doctorName && visitRecord->getDoctorSurname() == doctorSurname) {
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);

				Console_colors::record_info_num();
				cout << "Record " << i << " :" << endl;
                Console_colors::record_info_color();
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();

                i++;
            }
            else {
				Console_colors::errors_color();
				cout << "Record for you not found" << endl;
				Console_colors::default_color();
            }
        }
        Console_colors::default_color();
        system("pause");
        system("cls");
    }

    void showRecordsByNurse(const string& nurseName, const string& nurseSurname) {
        vector<string> records = LoadRecord::readAllRecords();
        int i = 1;
        for (const string& record : records) {
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (visitRecord->getNurseName() == nurseName && visitRecord->getNurseSurname() == nurseSurname) {
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);

                Console_colors::record_info_num();
                cout << "Record " << i << " :" << endl;
                Console_colors::record_info_color();
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();

                i++;
            }
        }
        Console_colors::default_color();
        system("pause");
        system("cls");
    }

    void showShortRecordsForAdminStaff() {
        vector<string> records = LoadRecord::readAllRecords();
        int i = 1;
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);

            Console_colors::record_info_num();
            cout << "Record " << i << " :" << endl;
            Console_colors::record_info_color();
            medicalRecord->displayRecord();
            visitRecord->displayRecord();

            i++;
        }
        Console_colors::default_color();
        system("pause");
        system("cls");
    }

    void showRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
        string record = LoadRecord::FindRecord(name, surname, date_of_visit, diagnos);
        if (record != "Record not found") {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            Console_colors::record_info_color();
            medicalRecord->displayRecord();
            diagnosticRecord->displayRecord();
            treatmentRecord->displayRecord();
            visitRecord->displayRecord();
            Console_colors::default_color();
            system("pause");
            system("cls");
        }
        else {
            Console_colors::errors_color();
            cout << "Record not found" << endl;
            Console_colors::default_color();
            system("pause");
            system("cls");
        }
    }

    void showRecordsByThree() {
        vector<string> records = LoadRecord::readAllRecords();
        int totalRecords = records.size();
        int currentIndex = 0;
        while (true) {
            Console_colors::record_info_color();
            for (int i = 0; i < 3 && currentIndex < totalRecords; ++i, ++currentIndex) {
                string record = records[currentIndex];
                MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
                DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
                TreatmentRecord* treatmentRecord = createTreatmentRecordFromString(record);
                VisitRecord* visitRecord = createVisitRecordFromString(record);

                Console_colors::record_info_num();
				cout << "Record " << currentIndex + 1 << " :" << endl;
                Console_colors::record_info_color();
                medicalRecord->displayRecord();
                diagnosticRecord->displayRecord();
                treatmentRecord->displayRecord();
                visitRecord->displayRecord();
            }
            Console_colors::default_color();

            if (currentIndex >= totalRecords) {
                Console_colors::errors_color();
                cout << "End of records." << endl;
                Console_colors::default_color();
                break;
            }

            Console_colors::inputs_color();
            cout << "Options: (n)ext, (p)revious, (c)ancel: ";
            char option;
            cin >> option;

            if (option == 'n') {
                system("pause");
                system("cls");
                continue;
            }
            else if (option == 'p' && currentIndex > 3) {
                currentIndex -= 6; // Move back to the previous set of 3 records
                system("pause");
                system("cls");
            }
            else if (option == 'c') {
                system("pause");
                system("cls");
                break;
            }
            else {
                Console_colors::errors_color();
                cout << "Invalid option. Exiting." << endl;
                Console_colors::default_color();
                break;
            }
            Console_colors::default_color();
            system("pause");
            system("cls");
        }
    }
};

#endif // !SHOW_RECORDS_CONSOLE