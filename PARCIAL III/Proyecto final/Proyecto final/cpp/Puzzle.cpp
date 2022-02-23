#pragma warning(disable:4996)
#include <windows.h>
#include <thread>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "Header.hpp"
#include "Puzzle.hpp"

using namespace std;

Puzzle::Puzzle() {

}

void Puzzle::main() {
	int count = 0;
	ifstream fptr;
	fptr.open("test1.txt", ios::in);            // opening the input file
	vector<Tile> Puzzle;            //vectore to store a tile

	for (int i = 0; i < 9; i++) {
		string input_line;
		getline(fptr, input_line, '\n');  // reading a line from the file

		stringstream S(input_line);
		string tok;

		int E[4], j = 0;

		while (getline(S, tok, ','))       // tokenizing the the line, extracting comma separated values
		{
			E[j] = tok[0] - 'A' + 1;
			if (tok[1] == '0')E[j] *= -1;        //Encodes the color as a positive or negative integer eg. A0 = -1, A1 = 1, C0 = -3 and similarly
			j++;
		}

		Puzzle.push_back(Tile(i + 1, E, 0));      // Storing a tile
	}
	fptr.close();

	cout << "Input tiles:" << endl;

	for (int i = 0; i < 9; i++)        // Printing the input 
	{
		cout << i + 1 << ". <" << pat(Puzzle[i].edges[0]) << ", " << pat(Puzzle[i].edges[1]) << ", " << pat(Puzzle[i].edges[2]) << ", " << pat(Puzzle[i].edges[3]) << ">" << endl;
	}
	cout << endl;

	
	for (int i = 0; i < 9; i++)Visited[i] = false;

	placenextpiece(0, Puzzle, count); // calling the recursive function to solve the puzzle
	//Printing the number of solutions
	if (count == 0) cout << "No hay solucion." << endl;
	else if (count == 1) cout << "1 unica solucion encontrada" << endl;
	else cout << count << " soluciones unicas encontradas:" << endl;
	cout << Soln.str();   // Printing the board if a solution exists
	system("pause");

}

Puzzle::~Puzzle() {}
