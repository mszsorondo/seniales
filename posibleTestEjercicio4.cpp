//test 1:
   //todos iguales
    int prof4 = 16;
    int freq4 = 10;

    senial sig = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9};

    reunion reunion_out = {make_pair(sig,0)};
    senial sig_res={43, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res = { make_pair(sig_res,0) };

    acelerar(reunion_out,prof,freq);

    cout << "test1:" << endl;
    if(reunion_out == res){
        cout << "";
    }else{
        cout << "no " ;
    }
    cout << "pasa" << endl;


    //test 2:
    //mismas seniales, distinto hablante
    int prof44 = 16;
    int freq44 = 10;

    senial sig44 = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                   -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                   -45,  -60,    9};

    reunion reunion_out44 = {make_pair(sig44,0)};
    senial sig_res44={43, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res44 = { make_pair(sig_res44,1) };

    acelerar(reunion_out44,prof44,freq44);

    cout << "test2:" << endl;
    if(reunion_out44 != res44){
        cout << "";
    }else{
        cout << "no " ;
    }
    cout << "pasa" << endl;

    //test 3:
    //distintas seniales, mismo hablante
    int prof444 = 16;
    int freq444 = 10;

    senial sig444 = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                     -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                     -45,  -60,    9};

    reunion reunion_out444 = {make_pair(sig444,0)};
    senial sig_res444={1,2,3,4,5,6, 9, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res444 = { make_pair(sig_res444,0) };

    acelerar(reunion_out444,prof444,freq444);

    cout << "test3:" << endl;
    if(reunion_out444 != res444){
        cout << "";
    }else{
        cout << "no " ;
    }
    cout << "pasa" << endl;


    //test 4:
    //distintas seniales, distintos hablantes
    int prof4444 = 16;
    int freq4444 = 10;

    senial sig4444 = { 9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,  -45,
                      -60,    9,   43,   54,  103,   44,   59,  -10,  -44,  -55, -104,
                      -45,  -60,    9};

    reunion reunion_out4444 = {make_pair(sig4444,1)};
    senial sig_res4444={90, 103, 59, -44, -104, -60, 43, 103, 59, -44, -104, -60};
    reunion res4444 = { make_pair(sig_res4444,0) };

    acelerar(reunion_out444,prof4444,freq4444);

    cout << "test4:" << endl;
    if(reunion_out4444 != res4444){
        cout << "";
    }else{
        cout << "no " ;
    }
    cout << "pasa" << endl;