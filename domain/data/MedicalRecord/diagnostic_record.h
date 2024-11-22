#ifndef DIAGNOSTIC_RECORD
#define DIAGNOSTIC_RECORD

#include "../../lib.h"

class DiagnosticRecord : public MedicalRecord {
private:
	string _diagnosis;
	string _analysis;
public:
	DiagnosticRecord() {
		_diagnosis = "no diagnosis";
		_analysis = "No analysis information";
	}

    DiagnosticRecord(const string& diagnosis, const string& analysis) {
		_diagnosis = diagnosis; 
		_analysis = analysis;
    }

	DiagnosticRecord(const DiagnosticRecord& diagnostic_record) {
		_diagnosis = diagnostic_record._diagnosis;
		_analysis = diagnostic_record._analysis;
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

	string getDiagnosis() const {
		return _diagnosis;
	}
};
#endif // !DIAGNOSTIC_RECORD

