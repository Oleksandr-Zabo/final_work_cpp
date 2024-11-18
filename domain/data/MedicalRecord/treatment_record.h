#ifndef TREATMENT_RECORD
#define TREATMENT_RECORD

#include "medical_record.h"

class TreatmentRecord : public MedicalRecord {
public:
	TreatmentRecord(const string& d, const string& det) : MedicalRecord(d, det) {}//TreatmentRecord based on MedicalRecord

	TreatmentRecord(const Date d, const string& det) : MedicalRecord(d, det) {}

	void displayRecord() const override {
		cout << "Treatment Record - Date: " << _date.toString() << ", Details: " << _details << endl;
	}
};
#endif // !TREATMENT_RECORD