
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
        this->savedCacheL1[i] = cacheL1[i];
    }
}

void Processor::rollBack() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (this->cacheL1[i] != this->savedCacheL1[i]) {
            this->cacheL1[i] = this->savedCacheL1[i];
            usleep(1);
        }
    }
}

void Processor::transcientMoveOctet(int position, unsigned char value) {
    this->cacheL1Octet[position] = value;
}

void Processor::setCacheL1Octet(unsigned char cacheL1[CACHE_SIZE]) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        this->cacheL1Octet[i] = cacheL1[i];
        this->savedCacheL1Octet[i] = cacheL1[i];
    }
}

void Processor::rollBackOctet() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (this->cacheL1Octet[i] != this->savedCacheL1Octet[i]) {
            this->cacheL1Octet[i] = this->savedCacheL1Octet[i];
            usleep(1);
        }
    }
}