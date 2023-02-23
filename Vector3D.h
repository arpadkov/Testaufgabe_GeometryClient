#pragma once

class Vector3D
{
public:
	Vector3D();
	Vector3D(double, double, double);

	double X;
	double Y;
	double Z;

	Vector3D getUnitVector();

	Vector3D operator+ (Vector3D const& vector);
	bool operator== (Vector3D const&);

private:
	int precision = 7;
};

Vector3D operator* (double, const Vector3D&);
Vector3D operator* (const Vector3D&, double);

double roundoff(double, int);
