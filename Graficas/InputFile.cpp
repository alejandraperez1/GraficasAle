#include "InputFile.h"
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>

bool InputFile::Read(std::string filename)
{
	std::ifstream file;
	std::stringstream alpha;
	file.open("Prueba.txt", std::ios::in);
	if (file.fail()) {
		return false;
	}
	else
	{

		while (!file.eof()) {
			getline(file, filename);
			alpha.str(filename +'\n');
			_contents += alpha.str();


		}


	}
	file.close();
}


std::string InputFile::GetContents()
{
	return _contents;
}

