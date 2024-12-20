#ifndef SAVE_RECORD
#define SAVE_RECORD

#include "../../lib.h"

#include "../../data/MedicalRecord/medical_record.h"
#include "../../data/MedicalRecord/diagnostic_record.h"
#include "../../data/MedicalRecord/treatment_record.h"
#include "../../data/MedicalRecord/visit_record.h"

#include "file_storage.h"

class SaveRecord : public FileStorage {
private:

    string convertRecordToString(const MedicalRecord& medical_record, const DiagnosticRecord& diagnos_record, const TreatmentRecord& treatment_record, const VisitRecord& visit_record) {
        stringstream ss;
        ss << "###\n";
        ss << "***\n";
        ss << medical_record.Medical_Record_to_string() << "\n";
        ss << "***\n";
        ss << diagnos_record.Diagnostic_Record_to_string() << "\n";
        ss << "***\n";
        ss << treatment_record.Treatment_Record_to_string() << "\n";
        ss << "***\n";
        ss << visit_record.Visit_Record_to_string();
        return ss.str();
    }

public:

	SaveRecord() : FileStorage("records.txt") {} // Initialize with a filename
    SaveRecord(const string& filename) : FileStorage(filename) {} // Initialize with a filename

	void saveRecordFunction(const MedicalRecord& medical_record, const DiagnosticRecord& diagnos_record, const TreatmentRecord& treatment_record, const VisitRecord& visit_record){
		string data = convertRecordToString(medical_record, diagnos_record, treatment_record, visit_record);
		saveData(data);
	}
};

#endif // !SAVE_RECORD
