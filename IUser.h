#ifndef I_USER
#define I_USER

class IUser abstract{
public:
    virtual void displayRole() const = 0;
    virtual ~IUser() = default;
};
#endif // !I_USER
