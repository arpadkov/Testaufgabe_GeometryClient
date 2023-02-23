#pragma once
#include "Geometry.h"
#include <vector>
#include <string>

class Client
{
public:
	Client();

	void readInputFile();
	void exportGeometries();

private:
	std::string client_path;
	std::vector<DataPoint> pointBuffer;
	std::vector<Geometry> savedGeometries;

	void readLine(std::string);
	void readDataEvent(std::string);
	void readErrorEvent(std::string);

	void onPointMeasurementEvent(std::string);
	void onKeyPressEvent(std::string);
};

