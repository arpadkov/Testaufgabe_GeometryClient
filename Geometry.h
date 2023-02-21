#pragma once
#include "PointMeasurement.h"
#include <vector>

class Geometry
{
private:
	std::vector<PointMeasurement> points;

public:
	Geometry(std::vector<PointMeasurement>);

	int size();
	PointMeasurement getPointAt(int);

	//void getCollisionPoints();
};

