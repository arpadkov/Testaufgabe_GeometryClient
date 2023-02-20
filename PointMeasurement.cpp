#include "PointMeasurement.h"
#include <string>


PointMeasurement::PointMeasurement(std::string raw_string)
{
    // There is some conversion error when casting from str to double
	double x = findXvalue(raw_string);
    double y = findYvalue(raw_string);
    double z = findZvalue(raw_string);

    double r = findRvalue(raw_string);
}

double PointMeasurement::findXvalue(std::string raw_string)
{
	// (X(122.9341357),  Y(93.2),  Z(-21.4388431),  IJK(-0.9848078,0.0,0.1736482),  R(1.5))
    // X value starts at 2nd opening bracket, ends at 1st closing bracket

    int start = findNthOccurance(raw_string, "(", 2) + 1;
    int end = findNthOccurance(raw_string, ")", 1);

    double x = std::stof(raw_string.substr(start, end - start));
    return x;
}

double PointMeasurement::findYvalue(std::string raw_string)
{
    // Y value starts at 3rd opening bracket, ends at 2nd closing bracket

    int start = findNthOccurance(raw_string, "(", 3) + 1;
    int end = findNthOccurance(raw_string, ")", 2);

    double y = std::stof(raw_string.substr(start, end - start));
    return y;
}

double PointMeasurement::findZvalue(std::string raw_string)
{
    // Z value starts at 4th opening bracket, ends at 3rd closing bracket

    int start = findNthOccurance(raw_string, "(", 4) + 1;
    int end = findNthOccurance(raw_string, ")", 3);

    double z = std::stof(raw_string.substr(start, end - start));
    return z;
}

double PointMeasurement::findRvalue(std::string raw_string)
{
    // R value starts at 6th opening bracket, ends at 5th closing bracket

    int start = findNthOccurance(raw_string, "(", 6) + 1;
    int end = findNthOccurance(raw_string, ")", 5);

    double r = std::stof(raw_string.substr(start, end - start));
    return r;
}


int findNthOccurance(std::string str, std::string find, int nth)
{
    int position = 0;
    int count = 0;

    while (count != nth)
    {
        position++;
        position = str.find(find, position);
        count++;
    }
    return position;
}