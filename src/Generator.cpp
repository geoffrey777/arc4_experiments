//
// Created by Nima Alikhani on 09/02/2021.
//

#include "Generator.h"


void print(std::vector<int> const &input) // https://www.techiedelight.com/print-vector-cpp/
{
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
    std::cout << std::endl;
}


EncryptedGroup Generator::generate(std::vector<int> iv, std::string text, int n) {
    EncryptedGroup enc = EncryptedGroup();

    std::vector<int> wep_key = iv;
    // https://stackoverflow.com/questions/201718/concatenating-two-stdvectors
    wep_key.insert( wep_key.end(), key.begin(), key.end() );

    enc.iv = iv;
    RC4 rc4_engine = RC4(wep_key);
    const int substring_len = 15;
    int text_len = text.size();

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, text_len-substring_len);

    // TODO: AAA
    for(int i=0; i<n; i++){
        std::string str2 = text.substr(distrib(gen),substring_len);
        std::vector<int> cipher = rc4_engine.cipher(str2);
        enc.ciphers.push_back(cipher);
        print(cipher);
    }

    return enc;
}

Generator::Generator(std::vector<int> key) {
    // Interesting thing : key is copied by value, transfering it to the local key is
    // better than recreating it again
    this->key = std::move(key);
}

Generator::Generator(std::string key) {
    this->key = std::vector<int> (key.begin(), key.end());
}
