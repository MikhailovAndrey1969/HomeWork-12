#include <iostream>
#include <fstream>

int main() {

	std::setlocale(LC_ALL, "");
	
	int size{};
	std::wcout << L"Введите размер массива: ";
	std::wcin >> size;

	int* arr = new int[size];
	for (int i{ 0 }; i < size; ++i)
	{
		std::wcout << "[" << i << "] = ";
		std::wcin >> *(arr + i);
	}

	char file_name[]{ "out.txt" };
	std::ofstream file(file_name);
	if (!file.is_open())
	{
		std::wcout << L"Невозможно создать файл " << file_name;
		return 1;
	}

	file << size << std::endl;;
	for (int i{ size - 1 }; i >= 0; --i)
	{
		file << *(arr + i) << " ";
	}

	file.close();
	delete[] arr;

	return 0;
}
