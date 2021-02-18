//
// Created by Nima Alikhani on 17/02/2021.
//
#include "Attack.h"

void print2(std::vector<int> const &input) // https://www.techiedelight.com/print-vector-cpp/
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << char(input.at(i));
    }
    std::cout << std::endl;
}


Attack::Attack(std::string key) {
    this->key = key;
    this->generator = Generator(key);
}

std::vector<int> Attack::attack() {
    std::vector<int> predictedKey = std::vector<int>();

    for(int i=0;i<5;i++){
        std::vector<int> iv = std::vector<int>{3+i, 255};
        EncryptedGroup group = this->generator.generate(iv,"Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of \"de Finibus Bonorum et Malorum\" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, \"Lorem ipsum dolor sit amet..\", comes from a line in section 1.10.32.\n Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum.\n", 25000);
        int key_byte = attack_i(i+3, group, predictedKey);
        predictedKey.push_back(key_byte);
    }
    print2(predictedKey);
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

int Attack::attack_i(int i, EncryptedGroup group, std::vector<int> predictedKey) {
    // Implement in rc4 partial KSA
    std::vector<int> suspected_bytes = std::vector<int>();
    for (int indice=0; indice<group.ciphers.size(); indice++) {
        std::vector<int> cipher = group.ciphers[indice];
        std::vector<int> wep_key = group.iv[indice];
        wep_key.insert( wep_key.end(), predictedKey.begin(), predictedKey.end() );

        RC4 partial = RC4(wep_key, i);
        int* SL = partial.getS();
        int j = partial.j;

        int SLL = SL[i];

        int ks = cipher[0] ^ 0xAA;
        int candidate = (ks - j - SLL + 256) % 256;
        suspected_bytes.push_back(candidate);
    }
    //K[L] = j L+1 - j L - SL [L]     with j L position of j in Lth KSA round and SL[L] Sbox L position at Lth round
    //J L+1 = S[L] = KS[L]            with KS[L] keystream at position L (xor clear)
    //Pick the most frequent K[L]
    return mostFrequent(suspected_bytes, 25000);
}
