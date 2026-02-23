#include <fstream>
#include <iostream>
#include <string>

int main() {

	std::setlocale(LC_ALL, "");
	
	char file_name[]{ "in.txt" };
	std::ifstream file(file_name);
	if ( !file.is_open() )
	{
		std::wcout << L"Невозможно открыть файл " << file_name;
		return 1;
	}

	std::string word{""};	
	while ( !file.eof() )
	{
		file >> word;
		std::cout << word << std::endl;
	}

	file.close();

	return 0;
}