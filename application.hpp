#ifndef DEF_APPLICATION
#define DEF_APPLICATION

#include <string>

class Application
{
    public:

    Application();
    void askPassword();
    std::string getPassword();
    void setEnclaveKey(int key);
    int getEnclaveKey();

    private:
    
    std::string inputPassword;
    int enclaveKey;
};

#endif