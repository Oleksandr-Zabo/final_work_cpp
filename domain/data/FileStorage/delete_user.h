#ifndef DELETE_USER
#define DELETE_USER

#include "../../lib.h"
#include "file_storage.h"
#include "save_user.h"
#include "load_user.h"

class DeleteUser : public LoadUser, public SaveUser {
public:
    void delete_user(const User& user) {
        vector<User*> users = readAllUsers();
        auto it = remove_if(users.begin(), users.end(), [&](User* u) {
            return u->getUsername() == user.getUsername();
            });

        if (it != users.end()) {
            users.erase(it, users.end());
            ofstream outFile("users.txt");
            for (const auto& u : users) {
                outFile << SaveUser::encrypt(convertUserToString(*u)) << endl;
            }
            outFile.close();
        }
    }

    void delete_user_by_username_password(const string& username, const string& password) {
        vector<User*> users = readAllUsers();
        auto it = find_if(users.begin(), users.end(), [&](User* u) {
            return u->getUsername() == username && u->getPassword() == password;
        });

        if (it != users.end()) {
            delete_user(**it);
        }
    }

    void delete_user_by_name_surname_role(const string& name, const string& surname, int role) {
        vector<User*> users = readAllUsers();
        auto it = find_if(users.begin(), users.end(), [&](User* u) {
            return (role == 1 && u->getRole() == "Doctor" && u->getName() == name && u->getSurname() == surname) ||
                (role == 2 && u->getRole() == "Nurse" && u->getName() == name && u->getSurname() == surname) ||
                (role == 3 && u->getRole() == "AdminStaff" && u->getName() == name && u->getSurname() == surname);
        });

        if (it != users.end()) {
            delete_user(**it);
        }
    }
};
#endif // DELETE_USER
