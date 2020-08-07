#include <algorithm>
#include "ejercicios.h"
#include "math.h"


// Ejercicios

void acelerarSenial();

bool esSenial(vector<int> const& s, int prof, int freq) {
    bool resp = false;
    // Implementacion
    //Diremos que una secuencia es señal cuando freq = 10Hz=10/s; prof = 8 o 16 0 32 y t>1
    //freq = s.size()/t <=> t = s.size()/freq
    float t = s.size()/freq;
    bool profValida = (prof == 8 || prof == 16 || prof == 32);
    if(freq==10 && profValida && t>=1) {
        resp = true;
        for(int i = 0; i<s.size() ; i++){
            int minimaMuestraValida = -pow(2,prof-1);
            int maximaMuestraValida = pow(2,prof-1)-1;
            resp = resp && ( minimaMuestraValida <= s[i] ) && (s[i]<= maximaMuestraValida );
        }
    }
    return resp;
}


bool seEnojo(senial const &s, int umbral, int prof, int freq){
    float sumaActual = float(sumatoriaAbsoluta(s,0,s.size()));
    int largoActual = s.size();
    int largoMinimo = freq * 2;
    bool resp = sumaActual/s.size()>umbral;
    for(int i = 0; (i <= s.size() - largoMinimo) && !resp; i++){
        float sumaCopia = sumaActual;
        int largoCopia = largoActual;
        for(int j = s.size()-1; (j >= largoMinimo) && !resp && j-i>=largoMinimo; j--){
            resp = resp || (sumaCopia/largoCopia>umbral);
            sumaCopia = sumaCopia - abs(s[j]);
            largoCopia--;
        }
        resp = resp || (sumaActual/largoActual>umbral);
        sumaActual = sumaActual - abs(s[i]);
        largoActual--;
    }
    return resp && largoMinimo<s.size();
}

int sumatoriaAbsoluta(vector<int> s, int desde, int hasta){
    int suma = 0;
    for(int i = desde; i<hasta ; i++){
        suma = suma + abs(s[i]);
    }
    return suma;
}

bool esReunionValida(reunion const &r, int prof, int freq) {
    bool result = r.size() > 0;
    result = result && esMatriz(r);
    result = result && senialesValidas(r,prof,freq);
    result = result && hablantesDeReunionValidos(r,prof,freq);
    return result;
}


void acelerar(reunion& r, int prof, int freq) {
    // Implementacions
    for (int i = 0 ; i<r.size() ; i++){
        acelerarSenial(r[i].first);
    }

    return;
}

void ralentizar(reunion& r, int prof, int freq) {
    // Implementacion
    for(int i = 0 ; i< r.size(); i++){
        ralentizarSenial(r[i].first);
    }

    return;
}

vector<hablante> tonosDeVozElevados(reunion const& r, int freq , int prof){

    vector<int> vector_hablantes_mas_elevados;
    int tono_maximo = tonoMasElevado(r);
    for(int i = 0; i<r.size();i++){
        if(tono(r[i].first) == tono_maximo ){
            vector_hablantes_mas_elevados.push_back(r[i].second);
        }
    }
    return vector_hablantes_mas_elevados;
}


void ordenar(reunion& r, int freq, int prof) {
    int posicionDelMaximo = 0;
    for (int i = 0; i < r.size(); i++) {
        posicionDelMaximo = findMaxPosition(r, i, r.size());
        swapDupla(r, i, posicionDelMaximo);

    }
}

vector< pair< int, int>> silencios(senial const &s, int prof, int freq, int umbral){

    //entrada
    vector<vector<int>> secuenciasDeSilencio = secuenciasDeSilencios(s, umbral);

    //salida
    vector< pair< int, int>> intervalos;

    for(int i = 0 ; i < secuenciasDeSilencio.size() ; i++){
        //puede haber varias subsecuencias vacias, asique primero chequeo eso:
        if(secuenciasDeSilencio[i].size() > 0){
            //si no es vacio, tomo el primer elemento y el ultimo, estos daran el intervalo deseado:
            int primero = secuenciasDeSilencio[i][0];
            int lenght = secuenciasDeSilencio[i].size();
            int ultimo = secuenciasDeSilencio[i][lenght-1];
            pair <int, int> intervalo = make_pair(primero, ultimo);
            intervalos.push_back(intervalo);
        }
    }

    return intervalos;
}

bool hablantesSuperpuestos(reunion const& r, int prof , int freq , int umbral ){
    bool seRespetan = true;
    for(int i = 0; i< r[0].first.size() && seRespetan ; i++){
        seRespetan = seRespetan && !hayMuestrasSuperpuestas(r,i, umbral);
    }
    return !seRespetan;
}



senial reconstruir(senial const &s, int prof, int freq){

    senial s0 = s;


    for(int i = 0 ; i < s.size() ; i++){

        if(s0[i] == 0 ) {
            if (esPasajePorCero(s0, i)) {
                s0[i] = 0;
            } else {
                //a promedioValores le paso la senial original, no la que se va modificando
                s0[i] = promedioValores(s, i);
            }
        }

    }

    //s0 = s;

    return s0;
}



void filtradoMediana(senial& s, int R, int prof , int freq){
    vector<int> w(2*R+1,0);
    vector<int> copiaOriginal = s;
    for(int i = R ; i<s.size()-R ; i++){
        vector<int> v = copiarSubSecDeLargoFDesde(copiaOriginal,w,i-R);
        bubbleSort(v);//RECORDAR CAMBIAR POR EL COUNTING SORT PARA BAJAR LA COMPLEJIDAD
        s[i] = v[R];
    }
}





