#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(filtradoMediana, senialDesordenada) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {54, 23, -65, -102, 34, 71, -35, 77, 13, -46};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {54, 23, 23, 23, -35, 34, 34, 13, 13, -46};

    EXPECT_EQ(esperada, s);
}
TEST(filtradoMediana, senialOrdenada) {
    int prof = 16;
    int freq = 10;
    int r = 2;

    senial s = {-102, -65, -46, -35, 13, 23, 34, 54, 71, 77 };

    filtradoMediana(s, r, prof, freq);
    senial esperada = {-102, -65, -46, -35, 13, 23, 34, 54, 71, 77 };

    EXPECT_EQ(esperada, s);
}
TEST(filtradoMediana, senialDesordenadaSubSenialLarga) {
    int prof = 16;
    int freq = 10;
    int r = 4;

    senial s = {54, 23, -65, 0, 50, -32, -102, 34, 71, -35, 77, 13, -46};

    filtradoMediana(s, r, prof, freq);
    senial esperada = {54, 23, -65, 0, 23, 0, 0, 13, 13, -35, 77, 13, -46};

    EXPECT_EQ(esperada, s);
}