#ifndef DIAGNOSTIC_RECORD
#define DIAGNOSTIC_RECORD

#include "medical_record.h"

class DiagnosticRecord : public MedicalRecord {
public:
	DiagnosticRecord(const string& d, const string& det) : MedicalRecord(d, det) {}//DiagnosticRecord based on MedicalRecord

    DiagnosticRecord(const Date d, const string& det) : MedicalRecord(d, det) {}

    void displayRecord() const override {
        cout << "Diagnosis Record - Date: " << _date.toString() << ", Details: " << _details << endl;
    }
};
#endif // !DIAGNOSTIC_RECORD

