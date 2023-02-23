#pragma once

class Vector3D
{
public:
	Vector3D(double, double, double);

	double X;
	double Y;
	double Z;

	Vector3D getUnitVector();

	bool sameVectorAs(Vector3D, float epsilon);

	Vector3D operator+ (Vector3D const& vector);
};

Vector3D operator* (double, const Vector3D&);
Vector3D operator* (const Vector3D&, double);
