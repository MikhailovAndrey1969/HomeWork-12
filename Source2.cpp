#include <iostream>
#include <fstream>

void Read(std::ifstream&, bool);

int main() {

	std::setlocale(LC_ALL, "");
	
	char file_name[]{ "in.txt" };
	std::ifstream file(file_name);	
	if (!file.is_open())
	{
		std::wcout << L"Невозможно открыть файл " << file_name;
		return 1;
	}	

	std::cout << std::endl;
	Read(file,false);
	std::cout << std::endl;

	file.close();		

	return 0;
}

void Read(std::ifstream& file, bool show) {
	
	std::string  str;
	file >> str;
	if (!file.eof())
	{
		Read(file,true);
	};
	
	if ( show )
		std::cout << str << " ";
}