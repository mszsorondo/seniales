//test 1 para seEnojo:
    //funca bien
    int prof = 8;
    int freq = 10;
    int thresh = 65;
    senial fstSig = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};
    cout << "test 1:" << endl;
    if(seEnojo(fstSig,thresh,prof,freq)){
        cout << "" ;
    }else{
        cout << "no" ;
    }
    cout << "se enojo" << endl;

    //test 2 para seEnojo:
    //umbral bien alto
    int proff = 8;
    int freqq = 10;
    int threshh = 85;
    senial fstSig2 = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
                      -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};
    cout << "test 2:" << endl;
    if(seEnojo(fstSig2,threshh,proff,freqq)){
        cout << "" ;
    }else{
        cout << "no " ;
    }
    cout << "se enojo" << endl;

    //test 3 para seEnojo:
    //frecuencia bien alta
    int profff = 8;
    int freqqq = 100;
    int threshhh = 65;
    senial fstSig3 = { 17,   32,   80,   85,   99,   62,    7,  -55, -107, -101,  -88, -26,
                       -3,   52,   62,   99,   89,   67,    7,  -61,  -97, -115, -71,  -45,   17};
    cout << "test 3:" << endl;
    if(seEnojo(fstSig3,threshhh,profff,freqqq)){
        cout << "" ;
    }else{
        cout << "no " ;
    }
    cout << "se enojo" << endl;