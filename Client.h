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

	void readLine(std::string);
	void readEvent(std::string);

	void onPointMeasurementEvent(std::string);
	void onKeyPressEvent(std::string);
	void onErrorEvenet(std::string);
};

