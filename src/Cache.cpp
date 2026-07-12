#include "Cache.h"

#include <iostream>
#include <iomanip>

using namespace std;

Cache::Cache(int cacheSize, int blockSize)
{
    this->cacheSize = cacheSize;
    this->blockSize = blockSize;

    numLines = cacheSize / blockSize;

    hits = 0;
    misses = 0;

    cache.resize(numLines);

    for (int i = 0; i < numLines; i++)
    {
        cache[i].valid = false;
        cache[i].tag = -1;
    }

    fout.open("output/output.txt");

    if (!fout)
    {
        cout << "Unable to create output file.\n";
    }
}

Cache::~Cache()
{
    if (fout.is_open())
        fout.close();
}

void Cache::accessAddress(int address)
{
    int blockNumber = address / blockSize;
    int index = blockNumber % numLines;
    int tag = blockNumber / numLines;

    bool hit = cache[index].valid && cache[index].tag == tag;

    if (hit)
    {
        hits++;
        cout << "Address " << address << " -> Hit\n";
        if (fout.is_open())
            fout << "Address " << address << " -> Hit\n";
    }
    else
    {
        misses++;

        cache[index].valid = true;
        cache[index].tag = tag;

        cout << "Address " << address << " -> Miss\n";
        if (fout.is_open())
            fout << "Address " << address << " -> Miss\n";
    }

    printCache();
}

void Cache::printCache()
{
    cout << "\nCurrent Cache State\n";
    cout << "-------------------------------------\n";
    cout << left
         << setw(10) << "Line"
         << setw(10) << "Valid"
         << setw(10) << "Tag"
         << endl;

    if (fout.is_open())
    {
        fout << "\nCurrent Cache State\n";
        fout << "-------------------------------------\n";
        fout << left
             << setw(10) << "Line"
             << setw(10) << "Valid"
             << setw(10) << "Tag"
             << endl;
    }

    for (int i = 0; i < numLines; i++)
    {
        cout << left
             << setw(10) << i
             << setw(10) << (cache[i].valid ? "Yes" : "No");

        if (cache[i].valid)
            cout << setw(10) << cache[i].tag;
        else
            cout << setw(10) << "-";

        cout << endl;

        if (fout.is_open())
        {
            fout << left
                 << setw(10) << i
                 << setw(10) << (cache[i].valid ? "Yes" : "No");

            if (cache[i].valid)
                fout << setw(10) << cache[i].tag;
            else
                fout << setw(10) << "-";

            fout << endl;
        }
    }

    cout << "-------------------------------------\n\n";

    if (fout.is_open())
        fout << "-------------------------------------\n\n";
}

void Cache::printStatistics()
{
    int total = hits + misses;

    double hitRate = 0.0;
    double missRate = 0.0;

    if (total > 0)
    {
        hitRate = (double)hits / total * 100.0;
        missRate = (double)misses / total * 100.0;
    }

    cout << "\n========== Cache Statistics ==========\n";
    cout << "Total Accesses : " << total << endl;
    cout << "Hits           : " << hits << endl;
    cout << "Misses         : " << misses << endl;
    cout << fixed << setprecision(2);
    cout << "Hit Rate       : " << hitRate << "%" << endl;
    cout << "Miss Rate      : " << missRate << "%" << endl;

    if (fout.is_open())
    {
        fout << "\n========== Cache Statistics ==========\n";
        fout << "Total Accesses : " << total << endl;
        fout << "Hits           : " << hits << endl;
        fout << "Misses         : " << misses << endl;
        fout << fixed << setprecision(2);
        fout << "Hit Rate       : " << hitRate << "%" << endl;
        fout << "Miss Rate      : " << missRate << "%" << endl;
    }
}