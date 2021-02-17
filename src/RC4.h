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
    RC4(std::vector<int> key, int n);
    std::vector<int> cipher(std::vector<int> plaintext);
    std::vector<int> cipher(std::string plaintext);
    std::vector<int> getStream(int n);
    int* getS();
    int j{0};
private:
    int S[256];
    std::vector<int> key;
    void key_schedule();
};



#endif //ARC4_EXPERIMENTS_RC4_H
