#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq) {
    int prof = 8;
    int freq = 10;
    int thresh = 65;

    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
    -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};

    EXPECT_TRUE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq2) {
    int prof = 8;
    int freq = 10;
    int thresh = 65;

    senial fstSig = { 17,   32,   80,   85,   99,   62,    -100,  -100, -107, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};

    EXPECT_TRUE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, noSuperanUmbral) {
    int prof = 8;
    int freq = 10;
    int thresh = 2000;

    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};

    EXPECT_FALSE(seEnojo(fstSig, thresh, prof, freq));
}

TEST(seEnojo, noSuperaUmbral2) {
    int prof = 8;
    int freq = 10;
    int thresh = 60;

    senial fstSig = { 10,  -55, -107, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17, 4}; //tono de esto es 59

    EXPECT_FALSE(seEnojo(fstSig, thresh, prof, freq));
}




TEST(seEnojo, unaSolaSubseqCumple) {
    int prof = 8;
    int freq = 10;
    int thresh = 73;

    //unica subseq que cumple: < 4 10 -55 -107 -111 -88 62 92 99 89 97 -39 52 62 91 109 97 78 -61 -80 >

    senial fstSig = { 1,2,-4,-1,-1,-2,4 ,10,  -55, -107, -111,  -88,
                      62,   92,   99,   89,   97,
                      -39,   52,   62,   91,   109,   97,
                      78,  -61, -80, 9};

    EXPECT_TRUE(seEnojo(fstSig, thresh, prof, freq));
}
TEST(seEnojo, enojoNoDuraMasDe) {
    int prof = 8;
    int freq = 10;
    int thresh = 47;

    senial fstSig = { 0, 0, 0, 0,
                      0, 0, 0, 0,
                      -9, -17, -30, 52, -30,       //
                      -3,   52,   62,   99,   89,  //
                      67,    7,  -61,  -97, -115,  //
                      -71,  -45,   17, 4,
                      0, 0, 0, 0}; //tono de esto asi es 29
    //unica subsenial que supera umbral es senial subsenial = { -9, -17, -30, 52, -30,
    //                   										-3,   52,   62,   99,   89,
    //                    									67,    7,  -61,  -97, -115,
    //                    									-71,  -45,   17, 4};
    //con tono = 48, pero no llega a tener 20 elementos. Tiene 19, asique no cumple duraMasDe(subsenial, freq, 2)

    EXPECT_FALSE(seEnojo(fstSig, thresh, prof, freq));
}
TEST(seEnojoTEST, senialMenorADosSegundos){
senial s = {1,3,-3,4,6,0,-2,-8,9,-15,7};
int prof = 8;
int freq = 10;
int umbral = 3;
    EXPECT_FALSE(seEnojo(s,umbral,prof,freq));
}
TEST(seEnojoTEST, justo2Seg) {
    int prof = 8;
    int freq = 10;
    int thresh = 50;

    senial sndSig = {-100, -100, -100, -100, -100, -100, -100, -100, -100, -100,
                     -100, -100, -100, -100, -100, -100, -100, -100, -100, -100};
    EXPECT_FALSE(seEnojo(sndSig, thresh,prof,freq));
}
