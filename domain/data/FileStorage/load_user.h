#ifndef LOAD_USER
#define LOAD_USER

#include "../../lib.h"
#include "../../data/Users/user.h"
#include "../../data/Users/admin.h"
#include "../../data/Users/doctor.h"
#include "../../data/Users/nurse.h"
#include "../../data/Users/admin_staff.h"
#include "file_storage.h"
#include "save_user.h"

class LoadUser : public FileStorage {
public:
    #include "load_user.h"
    #include <fstream>
    #include <sstream>

    vector<User*> readAllUsers() {
        vector<User*> users;
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            User* user = createUserFromString(line);
            if (user != nullptr) {
                users.push_back(user);
            }
        }
        file.close();
        return users;
    }

    User* findUser(const string& username) {
        vector<User*> users = readAllUsers();
        for (User* user : users) {
            if (user->getUsername() == username) {
                return user;
            }
        }
        return nullptr;
    }

    /*User* createUserFromString(const string& userInfo) {
        stringstream ss(userInfo);
        string type, username, password;
        ss >> type >> username >> password;

        if (type == "Admin") {
            return new Admin(username, password);
        } else if (type == "Doctor") {
            return new Doctor(username, password);
        } else if (type == "Nurse") {
            return new Nurse(username, password);
        } else if (type == "AdminStaff") {
            return new AdminStaff(username, password);
        } else {
            return nullptr;
        }
    }*/
};

#endif // !LOAD_USER
