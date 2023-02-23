#pragma once
#include "DataPoint.h"
#include <vector>

class Geometry
{
private:
	std::vector<DataPoint> points;

public:
	Geometry(std::vector<DataPoint>);

	int size();
	DataPoint getPointAt(int);
};

