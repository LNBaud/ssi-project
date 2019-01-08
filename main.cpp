
#include <chrono>
#include <iostream>
// #include "enclave.hpp"
// #include "application.hpp"
#include "processor.hpp"

using namespace std;

double timeToRollBackL1(Processor* processor, bool * cachedSecret, int pos, bool boolVal){
    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    processor->transcientMove(pos,boolVal);
    processor->rollBack(cachedSecret);
    
    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    return (std::chrono::duration<double> (finish - start)).count();
}

void decodeCacheL1(bool* decoded, Processor *processor, bool * cachedSecret) {
    for (int i=0; i<CACHE_SIZE; i++) {
        if (timeToRollBackL1(processor, cachedSecret, i, true) > 
                timeToRollBackL1(processor, cachedSecret, i, false)) {
            decoded[i] = false;
        } else {
            decoded[i] = true;
        }
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
    decodeCacheL1(decoded, processor, cachedSecret);
    for (int i = 0; i < CACHE_SIZE; i++) {
        cout << decoded[i] << endl;
    }

    delete processor;
    return 0;
}

