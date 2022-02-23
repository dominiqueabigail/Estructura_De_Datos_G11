#pragma warning(disable:4996)
#include <conio.h>
#include <sstream> 
//#include "Input.h"

/*
std::string Input::text_input(std::string message) {
	std::string text = "";
	char letter;

	std::cout << "\n\t" << message << "\n\t";
	letter = _getch();
	while (letter != 13) {

		if ((letter < 91 && letter > 64) || (letter < 123 && letter > 96) || letter == 48) {
			text.push_back(letter);
			std::cout << letter;
		}
		letter = _getch();
	}
	return text;
}

int Input::number_input(std::string message) {
	std::string num = "";
	char dig;
	int numero;

	std::cout << "\n\t" << message << "\n\t";
	dig = _getch();
	while (dig != 13) {

		if (dig < 58 && dig > 47) {
			num.push_back(dig);
			std::cout << dig;
		}
		dig = _getch();
	}
	std::istringstream(num) >> numero;
	return numero;
}
*/