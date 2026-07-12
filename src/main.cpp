#include <iostream>
#include <fstream>

#include "Cache.h"

using namespace std;

int main()
{
    int cacheSize, blockSize;

    cout << "========== Direct-Mapped Cache Simulator ==========\n\n";

    cout << "Enter Cache Size (bytes): ";
    cin >> cacheSize;

    cout << "Enter Block Size (bytes): ";
    cin >> blockSize;

    Cache cache(cacheSize, blockSize);

    ifstream inputFile("input/sample_input.txt");

    if (!inputFile)
    {
        cout << "Error: Could not open input/sample_input.txt\n";
        return 1;
    }

    cout << "\nReading memory addresses from input/sample_input.txt...\n\n";

    int address;

    while (inputFile >> address)
    {
        cache.accessAddress(address);
    }

    inputFile.close();

    cache.printStatistics();

    cout << "\nSimulation completed successfully.\n";
    cout << "Results have been saved to output/output.txt\n";

    return 0;
}