
#include "enclave.hpp"

using namespace std;

Enclave::Enclave(string password){
    m_password = password;
}

bool Enclave::checkPassword(std::string password) {
    return m_password == password;
}