#ifndef NURSE
#define NURSE

#include "user.h"

class Nurse : public User {
private:
    string name;       // Stores the nurse's name
    string surname;    // Stores the nurse's surname

public:
    // Constructor
    Nurse(const string& uname, const string& pwd, const string& n, const string& s)
        : User(uname, pwd), name(n), surname(s) {}

    // Method to display the nurse's role
    void displayRole() const override {
        cout << "Role: Nurse" << endl;
    }

    // Method to get the nurse role
    string getRole() const override {
        return "Nurse";
    }

	// Method to get the nurse's name
	string getName() const override{
		return name;
	}

	// Method to get the nurse's surname
	string getSurname() const override {
		return surname;
	}

};

#endif // !NURSE
