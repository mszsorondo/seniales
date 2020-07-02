//EJERCICI0 11:

    //test 1:
    int prof11 = 16;
    int freq11 = 10;
    int r11 = 2;

    senial s11 = {-102, -65, -46, -35, 13, 23, 34, 54, 71, 77 };

    filtradoMediana(s11, r11, prof11, freq11);
    senial esperada11 = {-102, -65, -46, -35, 13, 23, 34, 54, 71, 77 };

    if(esperada11 == s11){
        cout << "ejercicio 11 test 1 paso" << endl;
    }


    //test 2:
    int prof112 = 16;
    int freq112 = 10;
    int r112 = 4;

    senial s112 = {54, 23, -65, 0, 50, -32, -102, 34, 71, -35, 77, 13, -46};

    filtradoMediana(s112, r112, prof112, freq112);
    senial esperada112 = {54, 23, -65, 0, 23, 0, 0, 13, 13, -35, 77, 13, -46};

    if(esperada112 == s112){
        cout << "ejercicio 11 test 2 paso" << endl;
    }