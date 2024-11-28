#ifndef LIB_H
#define LIB_H

#include <iostream>	 //for input/output
#include <string>	 //for strings
#include <sstream>	 //for string streams
#include <vector>	 //for vectors
#include <fstream>   //for file operations
#include <stdexcept> //for exceptions
#include <windows.h> //for colors console
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
enum ProjectColors //enum for project colors
{
	defoult = 7,
	labels = 10,
	inputs = 15,
	record_info = 11,
	users_info= 14,
	errors = 12
};

#endif // !LIB_H


