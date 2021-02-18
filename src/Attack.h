//
// Created by Nima Alikhani on 17/02/2021.
//

#ifndef _LIB_ATTACK_H
#define _LIB_ATTACK_H

#include <iostream>
#include <string>
#include "EncryptedGroup.h"
#include "Generator.h"
#include <utility>
#include <unordered_map>
#include <map>

class Attack {
public:
    Attack(std::string key);
    std::string key;
    std::vector<int> attack();
    int attack_i(int i, EncryptedGroup group, std::vector<int> predicted);
    Generator generator = Generator(key);
};


#endif //_LIB_ATTACK_H
