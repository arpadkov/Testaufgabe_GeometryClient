#include "LineParser.h"

LineParser::LineParser(std::string input)
{
    raw_string = input;
}

double LineParser::findXvalue()
{
    // (X(122.9341357),  Y(93.2),  Z(-21.4388431),  IJK(-0.9848078,0.0,0.1736482),  R(1.5))
    // X value starts at 2nd opening bracket, ends at 1st closing bracket

    int start = findNthOccurance(raw_string, '(', 2) + 1;
    int end = findNthOccurance(raw_string, ')', 1);

    double x = std::stod(raw_string.substr(start, end - start));
    return x;
}

double LineParser::findYvalue()
{
    // Y value starts at 3rd opening bracket, ends at 2nd closing bracket

    int start = findNthOccurance(raw_string, '(', 3) + 1;
    int end = findNthOccurance(raw_string, ')', 2);

    double y = std::stod(raw_string.substr(start, end - start));
    return y;
}

double LineParser::findZvalue()
{
    // Z value starts at 4th opening bracket, ends at 3rd closing bracket

    int start = findNthOccurance(raw_string, '(', 4) + 1;
    int end = findNthOccurance(raw_string, ')', 3);

    double z = std::stod(raw_string.substr(start, end - start));
    return z;
}

double LineParser::findRvalue()
{
    // R value starts at 6th opening bracket, ends at 5th closing bracket

    int start = findNthOccurance(raw_string, '(', 6) + 1;
    int end = findNthOccurance(raw_string, ')', 5);

    double r = std::stod(raw_string.substr(start, end - start));
    return r;
}

std::string LineParser::findNormalSubStr()
{
    // Normal vector values start at 5th opening bracket, ends at 4th closing bracket
    int start = findNthOccurance(raw_string, '(', 5) + 1;
    int end = findNthOccurance(raw_string, ')', 4);

    return raw_string.substr(start, end - start);
}

double LineParser::findNormalXvalue()
{
    // X value starts at index 0, ends at 1st comma

    std::string normalVectorSubstr = findNormalSubStr();
    int start = 0;
    int end = findNthOccurance(normalVectorSubstr, ',', 1);

    double normalX = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalX;
}

double LineParser::findNormalYvalue()
{
    // Y value starts after 1st comma, ends at 2nd comma

    std::string normalVectorSubstr = findNormalSubStr();
    int start = findNthOccurance(normalVectorSubstr, ',', 1) + 1;
    int end = findNthOccurance(normalVectorSubstr, ',', 2);

    double normalY = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalY;
}

double LineParser::findNormalZvalue()
{
    // Z value starts after 2nd comma, ends at the end of substring

    std::string normalVectorSubstr = findNormalSubStr();
    int start = findNthOccurance(normalVectorSubstr, ',', 2) + 1;
    int end = normalVectorSubstr.length();

    double normalZ = std::stod(normalVectorSubstr.substr(start, end - start));
    return normalZ;
}

std::string LineParser::findErrorMessage()
{
    // E0000 ! Error(3, 500, HealthCheck, "Emergency Stop")
    // Error message starts at 1st ", ends at 2nd "

    int start = findNthOccurance(raw_string, '"', 1) + 1;
    int end = findNthOccurance(raw_string, '"', 2);
    std::string errorMessage = raw_string.substr(start, end - start);
    return errorMessage;
}


std::string LineParser::findErrorSeverity()
{
    // Error severity starts at 1st opening bracket, ends at 1st comma

    int start = findNthOccurance(raw_string, '(', 1) + 1;
    int end = findNthOccurance(raw_string, ',', 1);
    std::string errorSeverity = raw_string.substr(start, end - start);
    return errorSeverity;
}

std::string LineParser::findErrorCode()
{
    // Error code starts at 1st comma, ends at 2nd comma

    int start = findNthOccurance(raw_string, ',', 1) + 1;
    int end = findNthOccurance(raw_string, ',', 2);
    std::string errorCode = raw_string.substr(start, end - start);
    return errorCode;
}

std::string LineParser::findErrorMethod()
{
    // Error method starts at 2nd comma, ends at 3rd comma

    int start = findNthOccurance(raw_string, ',', 2) + 1;
    int end = findNthOccurance(raw_string, ',', 3);
    std::string errorMethod = raw_string.substr(start, end - start);
    return errorMethod;
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