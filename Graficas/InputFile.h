#pragma once
#include<string>
#include<fstream>

class InputFile{
public:
	bool Read(std::string filename);
	std::string GetContents();

private:
	std::string _contents;

};