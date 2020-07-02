//EJERCICIO 9

    //test 1
    int prof9 = 16;
    int freq9 = 10;
    int umbral9 = 12;

    senial s_a = {10, 51, 82, 97, 39, 2, 1, 0, 21, 15, 7};
    senial s_b = {2, 3, 2, -100, -32, -55, -4, -6, -100, -75, 20 };
    senial s_c = {-61, -9, -7, -65, -77, -8, -30, -3, 27, 36, 5};
    pair <senial, hablante> h_a (s_a, 0);
    pair <senial, hablante> h_b (s_b, 1);
    pair <senial, hablante> h_c (s_c, 2);

    reunion r = {h_a, h_b, h_c};

    //EXPECT_TRUE(hablantesSuperpuestos(r, prof, freq, umbral));
    if(hablantesSuperpuestos(r, prof9, freq9, umbral9)){
        cout << "Ejercicio 9 - test 1 PASA" << endl;
    }

    //test 2
    int prof92 = 16;
    int freq92 = 10;
    int umbral92 = 12;

    senial s_a2 = {2, 2, 82, 0, 4, 2, 1, 0, 1, 5, 7};
    senial s_b2 = {2, 3, 2, -100, -3, -55, -4, -6, -100, -5, 20 };
    senial s_c2 = {-61, -9, -7, -11, -77, -8, -30, -3, 2, 36, 5};
    pair <senial, hablante> h_a2 (s_a2, 0);
    pair <senial, hablante> h_b2 (s_b2, 1);
    pair <senial, hablante> h_c2 (s_c2, 2);

    reunion r2 = {h_a2, h_b2, h_c2};

    //EXPECT_FALSE(hablantesSuperpuestos(r, prof, freq, umbral));
    if(!hablantesSuperpuestos(r2, prof92, freq92, umbral92)){
        cout << "Ejercicio 9 - test 2 PASA" << endl;
    }