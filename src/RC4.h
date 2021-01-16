//
// Created by Nima Alikhani on 15/01/2021.
//
#include <iostream>
#include <string>
#include <vector>

#ifndef ARC4_EXPERIMENTS_RC4_H
#define ARC4_EXPERIMENTS_RC4_H

class RC4 {
public:
    RC4(std::string key);
    RC4(std::vector<int> key);
    std::vector<int> cipher(std::vector<int> plaintext);
    std::vector<int> cipher(std::string plaintext);
    std::vector<int> getStream(int n);
private:
    int S[256];
    int aa{3};
    std::vector<int> key;
    void key_schedule();

};



#endif //ARC4_EXPERIMENTS_RC4_H
