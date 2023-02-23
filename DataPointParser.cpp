#include "DataPointParser.h"

DataPointParser::DataPointParser(std::string input)
{
    raw_string = input;
    normalVectorSubstr = findNormalSubStr();
}

double DataPointParser::findXvalue()
{
    // (X(122.9341357),  Y(93.2),  Z(-21.4388431),  IJK(-0.9848078,0.0,0.1736482),  R(1.5))
    // X value starts at 2nd opening bracket, ends at 1st closing bracket

    int start = findNthOccurance(raw_string, '(', 2) + 1;
    int end = findNthOccurance(raw_string, ')', 1);

    double x = std::stod(raw_string.substr(start, end - start));
    return x;
}

double DataPointParser::findYvalue()
{
    // Y value starts at 3rd opening bracket, ends at 2nd closing bracket

    int start = findNthOccurance(raw_string, '(', 3) + 1;
    int end = findNthOccurance(raw_string, ')', 2);

    double y = std::stod(raw_string.substr(start, end - start));
    return y;
}

double DataPointParser::findZvalue()
{
    // Z value starts at 4th opening bracket, ends at 3rd closing bracket

    int start = findNthOccurance(raw_string, '(', 4) + 1;
    int end = findNthOccurance(raw_string, ')', 3);

    double z = std::stod(raw_string.substr(start, end - start));
    return z;
}

double DataPointParser::findRvalue()
{
    // R value starts at 6th opening bracket, ends at 5th closing bracket

    int start = findNthOccurance(raw_string, '(', 6) + 1;
    int end = findNthOccurance(raw_string, ')', 5);

    double r = std::stod(raw_string.substr(start, end - start));
    return r;
}

std::string DataPointParser::findNormalSubStr()
{
    // Normal vector values start at 5th opening bracket, ends at 4th closing bracket
    int start = findNthOccurance(raw_string, '(', 5) + 1;
    int end = findNthOccurance(raw_string, ')', 4);

    return raw_string.substr(start, end - start);
}

double DataPointParser::findNormalXvalue()
{
    // X value starts at index 0, ends at 1st comma

    int start = 0;
    int end = findNthOccurance(normalVectorSubstr, ',', 1);

    double normalX = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalX;
}

double DataPointParser::findNormalYvalue()
{
    // Y value starts after 1st comma, ends at 2nd comma

    int start = findNthOccurance(normalVectorSubstr, ',', 1) + 1;
    int end = findNthOccurance(normalVectorSubstr, ',', 2);

    double normalY = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalY;
}

double DataPointParser::findNormalZvalue()
{
    // Z value starts after 2nd comma, ends at the end of substring

    int start = findNthOccurance(normalVectorSubstr, ',', 2) + 1;
    int end = normalVectorSubstr.length();

    double normalZ = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalZ;
}


int findNthOccurance(std::string str, char find, int nth)
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