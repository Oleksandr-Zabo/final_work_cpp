#ifndef I_MEDICAL_RECORD
#define I_MEDICAL_RECORD

class IMedicalRecord abstract{
public:
    virtual void displayRecord() const = 0;
    virtual ~IMedicalRecord() = default;
};
#endif // !I_MEDICAL_RECORD

