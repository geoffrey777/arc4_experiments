//
// Created by Nima Alikhani on 09/02/2021.
//
#include <vector>
#include "EncryptedGroup.h"

#ifndef _LIB_GENERATOR_H
#define _LIB_GENERATOR_H


class Generator {
public:
    std::vector<int> key;
    EncryptedGroup generate(std::vector<int> iv, std::string text, int n)
};


#endif //_LIB_GENERATOR_H
