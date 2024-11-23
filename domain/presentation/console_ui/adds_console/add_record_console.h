#ifndef ADD_RECORD_CONSOLE
#define ADD_RECORD_CONSOLE

#include "../../../lib.h"
#include "../../../data/MedicalRecord/medical_record.h"
#include "../../../data/MedicalRecord/visit_record.h"
#include "../../../data/MedicalRecord/diagnostic_record.h"
#include "../../../data/MedicalRecord/treatment_record.h"
#include "../../../data/FileStorage/save_record.h"
#include "../../../data/FileStorage/load_record.h"
#include "../../../data/FileStorage/delete_record.h"

class AddRecordConsole : public SaveRecord, public LoadRecord, public DeleteRecordConsole {
public:
	void addRecord() {
		string name, surname;
		InsurancePolicy info_about_insurance;
		Date date_of_birth;
		cout << "Enter the name of patient: ";
		cin >> name;
		cout << "Enter the surname of patient: ";
		cin >> surname;
		cout << "Enter the date of birth of patient(dd/mm/yyyy): ";
		try
		{
			string date;
			cin >> date;
			date_of_birth.fromString(date);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		
		cout << "Enter the information about insurance: ";
		string policy_number, address, insurance_company;
		double amount_of_compensation;
		Date date_of_start, date_of_end;
		cout << "Enter the policy number: ";
		cin >> policy_number;
		cout << "Enter the address: ";
		cin >> address;
		cout << "Enter the insurance company: ";
		cin >> insurance_company;
		cout << "Enter the amount of compensation: ";
		cin >> amount_of_compensation;
		
		try
		{
			do
			{
				cout << "Enter the date of start(dd/mm/yyyy): ";
				string date;
				cin >> date;
				date_of_start.fromString(date);
				cout << "Enter the date of end(dd/mm/yyyy): ";
				cin >> date;
				date_of_end.fromString(date);

			} while (date_of_start>date_of_end);
			
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		info_about_insurance = InsurancePolicy(policy_number, name, address, insurance_company, amount_of_compensation, date_of_start, date_of_end);


		MedicalRecord medical_record(name, surname, date_of_birth, info_about_insurance);

		string diagnos, analyses;
		cout << "Enter the diagnos: ";
		cin >> diagnos;
		cout << "Enter the analyses: ";
		cin >> analyses;
		DiagnosticRecord diagnostic_record(diagnos, analyses);

		string treatment, medicine;
		cout << "Enter the treatment: ";
		cin >> treatment;
		cout << "Enter the medicine: ";
		cin >> medicine;
		TreatmentRecord treatment_record(treatment, medicine);

		string doctor_name, doctor_surname, nurse_name, nurse_surname;
		Date date_of_visit;
		cout << "Enter the date of visit(dd/mm/yyyy): ";
		try
		{
			string date;
			cin >> date;
			date_of_visit.fromString(date);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		cout << "Enter the name of doctor: ";
		cin >> doctor_name;
		cout << "Enter the surname of doctor: ";
		cin >> doctor_surname;
		cout << "Enter the name of nurse: ";
		cin >> nurse_name;
		cout << "Enter the surname of nurse: ";
		cin >> nurse_surname;

		VisitRecord visit_record(date_of_visit, doctor_name, doctor_surname, nurse_name, nurse_surname);

		if (LoadRecord::is_FindRecord(name, surname, date_of_visit, diagnos)) {
			cout << "Record already exists." << endl;
			return;
		}
		SaveRecord::saveRecord(medical_record, diagnostic_record, treatment_record, visit_record);

		cout << "Record added successfully." << endl;
	}
};

#endif // ADD_RECORD_CONSOLE

