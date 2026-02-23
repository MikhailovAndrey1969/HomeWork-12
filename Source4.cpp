#include <iostream>
#include <fstream>

int main() {

	std::setlocale(LC_ALL, "");

	char file_name[]{"in.txt"};
	std::ifstream file(file_name);
	if (!file.is_open())
	{
		std::wcout << L"Невозможно открыть файл " << file_name;
		return 1;
	}

	char txt[5];
	
	file >> txt;
	int rows{ atoi(txt) };
	file >> txt;
	int cols{ atoi(txt) };

	int** arr = new int*[rows];	
	for (int i{ 0 }; i < rows; ++i)
	{
		arr[i] = new int[cols];

		for (int j{ 0 }; j < cols; ++j)
		{
			file >> txt;
			arr[i][j] = atoi(txt);
		}

	}
	file.close();

	for (int i{ 0 }; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
		{
			std::wcout << arr[i][cols - 1 - j] << " ";
		}
		std::wcout << std::endl;
	}

	for (int i{ 0 }; i < rows; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return 0;
}
