#pragma once
#include "PointMeasurement.h"
#include <list>

class Geometry
{
private:
	std::list<PointMeasurement> points;

public:
	Geometry(std::list<PointMeasurement>);
};

