#ifndef DOCTOR
#define DOCTOR

#include "user.h"

class Doctor : public User {
private:
    string name;      // Stores the doctor's name
    string surname;   // Stores the doctor's surname

public:
    // Constructor
    Doctor(const string& uname, const string& pwd, const string& name, const string& surname)
        : User(uname, pwd), name(name), surname(surname) {}

    // Method to display the doctor's role
    void displayRole() const override {
        cout << "Role: Doctor" << endl;
    }

    // Method to get the doctor role
    string getRole() const override {
        return "Doctor";
    }

	// Method to get the doctor's name
	string getName() const override{
		return name;
	}

	// Method to get the doctor's surname
	string getSurname() const override{
		return surname;
	}

};

#endif // !DOCTOR
