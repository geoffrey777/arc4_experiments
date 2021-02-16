//
// Created by Nima Alikhani on 15/01/2021.
//

#include "RC4.h"

void RC4::key_schedule() {
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        int aux = S[i];
        S[i] = S[j];
        S[j] = aux;
    }
}

std::vector<int> RC4::cipher(std::vector<int> plaintext) {
    int n = plaintext.size();
    std::vector<int> stream = getStream(n);
    for(int i=0; i<n; i++){
        stream[i] ^= plaintext[i];
    }
    return stream;
}

std::vector<int> RC4::getStream(int n) {
    int * permutation = this->S;
    std::vector<int> stream = std::vector<int>();
    int i = 0;
    int j = 0;
    while(stream.size() < n) {
        i = (i + 1) % 256;
        j = (j + permutation[i]) % 256;
        int aux = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = aux;
        int int_chiffrement = S[(S[i] + S[j])%256];
        stream.push_back(int_chiffrement);
    }
    return stream;
}

RC4::RC4(std::string key) {
    for(auto character : key){
        this->key.push_back(character);
    }
    key_schedule();
}

RC4::RC4(std::vector<int> key) {
    this->key = key;
    key_schedule();
}

std::vector<int> RC4::cipher(std::string plaintext) {
    std::vector<int> vector_plain;
    for(auto character : plaintext){
        vector_plain.push_back(character);
    }
    return cipher(vector_plain);
}

int* RC4::getS() {
    return S;
}

RC4::RC4(std::vector<int> key, int n) {
    // only do keyschedule for n steps
    this->key = key;
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        j = (j + S[i] + key[i % key.size()]) % 256;
        int aux = S[i];
        S[i] = S[j];
        S[j] = aux;
    }
}
