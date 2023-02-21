#pragma once
#include "Geometry.h"
#include <vector>

class GeometryExporterCSV
{
public:
	GeometryExporterCSV(Geometry*);

	bool exportGeometry();

private:
	Geometry* geometry;

	void setPoints();

	std::vector<double> measurementPtsX;
	std::vector<double> measurementPtsY;
	std::vector<double> measurementPtsZ;

	std::vector<double> collisionPtsX;
	std::vector<double> collisionPtsY;
	std::vector<double> collisionPtsZ;
};

