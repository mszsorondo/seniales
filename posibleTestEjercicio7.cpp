//Test ejercicio 7:

    int prof = 32;
    int freq = 10;

    senial s_a = {-413, -422, -521, -500, 487, 549, 498, -456, -502, 599};
    senial s_b = {-213, -222, -321, -300, 287, 349, 298, -256, -302, 399};
    senial s_c = {-13, -22, -121, -100, 87, 149, 98, -56, -102, 199};
    reunion r = {std::make_pair(s_c, 2), std::make_pair(s_b, 1), std::make_pair(s_a, 0)};

    ordenarPorTonos(r);
    reunion esperada = {std::make_pair(s_a, 0), std::make_pair(s_b, 1), std::make_pair(s_c, 2)};

    //EXPECT_EQ(r, esperada);
    if(r == esperada){
        cout << "funcaaaa" ;
    }