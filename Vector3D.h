#pragma once

class Vector3D
{
public:
	Vector3D(double, double, double);

	Vector3D getUnitVector();

	double X;
	double Y;
	double Z;
	
};

Vector3D operator* (double, const Vector3D&);
Vector3D operator* (const Vector3D&, double);
