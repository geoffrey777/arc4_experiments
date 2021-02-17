#include <iostream>
#include "RC4.h"
#include "Generator.h"
#include "Attack.h"

using namespace std;

int main() {
    Attack a = Attack("eeeee");
    vector<int> b = a.attack();
    cout << b[0] << endl;

    return 0;
}
