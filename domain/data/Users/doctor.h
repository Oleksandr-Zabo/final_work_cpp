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

    // Method to diagnose a patient (example function)
    void diagnose() const {
        cout << "Doctor diagnosing a patient" << endl;
    }

    // Method to prescribe treatment (example function)
    void prescribeTreatment() const {
        cout << "Doctor prescribing treatment" << endl;
    }
};

#endif // !DOCTOR
