#pragma once
#include <string>

class PointMeasurement
{
public:
	PointMeasurement(std::string);

	int CollisionPoint;
	int MeasurementPoint;
	int NormalVector;
private:
	double findXvalue(std::string);
	double findYvalue(std::string);
	double findZvalue(std::string);

	double findRvalue(std::string);
};

int findNthOccurance(std::string, std::string, int);

