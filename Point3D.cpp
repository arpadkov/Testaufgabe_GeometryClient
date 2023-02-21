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
