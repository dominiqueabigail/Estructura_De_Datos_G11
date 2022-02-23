#pragma once
#include <iostream>
#include <sqlite3.h>

static int callback(void* data, int argc, char** argv, char** azColName) {
	printf("%s = %s\n", azColName[0], argv[0]);
	return 0;
}

void mostrarUsuarios() {
	sqlite3* DB;
	char* messaggeError;
	int exit = sqlite3_open("MySQLiteDatabase.db", &DB);
	std::string query = "SELECT * FROM USUARIOS;";
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);
	sqlite3_close(DB);
}
