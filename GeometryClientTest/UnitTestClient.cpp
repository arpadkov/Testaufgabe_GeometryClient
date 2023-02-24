#include "pch.h"
#include "UnitTestClient.h"
#include "../Client.cpp"
#include "../GeometryExporterCSV.cpp"
#include "../GeometryExporter.cpp"
#include "../Geometry.cpp"

bool UnitTestClient::readPointMeasurementLineTest()
{
	Client client = Client();

	std::string inputLine = "E0000 # PtMeas  (X(10),  Y(10),  Z(10),  IJK(9,0,0),  R(7))";
	client.readLine(inputLine);

	inputLine = "E0000 # PtMeas  (X(10.000),  Y(99.38),  Z(10),  IJK(9,0,0),  R(7))";
	client.readLine(inputLine);

	if (client.pointBuffer.size() ==  2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
