#ifndef DOCTOR
#define DOCTOR

#include "user.h"

class Doctor : public User {
private:
    string specialty;  // Stores the doctor's specialty

public:
    // Constructor
    Doctor(const string& uname, const string& pwd, const string& spec)
        : User(uname, pwd), specialty(spec) {}

    // Method to display the doctor's role
    void displayRole() const override {
        cout << "Role: Doctor" << endl;
    }

    // Method to get the doctor's specialty
    string getSpecialty() const {
        return specialty;
    }

    // Method to set the doctor's specialty
    void setSpecialty(const string& spec) {
        specialty = spec;
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

