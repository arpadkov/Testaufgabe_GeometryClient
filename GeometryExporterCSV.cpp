#include "GeometryExporterCSV.h"
#include "PointMeasurement.h"
#include <fstream>
#include <algorithm>

GeometryExporterCSV::GeometryExporterCSV(Geometry* geom)
{
	geometry = geom;
	setPoints();

}

bool GeometryExporterCSV::exportGeometry(std::string outputFilePath, std::string geomName)
{
	std::ofstream file(outputFilePath);

	// Write Header
	file << geomName + separator + new_line;

	file << "messPunktX" + separator;
	file << "messPunktY" + separator;
	file << "messPunktZ" + separator;

	file << "antastPunktX" + separator;
	file << "antastPunktY" + separator;
	file << "antastPunktZ" + separator;

	file << new_line;

	// Write datapoints
	for (int i = 0; i < measurementPtsX.size(); i++)
	{
		file << convertToStr(measurementPtsX[i]) << separator;
		file << convertToStr(measurementPtsY[i]) << separator;
		file << convertToStr(measurementPtsZ[i]) << separator;

		file << convertToStr(collisionPtsX[i]) << separator;
		file << convertToStr(collisionPtsY[i]) << separator;
		file << convertToStr(collisionPtsZ[i]) << separator;

		file << new_line;
	}

	file.close();

	return true;
}

void GeometryExporterCSV::setPoints()
{

	for (int i = 0; i < geometry->size(); i++)
	{
		PointMeasurement current_point = geometry->getPointAt(i);

		measurementPtsX.push_back(current_point.measurementPoint->X);
		measurementPtsY.push_back(current_point.measurementPoint->Y);
		measurementPtsZ.push_back(current_point.measurementPoint->Z);

		collisionPtsX.push_back(current_point.getCollisionPoint()->X);
		collisionPtsY.push_back(current_point.getCollisionPoint()->Y);
		collisionPtsZ.push_back(current_point.getCollisionPoint()->Z);
	}

}

std::string GeometryExporterCSV::convertToStr(double num)
{
	std::string result = std::to_string(num);
	std::replace(result.begin(), result.end(), '.', ',');
	return result;
}
