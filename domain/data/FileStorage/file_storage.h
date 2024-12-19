#ifndef FILE_STORAGE_CLASS
#define FILE_STORAGE_CLASS

#include "../../lib.h"
#include "../Interfaces/IDataStorage.h"

class FileStorage : public IDataStorage {
private:
    string filename;  // Stores the name of the file

public:
	// Constructors
	FileStorage() : filename("data.txt") {}  // Default constructor
	FileStorage(const string& fname) : filename(fname) {}  // Constructor with a filename

    // Method to encrypt data using Caesar cipher with a shift of 3
    string encrypt(const string& data) const {
        string encrypted = data;
        for (char& c : encrypted) {
            c = c + 3;
        }
        return encrypted;
    }

    // Method to decrypt data using Caesar cipher with a shift of 3
    string decrypt(const string& data) {
        string decrypted = data;
        for (char& c : decrypted) {
            c = c - 3;
        }
        return decrypted;
    }

    // Method to save data to a file with encryption
    void saveData(const string& data) override {
        try {
            ofstream outFile(filename, ios::app);  // Open file in append mode
            if (!outFile.is_open()) {
                throw runtime_error("Cannot open file for writing");
            }
            string encryptedData = encrypt(data);
            outFile << encryptedData << endl;
            outFile.close();
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    // Method to rewrite data to a file with encryption
    void saveDataClear(const string& data) override{
        try {
            ofstream outFile(filename, ios::out);  // Open file in write mode
            if (!outFile.is_open()) {
                throw runtime_error("Cannot open file for writing");
            }
            string encryptedData = encrypt(data);
            outFile << encryptedData << endl;
            outFile.close();
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    // Method to load data from a file with decryption
    string loadData() override {
        try {
            ifstream inFile(filename);
            if (!inFile.is_open()) {
                throw runtime_error("Cannot open file for reading");
            }
            stringstream buffer;
            buffer << inFile.rdbuf();
            inFile.close();
            string encryptedData = buffer.str();
            return decrypt(encryptedData);
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            return "";
        }
    }
};

#endif // !FILE_STORAGE_CLASS
