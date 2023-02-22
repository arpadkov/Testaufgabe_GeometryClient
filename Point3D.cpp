#include "Point3D.h"

Point3D::Point3D(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

Point3D* Point3D::offsetByVector(Vector3D offsetVector)
{
	double resultX = X + offsetVector.X;
	double resultY = Y + offsetVector.Y;
	double resultZ = Z + offsetVector.Z;

	return new Point3D(resultX, resultY, resultZ);
}

bool Point3D::samePointAs(Point3D otherPoint, float relativeTolerance)
{
	// Comparing coordinates of the 2 points
	// Used for the unittests
	// Comparing doubles can lead to false result due to rounding errors -> tolerance is specified
	// NOTE: fails if one coordinate is 0.0 and comparing to non-zero value inside tolerance

	bool equalX = false;
	if (X != 0.0 && otherPoint.X != 0.0)
	{
		double diffX = X / otherPoint.X;
		equalX = (diffX < (1 + relativeTolerance)) && (diffX > (1 - relativeTolerance));
	}
	else if (X == otherPoint.X)
	{
		equalX = true;
	}

	bool equalY = false;
	if (Y != 0.0 && otherPoint.Y != 0.0)
	{
		double diffY = Y / otherPoint.Y;
		equalY = (diffY < (1 + relativeTolerance)) && (diffY > (1 - relativeTolerance));
	}
	else if (Y == otherPoint.Y)
	{
		equalY = true;
	}

	bool equalZ = false;
	if (Z != 0.0 && otherPoint.Z != 0.0)
	{
		double diffZ = Z / otherPoint.Z;
		equalZ = (diffZ < (1 + relativeTolerance)) && (diffZ > (1 - relativeTolerance));
	}
	else if (Z == otherPoint.Z)
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
