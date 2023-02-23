#include "Geometry.h"

Geometry::Geometry(std::vector<DataPoint> inputPoints)
{
	points = inputPoints;
}

int Geometry::size()
{
	return points.size();
}

DataPoint Geometry::getPointAt(int index)
{
	return points[index];
}

//void Geometry::getCollisionPoints()
//{
//	points[0].getCollisionPoint();
//}