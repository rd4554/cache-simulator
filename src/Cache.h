#ifndef CACHE_H
#define CACHE_H

#include <vector>
#include <fstream>

using namespace std;

struct CacheLine
{
    bool valid;
    int tag;
};

class Cache
{
private:
    int cacheSize;
    int blockSize;
    int numLines;

    int hits;
    int misses;

    vector<CacheLine> cache;

    ofstream fout;

public:
    Cache(int cacheSize, int blockSize);

    ~Cache();

    void accessAddress(int address);

    void printCache();

    void printStatistics();
};

#endif