int prof = 8;
    int freq = 10;
    hablante a = 0;
    hablante b = 1;

    senial fstSig = { -9,   43,   -54,  103,   -44,   59,  -10,  44,  -55,   104,
                      -45,  60,   -9,   43,   -54,  103,   -44,   59,  -10,  44};

    senial rdSig = { 17, -128, 127 , -18,  15, -16,  17, -20,  19, -18,
                     1, -1,  2,  1, -2,  3,  0, -1,  3,  0,  0,  1,  1,
                     -1,  2,  1, -2, 3,  0, -1,  3,  0,  0,  1,  1};

    reunion meet6 = {make_pair(rdSig, a), make_pair(fstSig, b)};

    vector<hablante> expectedMeet = {b};

    if(tonosDeVozElevados(meet6, prof, freq) == expectedMeet){
        cout << "funcaaaa" ;
    }