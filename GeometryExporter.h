#pragma once
#include "Geometry.h"

class GeometryExporter
	// Possibility to implement exporters for different formats, e.g. CSV Exporter
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


