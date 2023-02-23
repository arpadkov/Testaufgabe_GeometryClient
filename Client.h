#pragma once
#include "Geometry.h"
#include <vector>
#include <string>

class Client
{
private:
	std::string client_path;
	std::vector<DataPoint> pointBuffer;
	std::vector<Geometry> savedGeometries;

	void readLine(std::string);
	void readAckEvent(std::string);
	void readTransactionEvent(std::string);
	void readDataEvent(std::string);
	void readErrorEvent(std::string);

	void onPointMeasurementEvent(std::string);
	void onKeyPressEvent(std::string);

public:
	Client();	

	void readInputFile();
	void exportGeometries();
};

