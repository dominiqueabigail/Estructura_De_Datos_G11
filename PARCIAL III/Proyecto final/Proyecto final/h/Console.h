#pragma once
#define _HAS_STD_BYTE 0
#include <iostream>
#include <windows.h>


namespace fg {

	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BWhite(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[97m";
	}
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/

	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& Gray(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[90m";
	}
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BGray(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[37m";
	}
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& Green(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[32m";
	}
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BGreen(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[92m";
	}
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& Red(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[31m";
	}
	/**
* @brief Function to basic options for console operation
*
* @return the os
*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BRed(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[91m";
	}
	/**
* @brief Function to basic options for console operation
*
* @return the os
*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& Yellow(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[33m";
	}
	/**
* @brief Function to basic options for console operation
*
* @return the os
*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BYellow(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[93m";
	}

}

namespace bg {
	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& BWhite(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[47m";
	}

	/**
	* @brief Function to basic options for console operation
	*
	* @return the os
	*/
	template <typename CharT, typename Traits>
	constexpr std::basic_ostream< CharT, Traits >& Black(std::basic_ostream< CharT, Traits >& os) {
		return os << "\033[40m";
	}

}

class Console {
public:
	void hideCursor(bool);
	void changeSize(int, int);
	void gotoXY(int, int);
};