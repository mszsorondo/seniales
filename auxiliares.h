//
// Created by Sebastian Vita on 2020-05-25.
//

#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H
#endif //REUNIONESREMOTAS_AUXILIARES_H
#include "definiciones.h"
//1 (sin auxiliares)
//2(J)...
senial subseq(senial s, int d, int h);
bool  superaUmbral(senial s, int umbral);
bool duraMasDe(senial s, int freq, float seg);
float tono(senial s);
//2(M)
int promedio(int suma,int tamanio);
bool hayTonoDeTamanioSQueSupera(senial s, int tamanio, int umbral);
//3 (sin auxiliares)
//4
void acelerarSenial(senial& s);
//5
void ralentizarSenial(senial &s);
//6
float tonoMasElevado(reunion r);
//7
int findMaxPosition(reunion &r, int desde, int hasta);
void swapDupla(reunion& r, int i , int j);
//8...
void limpiar(senial &s);
vector<vector<int>> secuenciasDeSilencios(senial s, int umbral);

//9...
bool hayMuestrasSuperpuestas(reunion const& r, int i, int umbral);
//10(J)
int promedioValores(senial s, int i);
int signo(int x);
bool esPasajePorCero(senial s, int i);
//11
int sumatoriaAbsoluta(vector<int>s, int desde, int hasta);
void swap(reunion const& s, int i , int j);
vector<int> copiarSubSecDeLargoFDesde(senial s, vector<int> w, int i);
void burbujeo(vector<int>& lista, int i);
void bubbleSort(vector<int>& lista);



