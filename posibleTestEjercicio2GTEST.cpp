TEST(seEnojo, checkForSubseqOfMinSizeTwoTimesFreq) {  //hay muchas subseq que cumplen
    int prof = 8;
    int freq = 10;
    int thresh = 65;

    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
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