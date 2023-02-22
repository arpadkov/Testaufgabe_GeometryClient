#include <iostream>
#include "Client.h"

int main()
{
    //std::cout << "Press Enter to start reading data\n";

    Client client = Client();

    std::cout << "Press any key to start reading input" << "\n";
    std::cin.ignore();
    client.readInputFile();

    client.exportGeometries();
}


