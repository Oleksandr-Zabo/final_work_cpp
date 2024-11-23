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
    vector<User*> readAllUsers() {
        vector<User*> users;
        ifstream file("users.txt");
        string line;
        while (getline(file, line)) {
            string decodedLine = FileStorage::decrypt(line);
            User* user = createUserFromString(decodedLine);
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

    User* createUserFromString(const string& userInfo) {
        stringstream ss(userInfo);
		string username, password, name, surname, role;
        ss >> username, password, name, surname, role;

        if (role == "Admin") {
            return new Admin(username, password);
        } else if (role == "Doctor") {
            return new Doctor(username, password, name, surname);
        } else if (role == "Nurse") {
            return new Nurse(username, password, name, surname);
        } else if (role == "AdminStaff") {
            return new AdminStaff(username, password, name, surname);
        } else {
            return nullptr;
        }
    }
};

#endif // !LOAD_USER
