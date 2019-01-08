
#include <chrono>
#include <iostream>
// #include "enclave.hpp"
// #include "application.hpp"
#include "processor.hpp"

using namespace std;

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
    cachedSecret[2] = true;
    cachedSecret[3] = false;
    cachedSecret[4] = false;
    processor->setCacheL1(cachedSecret);

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();

    processor->transcientMove(0,true);
    processor->roolBack(cachedSecret);

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    cout << "1 --- time needed: " << elapsed.count() << endl;

    // Record start time
    start = std::chrono::high_resolution_clock::now();

    processor->transcientMove(0,false);
    processor->roolBack(cachedSecret);

    // Record end time
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;

    cout << "2 --- time needed: " << elapsed.count() << endl;

    delete processor;
    return 0;
}

