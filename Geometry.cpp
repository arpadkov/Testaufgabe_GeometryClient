#include "Geometry.h"

Geometry::Geometry(std::vector<PointMeasurement> inputPoints)
{
	points = inputPoints;
}

int Geometry::size()
{
	return points.size();
}

PointMeasurement Geometry::getPointAt(int index)
{
	return points[index];
}

//void Geometry::getCollisionPoints()
//{
//	points[0].getCollisionPoint();
//}