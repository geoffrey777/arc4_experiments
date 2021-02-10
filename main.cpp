#include <iostream>
#include "RC4.h"
#include "Generator.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    RC4 aa = RC4("Key");
    vector<int> cipher = aa.cipher("Plaintext");
    for(auto character : cipher){
        cout << hex << character << " ";
    }
    cout << endl;

    Generator g = Generator("lol");
    g.generate(vector<int>{1,2,4}, "texttexttexttexttexttexttexttexttexttexttexttexttexttexttexttexttexttexttexttext", 10);
    return 0;
}
