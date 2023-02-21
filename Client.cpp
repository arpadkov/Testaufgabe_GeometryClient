#include "Client.h"
#include "PointMeasurement.h"
#include "Geometry.h"
#include "GeometryExporterCSV.h"
#include <fstream>
#include <iostream>

Client::Client()
{
	// Setting path to client folder
	char* buf = nullptr;
	size_t sz = 0;
	if (_dupenv_s(&buf, &sz, "AppData") == 0 && buf != nullptr)
	{
		client_path = buf;
		free(buf);
	}
	client_path += "\\GeometryClient";
}

void Client::readInputFile()
{
	std::string input_filename = client_path + "\\input\\Input.txt";

	std::ifstream file(input_filename);
	if (!file)
	{
		std::cout << "File not found" << "\n";
		//throw FileNotFoundException();
	}

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line)) {
			//std::cout << line << "\n";
			readLine(line);
		}
		file.close();
	}
}

void Client::exportGeometries()
{
	for (int i = 0; i < savedGeometries.size(); i++)
	{
		GeometryExporterCSV exporter = GeometryExporterCSV(&savedGeometries[i]);
		exporter.exportGeometry();
	}

}
	
void Client::readLine(std::string input)
{
	std::string tag = input.substr(0, 5);
	if (tag == "E0000")
	{
		readEvent(input);
	}
	// Can be extended for additional message types
}

void Client::readEvent(std::string input)
{
	//std::cout << input.substr(8, 8) << "\n";

	if (input.substr(8, 6) == "PtMeas")
	{
		// Point Measurement event
		onPointMeasurementEvent(input);
	}

	else if(input.substr(8, 5) == "Error")
	{
		// Error event
		onErrorEvenet(input);
	}

	else if (input.substr(8, 8) == "KeyPress")
	{
		// Key press event
		onKeyPressEvent(input);
	}
}

void Client::onPointMeasurementEvent(std::string pointMeasEventLine)
{
	// create PointMeasurement
	// add point to buffer
	// log to cout

	PointMeasurement point = PointMeasurement(pointMeasEventLine);
	pointBuffer.push_back(point);
}

void Client::onKeyPressEvent(std::string keyPressEventLine)
{
	// create Geometry object from buffer
	// export object to file
	// log to cout
	if (keyPressEventLine.find("Done") != std::string::npos)
	{
		savedGeometries.push_back(Geometry(pointBuffer));
		pointBuffer.clear();
	}
	// elseif (...) -> possibility to define actions for other KeyPressEvents
}

void Client::onErrorEvenet(std::string errorEventLine)
{
	// delete points from buffer
	// continue reading file after confirmation
	// log to cout

	pointBuffer.clear();
	std::cout << errorEventLine;
}
