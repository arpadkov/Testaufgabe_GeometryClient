#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include <string>

class PointMeasurement
{
public:
	PointMeasurement(std::string);

	Point3D* getCollisionPoint();

private:
	Point3D* measurementPoint;
	Vector3D* normalVector;
	double sphereRadius;
};



