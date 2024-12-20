#ifndef VISIT_RECORD
#define VISIT_RECORD

#include "medical_record.h"

class VisitRecord : public MedicalRecord {
private:
	Date _date_of_visit;
	string _name_of_doctor;
	string _surname_of_doctor;
	string _name_of_nurse;
	string _surname_of_nurse;
public:
	VisitRecord() {
		_date_of_visit = Date();
		_name_of_doctor = "No_name_doctor";
		_surname_of_doctor = "No_surname_doctor";
		_name_of_nurse = "No_name_nurse";
		_surname_of_nurse = "No_surname_nurse";
	}

	VisitRecord(const Date& date, const string& doctor_name, const string& doctor_surname, const string& nurse_name, const string& nurse_surname) {
		_date_of_visit = date;
		_name_of_doctor = doctor_name;
		_surname_of_doctor = doctor_surname;
		_name_of_nurse = nurse_name;
		_surname_of_nurse = nurse_surname;
	}

	VisitRecord(const VisitRecord& visit_record) {
		_date_of_visit = visit_record._date_of_visit;
		_name_of_doctor = visit_record._name_of_doctor;
		_surname_of_doctor = visit_record._surname_of_doctor;
		_name_of_nurse = visit_record._name_of_nurse;
		_surname_of_nurse = visit_record._surname_of_nurse;
	}

	void displayRecord() const override {
		cout << "Visit Record - Date: " << _date_of_visit.toString() << "\nDoctor: " << _name_of_doctor << " " << _surname_of_doctor << "\nNurse: " << _name_of_nurse << " " << _surname_of_nurse << endl;
	}

	string Visit_Record_to_string() const {
		return "Visit Record - Date: " + _date_of_visit.toString() + "\n" +
			"Doctor name: " + _name_of_doctor + "\n" + "Doctor surname: " + _surname_of_doctor + "\n" +
			"Nurse name: " + _name_of_nurse + "\n" + "Nurse surname: " + _surname_of_nurse;
	}

	void Visit_Record_from_string(const string& str) {
		istringstream iss(str);
		string line;
		getline(iss, line);
		_date_of_visit = Date::fromString(line.substr(line.find(": ") + 2));
		getline(iss, line);
		_name_of_doctor = line.substr(line.find(": ") + 2);//for doctor name
		getline(iss, line);
		_surname_of_doctor = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_name_of_nurse = line.substr(line.find(": ") + 2);
		getline(iss, line);
		_surname_of_nurse = line.substr(line.find(": ") + 2);
	}

	string getDoctorName() const { 
		return _name_of_doctor; 
	}
	string getDoctorSurname() const { 
		return _surname_of_doctor; 
	}

	string getNurseName() const { 
		return _name_of_nurse; 
	}
	string getNurseSurname() const { 
		return _surname_of_nurse; 
	}

	Date getDateOfVisit() const {
		return _date_of_visit;
	}

	string getStringDateOfVisit() const {
		return _date_of_visit.toString();
	}
};
#endif // !VISIT_RECORD