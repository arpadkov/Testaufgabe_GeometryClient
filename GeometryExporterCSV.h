#pragma once
#include "Geometry.h"
#include <vector>

class GeometryExporterCSV
{
public:
	GeometryExporterCSV(Geometry*);

	bool exportGeometry(std::string outputFilePath, std::string geomName);

private:
	Geometry* geometry;

	std::string separator = ";";
	std::string new_line = "\n";

	std::vector<double> measurementPtsX;
	std::vector<double> measurementPtsY;
	std::vector<double> measurementPtsZ;

	std::vector<double> collisionPtsX;
	std::vector<double> collisionPtsY;
	std::vector<double> collisionPtsZ;

	void setPoints();

	std::string convertToStr(double);
};

