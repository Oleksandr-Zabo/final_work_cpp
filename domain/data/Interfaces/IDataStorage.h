#ifndef I_DATA_STORAGE
#define I_DATA_STORAGE
#include "../../lib.h"

class IDataStorage abstract{
public:
    virtual void saveData(const string& data) = 0;
	virtual void saveDataClear(const string& data) = 0;
    virtual string loadData() = 0;
    virtual ~IDataStorage() = default;
};

#endif // !I_DATA_STORAGE

