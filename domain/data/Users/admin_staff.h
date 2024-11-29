#ifndef ADMIN_STAFF
#define ADMIN_STAFF

#include "user.h"

class AdminStaff : public User {
private:
    string name;      // Stores the admin staff's name
    string surname;   // Stores the admin staff's surname

public:
    // Constructor
    AdminStaff(const string& uname, const string& pwd, const string& fname, const string& lname)
        : User(uname, pwd), name(fname), surname(lname) {}

    // Method to display the admin staff's role
    void displayRole() const override {
        cout << "Role: Admin Staff" << endl;
    }

    // Method to get the admin_staff role
    string getRole() const override{
        return "Admin staff";
    }

	// Method to get the admin staff's name
	string getName() const override {
		return name;
	}

    // Method to get the admin staff's surname
    string getSurname() const override{
        return surname;
    }

    // Method to set the admin staff's surname
    void setSurname(const string& lname) {
        surname = lname;
    }
};

#endif // !ADMIN_STAFF
