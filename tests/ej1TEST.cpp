#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(esSenial, senialEsValida) {
    int prof = 8;
    int freq = 10;
    
    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
        -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
        -45,  -60,    9} ;
    
    EXPECT_TRUE(esSenial(sig,prof,freq));
}
TEST(esSenial, freqInvalida) {
    int prof = 8;
    int freq = 11;

    senial sig = { 20,   0,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   255,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9} ;

    EXPECT_FALSE(esSenial(sig,prof,freq));
}
TEST(esSenial, profInvalida) {
    int prof = 10;
    int freq = 10;

    senial sig = { 68,   32,   123,  -30,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   255,   54,  123,   -23,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9} ;

    EXPECT_FALSE(esSenial(sig,prof,freq));
}

TEST(esSenial, duracionInsuficiente) {
    int prof = 8;
    int freq = 10;

    senial sig = {  -60,    9,   255,   54,  123,   44,   59,  -10,  -44,  -55, -104,
                    -45,  -60,    9} ;

    EXPECT_FALSE(esSenial(sig,prof,freq));
}


TEST(esSenial, muestraMayoralRango) {
    int prof = 8;
    int freq = 10;

    senial sig = {68, 32, 123, -30, 44, 59, -10, -44, -55, -104, -45,
                  -60, 9, 255, 54, 300, -23, 59, -10, -44, -55, -104,
                  -45, -60, 100};
}
TEST(esSenial, muestraMenorAlRango) {
    int prof = 8;
    int freq = 10;

    senial sig = { 56, 67, 109, 78, -150, -72, 129, 23, 12, 98, -10, 6, 45, 100,
                   -60,    9,   20,   54,  30,   -23,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    100} ;

    EXPECT_FALSE(esSenial(sig,prof,freq));
}