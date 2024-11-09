#ifndef VISIT_RECORD
#define VISIT_RECORD

#include "medical_record.h"

class VisitRecord : public MedicalRecord {
public:
	VisitRecord(const string& d, const string& det) : MedicalRecord(d, det) {}//VisitRecord based on MedicalRecord

	VisitRecord(const Date d, const string& det) : MedicalRecord(d, det) {}

	void displayRecord() const override {
		cout << "Visit Record - Date: " << _date.toString() << ", Details: " << _details << endl;
	}
};
#endif // !VISIT_RECORD