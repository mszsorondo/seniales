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