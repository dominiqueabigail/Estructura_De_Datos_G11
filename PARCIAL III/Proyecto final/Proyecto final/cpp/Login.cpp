#include "Login.h"
#include "MySQL.h"
#include "MD5.h"
#include "Calculadora.h"
#include "Input.h"

bool Login::mostrarLogin() {
	Calculadora c;
	MySQL base;
	std::string user;
	std::string auxPassword;
	char password[200];
	char passMD[16];
	std::string stringpasswordMD;
	bool logeado = false;
	
	std::cout << "Ingrese el nombre de usuario: " << std::endl;
	std::cin >> user;
	
	do {
		auxPassword = read_password("Ingrese la contrasenia: ");
	} while (auxPassword.empty());

	for (int i = 0; i < auxPassword.length(); i++) {
		password[i] = auxPassword.at(i);
	}
	password[auxPassword.length()] = '\0';
	MD5Diges(password, strlen(password), passMD);
	for (int i = 0; i < 16; i++) {
		stringpasswordMD.push_back((unsigned char)passMD[i]);
	}


	if (base.validarLogin(user, stringpasswordMD)) {
		system("cls");
		std::cout << "Bienvenido! " << std::endl;
		c.pedirDatos();
		system("pause");
		logeado = true;
	}
	else {
		std::cout << "Usarios/Contrasena incorrectos!!!" << std::endl;
		system("pause");
	}

	return logeado;
}


void Login::crearUsuario() {
	MySQL base;
	std::string user;
	char password[200];
	char passMD[16];
	std::string auxPassword;
	std::string stringpasswordMD;
	std::cout << "Ingrese el nuevo nombre de usuario: " << std::endl;
	std::cin >> user;
	do {
		auxPassword = read_password("Ingrese la contrasenia: ");
	} while (auxPassword.empty());
	for (int i = 0; i < auxPassword.length(); i++) {
		password[i] = auxPassword.at(i);
	}
	password[auxPassword.length()] = '\0';
	MD5Diges(password, strlen(password), passMD);
	for (int i = 0; i < 16; i++) {
		stringpasswordMD.push_back((unsigned char)passMD[i]);
	}
	base.insert(user, stringpasswordMD);
}