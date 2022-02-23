#pragma once
#include <stdlib.h>
#include <conio.h>
#include <cstdarg>
#include <vadefs.h>
#include <stdarg.h>
#include <string>
#include "Console.h"

/**
* this class manage the screen
*
*/
class Screen {
private:
	Console console;
public:
	/**
	* @brief Function to generate menu
	*
	*/
	int generate_menu(int nargs, ...);
	void clear();
	void spaces(int);
	void goTo(int, int);
	void WriteLine(std::string text, SHORT x, SHORT y);
};
