#pragma once
#include "Vector3D.h"

class Point3D
{
public:
	Point3D(double, double, double);

	Point3D* offsetByVector(Vector3D);

private:
	double X;
	double Y;
	double Z;

};

