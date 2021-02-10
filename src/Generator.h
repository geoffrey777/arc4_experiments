//
// Created by Nima Alikhani on 09/02/2021.
//

#ifndef _LIB_GENERATOR_H
#define _LIB_GENERATOR_H

#include <vector>
#include "EncryptedGroup.h"
#include <utility>
#include <string>
#include <random>
#include "RC4.h"

class Generator {
public:
    Generator(std::vector<int> key);
    Generator(std::string key);
    EncryptedGroup generate(std::vector<int> iv, std::string text, int n);
private:
    std::vector<int> key;
};


#endif //_LIB_GENERATOR_H
