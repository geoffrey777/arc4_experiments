#include <iostream>
#include <string>

//adding ifndef

class RC4 {
    public:
        RC4(std::string key);
        std::string cipher(std::string text);
    private:
        int S[256];
        void key_schedule(std::string key);

};
