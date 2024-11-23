//includes

//lib
#include "lib.h"


//interfaces
#include "data/Interfaces/IDataStorage.h"
#include "data/Interfaces/IMedicalRecord.h"
#include "data/Interfaces/IUser.h"

//file storage
#include "data/FileStorage/file_storage.h"
#include "data/FileStorage/save_user.h"
#include "data/FileStorage/load_user.h"
#include "data/FileStorage/delete_user.h"
#include "data/FileStorage/save_record.h"
#include "data/FileStorage/load_record.h"
#include "data/FileStorage/delete_record.h"


//medical records
#include "data/MedicalRecord/medical_record.h"
#include "data/MedicalRecord/diagnostic_record.h"
#include "data/MedicalRecord/treatment_record.h"
#include "data/MedicalRecord/visit_record.h"

//users
#include "data/Users/user.h"
#include "data/Users/admin.h"
#include "data/Users/doctor.h"
#include "data/Users/nurse.h"
#include "data/Users/admin_staff.h"

//console ui
#include "presentation/console_ui/adds_console/add_record_console.h"
#include "presentation/console_ui/adds_console/add_user_console.h"

#include "presentation/console_ui/delete_console/delete_record_console.h"
#include "presentation/console_ui/delete_console/delete_user_console.h"

#include "presentation/console_ui//change_console/change_record_console.h"
#include "presentation/console_ui//change_console/change_user_console.h"

#include "presentation/console_ui/show_console/show_records_console.h"
#include "presentation/console_ui/show_console/show_all_users_console.h"