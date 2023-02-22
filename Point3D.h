#pragma once
#include "Vector3D.h"

class Point3D
{
public:
	Point3D(double, double, double);

	double X;
	double Y;
	double Z;

	Point3D* offsetByVector(Vector3D);

	bool samePointAs(Point3D, float epsilon);
};


