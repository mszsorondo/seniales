#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esReunionValida, reunionNoCuadrada) {
    int prof = 8;
    int freq = 10;

    senial Sig1 = { 17, -128, 128 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19};

	reunion reunion1= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_FALSE(esReunionValida(reunion1,prof,freq));
}
TEST(esReunionValida, reunionCuadrada) {
    int prof = 16;
    int freq = 10;

    senial Sig1 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, 16};

    reunion reunion1= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_TRUE(esReunionValida(reunion1,prof,freq));
}
TEST(esReunionValida, hablanteInvalido) {
    int prof = 16;
    int freq = 10;

    senial Sig1 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, 16};

    reunion reunion1= {make_pair(Sig1,0), make_pair(Sig2, 0), make_pair(Sig3, 2)};

    EXPECT_FALSE(esReunionValida(reunion1,prof,freq));
}

TEST(esReunionValida, senialInvalida) {
    int prof = 16;
    int freq = 10;

    senial Sig1 = { 17, -128, 10000000 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig2 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, -18};
    senial Sig3 = { 17, -128, 127 , 18,  15, -16, 0, 17, -20,  19, 16};

    reunion reunion1= {make_pair(Sig1,0), make_pair(Sig2, 1), make_pair(Sig3, 2)};

    EXPECT_FALSE(esReunionValida(reunion1,prof,freq));
}
TEST(esReunionValida, reunionVacia) {
    int prof = 16;
    int freq = 10;

    reunion reunion1= {};

    EXPECT_FALSE(esReunionValida(reunion1,prof,freq));
}