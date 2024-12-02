#ifndef LOAD_RECORD
#define LOAD_RECORD

#include "../../lib.h"
#include "../../data/MedicalRecord/medical_record.h"
#include "../../data/MedicalRecord/diagnostic_record.h"
#include "../../data/MedicalRecord/treatment_record.h"
#include "../../data/MedicalRecord/visit_record.h"
#include "file_storage.h"
#include "save_record.h"
#include "../../presentation/console_ui/console_colors.h"

class LoadRecord : public FileStorage {
public:
    vector<string> readAllRecords() {
        vector<string> records;
        ifstream file("records.txt");
        if (file.is_open()) {
            string line;
            string record;
            while (getline(file, line)) {
                line = decrypt(line); // Decrypt the line before processing
                if (line == "###") {
                    if (!record.empty()) {
                        records.push_back(record);
                        record.clear();
                    }
                }
                else {
                    record += line + "\n";
                }
            }
            if (!record.empty()) {
                records.push_back(record);
            }
            file.close();
        }
        else {
            Console_colors::errors_color();
            cout << "Unable to open file" << endl;
            Console_colors::default_color();
            system("pause");
            system("cls");
        }
        return records;
    }


    string FindRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
        vector<string> records = readAllRecords();
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (medicalRecord && diagnosticRecord && visitRecord &&
                medicalRecord->getName() == name && medicalRecord->getSurname() == surname &&
                diagnosticRecord->getDiagnosis() == diagnos && visitRecord->getDateOfVisit() == date_of_visit) {
                delete medicalRecord;
                delete diagnosticRecord;
                delete visitRecord;
                return record;
            }
            delete medicalRecord;
            delete diagnosticRecord;
            delete visitRecord;
        }
        Console_colors::errors_color();
        return "Record not found";
    }

    bool is_FindRecord(const string& name, const string& surname, Date date_of_visit, const string& diagnos) {
        vector<string> records = readAllRecords();
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (medicalRecord && diagnosticRecord && visitRecord &&
                medicalRecord->getName() == name && medicalRecord->getSurname() == surname &&
                diagnosticRecord->getDiagnosis() == diagnos && visitRecord->getDateOfVisit() == date_of_visit) {
                delete medicalRecord;
                delete diagnosticRecord;
                delete visitRecord;
                return true;
            }
            delete medicalRecord;
            delete diagnosticRecord;
            delete visitRecord;
        }
        return false;
    }

    MedicalRecord* createMedicalRecordFromString(const string& recordInfo) {
        size_t start = recordInfo.find("***\n") + 4;
        size_t end = recordInfo.find("\n***", start);
        if (start == string::npos || end == string::npos) {
            return nullptr; // or handle the error as needed
        }
        string medicalRecordStr = recordInfo.substr(start, end - start);
        MedicalRecord* medicalRecord = new MedicalRecord();
        medicalRecord->Medical_Record_from_string(medicalRecordStr);
        return medicalRecord;
    }

    DiagnosticRecord* createDiagnosticRecordFromString(const string& recordInfo) {
        size_t start = recordInfo.find("***\n", recordInfo.find("***\n") + 4) + 4;
        size_t end = recordInfo.find("\n***", start);
        if (start == string::npos || end == string::npos) {
            return nullptr; // or handle the error as needed
        }
        string diagnosticRecordStr = recordInfo.substr(start, end - start);
        DiagnosticRecord* diagnosticRecord = new DiagnosticRecord();
        diagnosticRecord->Diagnostic_Record_from_string(diagnosticRecordStr);
        return diagnosticRecord;
    }

    TreatmentRecord* createTreatmentRecordFromString(const string& recordInfo) {
        size_t start = recordInfo.find("***\n", recordInfo.find("***\n", recordInfo.find("***\n") + 4) + 4) + 4;
        size_t end = recordInfo.find("\n***", start);
        if (start == string::npos || end == string::npos) {
            return nullptr; // or handle the error as needed
        }
        string treatmentRecordStr = recordInfo.substr(start, end - start);
        TreatmentRecord* treatmentRecord = new TreatmentRecord();
        treatmentRecord->Treatment_Record_from_string(treatmentRecordStr);
        return treatmentRecord;
    }

    VisitRecord* createVisitRecordFromString(const string& recordInfo) {
        size_t start = recordInfo.find("***\n", recordInfo.find("***\n", recordInfo.find("***\n", recordInfo.find("***\n") + 4) + 4) + 4) + 4;
        size_t end = recordInfo.find("\n***", start);
        if (start == string::npos || end == string::npos) {
            return nullptr; // or handle the error as needed
        }
        string visitRecordStr = recordInfo.substr(start, end - start);
        VisitRecord* visitRecord = new VisitRecord();
        visitRecord->Visit_Record_from_string(visitRecordStr);
        return visitRecord;
    }
};

#endif // !LOAD_RECORD
