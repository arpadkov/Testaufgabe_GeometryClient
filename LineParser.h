#pragma once
#include <string>

class LineParser
{
public:
	LineParser(std::string);

	double findXvalue();
	double findYvalue();
	double findZvalue();

	double findNormalXvalue();
	double findNormalYvalue();
	double findNormalZvalue();

	double findRvalue();

	std::string findErrorMessage();
	std::string findErrorSeverity();
	std::string findErrorCode();
	std::string findErrorMethod();

private:
	std::string raw_string;

	std::string findNormalSubStr();
};

int findNthOccurance(std::string, char, int);
