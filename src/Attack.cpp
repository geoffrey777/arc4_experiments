//
// Created by Nima Alikhani on 17/02/2021.
//
#include "Attack.h"

Attack::Attack(std::string key) {
    this->key = std::move(key);
}

std::vector<int> Attack::attack() {
    std::vector<int> predictedKey = std::vector<int>();

    for(int i=0;i<1;i++){
        std::vector<int> iv = std::vector<int>{3+i, 255, 14};
        EncryptedGroup group = this->generator.generate(iv,"TestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTestTennljlstTest", 200000);
        int key_byte = attack_i(i+3, group);
        predictedKey.push_back(key_byte);
    }

    return predictedKey;
}

int mostFrequent(std::vector<int> arr, int n)
{
    // Insert all elements in hash.
    std::unordered_map<int, int> hash;
    for (int i = 0; i < n; i++)
        hash[arr[i]]++;

    // find the max frequency
    int max_count = 0, res = -1;
    for (auto i : hash) {
        if (max_count < i.second) {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}

int Attack::attack_i(int i, EncryptedGroup group) {
    // Implement in rc4 partial KSA
    std::vector<int> suspected_bytes = std::vector<int>();
    std::vector wep_key = group.iv;
    wep_key.insert( wep_key.end(), key.begin(), key.end() );

    RC4 partial = RC4(wep_key, i);
    int* SL = partial.getS();
    int SLL = SL[i];
    int j = partial.j;

    for(auto cipher : group.ciphers){
        int ks = cipher[i] ^ 0xAA;
        int candidate = (ks - j - SLL + 256) % 256;
        suspected_bytes.push_back(candidate);
    }

    std::cout << std::dec << mostFrequent(suspected_bytes, 1) << std::endl;
    //K[L] = j L+1 - j L - SL [L]     with j L position of j in Lth KSA round and SL[L] Sbox L position at Lth round
    //J L+1 = S[L] = KS[L]            with KS[L] keystream at position L (xor clear)
    //Pick the most frequent K[L]
    return 4;
}
