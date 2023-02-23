#include "Vector3D.h"
#include <cmath>

Vector3D::Vector3D()
{
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
}

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

Vector3D Vector3D::operator+ (Vector3D const &vector)
{
	// Sum of 2 vectors

	double resultX = X + vector.X;
	double resultY = Y + vector.Y;
	double resultZ = Z + vector.Z;

	return Vector3D(resultX, resultY, resultZ);
}

bool Vector3D::operator== (Vector3D const& vector)
{
	double x1 = roundoff(X, precision);
	double x2 = roundoff(vector.X, precision);

	bool equalX = roundoff(X, precision) == roundoff(vector.X, precision);
	bool equalY = roundoff(Y, precision) == roundoff(vector.Y, precision);
	bool equalZ = roundoff(Z, precision) == roundoff(vector.Z, precision);

	if (equalX && equalY && equalZ)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

Vector3D operator* (double num, const Vector3D& vector)
{
	// Multiplying vector by double value

	double resultX = num * vector.X;
	double resultY = num * vector.Y;
	double resultZ = num * vector.Z;

	return Vector3D(resultX, resultY, resultZ);
}

Vector3D operator* (const Vector3D& vector, double num)
{
	// Multiplying vector by double value

	double resultX = num * vector.X;
	double resultY = num * vector.Y;
	double resultZ = num * vector.Z;

	return Vector3D(resultX, resultY, resultZ);
}

double roundoff(double value, int precision)
{
	double factor = pow(10, precision) ;
	double result = std::round(value * factor) / factor;
	return result;
}
