#include "PointMeasurement.h"
#include "PointMeasurementParser.h"
#include <string>


PointMeasurement::PointMeasurement(std::string raw_string)
{
    // There is some conversion error when casting from str to double

    PointMeasurementParser parser = PointMeasurementParser(raw_string);

    double X = parser.findXvalue();
    double Y = parser.findYvalue();
    double Z = parser.findZvalue();

    double R = parser.findRvalue();

    double normalX = parser.findNormalXvalue();
    double normalY = parser.findNormalYvalue();
    double normalZ = parser.findNormalZvalue();
}
