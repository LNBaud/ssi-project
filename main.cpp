
#include <chrono>
#include <iostream>
// #include "enclave.hpp"
// #include "application.hpp"
#include "processor.hpp"
#include <unistd.h>

using namespace std;

double timeToRollBackL1(Processor* processor, int pos, bool boolVal){
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    processor->transcientMove(pos,boolVal);
    processor->rollBack();
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    return (std::chrono::duration<double> (finish - start)).count();
}

void decodeCacheL1(bool* decoded, Processor *processor) {
    for (int i=0; i<CACHE_SIZE; i++) {
        if (timeToRollBackL1(processor, i, true) > 
                timeToRollBackL1(processor, i, false)) {
            decoded[i] = false;
        } else {
            decoded[i] = true;
        }
    } 
}

double timeToRollBackL1Octet(Processor* processor, int pos, char val) {
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    processor->transcientMoveOctet(pos,val);
    processor->rollBackOctet();
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    return (std::chrono::duration<double> (finish - start)).count();
}

void displayDecoded(char * decoded, int length){
    system("clear");
    cout << length << " bytes /4096" << endl;
    for(int i=0; i!=length; i++){
        cout << decoded[i];
    }
    cout << endl;
}

void decodeCacheL1Octet(char* decoded, Processor *processor) {
    double rollBackTime[256];
    char minOctet;
    double minTime = 100.0;
    for (int i=0; i<CACHE_SIZE; i++) {
        for (int j=0; j<255; j++) {
            rollBackTime[j] = timeToRollBackL1Octet(processor, i, j);
        }
        minOctet = '.';
        minTime = 100.0;
        for (int j=0; j<255; j++) {
            if (rollBackTime[j] < minTime) {
                minTime = rollBackTime[j];
                minOctet = j;
            }
        }
        decoded[i] = minOctet;
        displayDecoded(decoded, i+1);
        usleep(10000);
    } 
}

int main(int argc, char** argv)
{
    // cout << "Foreshadow !" << endl;
    // // Create Objects
    // Enclave* enclave = (Enclave*) malloc(sizeof(Enclave));
    // Application* app = new Application();

    // Application* app2 = new Application();

    // createEnclave(app, enclave);

    // app->askPassword();
    // bool isGoodPassword1 = enclave->checkPassword(app->getPassword(), app->getEnclaveKey());
    // bool isGoodPassword2 = enclave->checkPassword("qwertyu", 32);
    // cout << "App checking the password: " << isGoodPassword1 << endl;
    // cout << "App2 checking the password: " << isGoodPassword2 << endl;

    // delete app;
    // delete app2;
    // delete enclave;

    // Processor* processor = new Processor();
    // bool cachedSecret[CACHE_SIZE];
    //      cachedSecret[0] = false;
    //      cachedSecret[1] = true;
    //      cachedSecret[2] = false;
    //      cachedSecret[3] = true;
    //      cachedSecret[4] = false;
    //      cachedSecret[5] = true;
    //      cachedSecret[6] = false;
    //      cachedSecret[7] = false;
    // processor->setCacheL1(cachedSecret);

    // bool decoded[CACHE_SIZE]; 
    // decodeCacheL1(decoded, processor);
    // for (int i = 0; i < CACHE_SIZE; i++) {
    //     cout << decoded[i] << endl;
    // }


    Processor* processor2 = new Processor();
    const char secret[CACHE_SIZE] = "This is your last chance.\nAfter this, there is no turning back.\n- You take the blue pill -\nthe story ends, you wake up in your bed and believe whatever you want to believe.\n- You take the red pill —\nyou stay in Wonderland, and I show you how deep the rabbit hole goes.\nRemember: all I'm offering is the truth.\nNothing more.\n";
    processor2->setCacheL1Octet(secret, CACHE_SIZE);

    char decodedOctet[CACHE_SIZE];
    decodeCacheL1Octet(decodedOctet, processor2);
    // for (int i = 0; i < CACHE_SIZE; i++) {
    //     cout << decodedOctet[i];
    // }
    // cout << endl;
    // for (int i = 0; i < CACHE_SIZE; i++) {
    //     cout << processor2->cacheL1Octet[i];
    // }

    // delete processor;
    delete processor2;
    return 0;
}

