#pragma once
#include "PointMeasurement.h"
#include "Geometry.h"
#include <list>
#include <string>

class Client
{
private:
	std::string client_path;
	std::list<PointMeasurement> pointBuffer;
	std::list<Geometry> savedGeometries;

	void readLine(std::string);
	void readEvent(std::string);

	void onPointMeasurementEvent(std::string);
	void onKeyPressEvent(std::string);
	void onErrorEvenet(std::string);

public:
	Client();	

	void readInputFile();
	void exportGeometries();
};

