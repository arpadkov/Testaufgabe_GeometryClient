#pragma once
#include "Vector3D.h"
#include <string>

class DataPoint
{
public:
	DataPoint(std::string);

	Vector3D getCollisionPoint();
	Vector3D measurementPoint;

private:
	Vector3D normalVector;
	double sphereRadius;
};



