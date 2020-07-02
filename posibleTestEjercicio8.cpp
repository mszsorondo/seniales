//Test1 ejercicio 8:
    int prof = 32;
    int freq = 10;
    int umbral = 80;

    senial s = {5, -3, 2, 1, 66, 734, -1803, -551, -19, 27, 396, 231, 32, 33, 14,777};


    vector<pair<int, int>> intervalos = silencios(s, prof, freq, umbral);
    vector<pair<int, int>> esperado = {make_pair(0, 4), make_pair(8, 9), make_pair(12, 14)};

    //EXPECT_EQ(intervalos, esperado);
    if(intervalos == esperado){
        cout << "Ejercicio 8 - test 1 PASA"<<endl;
    }



    //Test2 ejercicio 8:
    int prof2 = 32;
    int freq2 = 10;
    int umbral2 = 3;

    senial s2 = {5, -3, 21, 1, 66, 734, -1803, -551, -19, 27, 396, 231, 32, 33, 14,777};


    vector<pair<int, int>> intervalos2 = silencios(s2, prof2, freq2, umbral2);
    vector<pair<int, int>> esperado2 = {make_pair(3, 3)};

    //EXPECT_EQ(intervalos, esperado);
    if(intervalos2 == esperado2){
        cout << "Ejercicio 8 - test 2 PASA" << endl;
    }

    //Test3 ejercicio 8:        (todos es silencio)
    int prof3 = 32;
    int freq3 = 10;
    int umbral3 = 999;

    senial s3 = {5, -3, 21, 1, 66, 734, -803, -551, -19, 27, 396, 231, 32, 33, 14,777};


    vector<pair<int, int>> intervalos3 = silencios(s3, prof3, freq3, umbral3);
    vector<pair<int, int>> esperado3 = {make_pair(0, 15)};

    //EXPECT_EQ(intervalos, esperado);
    if(intervalos3 == esperado3){
        cout << "Ejercicio 8 - test 3 PASA" << endl;
    }

    //Test4 ejercicio 8:        (no hay silencio)
    int prof4 = 32;
    int freq4 = 10;
    int umbral4 = 2;

    senial s4 = {5, -3, 21, 11, 66, 734, -803, -551, -19, 27, 396, 231, 32, 33, 14,777};


    vector<pair<int, int>> intervalos4 = silencios(s4, prof4, freq4, umbral4);
    vector<pair<int, int>> esperado4 = {};

    //EXPECT_EQ(intervalos, esperado);
    if(intervalos4 == esperado4){
        cout << "Ejercicio 8 - test 4 PASA" << endl;
    }