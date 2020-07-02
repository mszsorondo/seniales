//ejercicio 5:

    //test 1:
    int prof5 = 16;
    int freq5 = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10};

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof5,freq5);

    if(meet_res == meet_out){
        cout << "ejercicio 5 test 1 paso" << endl;
    }


    //test 2:
    int prof52 = 16;
    int freq52 = 10;

    senial sig12={ 2,7,2};

    reunion meet_out2 = { make_pair(sig12,0 )  };

    senial sig1_res2={2,4,7,4,2};

    reunion meet_res2 = { make_pair(sig1_res2,0 ) };

    ralentizar(meet_out2,prof52,freq52);

    if(meet_res2 == meet_out2){
        cout << "ejercicio 5 test 2 paso" << endl;
    }

    //test 3:
    int prof53 = 16;
    int freq53 = 10;

    senial sig13={ 3,5,4};

    reunion meet_out3 = { make_pair(sig13,0 )  };

    senial sig1_res3={3,4,5,4,4};

    reunion meet_res3 = { make_pair(sig1_res3,0 ) };

    ralentizar(meet_out3,prof53,freq53);

    if(meet_res3 == meet_out3){
        cout << "ejercicio 5 test 3 paso" << endl;
    }