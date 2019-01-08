#ifndef DEF_PROCESSOR
#define DEF_PROCESSOR

#define CACHE_SIZE 8

#include <string>

using namespace std;

class Processor
{
    public:

    Processor();
    void transcientMove(int position, bool value);
    void rollBack(bool targetCacheL1[CACHE_SIZE]);
    void setCacheL1(bool cacheL1[CACHE_SIZE]);

    private:

    bool cacheL1[CACHE_SIZE];
};

#endif