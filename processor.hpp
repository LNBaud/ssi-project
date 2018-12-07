#ifndef DEF_PROCESSOR
#define DEF_PROCESSOR

#include <string>

using namespace std;

class Processor
{
    public:

    Processor();
    void lockCacheForEnclave(int secret);
    int getCachedData(int position, int secret);

    private:

    int secretLocker;
    int cacheL1[256];
    bool locked;
};

#endif