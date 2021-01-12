#include <iostream>
#include <string>
#include <vector>

//adding ifndef

class RC4 {
    public:
        RC4(std::string key);
        RC4(std::vector<int> key);
        std::vector<int> cipher(std::vector<int> plaintext);
        std::vector<int> cipher(std::string plaintext);
        std::vector<int> getStream(int n);
    private:
        int S[256];
        std::vector<int> key;
        void key_schedule();

};
