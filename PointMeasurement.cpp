#include "PointMeasurement.h"
#include "PointMeasurementParser.h"
//#include "Point3D.h"
#include <string>



PointMeasurement::PointMeasurement(std::string raw_string)
{
    // There is some conversion error when casting from str to double

    PointMeasurementParser parser = PointMeasurementParser(raw_string);

    double X = parser.findXvalue();
    double Y = parser.findYvalue();
    double Z = parser.findZvalue();
    measurementPoint = new Point3D(X, Y, Z);

    double normalX = parser.findNormalXvalue();
    double normalY = parser.findNormalYvalue();
    double normalZ = parser.findNormalZvalue();
    normalVector = new Vector3D(normalX, normalY, normalZ);

    sphereRadius = parser.findRvalue();
}

Point3D PointMeasurement::getCollisionPoint()
{
    // Calculate collision point from measuredPoint, offsetDirection and offsetRadius

    double X = 0.0;
    double Y = 0.0;
    double Z = 0.0;

    return Point3D(X, Y, Z);
}


