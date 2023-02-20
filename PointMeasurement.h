#pragma once
#include "Point3D.h"
#include <string>

class PointMeasurement
{
public:
	PointMeasurement(std::string);

	int CollisionPoint;
	int NormalVector;

private:
	Point3D MeasurementPoint;
};



