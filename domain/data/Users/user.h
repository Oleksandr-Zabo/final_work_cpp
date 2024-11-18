#ifndef USER_CLASS
#define USER_CLASS

#include "../../lib.h"
#include "../Interfaces/IUser.h"

class User : public IUser {
private:
    string username;  // Stores the username
    string password;  // Stores the password

public:
    // Constructor
    User(const string& uname, const string& pwd) : username(uname), password(pwd) {}

    // Method to display the user's role
	void virtual displayRole() const override = 0;

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
