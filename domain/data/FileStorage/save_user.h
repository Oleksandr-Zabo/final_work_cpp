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
protected:
    string convertUserToString(const User& user) {
        stringstream ss;
        ss << user.getUsername() << " ";
        ss << user.getPassword() << " ";
        ss << user.getName() << " ";
        ss << user.getSurname() << " ";
        ss << user.getRole();
        return ss.str();
    }

public:
    SaveUser() = default;

    void saveUser(const User& user) {
        string data = convertUserToString(user);
        saveData(data);
    }

};

#endif // !SAVE_USER
