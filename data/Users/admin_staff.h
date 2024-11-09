#ifndef ADMIN_STAFF
#define ADMIN_STAFF

#include "user.h"

class AdminStaff : public User {
private:
    string department;  // Stores the admin staff's department

public:
    // Constructor
    AdminStaff(const string& uname, const string& pwd, const string& dept)
        : User(uname, pwd), department(dept) {}

    // Method to display the admin staff's role
    void displayRole() const override {
        cout << "Role: Admin Staff" << endl;
    }

    // Method to get the admin staff's department
    string getDepartment() const {
        return department;
    }

    // Method to set the admin staff's department
    void setDepartment(const string& dept) {
        department = dept;
    }

    // Method to manage appointments (example function)
    void manageAppointments() const {
        cout << "Admin Staff managing appointments" << endl;
    }

    // Method to handle insurance claims (example function)
    void handleInsuranceClaims() const {
        cout << "Admin Staff handling insurance claims" << endl;
    }
};

#endif // !ADMIN_STAFF
