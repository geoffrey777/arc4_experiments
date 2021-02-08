//
// Created by Nima Alikhani on 09/02/2021.
//
#include <vector>

#ifndef _LIB_ENCRYPTEDGROUP_H
#define _LIB_ENCRYPTEDGROUP_H

class EncryptedGroup {
public:
    std::vector<int> iv;
    std::vector<std::vector<int>> ciphers;
};


#endif //_LIB_ENCRYPTEDGROUP_H
