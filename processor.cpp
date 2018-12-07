
#include "processor.hpp"
#define ACCESS_FAILED -1

using namespace std;

Processor::Processor(){

}

int Processor::getCachedData(int position, int secret) {
    if (position < 256 && position >= 0) {
        if (!locked) {
            return cacheL1[position];
        } else if (secretLocker = secret) {
            return cacheL1[position];
        } else {
            return ACCESS_FAILED;
        }
        
    }
    return ACCESS_FAILED;
}