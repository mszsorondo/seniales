#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(ralentizar, unHablanteSenialAscendente) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={1, 1, 2, 2, 3, 3, 4, 4, 5, 5,
                     6, 6, 7, 7, 8, 8, 9, 9, 10};

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}

TEST(ralentizar, unHablantesSenialDescendente) {
    int prof = 16;
    int freq = 10;

    senial sig1={ 10,8,2,-2,-3,-5,-6,-6,-8,-9,
                  -20,-21,-22,-22,-23,-24,-27,-30,-33};

    reunion meet_out = { make_pair(sig1,0 )  };

    senial sig1_res={ 10,9,8,5,2,0,-2,-2,-3,-4,-5,-5,-6,-6,-6,-7,-8,-8,-9,-14,
                      -20,-20,-21,-21,-22,-22,-22,-22,-23,-23,-24,-25,-27,-28,-30,-31,-33};;

    reunion meet_res = { make_pair(sig1_res,0 ) };

    ralentizar(meet_out,prof,freq);

    EXPECT_EQ(meet_res, meet_out);
}