#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

Vector3D Vector3D::getUnitVector()
{
	// Caclulating the unit vector: Length=1, direction same as original vector

	double vectorLength = sqrt(X*X + Y*Y + Z*Z);

	double unitX = X / vectorLength;
	double unitY = Y / vectorLength;
	double unitZ = Z / vectorLength;

	return Vector3D(unitX, unitY, unitZ);
}

Vector3D operator* (double x, const Vector3D& vector)
{
	// Multiplying vector by double value

	double resultX = x * vector.X;
	double resultY = x * vector.Y;
	double resultZ = x * vector.Z;

	return Vector3D(resultX, resultY, resultZ);
}

Vector3D operator* (const Vector3D& vector, double x)
{
	// Multiplying vector by double value

	double resultX = x * vector.X;
	double resultY = x * vector.Y;
	double resultZ = x * vector.Z;

	return Vector3D(resultX, resultY, resultZ);
}

