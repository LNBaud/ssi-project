

#include <iostream>
#include "enclave.hpp"
#include "application.hpp"

using namespace std;

// Service to Create an enclave for an application 
void createEnclave(Application* app, Enclave* enclave) {
    int geratedKey = 42;
    enclave = new Enclave(geratedKey);
    app->setEnclaveKey(geratedKey);
}

int main(int argc, char** argv)
{
    cout << "Foreshadow !" << endl;
    // Create Objects
    Enclave* enclave = (Enclave*) malloc(sizeof(Enclave));
    Application* app = new Application();

    Application* app2 = new Application();

    createEnclave(app, enclave);

    app->askPassword();
    bool isGoodPassword1 = enclave->checkPassword(app->getPassword(), app->getEnclaveKey());
    bool isGoodPassword2 = enclave->checkPassword("qwertyu", 32);
    cout << "App checking the password: " << isGoodPassword1 << endl;
    cout << "App2 checking the password: " << isGoodPassword2 << endl;

    delete app;
    delete app2;
    delete enclave;

    return 0;
}

