
#include <unistd.h>

#include "processor.hpp"

using namespace std;

Processor::Processor() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        this->cacheL1[i] = false;
    }
}

void Processor::transcientMove(int position, bool value) {
    this->cacheL1[position] = value;
}

void Processor::setCacheL1(bool cacheL1[CACHE_SIZE]) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        this->cacheL1[i] = cacheL1[i];
    }
}

void Processor::rollBack(bool cacheL1[CACHE_SIZE]) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (this->cacheL1[i] != cacheL1[i]) {
            this->cacheL1[i] = cacheL1[i];
            usleep(1);
        }
    }
}