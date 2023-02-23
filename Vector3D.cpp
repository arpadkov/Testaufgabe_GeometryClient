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

Vector3D Vector3D::operator+ (Vector3D const &vector)
{
	// Sum of 2 vectors

	double resultX = X + vector.X;
	double resultY = Y + vector.Y;
	double resultZ = Z + vector.Z;

	return Vector3D(resultX, resultY, resultZ);
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

bool Vector3D::sameVectorAs(Vector3D otherVector, float relativeTolerance)
{
	// Comparing coordinates of the 2 vectors
	// Used for the unittests
	// Comparing doubles can lead to false result due to rounding errors -> tolerance is specified
	// NOTE: fails if one coordinate is 0.0 and comparing to non-zero value inside tolerance

	bool equalX = false;
	if (X != 0.0 && otherVector.X != 0.0)
	{
		double diffX = X / otherVector.X;
		equalX = (diffX < (1 + relativeTolerance)) && (diffX > (1 - relativeTolerance));
	}
	else if (X == otherVector.X)
	{
		equalX = true;
	}
	
	bool equalY = false;
	if (Y != 0.0 && otherVector.Y != 0.0)
	{
		double diffY = Y / otherVector.Y;
		equalY = (diffY < (1 + relativeTolerance)) && (diffY > (1 - relativeTolerance));
	}
	else if (Y == otherVector.Y)
	{
		equalY = true;
	}

	bool equalZ = false;
	if (Z != 0.0 && otherVector.Z != 0.0)
	{
		double diffZ = Z / otherVector.Z;
		equalZ = (diffZ < (1 + relativeTolerance)) && (diffZ > (1 - relativeTolerance));
	}
	else if (Z == otherVector.Z)
	{
		equalZ = true;
	}


	if (equalX && equalY && equalZ)
	{
		return true;
	}
	else
	{
		return false;
	}
}
