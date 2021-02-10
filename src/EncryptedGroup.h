//
// Created by Nima Alikhani on 09/02/2021.
//
#ifndef _LIB_ENCRYPTEDGROUP_H
#define _LIB_ENCRYPTEDGROUP_H

#include <vector>

class EncryptedGroup {
public:
    std::vector<int> iv;
    std::vector<std::vector<int>> ciphers;
};


#endif //_LIB_ENCRYPTEDGROUP_H
