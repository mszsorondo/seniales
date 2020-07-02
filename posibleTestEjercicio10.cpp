//EJERCICIO 10
    //test 1:

    int prof10 = 8;
    int freq10 = 10;

    senial s10 = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77, -80, 0, -91};

    //senial s10 = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77, 0, 0, 0, 0, -80, 0, -91, -77, -80, 0, -91}; // i = 12
    senial rec = reconstruir(s10, prof, freq);
    senial esperada = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, -80, -85, -91};



    //EXPECT_EQ(rec, esperada);/
     if(rec == esperada){
        cout << "Ejercicio 10 - test 1 PASA" << endl;
    }

    //test 2:

    int prof102= 8;
    int freq102 = 10;

    senial s102 = {1, 0, 2, 4, 2, 0, 0, 0, 0, 7, 5, 1, 2};

    senial rec2 = reconstruir(s102, prof102, freq102);
    senial esperada2 = {1, 1, 2, 4, 2, 4, 4, 4, 4, 7, 5, 1, 2};

    //EXPECT_EQ(rec, esperada);/
    if(rec2 == esperada2){
        cout << "Ejercicio 10 - test 2 PASA" << endl;
    }

    //test 3:

    int prof103= 8;
    int freq103 = 10;

    senial s103 = {-2, 0, 3, 5, 0, -7, 0, 0, -2, 0, 3, 4};

    senial rec3 = reconstruir(s103, prof103, freq103);
    senial esperada3 = {-2, 0, 3, 5, 0, -7, -4, -4, -2, 0, 3, 4};

    //EXPECT_EQ(rec, esperada);/
    if(rec3 == esperada3){
        cout << "Ejercicio 10 - test 3 PASA" << endl;
    }