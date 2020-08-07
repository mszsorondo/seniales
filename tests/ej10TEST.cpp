#include "gtest/gtest.h"
#include "../ejercicios.h"

TEST(reconstruir, faltantesDeUnaMuestra) {
    int prof = 8;
    int freq = 10;

    senial s = {50, 24, 0, 30, 1, -17, -60, 0, -55, -77,
                -80, 0, -91};
    senial rec = reconstruir(s, prof, freq);
    senial esperada = {50, 24, 27, 30, 1, -17, -60, -57, -55, -77, 
                       -80, -85, -91};

    EXPECT_EQ(rec, esperada);
}
TEST(reconstruir, test1){
    int prof102= 8;
    int freq102 = 10;

    senial s102 = {1, 0, 2, 4, 2, 0, 0, 0, 0, 7, 5, 1, 2};

    senial rec2 = reconstruir(s102, prof102, freq102);
    senial esperada2 = {1, 1, 2, 4, 2, 4, 4, 4, 4, 7, 5, 1, 2};
    EXPECT_EQ(rec2,esperada2);
}
TEST(reconstruir, test2){
    int prof103= 8;
    int freq103 = 10;

    senial s103 = {-2, 0, 3, 5, 0, -7, 0, 0, -2, 0, 3, 4};

    senial rec3 = reconstruir(s103, prof103, freq103);
    senial esperada3 = {-2, 0, 3, 5, 0, -7, -4, -4, -2, 0, 3, 4};

    EXPECT_EQ(rec3, esperada3);
}