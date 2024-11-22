#ifndef MEDICAL_RECORD_CLASS
#define MEDICAL_RECORD_CLASS

#include "../../lib.h"
#include "../Interfaces/IMedicalRecord.h"

struct Date {
private:
    int _day;
    int _month;
    int _year;
public:
	Date(){
		_day = 0;
		_month = 0;
		_year = 0;
	}
	Date(int day, int month, int year) : _day(day), _month(month), _year(year) {
		_day = day;
		_month = month;
		_year = year;
	}

	int getDay() const { return _day; }

	int getMonth() const { return _month; }

	int getYear() const { return _year; }

	void setDay(int day) { _day = day; }

	void setMonth(int month) { _month = month; }

	void setYear(int year) { _year = year; }

	string toString() const {
		return to_string(_day) + "/" + to_string(_month) + "/" + to_string(_year);
	}

	static Date fromString(const string& str) {
		Date date;
		stringstream ss(str);
		string token;
		vector<string> tokens;
		while (getline(ss, token, '/')) {
			tokens.push_back(token);
		}
		date.setDay(stoi(tokens[0]));
		date.setMonth(stoi(tokens[1]));
		date.setYear(stoi(tokens[2]));
		return date;
	}

};

struct InsurancePolicy {
    string policyNumber;
    string holderName;
    string holderAddress;
    string insuranceCompany;
    double coverageAmount;
    Date startDate;
    Date endDate;

    // Default constructor
    InsurancePolicy() {
        policyNumber = "";
        holderName = "";
        holderAddress = "";
        insuranceCompany = "";
        coverageAmount = 0.0;
        startDate = Date();
        endDate = Date();
    }

    // Parameterized constructor
    InsurancePolicy(string policyNum, string holderNm, string holderAddr, string insuranceComp, double coverageAmt, Date startDt, Date endDt) {
        policyNumber = policyNum;
        holderName = holderNm;
        holderAddress = holderAddr;
        insuranceCompany = insuranceComp;
        coverageAmount = coverageAmt;
        startDate = startDt;
        endDate = endDt;
    }

    string toString() const {
        return "Policy Number: " + policyNumber + "\n" +
            "Holder Name: " + holderName + "\n" +
            "Holder Address: " + holderAddress + "\n" +
            "Insurance Company: " + insuranceCompany + "\n" +
            "Coverage Amount: " + to_string(coverageAmount) + "\n" +
            "Start Date: " + startDate.toString() + "\n" +
            "End Date: " + endDate.toString();
    }

    void fromString(const string& str) {
        istringstream iss(str);
        string line;

        getline(iss, line);
        policyNumber = line.substr(line.find(": ") + 2);

        getline(iss, line);
        holderName = line.substr(line.find(": ") + 2);

        getline(iss, line);
        holderAddress = line.substr(line.find(": ") + 2);

        getline(iss, line);
        insuranceCompany = line.substr(line.find(": ") + 2);

        getline(iss, line);
        coverageAmount = stod(line.substr(line.find(": ") + 2));

        getline(iss, line);
        startDate = Date::fromString(line.substr(line.find(": ") + 2));

        getline(iss, line);
        endDate = Date::fromString(line.substr(line.find(": ") + 2));
    }
};

class MedicalRecord : public IMedicalRecord {
protected:
	string _name_of_patient;
	string _surname_of_patient;
    Date _date_of_birth;
	InsurancePolicy _policy;
public:
	MedicalRecord() {
		_name_of_patient = "";
		_surname_of_patient = "";
		_date_of_birth = Date();
		_policy = InsurancePolicy();
	}

	MedicalRecord(const string& name, const string& surname, Date date_of_birth, InsurancePolicy policy){
		_name_of_patient = name;
		_surname_of_patient = surname;
		_date_of_birth = date_of_birth;
		_policy = policy;

    }

	MedicalRecord(const MedicalRecord& medical_record) {
		_name_of_patient = medical_record._name_of_patient;
		_surname_of_patient = medical_record._surname_of_patient;
		_date_of_birth = medical_record._date_of_birth;
		_policy = medical_record._policy;
	}

    void displayRecord() const override {
        cout << "Name of patienn: " << _name_of_patient << endl;
		cout << "Surname of patient: " << _surname_of_patient << endl;
		cout << "Date of birth: " << _date_of_birth.toString() << endl;
		cout << "Insurance policy: " << _policy.toString() << endl;
    }

	string Medical_Record_to_string() const {
		return "Name of patient: " + _name_of_patient + "\n" +
			"Surname of patient: " + _surname_of_patient + "\n" +
			"Date of birth: " + _date_of_birth.toString() + "\n" +
			"Insurance policy: " + _policy.toString();
	}

	void Medical_Record_from_string(const string& str) {
		istringstream iss(str);
		string line;
		getline(iss, line);
		_name_of_patient = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_surname_of_patient = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_date_of_birth = Date::fromString(line.substr(line.find(": ") + 2));
		getline(iss, line);
		_policy.fromString(line.substr(line.find(": ") + 2));
	}

};
#endif // !MEDICAL_RECORD_CLASS
