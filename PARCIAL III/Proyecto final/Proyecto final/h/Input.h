
#pragma warning(disable:4996)
#pragma once
#include <iostream>
#include <conio.h>

class Input {
public:
	/**
	* @brief Function to text input
	*/
	std::string text_input(std::string message);
	/**
	* @brief Function to number input
	*
	*/
	int number_input(std::string message);
};


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
	int numero = 0;

	std::cout << "\n\t" << message << "\n\t";
	dig = _getch();
	while (dig != 13) {

		if (dig < 58 && dig > 47) {
			num.push_back(dig);
			std::cout << dig;
		}
		dig = _getch();
	}
	//std::istringstream(num) >> numero;
	return numero;
}



static std::string read_password(std::string label) {
	const char BACKSPACE = 8;
	const char RETURN = 13;

	std::string password;
	int ch = 0;

	std::cout << label << std::endl;

	while (true) {
		ch = _getch();

		if (ch == 0x00) {
			ch = _getch();
		}

		if (ch == RETURN) {
			break;
		}

		if (ch == BACKSPACE) {
			if (password.length() != 0) {
				std::cout << "\b \b";
				password.resize(password.length() - 1);
			}
			else {
				//Beep(523, 100);
			}
		}
		else {
			password += ch;
			std::cout << '*';
		}
	}

	std::cout << std::endl;

	return password;
}