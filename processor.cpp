
#include <unistd.h>
#include <iostream>

#include "processor.hpp"

using namespace std;

Processor::Processor() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        this->cacheL1[i] = false;
        this->savedCacheL1[i] = false;
        this->cacheL1Octet[i] = 0;
        this->savedCacheL1Octet[i] = 0;
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

void Processor::transcientMoveOctet(int position, char value) {
    this->cacheL1Octet[position] = value;
}

void Processor::setCacheL1Octet(const char * cacheL1, int length) {
    for (int i = 0; i < length; i++) {
        this->cacheL1Octet[i] = cacheL1[i];
        this->savedCacheL1Octet[i] = cacheL1[i];
    }
}

void Processor::rollBackOctet() {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (this->cacheL1Octet[i] != this->savedCacheL1Octet[i]) {
            this->cacheL1Octet[i] = this->savedCacheL1Octet[i];
            usleep(50);
        }
    }
}