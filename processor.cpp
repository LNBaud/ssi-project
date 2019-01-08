
#include "processor.hpp"

using namespace std;

Processor::Processor() {
    for (int i=0; i< CACHE_SIZE; i++) {
        this->cacheL1[i] = false;
    }
}

void Processor::transcientMove(int position, bool value) {
    this->cacheL1[position] = value;
}

void Processor::setCacheL1(bool cacheL1[CACHE_SIZE]) {
    for (int i=0; i< CACHE_SIZE; i++) {
        this->cacheL1[i] = cacheL1[i];
    }
}

void Processor::roolBack(bool cacheL1[CACHE_SIZE]) {
    this->setCacheL1(cacheL1);
}