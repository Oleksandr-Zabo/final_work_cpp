#ifndef NURSE
#define NURSE

#include "user.h"

class Nurse : public User {
private:
    string department;  // Stores the nurse's department

public:
    // Constructor
    Nurse(const string& uname, const string& pwd, const string& dept)
        : User(uname, pwd), department(dept) {}

    // Method to display the nurse's role
    void displayRole() const override {
        cout << "Role: Nurse" << endl;
    }

    // Method to get the nurse's department
    string getDepartment() const {
        return department;
    }

    // Method to set the nurse's department
    void setDepartment(const string& dept) {
        department = dept;
    }

    // Method to assist doctors (example function)
    void assistDoctor() const {
        cout << "Nurse assisting doctor" << endl;
    }

    // Method to monitor patient vitals (example function)
    void monitorVitals() const {
        cout << "Nurse monitoring patient vitals" << endl;
    }
};

#endif // !NURSE

