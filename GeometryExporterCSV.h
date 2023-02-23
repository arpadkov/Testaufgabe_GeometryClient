#pragma once
#include "GeometryExporter.h"
#include <vector>

class GeometryExporterCSV : GeometryExporter
{
public:
	GeometryExporterCSV(Geometry* geom);

	bool exportGeometry(std::string outputFilePath, std::string geomName);

private:
	std::string separator = ";";
	std::string new_line = "\n";
};

