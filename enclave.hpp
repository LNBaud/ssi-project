#ifndef DEF_ENCLAVE
#define DEF_ENCLAVE

#include <string>

class Enclave
{
    public:

    Enclave(std::string password);
    bool checkPassword(std::string password);

    private:

    std::string m_password;
};

#endif