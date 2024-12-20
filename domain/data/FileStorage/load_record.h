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

			file.seekg(0, ios::end); // Set the pointer to the end of the file
			if (file.tellg() == 0) {//if file is empty (.telg()- get the current position in the file)
                Console_colors::errors_color();
                cout << "File is empty" << endl;
                Console_colors::default_color();
                file.close(); // Close the file before returning
                system("pause");
                system("cls");
                return records;
            }
			file.seekg(0, ios::beg); // Set the pointer to the beginning of the file

            string line;
            if (getline(file, line)) {
                line = decrypt(line); // Decrypt the line
                size_t pos = 0;
                string delimiter = "###";
                while ((pos = line.find(delimiter)) != string::npos) {
                    string record = line.substr(0, pos);
                    if (!record.empty()) {
                        records.push_back(record);
                    }
                    line.erase(0, pos + delimiter.length());
                }
                if (!line.empty()) {
                    records.push_back(line);
                }
            }
            file.close();
        } else {
            Console_colors::errors_color();
            cout << "Unable to open file" << endl;
            Console_colors::default_color();
            system("pause");
            system("cls");
        }
        if (records.empty()) {
            records = readAllRecordsReserve();
            if (records.empty()) {
                Console_colors::errors_color();
                cout << "No records found" << endl;
                Console_colors::default_color();
                system("pause");
                system("cls");
            }
        }
        return records;
    }

    vector<string> readAllRecordsReserve() {
        vector<string> records;
        ifstream file("records.txt");
        if (file.is_open()) {

            file.seekg(0, ios::end);
            if (file.tellg() == 0) {
                Console_colors::errors_color();
                cout << "File is empty" << endl;
                Console_colors::default_color();
                system("pause");
                system("cls");
                return records;
            }
            file.seekg(0, ios::beg);

            string line;
            string record;
            while (getline(file, line)) {
                line = decrypt(line); // Decrypt the line
                if (line == "###" || line == "###\n") {
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
            if (medicalRecord != nullptr && diagnosticRecord != nullptr && visitRecord != nullptr) {
                if (medicalRecord->getName() == name && medicalRecord->getSurname() == surname &&
                    diagnosticRecord->getDiagnosis() == diagnos && visitRecord->getDateOfVisit() == date_of_visit) {
                    delete medicalRecord;
                    delete diagnosticRecord;
                    delete visitRecord;
                    return true;
                }
				//if record is not found
                delete medicalRecord;
                delete diagnosticRecord;
                delete visitRecord;
                
            }
        }
        return false;
    }

	bool isFindRecordByRecord(const string& record) {
		vector<string> records = readAllRecords();
		for (const string& rec : records) {
			if (rec == record) {
				return true;
			}
		}
		return false;
	}

    bool is_FindRecordShort(const string& name, const string& surname, Date date_of_visit) {
        vector<string> records = readAllRecords();
        for (const string& record : records) {
            MedicalRecord* medicalRecord = createMedicalRecordFromString(record);
            DiagnosticRecord* diagnosticRecord = createDiagnosticRecordFromString(record);
            VisitRecord* visitRecord = createVisitRecordFromString(record);
            if (medicalRecord && diagnosticRecord && visitRecord &&
                medicalRecord->getName() == name && medicalRecord->getSurname() == surname && 
                visitRecord->getDateOfVisit() == date_of_visit) {
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
        if (start == string::npos) {
            Console_colors::errors_color();
            cout << "Unable to read record information" << endl;
            Console_colors::default_color();
            return nullptr;
        }
		size_t end = recordInfo.find("***\n", start);//***/n- what find, start - where to start
        if (end == string::npos) {
            end = recordInfo.length(); // Fix: set end to the length of the string if delimiter is not found
        }
        string medicalRecordStr = recordInfo.substr(start, end - start);
        MedicalRecord* medicalRecord = new MedicalRecord();
        medicalRecord->Medical_Record_from_string(medicalRecordStr);
        return medicalRecord;
    }

    DiagnosticRecord* createDiagnosticRecordFromString(const string& recordInfo) {
        size_t start = recordInfo.find("***\n", recordInfo.find("***\n") + 4) + 4;
        if (start == string::npos) {
            Console_colors::errors_color();
            cout << "Unable to read record information" << endl;
            Console_colors::default_color();
            return nullptr;
        }
        size_t end = recordInfo.find("***\n", start);//***/n- what find, start - where to start
        if (end == string::npos) {
            end = recordInfo.length(); // Fix: set end to the length of the string if delimiter is not found
        }
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
        if (start == string::npos) {
            Console_colors::errors_color();
            cout << "Unable to read record information" << endl;
            Console_colors::default_color();
            return nullptr;
        }
        size_t end = recordInfo.find("***\n", start);//***/n- what find, start - where to start
        if (end == string::npos) {
            end = recordInfo.length(); // Fix: set end to the length of the string if delimiter is not found
        }
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
        if (start == string::npos) {
            Console_colors::errors_color();
            cout << "Unable to read record information" << endl;
            Console_colors::default_color();
            return nullptr;
        }
        size_t end = recordInfo.find("***\n", start);
        if (end == string::npos) {
            end = recordInfo.length(); // Fix: set end to the length of the string if delimiter is not found
        }
        string visitRecordStr = recordInfo.substr(start, end - start);
        VisitRecord* visitRecord = new VisitRecord();
        visitRecord->Visit_Record_from_string(visitRecordStr);
        return visitRecord;
    }

};

#endif // !LOAD_RECORD
