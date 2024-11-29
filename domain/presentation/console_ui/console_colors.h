#ifndef CONSOLE_COLORS_H
#define CONSOLE_COLORS_H
#include "../../lib.h"
class Console_colors {
public:
	static bool is_use_colors;
	static const unsigned short _default = 7;	      //default color in console
	static const unsigned short _labels = 10;	      //labels in console
	static const unsigned short _inputs = 15;	      //inputs in console
	static const unsigned short _record_info = 11;    //record information in console
	static const unsigned short _record_info_num = 3; //number of record information in console
	static const unsigned short _users_info = 14;     //users information in console
	static const unsigned short _users_info_num = 6;  //number of user information in console
	static const unsigned short _errors = 12;         //errors in console
	

	static void default_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _default);
		}
	}

	static void labels_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _labels);
		}
	}

	static void inputs_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _inputs);
		}
	}

	static void record_info_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _record_info);
		}
	}

	static void record_info_num()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _record_info_num);
		}
	}

	static void users_info_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _users_info);
		}
	}

	static void users_info_num()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _users_info_num);
		}
	}

	static void errors_color()
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, _errors);
		}
	}

	static void set_color(unsigned short color)
	{
		if (is_use_colors)
		{
			SetConsoleTextAttribute(hConsole, color);
		}
	}
};

#endif //!CONSOLE_COLORS_H
