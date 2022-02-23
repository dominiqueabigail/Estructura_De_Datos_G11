#include "Screen.h"

HANDLE hStdin;
DWORD fdwSaveOldMode;
VOID ErrorExit(LPCSTR);


void Screen::goTo(int x, int y) {
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Screen::spaces(int n) {
	for (int i = 0; i < n; i++) {
		std::cout << "\n";
	}
}

void Screen::clear() {
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);
}

void Screen::WriteLine(std::string text, SHORT x, SHORT y) {
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	CHAR_INFO* buff = (CHAR_INFO*)calloc(text.length(), sizeof(CHAR_INFO));
	for (int i = 0; i < text.length(); i++) {
		buff[i].Char.AsciiChar = text.at(i);
		buff[i].Attributes = 15;
	}
	SMALL_RECT pos = { x, y,text.length() + x, y };
	WriteConsoleOutputA(hStdOut, buff, { (SHORT)text.length(), 1 }, { 0, 0 }, &pos);
}

int Screen::generate_menu(int nargs, ...) {
	//OPCION ESCOGIDA POR EL USUARIO
	int selection = 1;

	//ROMPER HILO
	bool flag = true;

	//ESCONDER CURSOR
	//console.hideCursor(false);

	//EVENTO MOUSE
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];

	// Get the standard input handle. 
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
	if (hStdin == INVALID_HANDLE_VALUE)
		ErrorExit("GetStdHandle");

	// Save the current input mode, to be restored on exit. 
	if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
		ErrorExit("GetConsoleMode");

	do {
		//MENU-CURSOR	
		va_list args;
		va_start(args, nargs);
		system("cls");
		//clear();
		// Enable the window and mouse input events. 
		fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;
		if (!SetConsoleMode(hStdin, fdwMode))
			ErrorExit("SetConsoleMode");
		console.gotoXY(20, 10);
		std::cout << " | UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE GRUPO 11" << std::endl;
		std::cout << " \t\t     | GRUPO 11				         " << std::endl;
		std::cout << " \t\t     | PROYECTO TERCER PARCIAL          " << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < nargs; i++) {
			if (selection == i + 1) {
				std::string str = "->";
				str.append(va_arg(args, char*));
				WriteLine(str, 20, 14 + i);
			}
			else {
				std::string str(va_arg(args, char*));
				WriteLine(str, 20, 14 + i);
			}
		}

		//LEER SIN INTERRUPCIONES
		if (!ReadConsoleInput(
			hStdin,      // input buffer handle 
			irInBuf,     // buffer to read into 
			128,         // size of read buffer 
			&cNumRead)) // number of records read 
			ErrorExit("ReadConsoleInput");

		// Dispatch the events to the appropriate handler.
		for (i = 0; i < cNumRead; i++) {
			switch (irInBuf[i].EventType) {
			case KEY_EVENT: // keyboard input 
				if (GetKeyState(VK_UP) & 0x8000) {
					selection--;
					if (selection <= 0) {
						selection = nargs;
					}
				}
				if (GetKeyState(VK_DOWN) & 0x8000) {
					selection++;
					if (selection > nargs) {
						selection = 1;
					}
				}
				if (GetKeyState(VK_RETURN) & 0x8000) {
					flag = false;
				}
				break;

			case MOUSE_EVENT: // mouse input
				switch (irInBuf[i].Event.MouseEvent.dwEventFlags) {
				case 0:
					if (irInBuf[i].Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 14) {
							return 1;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 15) {
							return 2;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 16) {
							return 3;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 17) {
							return 4;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 18) {
							return 5;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 19) {
							return 6;
						}
						if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 20) {
							return nargs;
						}
					}
					break;
				case MOUSE_MOVED:
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 14) {
						selection = 1;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 15) {
						selection = 2;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 16) {
						selection = 3;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 17) {
						selection = 4;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 18) {
						selection = 5;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 19) {
						selection = 6;
					}
					if (irInBuf[i].Event.MouseEvent.dwMousePosition.Y == 20) {
						selection = 7;
					}
					break;
				}
				break;

			default:
				ErrorExit("Unknown event type");
				break;
			}
		}
		va_end(args);
	} while (flag);

	return selection;
}

VOID ErrorExit(LPCSTR lpszMessage) {
	fprintf(stderr, "%s\n", lpszMessage);
	SetConsoleMode(hStdin, fdwSaveOldMode);
	ExitProcess(0);
}

