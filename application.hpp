#ifndef DEF_APPLICATION
#define DEF_APPLICATION

#include <string>

class Application
{
    public:

    Application();
    void askPassword();
    std::string getPassword();

    private:
    
    std::string inputPassword;
};

#endif