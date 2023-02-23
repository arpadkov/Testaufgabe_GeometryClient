#pragma once
#include <string>

class DataPointParser
{
public:
	DataPointParser(std::string);

	double findXvalue();
	double findYvalue();
	double findZvalue();

	double findRvalue();

	std::string findNormalSubStr();
	double findNormalXvalue();
	double findNormalYvalue();
	double findNormalZvalue();

private:
	std::string raw_string;
	std::string normalVectorSubstr;
};

int findNthOccurance(std::string, char, int);
