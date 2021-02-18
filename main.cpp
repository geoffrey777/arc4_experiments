#include <iostream>
#include "RC4.h"
#include "Generator.h"
#include "Attack.h"

using namespace std;

int main() {
    Attack a = Attack("findm");
    vector<int> b = a.attack();

    return 0;
}
