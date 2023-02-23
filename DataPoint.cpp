#include "DataPoint.h"
#include "DataPointParser.h"
#include <string>



DataPoint::DataPoint(std::string raw_string)
{
    // There is some conversion error when casting from str to double

    DataPointParser parser = DataPointParser(raw_string);

    double X = parser.findXvalue();
    double Y = parser.findYvalue();
    double Z = parser.findZvalue();
    measurementPoint = new Vector3D(X, Y, Z);

    double normalX = parser.findNormalXvalue();
    double normalY = parser.findNormalYvalue();
    double normalZ = parser.findNormalZvalue();
    normalVector = new Vector3D(normalX, normalY, normalZ);

    sphereRadius = parser.findRvalue();
}

Vector3D DataPoint::getCollisionPoint()
{
    // Calculate collision point from measuredPoint, offsetDirection and offsetRadius

    Vector3D unitVector = normalVector->getUnitVector();
    Vector3D offsetVector = unitVector * sphereRadius * -1;
    Vector3D collisionPoint = *measurementPoint + offsetVector;

    return collisionPoint;
}


