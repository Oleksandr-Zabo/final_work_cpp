#ifndef SAVE_RECORD
#define SAVE_RECORD

#include "../../lib.h"

#include "../../data/MedicalRecord/medical_record.h"
#include "../../data/MedicalRecord/diagnostic_record.h"
#include "../../data/MedicalRecord/treatment_record.h"
#include "../../data/MedicalRecord/visit_record.h"

#include "file_storage.h"
#include "save_user.h"

class SaveRecord : public FileStorage {
private:
    /*string convertUserToString(const User& user) {
        stringstream ss;
        ss << user.getUsername() << " ";
        ss << user.getPassword() << " ";
        ss << user.getName() << " ";
        ss << user.getSurname() << " ";
        ss << user.getRole();
        return ss.str();
    }*/

    string convertRecordToString(const MedicalRecord& medical_record, const DiagnosticRecord& diagnos_record, const TreatmentRecord& treatment_record, const VisitRecord& visit_record) {
        stringstream ss;
        return ss.str();
    }

public:
    /*void saveUser(const User& user) {
        string data = convertUserToString(user);
        saveData(data);
    }*/
};

#endif // !SAVE_RECORD
