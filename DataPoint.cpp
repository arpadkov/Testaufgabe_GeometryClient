#include "DataPoint.h"
#include "LineParser.h"
#include <string>



DataPoint::DataPoint(std::string raw_string)
{
    LineParser parser = LineParser(raw_string);

    double X = parser.findXvalue();
    double Y = parser.findYvalue();
    double Z = parser.findZvalue();
    measurementPoint = Vector3D(X, Y, Z);

    double normalX = parser.findNormalXvalue();
    double normalY = parser.findNormalYvalue();
    double normalZ = parser.findNormalZvalue();
    normalVector = Vector3D(normalX, normalY, normalZ);

    sphereRadius = parser.findRvalue();
}

Vector3D DataPoint::getCollisionPoint()
{
    // Calculate collision point from measuredPoint, offsetDirection and offsetRadius

    Vector3D unitVector = normalVector.getUnitVector();
    Vector3D offsetVector = unitVector * sphereRadius * -1;
    Vector3D collisionPoint = measurementPoint + offsetVector;

    return collisionPoint;
}


