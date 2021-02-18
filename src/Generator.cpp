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

    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<> distrib2(0, 256);

    const int substring_len = 15; // Final plaintext len = 15+3 (header)
    int text_len = text.size();

    // https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, text_len-substring_len);

    for(int i=0; i<n; i++){
        std::vector<int> wep_key = iv;
        wep_key.push_back(distrib2(gen2));

        enc.iv.emplace_back(wep_key);
        // https://stackoverflow.com/questions/201718/concatenating-two-stdvectors
        wep_key.insert( wep_key.end(), key.begin(), key.end() );

        std::string str2 = text.substr(distrib(gen),substring_len);
        std::vector<int> snap_header{0xAA, 0xAA, 0x03, 0x00};
        
        snap_header.insert( snap_header.end(), str2.begin(), str2.end() );
        std::vector<int> cipher = RC4(wep_key).cipher(snap_header);
        enc.ciphers.push_back(cipher);
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
