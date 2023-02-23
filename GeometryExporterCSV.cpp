#include "GeometryExporterCSV.h"
#include <fstream>

GeometryExporterCSV::GeometryExporterCSV(Geometry* geom) : GeometryExporter(geom)
{

}

bool GeometryExporterCSV::exportGeometry(std::string outputFilePath, std::string geomName)
{
	std::ofstream file(outputFilePath);

	// Write Header
	file << geomName + separator + new_line;

	file << "messPunktX" + separator;
	file << "messPunktY" + separator;
	file << "messPunktZ" + separator;

	file << "antastPunktX" + separator;
	file << "antastPunktY" + separator;
	file << "antastPunktZ" + separator;

	file << new_line;

	// Write datapoints
	for (int i = 0; i < measurementPtsX.size(); i++)
	{
		file << convertToStr(measurementPtsX[i]) << separator;
		file << convertToStr(measurementPtsY[i]) << separator;
		file << convertToStr(measurementPtsZ[i]) << separator;

		file << convertToStr(collisionPtsX[i]) << separator;
		file << convertToStr(collisionPtsY[i]) << separator;
		file << convertToStr(collisionPtsZ[i]) << separator;

		file << new_line;
	}

	file.close();

	return true;
}
