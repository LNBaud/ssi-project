
#include "enclave.hpp"

using namespace std;

Enclave::Enclave(int applicationKey) {
    this->password = "qwerty";
    this->applicationKey = applicationKey;
}

bool Enclave::checkPassword(std::string password, int applicationKey) {
    if (this->verifyKey(applicationKey)) {
        return this->password == password;
    }
    cout << "Wrong key:" << applicationKey << ":" << this->applicationKey << endl ;
    return false;
}

bool Enclave::verifyKey(int key) {
    return this->applicationKey == key;
}