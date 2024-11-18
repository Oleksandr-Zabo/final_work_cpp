#ifndef SAVE_USER
#define SAVE_USER

#include "../../lib.h"
#include "../../data/Users/user.h"
#include "../../data/Users/admin.h"
#include "../../data/Users/doctor.h"
#include "../../data/Users/nurse.h"
#include "../../data/Users/admin_staff.h"
#include "file_storage.h"

class SaveUser : public FileStorage {
private:
    string convertUserToString(const User& user) {
        stringstream ss;
        ss << "Username: " << user.getUsername() << ", ";
        ss << "Password: " << user.getPassword() << ", ";
        if (dynamic_cast<const Admin*>(&user) == nullptr) {
            ss << "Name: " << user.getName() << ", ";
            ss << "Surname: " << user.getSurname() << ", ";
        }
        ss << "Role: " << user.getRole();
        return ss.str();
    }

public:
    void saveUser(const User& user) {
        string data = convertUserToString(user);
        saveData(data);
    }

};

#endif // !SAVE_USER
