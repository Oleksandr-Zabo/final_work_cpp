#ifndef MEDICAL_RECORD_CLASS
#define MEDICAL_RECORD_CLASS

#include "../../domain/lib.h"
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

class MedicalRecord : public IMedicalRecord {
protected:
    Date _date;
    string _details;

public:
    MedicalRecord(const string& d, const string& det){
		_date = Date::fromString(d);
		_details = det;
	}

	MedicalRecord(const Date d, const string& det) {
		_date = d;
		_details = det;
	}

    virtual void displayRecord() const override = 0;
};
#endif // !MEDICAL_RECORD_CLASS
