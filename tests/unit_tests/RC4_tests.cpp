//
// Created by Nima Alikhani on 16/01/2021.
//

#include "gtest/gtest.h"
#include "RC4.h"

TEST(RC4_Test, Test_Vector_1){
    RC4 to_test = RC4("Key");
    std::vector<int> cipher = to_test.cipher("Plaintext");

    int myints[] = { 187, 243, 22, 232, 217, 64, 175, 10, 211 };
    std::vector<int> truth = std::vector<int>(myints, myints + sizeof(myints) / sizeof(int) );
    ASSERT_EQ(cipher, truth);
}

TEST(RC4_Test, Test_Vector_2){
    RC4 to_test = RC4("Wiki");
    std::vector<int> cipher = to_test.cipher("pedia");

    int myints[] = { 16, 33, 191, 4, 32 };
    std::vector<int> truth = std::vector<int>(myints, myints + sizeof(myints) / sizeof(int) );
    ASSERT_EQ(cipher, truth);
}

TEST(RC4_Test, Test_Vector_3){
    RC4 to_test = RC4("Secret");
    std::vector<int> cipher = to_test.cipher("Attack at dawn");

    int myints[] = { 69, 160, 31, 100, 95, 195, 91, 56, 53, 82, 84, 75, 155, 245 };
    std::vector<int> truth = std::vector<int>(myints, myints + sizeof(myints) / sizeof(int) );
    ASSERT_EQ(cipher, truth);
}