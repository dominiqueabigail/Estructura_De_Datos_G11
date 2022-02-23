#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <limits>
#include "Calculadora.h"
#include "calculate.hpp"

using namespace std;

void Calculadora::pedirDatos() {
	opers.insert({ "+", oper_t{false, 1, false} });
	opers.insert({ "-", oper_t{false, 1, false} });
	opers.insert({ "*", oper_t{false, 2, false} });
	opers.insert({ "/", oper_t{false, 2, false} });
	opers.insert({ "%", oper_t{false, 2, false} });
	opers.insert({ "^", oper_t{true, 3, false} });
	opers.insert({ "+", oper_t{false, 10, true} });
	opers.insert({ "-", oper_t{false, 10, true} });
	opers.insert({ "!", oper_t{true, 11, true} });
	opers.insert({ ">", oper_t{false, 11, false} });
	opers.insert({ "<", oper_t{false, 11, false} });


	funcs.insert({ ">", func_args(2, [](args_t v)
	{
		return v[0] > v[1];
	}) });
	funcs.insert({ "<", func_args(2, [](args_t v)
	{
		return v[0] < v[1];
	}) });
	funcs.insert({ "+", func_args(1, [](args_t v)
	{
		return v[0];
	}) });
	funcs.insert({ "+", func_args(2, [](args_t v)
	{
		return v[0] + v[1];
	}) });
	funcs.insert({ "-", func_args(1, [](args_t v)
	{
		return -v[0];
	}) });
	funcs.insert({ "-", func_args(2, [](args_t v)
	{
		return v[0] - v[1];
	}) });
	funcs.insert({ "*", func_args(2, [](args_t v)
	{
		return v[0] * v[1];
	}) });
	funcs.insert({ "/", func_args(2, [](args_t v)
	{
		return v[0] / v[1];
	}) });
	funcs.insert({ "%", func_args(2, [](args_t v)
	{
		return fmod(v[0], v[1]);
	}) });
	funcs.insert({ "^", func_args(2, [](args_t v)
	{
		return pow(v[0], v[1]);
	}) });
	funcs.insert({ "abs", func_args(1, [](args_t v)
	{
		return abs(v[0]);
	}) });
	funcs.insert({ "log", func_args(1, [](args_t v)
	{
		return log10(v[0]);
	}) });
	funcs.insert({ "log", func_args(2, [](args_t v)
	{
		return log(v[1]) / log(v[0]);
	}) });
	funcs.insert({ "ln", func_args(1, [](args_t v)
	{
		return log(v[0]);
	}) });
	funcs.insert({ "sqrt", func_args(1, [](args_t v)
	{
		return sqrt(v[0]);
	}) });
	funcs.insert({ "root", func_args(2, [](args_t v)
	{
		return pow(v[1], 1.0 / v[0]);
	}) });
	//Recibe radianes - casteamos a radianes
	//Un radian es igual a 180/PI
	funcs.insert({ "sin", func_args(1, [](args_t v)
	{
		return sin(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "cos", func_args(1, [](args_t v)
	{
		return cos(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "tan", func_args(1, [](args_t v)
	{
		return tan(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "asin", func_args(1, [](args_t v)
	{
		return asin(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "acos", func_args(1, [](args_t v)
	{
		return acos(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "atan", func_args(1, [](args_t v)
	{
		return atan(v[0] * acos(-1.L) / 180);
	}) });
	funcs.insert({ "!", func_args(1, [](args_t v)
	{
		return tgamma(v[0] + 1);
	}) });
	funcs.insert({ "pi", func_constant(acos(-1.L)) });
	funcs.insert({ "e", func_constant(exp(1.L)) });
	funcs.insert({ "_", func_constant(NAN) });

	string exp = "";
	std::cout.flush();
	while (exp != "SALIR") {
		cout << "Ingrese una expresion: ";
		cin >> exp;
		try {
			auto postfix = infix2postfix(exp);
			auto value = evalpostfix(postfix);
			cout << setprecision(numeric_limits<decltype(value)>::digits10) << value << endl;
			funcs.find("_")->second = func_constant(value);
		}
		catch (parse_error& e) {
			cerr << string(e.index() + 2, ' ') << "^" << endl;
			cerr << e.what() << " en la posicion " << e.index() << endl;
		}
		catch (runtime_error& e) {
			cerr << e.what() << endl;
		}
		catch (exception& e) {
			cerr << "Error Interno: " << e.what() << endl;
		}
		cout << endl;
	}

}
























/*
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stdio.h>
#include <math.h>
#include "cmathematics/util/expressions.h"
void printToken(void* el)
{
	exp_token* t = el;
	switch (t->type) {
	case CONSTANT:
		printf("Xf ", t->val.constval);
		break;
	case FUNCTION:
	case OPERATOR:
		printf("%s ", t->val.funcVal.name);
		break;
	case CONSTANTSTR:
		printf("%s ", t->val.namedConstVal.name);
		break;
	case ELSE:
		printf("null ");
		break;
	default:
		printf("%s ", t->val.strval);
		break;
	}
}*/


/*
	int opc = 0;
	char* expresion = new char[50];

	std::vector<std::string> expressions;
	dynamicarray tokenList;
	exp_tokenNode* tree;

	do {
		system("cls");
		std::cout << "[1]. Operadores matematicos (+, -, *, /, %, ^)." << std::endl;
		std::cout << "[2]. Trigonometricos (sin, cos, tan, acos, asin, atan, etc)." << std::endl;
		std::cout << "[3]. Comparadores (=, ==, <>, !=, <, <=, >, >=)." << std::endl;
		std::cout << "[4]. Polinomios (sin, cos, tan, acos, asin, atan, etc)." << std::endl;
		std::cout << "[0]. Salir." << std::endl;
		std::cout << "Escoja una opcion: ";
		std::cin >> opc;
		switch (opc)
		{
		case 1:
			system("pause");
			break;
		case 2:
			std::cout << "Ingrese una expresion: " << std::endl;
			std::cin >> expresion;
			//exp_init();
			tokenList = exp_RPN(expresion);
			tree = exp_getEquationTree(tokenList);
			printf("\n%.2f\n", exp_evalTree(tree));
			//exp_cleanup();
			system("pause");
			break;
		case 0:
			system("pause");
			break;
		default:
			std::cout << "Opcion incorrecta." << std::endl;
			system("pause");
			break;
		}
	} while (opc != 0);
	*/
