#ifndef ADMIN
#define ADMIN

#include "user.h"

class Admin : public User {
public:
    // Constructor
    Admin(const string& uname, const string& pwd) : User(uname, pwd) {}

    // Method to display the admin's role
    void displayRole() const override {
        cout << "Role: Admin" << endl;
    }

    // Method to manage users (example function)
    void manageUsers() const {
        cout << "Admin managing users" << endl;
    }

    // Method to monitor system security (example function)
    void monitorSecurity() const {
        cout << "Admin monitoring system security" << endl;
    }
};

#endif // !ADMIN

