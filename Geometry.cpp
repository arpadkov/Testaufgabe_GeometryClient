#include "Geometry.h"

Geometry::Geometry(std::vector<PointMeasurement> inputPoints)
{
	points = inputPoints;
}

void Geometry::getCollisionPoints()
{
	points[0].getCollisionPoint();
}