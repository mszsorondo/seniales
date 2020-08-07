#include "definiciones.h"
#include "auxiliares.h"

// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
//2(J)...
senial subseq(senial s, int d, int h) {
    senial result;
    for(int i = d; i < h; i++){
        result.push_back(s[i]);
    }
    return result;
}
bool  superaUmbral(senial s, int umbral) {
    return tono(s) > umbral;
}
float tono(senial s){
    int sum = 0;
    for(int i = 0 ; i < s.size() ; i++){
        sum = sum + abs(s[i]);
    }
    return sum / s.size();
}
bool duraMasDe(senial s, int freq, float seg) {
    return s.size() >= freq * seg;
}
//3...
bool esMatriz(reunion const &r) {
    bool result = true;
    for(int a = 0 ; a < r.size() ; a++){
        if(r[a].first.size() != r[0].first.size()){
            result = false;
        }
    }
    return result;
}

bool esSenialValidaw(senial s, int prof, int freq) {

    bool result = esFrecValida(freq);
    result = result && profValida(prof);
    result = result && enRango(s, prof);
    result = result && duraMasDe(s, freq, 1);

    return result;
}

bool senialesValidas(reunion const &r, int prof, int freq) {
    bool result = true;
    for(int i = 0 ; i < r.size() ; i++){
        senial lasenial = r[i].first;
        if(!esSenialValidaw(lasenial,prof,freq)){
            result = false;
        }
    }
    return result;
}

bool hablantesDeReunionValidos(reunion const &r, int prof, int freq) {
    bool result = true;
    for(int i = 0 ; i < r.size() ; i++){
        if(r[i].second < 0 || r[i].second >= r.size()){
            result = false;
        }
        int j = 0;
        while(j < r.size() && r[j].second == r[i].second){
            if(i != j){
                result = false;
            }
            j++;
        }
    }
    return result;

}
bool esSenialValida(vector<int> const& s, int prof, int freq) {

    bool result = esFrecValida(freq);
    result = result && profValida(prof);
    result = result && enRango(s, prof);
    result = result && duraMasDe(s, freq, 1);
    return result;
}

bool esFrecValida(int freq) {
    return freq == 10;
}

bool enRango(senial s, int prof) {
    bool result = true;
    for(int i = 0; i < s.size(); i++){
        if (pow(-2, prof-1) > s[i] ) {
            result = false;
        }
        if (pow(2, prof-1) - 1 < s[i] ) {
            result = false;
        }
    }
    return result;
}


bool profValida(int prof) {
    return prof == 8 || prof == 16 || prof == 32;
}


//4,5...
void acelerarSenial(senial& s){
    senial acelerada;
    for (int i = 1; i<s.size() ; i+=2){
        acelerada.push_back(s[i]);
    }
    s = acelerada;
}
void ralentizarSenial(senial &s){
    senial ralentizada;
    for (int i = 1 ; i<s.size(); i++ ){
        int promedio = (s[i-1]+s[i])/2;
        ralentizada.push_back(s[i-1]);
        ralentizada.push_back(promedio);
    }
    ralentizada.push_back(s[s.size()-1]);
    s = ralentizada;
}

//6
float tonoMasElevado(reunion r){
    float max = tono(r[0].first);
    for(int i = 1 ; i < r.size() ; i++){
        if(tono(r[i].first) > max ){
            max = tono(r[i].first);
        }
    }
    return max;
}
//7...
int findMaxPosition(reunion &r, int desde, int hasta){
    int max = desde;
    for(int i = desde + 1; i<hasta; i++){
        if(tono(r[i].first) > tono(r[max].first))
            max = i;
    }
    return max;
}
void swapDupla(reunion& r, int i , int j){
    pair<senial, hablante> aux = r[i];
    r[i] = r[j];
    r[j] = aux;
}
//8...(J)
void limpiar(senial &s){
    senial s0 = s;
    if(s0.size() > 0){
        for(int i = 0 ; i < s0.size() ; i++){
            s.pop_back();
        }
    }
}
//esto devuelve tipo esto: < < 0 1 2 3 4 >, < >, < >, < 8 9 >, < >, < 12 13 14 >, < >, >
vector<vector<int>> secuenciasDeSilencios(senial s, int umbral){

    vector<vector<int>> seqDeSeqDeSilencio;
    vector<int> seqDeSilencio;


    for(int i = 0 ; i < s.size() ; i++){
        if(abs(s[i]) < umbral){                             //si me cruzo con un silencio, lo pusheo a seqDeSilencio
            seqDeSilencio.push_back(i);
        }else if(seqDeSilencio.size() > 1){                     //ahora si el que estoy parado no es silencio, miro a ver si tengo      algo en seqDeSilencio como para guardar hasta el momento
            //cout << i << " : " << seqDeSilencio[i] << endl;
            seqDeSeqDeSilencio.push_back(seqDeSilencio);        //me guardo la seqDeSilencio que junte hasta ahora
            limpiar(seqDeSilencio);                         //limpio la seqDeSilencio para poder leer la proxima secuencia de silencio
        }else{
            limpiar(seqDeSilencio);
        }
    }
    //en caso que haya una seqDeSilencio que llegue hasta el final:
    //seqDeSeqDeSilencio.push_back(seqDeSilencio);
    if(seqDeSilencio.size() > 1){
        seqDeSeqDeSilencio.push_back(seqDeSilencio);
    }


    return seqDeSeqDeSilencio;
}

//9...
bool hayMuestrasSuperpuestas(reunion const& r, int i, int umbral){
    int hablantesHablando = 0;
    for(int k = 0; k< r.size() && hablantesHablando<2 ; k++){
        if (abs(r[k].first[i]) >= umbral)
            hablantesHablando++;
    }
    return (hablantesHablando>1);
}
//10...(J)
int promedioValores(senial s, int i){
    int j = i - 1;
    int k = i + 1;
    int prom = 0;

    //cout << "en esta llamada i vale: " << i << "y s[i-1]: " << s[i-1] << endl;
    while(abs(j-k) <= 5 && prom == 0){
        if(s[j] == 0){
            j--;
        }
        if(s[k] == 0){
            k++;
        }
        if(s[j] + s[k] != 0 && s[j] != 0 && s[k] != 0){
            prom = ( s[j] + s[k] ) / 2;
            //cout << "s[j]: " << s[j] << ", s[k]: " << s[k] << endl;
        }
    }
    return prom;
}
int signo(int x){
    int signoToReturn;
    if(x<0){
        signoToReturn = -1;
    }else if(x>0){
        signoToReturn = 1;
    }else{
        signoToReturn = 0;
    }
    return signoToReturn;
}
bool esPasajePorCero(senial s, int i){
    return signo(s[i-1]) * signo(s[i+1]) == -1;
}

//11

vector<int> copiarSubSecDeLargoFDesde(senial s, vector<int> w, int i){
    for(int k = 0; k < w.size() ; k++){
        w[k] = s[i+k];
    }
    return w;
}
void swap(vector<int> &s, int i , int j){
    int aux = s[i];
    s[i] = s[j];
    s[j] = aux;
}
void bubbleSort(vector<int> &s){
    for(int k = 0; k<s.size(); k++){
        burbujeo(s,k);
    }
}
void burbujeo(vector<int> &s, int i){
    for(int j=s.size()-1; j > i; j--){
        if(s[j] < s[j - 1]){
            swap(s, j, j - 1);
        }
    }
}





