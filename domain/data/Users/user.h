#ifndef USER_CLASS
#define USER_CLASS

#include "../../lib.h"
#include "../Interfaces/IUser.h"

class User : public IUser {
private:
    string username;  // Stores the username
    string password;  // Stores the password
	string name;      // Stores the user's name
	string surname;   // Stores the user's surname
	string role;      // Stores the user's role

public:
    // Constructor
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}

    // Method to display the user's role
	void virtual displayRole() const override = 0;

	// Method to get the user's name
	virtual string getName() const {
		return "no-data";
	}

	// Method to set the user's name
	void setName(const string& n) {
		name = n;
	}

	// Method to get the user's surname
	virtual string getSurname() const {
		return "no-data";
	}

	// Method to set the user's surname

	void setSurname(const string& s) {
		surname = s;
	}

	// Method to get the user's role
	virtual string getRole() const {
		return "no-data";
	}

	// Method to set the user's role
	void setRole(const string& r) {
		role = r;
	}

    // Method to get the username
    string getUsername() const {
        return username;
    }

    // Method to set the username
    void setUsername(const string& uname) {
        username = uname;
    }

    // Method to get the password
    string getPassword() const {
        return password;
    }

    // Method to set the password
    void setPassword(const string& pwd) {
        password = pwd;
    }
};

#endif // !USER_CLASS
