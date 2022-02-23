#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include <cwchar>
#include <fstream>
//OPEN CV
#include <opencv2/opencv.hpp>

class Ascii
{
private:
	cv::Mat imagen{0};
	int tipoProceso{0};
	std::string ascii;

public:
	Ascii(const std::string, const int);
	void showAscii();
	void consoleFont(int, int) noexcept;
	void grayColor() noexcept;
	std::string charAscii(int) noexcept;
	inline void intensity();
	void resize(int, int) noexcept;
	void generateFile(std::string) noexcept;
};
