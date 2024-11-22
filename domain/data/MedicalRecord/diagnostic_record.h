#ifndef DIAGNOSTIC_RECORD
#define DIAGNOSTIC_RECORD

#include "../../lib.h"

class DiagnosticRecord : public MedicalRecord {
private:
	string _diagnosis;
	string _analysis;
public:
    DiagnosticRecord(const string& diagnosis, const string& analysis) {
		_diagnosis = diagnosis;
		_analysis = analysis;
    }

    void displayRecord() const override {
		cout << "Diagnosis: " << _diagnosis << endl;
		cout << "Analysis: " << _analysis << endl;
    }

	string Diagnostic_Record_to_string() const {
		return "Diagnosis: " + _diagnosis + "\n" +
			"Analysis: " + _analysis;
	}

	void Diagnostic_Record_from_string(const string& str) {
		istringstream iss(str);
		string line;
		getline(iss, line);
		_diagnosis = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_analysis = line.substr(line.find(": ") + 2);
	}
};
#endif // !DIAGNOSTIC_RECORD

