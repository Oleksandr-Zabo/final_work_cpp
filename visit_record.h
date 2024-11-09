#ifndef VISIT_RECORD
#define VISIT_RECORD

#include "medical_record.h"

class VisitRecord : public IMedicalRecord {
public:
	VisitRecord(const string& d, const string& det) : IMedicalRecord(d, det) {}//VisitRecord based on MedicalRecord

	VisitRecord(const Date d, const string& det) : IMedicalRecord(d, det) {}

	void displayRecord() const override {
		cout << "Visit Record - Date: " << _date.toString() << ", Details: " << _details << endl;
	}
};
#endif // !VISIT_RECORD