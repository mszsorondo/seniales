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
    int t = s.size()/freq;
    bool profValida = (prof == 8 || prof == 16 || prof == 32);
    if(freq==10 && profValida && t>1) {
        resp = true;
        for(int i = 0; i<s.size() ; i++){
            int minimaMuestraValida = (-pow(2,prof-1));
            int maximaMuestraValida = (pow(2,prof-1)-1);
            resp = resp && ( minimaMuestraValida <= s[i] && s[i]<= maximaMuestraValida );
        }
    }//DUDA: La spec dice que frecuencia debe ser pow(10,2) y no pow(10,1) como puse aca (y sin embargo el test da true!)
    return resp;
}


bool seEnojo(senial const& s, int umbral, int prof, int freq) {
    bool result = false;
    for(int i = 0; i < s.size() -1; i++) {
        for (int j = i+1; j < s.size(); j++) {
            if(duraMasDe(subseq(s,i,j),freq,2) && superaUmbral(subseq(s,i,j),umbral)){
                result = true;
            }
        }
    }
    return result;
}
bool seEnojo2(senial const& s, int umbral, int prof, int freq) {
    bool resp = false;
    for(int i = s.size() ; i>=21 && (resp == false) ; i--){
        resp = resp || hayTonoDeTamanioSQueSupera(s, i, umbral);
    }
    return resp;
}
//un caso sería(supongamos que la frecuencia es 2/s): s = {10,21,15,25,5,2,16,13}, umbral = 20 , prof = 4 -> max(s) = 31 min(s)=-32

bool esReunionValida(reunion const& r, int prof, int freq) {
    bool resp = true;
    resp = resp && r.size()>0;
    int nFilas = r[0].first.size();
    bool tamanioDeSenialCorrecto = true, senialValida=true , idEnRango= true, sinRepetidos = true;

    for(int i = 0 ; i<r.size() ;i++){
        tamanioDeSenialCorrecto = tamanioDeSenialCorrecto && r[i].first.size() == nFilas;
        senialValida = senialValida && esSenial(r[i].first,prof,freq);
        idEnRango = idEnRango && r[i].second>=0 && r[i].second<r.size();
        sinRepetidos = sinRepetidos && (r[i].second != r[i+1].second);

    }
    resp = tamanioDeSenialCorrecto && senialValida && idEnRango && sinRepetidos;
    return resp;

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



senial reconstruir(senial const& s, int prof, int freq) {
    senial senalReconstruida;
    // Implementacion
    return senalReconstruida;
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





