#pragma once
#include <iostream>
#include <sqlite3.h>

class MySQL {
public:
	void connection();
	void crearNuevaBase(std::string name);
	static int callback(void* data, int argc, char** argv, char** azColName);
	void insert(std::string user, std::string password);
	void eliminar(int id);
	bool validarLogin(std::string user, std::string password);
	void mostrarUsuarios();
};

void  MySQL::connection() {
	sqlite3* DB;
	int exit = 0;
	exit = sqlite3_open("MySQLiteDatabase.db", &DB);

	if (exit) {
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
	}
	else
		std::cout << "Opened Database Successfully!" << std::endl;
	sqlite3_close(DB);
}

void MySQL::crearNuevaBase(std::string name) {
	sqlite3* DB;
	int exit = sqlite3_open(name.c_str(), &DB);
	sqlite3_close(DB);
}

int MySQL::callback(void* data, int argc, char** argv, char** azColName) {
	int i;
	fprintf(stderr, "%s: ", (const char*)data);

	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void MySQL::insert(std::string user, std::string password) {
	//CREAMOS LA TABLA
	sqlite3* DB;
	char* messaggeError;
	int exit = sqlite3_open("MySQLiteDatabase.db", &DB);
	std::cout << exit << std::endl;
	std::string tablePerson =
		"CREATE TABLE IF NOT EXISTS USUARIOS("
		"USER			TEXT    NOT NULL, "
		"PASSWORD       TEXT    NOT NULL);";

	int table = sqlite3_exec(DB, tablePerson.c_str(), NULL, 0, &messaggeError);
	//INSERCION
	std::string sql = "INSERT INTO USUARIOS (USER, PASSWORD) VALUES(";
	sql.append("'");
	sql.append(user);
	sql.append("'");
	sql.append(",");
	sql.append("'");
	sql.append(password);
	sql.append("'");
	sql.append(");");
	std::cout << sql << std::endl;
	system("pause");
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error al insertar" << std::endl;
		system("pause");
		sqlite3_free(messaggeError);
	}
	else {
		std::cout << "Agregado correctamente!" << std::endl;
		system("pause");
	}
	sqlite3_close(DB);
}

void MySQL::eliminar(int id) {
	sqlite3* DB;
	char* messaggeError;
	sqlite3_open("example.db", &DB);
	std::string sql = "DELETE FROM USUARIOS WHERE ID = ";
	//sql.append(std::to_string(id));
	sql.append(";");
	int exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK) {
		std::cerr << "Error no existe el ID" << std::endl;
	}
	sqlite3_close(DB);
}

bool MySQL::validarLogin(std::string user, std::string password) {
	bool valido = false;
	sqlite3* DB;
	sqlite3_stmt* res;
	sqlite3_open("MySQLiteDatabase.db", &DB);
	std::string query = "SELECT * FROM USUARIOS WHERE USER = ";
	query.append("'");
	query.append(user);
	query.append("'");
	query.append(" AND ");
	query.append("PASSWORD = ");
	query.append("'");
	query.append(password);
	query.append("'");
	query.append(";");

	int exit = sqlite3_prepare(DB, query.c_str(), -1, &res, 0);

	if (exit == SQLITE_OK) {
		sqlite3_bind_int(res, 1, 3);
	}

	int step = sqlite3_step(res);
	if (step == SQLITE_ROW) {
		valido = true;
	}

	sqlite3_finalize(res);
	sqlite3_close(DB);
	return valido;
}

void MySQL::mostrarUsuarios() {
	sqlite3* DB;
	char* messaggeError;
	int exit = sqlite3_open("MySQLiteDatabase.db", &DB);
	std::string query = "SELECT * FROM USUARIOS;";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	sqlite3_close(DB);
}