#pragma once
#include <list>
#include <string>

class Client
{
private:
	std::string client_path;
public:
	Client();
	std::list<int> pointBuffer;

	void readFileStart();

};

