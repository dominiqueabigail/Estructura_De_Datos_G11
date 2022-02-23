#include "Ascii.h"

Ascii::Ascii(const std::string src, const int type_process)
	: imagen(cv::imread(src)), tipoProceso(type_process)
{
}

void Ascii::showAscii()
{
	Ascii::intensity();
}

void Ascii::consoleFont(int x, int y) noexcept
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = x;
	cfi.dwFontSize.Y = y;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Ascii::grayColor() noexcept
{
	cv::Mat _grey_image;
	cv::cvtColor(imagen, _grey_image, cv::COLOR_BGR2GRAY);
	imagen = _grey_image;
}

inline void Ascii::intensity()
{
	double unit = (256.0 + 1) / 68.0;
	int cn = imagen.channels();
	std::string str;
	uint8_t* pixelPtr = (uint8_t*)imagen.data;
	cv::Scalar_<uint8_t> bgrPixel;
	for (int i = 0; i < imagen.rows; i++)
	{
		for (int j = 0; j < imagen.cols; j++)
		{
			int R = pixelPtr[i * imagen.cols * cn + j * cn + 2];
			int G = pixelPtr[i * imagen.cols * cn + j * cn + 1];
			int B = pixelPtr[i * imagen.cols * cn + j * cn + 0];
			int grayScaleValue = (B * 0.0722) + // B
				(G * 0.7152) + // G
				(R * 0.2126);	// R
			int intensity = grayScaleValue / unit;
			str = charAscii(intensity);
			ascii += str;			
			printf("\033[%d;2;%d;%d;%dm%c\033[0;00m", tipoProceso, R, G, B, str[0]);
		}
		ascii += "\n";
		std::cout << std::endl;
	}
}

void Ascii::resize(int x, int y) noexcept
{
	try {
		cv::Mat resizeImage;
		cv::resize(imagen, resizeImage, cv::Size(x, y));
		imagen = resizeImage;
	}
	catch (...) {
		std::cout << "!";
	}

}

void Ascii::generateFile(std::string name) noexcept
{
	std::ofstream file;
	file.open(name);
	if (file.is_open())
		file << ascii;
	file.close();
}


std::string Ascii::charAscii(int intensity) noexcept
{
	std::vector<std::string> map{
		"$", "@", "B", "%", "8", "&", "W", "M", "#", "*", "o", "a", "h", "k", "b", "d", "p", "q", "w", "m", "Z",
		"O", "0", "Q", "L", "C", "J", "U", "Y", "X", "z", "c", "v", "u", "n", "x", "r", "j", "f", "t", "/", "\\",
		"|", "(", ")", "1", "{", "}", "[", "]", "?", "-", "_", "+", "~", "<", ">", "i", "!", "l",
		"I", ";", ":", "\"", "^", "`", "'", "." };
	return map[intensity];
}
