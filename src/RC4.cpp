#include "RC4.h"

void RC4::key_schedule(std::string key) {
    int * permutation = this->S;
    
    for (int i = 0; i < 256; i++) {
        permutation[i] = i;
    }
    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + permutation[i] + key[i % key.length()]) % 256;
        int aux = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = aux;
    }
}

std::string RC4::cipher(std::string text) {
    int * permutation = this->S;
    std::string new_text;
    int i = 0;
    int j = 0;
    for (char t : text) {
        i = (i + 1) % 256;
        j = (j + permutation[i]) % 256;
        int aux = permutation[i];
        permutation[i] = permutation[j];
        permutation[j] = aux;
        int int_chiffrement = S[(S[i] + S[j])%256];
        new_text += std::to_string(int_chiffrement ^ t);
    }
    return new_text;
}

RC4::RC4(std::string key) {
    key_schedule(key);
}
