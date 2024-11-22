#ifndef TREATMENT_RECORD
#define TREATMENT_RECORD

#include "medical_record.h"

class TreatmentRecord : public MedicalRecord {
private:
	string _treatment;
	string _medicines;
public:
	TreatmentRecord(const string& treatment, const string& medicines) {
		_treatment = treatment;
		_medicines = medicines;
	}

	void displayRecord() const override {
		cout << "Treatment: " << _treatment << endl;
		cout << "Medicines: " << _medicines << endl;
	}
	
	string Treatment_Record_to_string() const {
		return "Treatment: " + _treatment + "\n" +
			"Medicines: " + _medicines;
	}

	void Treatment_Record_from_string(const string& str) {
		istringstream iss(str);
		string line;
		getline(iss, line);
		_treatment = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_medicines = line.substr(line.find(": ") + 2);
	}
};
#endif // !TREATMENT_RECORD