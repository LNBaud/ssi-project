
#include <iostream>
#include "application.hpp"

using namespace std;

Application::Application() {

}

void Application::askPassword() {
    string input;
    cout << "enter password" << endl;
    cin >> input;
    inputPassword = input;
    cout << "askPassword ended" << endl;
}

string Application::getPassword() {
    return inputPassword;
}

void Application::setEnclaveKey(int key) {
    this->enclaveKey = key;
}

int Application::getEnclaveKey() {
    return this->enclaveKey;
}