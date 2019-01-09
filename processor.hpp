#ifndef DEF_PROCESSOR
#define DEF_PROCESSOR

#define CACHE_SIZE 4096

#include <string>

using namespace std;

class Processor
{
    public:

    Processor();
    void transcientMove(int position, bool value);
    void rollBack();
    void setCacheL1(bool cacheL1[CACHE_SIZE]);

    void transcientMoveOctet(int position, unsigned char value);
    void rollBackOctet();
    void setCacheL1Octet(const char * cacheL1);

    private:

    bool cacheL1[CACHE_SIZE];
    bool savedCacheL1[CACHE_SIZE];

    char cacheL1Octet[CACHE_SIZE];
    char savedCacheL1Octet[CACHE_SIZE];
};

#endif