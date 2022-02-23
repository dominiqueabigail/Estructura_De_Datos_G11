#pragma once
#define _HAS_STD_BYTE 0
#include <thread>
#include <windows.h>
#include "Ascii.h"
#include "Login.h"
#include "Screen.h"
#include "FileManager.h"
#include "Auxiliar.h"
#include "Puzzle.hpp"


void marquee(std::string text) {
	HANDLE conhandler = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int ancho, alto;
	GetConsoleScreenBufferInfo(conhandler, &csbi);
	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	SetConsoleCursorPosition(conhandler, { 0, 4 });

	while (true) {
		std::string temp = text;
		text.erase(0, 1);
		text += temp[0];
		CHAR_INFO* buff = (CHAR_INFO*)calloc(ancho, sizeof(CHAR_INFO));

		for (int i = 0; i < text.length(); i++) {
			buff[i].Char.AsciiChar = text.at(i);
			buff[i].Attributes = 15;
		}

		SMALL_RECT pos = { 0, 0, ancho, 1 };
		WriteConsoleOutputA(conhandler, buff, { (SHORT)ancho, 1 }, { 0, 0 }, &pos);
		free(buff);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}

}


void mainMenu() {
	std::string test = "UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE ";
	std::thread t2(marquee, test);
	t2.detach();
	//changeSize();
	Ascii ascii("img.jpeg", 48); //Ubicacion de la imagen.
	ascii.consoleFont(8, 15);  //tamaño de cada caracter en pixeles.
	ascii.resize(120, 70); //redimensiona la imagen.
	ascii.showAscii();

	Login l;
	Screen screen;
	FileManager fm;
	Puzzle puzzle;
	system("pause");
	system("cls");
	int opc = 0;
	int nVars = 7;
	do {
		opc = screen.generate_menu(nVars, "Crear usuario.", "Iniciar sesion.", "Generar juego.", "Hacer backup.", "Restaurar un backup.", "Mostrar usuarios.", "Salir.");
		switch (opc) {
		case 1:
			system("cls");
			screen.spaces(1);
			l.crearUsuario();
			break;
		case 2:
			system("cls");
			screen.spaces(1);
			l.mostrarLogin();
			break;
		case 3:
			//JUEGO
			system("cls");
			screen.spaces(1);
			puzzle.main();
			break;
		case 4:
			//HACER BACKUP
			system("cls");
			screen.spaces(1);
			fm.init();
			system("pause");
			break;
		case 5:
			//RESTORE
			system("cls");
			screen.spaces(1);
			fm.showBackups();
			system("pause");
			break;
		case 6:
			//MOSTRAR USUARIOS
			system("cls");
			screen.spaces(1);
			mostrarUsuarios();
			system("pause");
			break;
		case 7:
			system("cls");
			screen.spaces(1);
			std::cout << "Saliendo..." << std::endl;

			break;
		}
	} while (opc != 7);
	


}