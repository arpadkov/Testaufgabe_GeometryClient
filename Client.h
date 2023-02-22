#pragma once
#include "PointMeasurement.h"
#include "Geometry.h"
#include <vector>
#include <string>

class Client
{
private:
	std::string client_path;
	std::vector<PointMeasurement> pointBuffer;
	std::vector<Geometry> savedGeometries;

	void readLine(std::string);
	void readEvent(std::string);

	void onPointMeasurementEvent(std::string);
	void onKeyPressEvent(std::string);
	void onErrorEvent(std::string);
	void onLastLineEvent();

public:
	Client();	

	void readInputFile();
	void exportGeometries();
};

