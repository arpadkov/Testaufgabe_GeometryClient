#include "Client.h"
#include <fstream>
#include <iostream>

Client::Client()
{
	// Setting path to client folder
	char* buf = nullptr;
	size_t sz = 0;
	if (_dupenv_s(&buf, &sz, "AppData") == 0 && buf != nullptr)
	{
		client_path = buf;
		free(buf);
	}
	client_path += "\\GeometryClient";
}

void Client::readFileStart()
{
	std::string input_filename = client_path + "\\input\\Input.txt";

	std::ifstream file(input_filename);
	if (!file)
	{
		std::cout << "File not found" << "\n";
		//throw FileNotFoundException();
	}
	
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << "\n";
		}
		file.close();
	}
	
	file.close();

	//try
	//{
	//	jfile = json::parse(file);
	//}
	//catch (json::parse_error parseError)
	//{
	//	throw;
	//}
}