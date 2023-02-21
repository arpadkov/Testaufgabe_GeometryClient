#include "GeometryExporterCSV.h"
#include "PointMeasurement.h"

GeometryExporterCSV::GeometryExporterCSV(Geometry* geom)
{
	geometry = geom;
	setPoints();
}

bool GeometryExporterCSV::exportGeometry()
{
	

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
