
#include <chrono>
#include <iostream>
// #include "enclave.hpp"
// #include "application.hpp"
#include "processor.hpp"

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

void decodeCacheL1Octet(unsigned char* decoded, Processor *processor) {
    double rollBackTime[256];
    for (int i=0; i<CACHE_SIZE; i++) {
        for (unsigned char j=0; j<255; j++) {
            rollBackTime[j] = timeToRollBackL1Octet(processor, i, j);
        }
        
        unsigned char minOctet;
        double minTime = 12;
        for (unsigned char j=0; j<255; j++) {
            if (rollBackTime[j] < minTime) {
                minTime = rollBackTime[j];
                minOctet = j;
            }
        }
        decoded[i] = minOctet;
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

    Processor* processor = new Processor();
    bool cachedSecret[CACHE_SIZE];
         cachedSecret[0] = false;
         cachedSecret[1] = true;
         cachedSecret[2] = false;
         cachedSecret[3] = true;
         cachedSecret[4] = false;
         cachedSecret[5] = true;
         cachedSecret[6] = false;
         cachedSecret[7] = false;
    processor->setCacheL1(cachedSecret);

    bool decoded[CACHE_SIZE]; 
    decodeCacheL1(decoded, processor);
    for (int i = 0; i < CACHE_SIZE; i++) {
        cout << decoded[i] << endl;
    }


    Processor* processor2 = new Processor();
    unsigned char cachedSecretOctet[CACHE_SIZE];
         cachedSecretOctet[0] = 'F';
         cachedSecretOctet[1] = 'O';
         cachedSecretOctet[2] = 'r';
         cachedSecretOctet[3] = 'S';
         cachedSecretOctet[4] = 'H';
         cachedSecretOctet[5] = 'a';
         cachedSecretOctet[6] = 'D';
         cachedSecretOctet[7] = 'O';
    processor2->setCacheL1Octet(cachedSecretOctet);

    unsigned char decodedOctet[CACHE_SIZE];
    decodeCacheL1Octet(decodedOctet, processor2);
    for (int i = 0; i < CACHE_SIZE; i++) {
        cout << (unsigned char) decodedOctet[i];
    }


    delete processor;
    delete processor2;
    return 0;
}

