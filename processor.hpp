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
    void rollBack();
    void setCacheL1(bool cacheL1[CACHE_SIZE]);

    private:

    bool cacheL1[CACHE_SIZE];
    bool savedCacheL1[CACHE_SIZE];
};

#endif