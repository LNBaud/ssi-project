#ifndef DEF_ENCLAVE
#define DEF_ENCLAVE

#include <string>
#include <iostream>

class Enclave
{
    public:

    Enclave(int applicationKey);
    bool checkPassword(std::string password, int applicationKey);

    private:
    bool verifyKey(int key);
    std::string password;
    int applicationKey;
};

#endif