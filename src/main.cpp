#include <iostream>
#include "RC4.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    RC4 aa = RC4("Key");
    vector<int> cipher = aa.cipher("Plaintext");
    for(auto character : cipher){
        cout << hex << character << " ";
    }
    cout << endl;
    return 0;
}
