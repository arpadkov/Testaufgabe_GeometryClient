#include "GeometryExporter.h"
#include <algorithm>
#include <iomanip>
#include <sstream>

GeometryExporter::GeometryExporter(Geometry* geom)
{
	geometry = geom;
	setPoints();
}

void GeometryExporter::setPoints()
{

	for (int i = 0; i < geometry->size(); i++)
	{
		DataPoint current_point = geometry->getPointAt(i);
		measurementPtsX.push_back(current_point.measurementPoint.X);
		measurementPtsY.push_back(current_point.measurementPoint.Y);
		measurementPtsZ.push_back(current_point.measurementPoint.Z);

		collisionPtsX.push_back(current_point.getCollisionPoint().X);
		collisionPtsY.push_back(current_point.getCollisionPoint().Y);
		collisionPtsZ.push_back(current_point.getCollisionPoint().Z);
	}

}

std::string GeometryExporter::convertToStr(double num)
{
	// stringstream & std::setprecision used, because to_string uses only 6 decimal digits

	std::ostringstream stringStream;
	stringStream << std::setprecision(7);
	stringStream << std::fixed;
	stringStream << num;

	std::string result = stringStream.str();

	std::replace(result.begin(), result.end(), '.', ',');
	return result;
}