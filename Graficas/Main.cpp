/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 201
Autor: A0133993 Alejandra Maria Perez Aleman
*********************************************************/

#include<iostream>
#include<sstream>
#include "InputFile.h"

int main(int argc, char* argv[]) {

	std::string filename = "Prueba.txt";
	InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();

	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();

	return 0;
}