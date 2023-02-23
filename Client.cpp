#include "Client.h"
#include "LineParser.h"
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
	}

	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			readLine(line);
		}
		file.close();
	}
}

void Client::exportGeometries()
{
	for (int i = 0; i < savedGeometries.size(); i++)
	{
		std::string geomName = "Geometrie" + std::to_string(i+1) + ".csv";
		std::string outputFilename = client_path + "\\output" + "\\" + geomName;

		GeometryExporterCSV exporter = GeometryExporterCSV(&savedGeometries[i]);
		exporter.exportGeometry(outputFilename, geomName);

		std::cout << "Geometrie " + std::to_string(i + 1) << " exported to:\n";
		std::cout << outputFilename << "\n";
	}
}

void Client::readLine(std::string input)
{
	if (input[6] == '&')
	{
		// ACK event, not implemented
	}
	else if (input[6] == '%')
	{
		// Transaction complete, not implemented
	}
	else if (input[6] == '#')
	{
		readDataEvent(input);
	}
	else if (input[6] == '!')
	{
		readErrorEvent(input);
	}
	else
	{
		// CommandLine, not implemented
	}
}

void Client::readDataEvent(std::string input)
{
	if (input.substr(8, 6) == "PtMeas")
	{
		onPointMeasurementEvent(input);
	}

	else if (input.substr(8, 8) == "KeyPress")
	{
		onKeyPressEvent(input);
	}
}

void Client::onPointMeasurementEvent(std::string pointMeasEventLine)
{
	// create PointMeasurement
	// add point to buffer

	DataPoint point = DataPoint(pointMeasEventLine);
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

		std::cout << "Geometry " << std::to_string(savedGeometries.size()) << " finished\n";
		std::cout << "Press any key to continue reading" << "\n";
		std::cin.ignore();
	}

	else if (keyPressEventLine.find("Del") != std::string::npos)
	{
		pointBuffer.pop_back();

		std::cout << "Previous point is deleted" << "\n";
		std::cout << "Press any key to continue reading" << "\n";
		std::cin.ignore();
	}
}

void Client::readErrorEvent(std::string errorEventLine)
{
	// delete points from buffer
	// continue reading file after confirmation
	// log to cout

	LineParser errorParser = LineParser(errorEventLine);

	std::cout << "Error message: " << errorParser.findErrorMessage() << "\n";
	std::cout << "Error severity: " << errorParser.findErrorSeverity() << "\n";
	std::cout << "Error code: " << errorParser.findErrorCode() << "\n";
	std::cout << "Caused by method: " << errorParser.findErrorMethod() << "\n";
	std::cout << std::to_string(pointBuffer.size()) << " Points will be discarded" << "\n";;
	std::cout << "Press any key to continue reading" << "\n";
	std::cin.ignore();

	pointBuffer.clear();
}

