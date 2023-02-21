#pragma once
#include "Point3D.h"
#include "Vector3D.h"
#include <string>

class PointMeasurement
{
public:
	PointMeasurement(std::string);

	Point3D* getCollisionPoint();
	Point3D* measurementPoint;

private:
	Vector3D* normalVector;
	double sphereRadius;

};



