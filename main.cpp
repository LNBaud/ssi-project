

#include <iostream>
#include "enclave.hpp"
#include "application.hpp"

using namespace std;


int main(int argc, char** argv)
{
    cout << "Foreshadow !" << endl;
    // Create Objects
    Enclave enclave = Enclave("qwerty");
    Application app = Application();

    app.askPassword();
    cout << enclave.checkPassword(app.getPassword()) << endl;

    return 0;
}

