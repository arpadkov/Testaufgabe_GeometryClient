#pragma once
#include "Geometry.h"

class GeometryExporter
{
public:
	GeometryExporter(Geometry*);

protected:
	Geometry* geometry;

	std::vector<double> measurementPtsX;
	std::vector<double> measurementPtsY;
	std::vector<double> measurementPtsZ;

	std::vector<double> collisionPtsX;
	std::vector<double> collisionPtsY;
	std::vector<double> collisionPtsZ;

	void setPoints();

	std::string convertToStr(double);
};


