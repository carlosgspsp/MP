/** 
 * @file Idioma.cpp
 * @author DECSAI
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"

using namespace std;

Idioma::Idioma() {
    _idioma="unkown";
    _conjunto = nullptr;
    _nBigramas = 0;
}

Idioma::Idioma(int nbg)  {
    _conjunto = nullptr;
    reservarMemoria(nbg);
}

void Idioma::liberarMemoria() {
    delete _conjunto;
}

string Idioma::getIdioma() const {
    return _idioma;
}

void Idioma::setIdioma(const string& id) {
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const {
    if (_conjunto+p < _conjunto + _nBigramas) 
    return *(_conjunto+p);
}


void Idioma::setPosicion(int p, const Bigrama& bg) {
     _nBigramas=p;
}

bool Idioma::insertarBigrama(const Bigrama& bg){
   
   int pos;
   if ((pos=findBigrama(bg.getBigrama()))!= -1)
   {
       _conjunto[pos].setFrecuencia(bg.getFrecuencia());
   }
   else {
       _nBigramas++;
       Bigrama *aux = new Bigrama[_nBigramas];
       for (int i= 0; i< _nBigramas; i++)
          aux[i] = _conjunto[i]; // *(aux+i) = *(_conjunto +i)
       reservarMemoria(_nBigramas);
       for (int i = 0; i < _nBigramas - 1; i++)
       {
       _conjunto[i] = aux[i];
       _conjunto[_nBigramas-1] = bg;
       }
        }

    }

int Idioma::findBigrama(const char bg[]) const  {
     int posicion=-1;
    for(int i = 0;i < _nBigramas; i++){
        if( strcmp(_conjunto[i].getBigrama(), bg)==0)
            posicion = i;
    }
    return(posicion);
}
    
bool Idioma::salvarAFichero(const char *fichero) const {
     ofstream fichero1;
    fichero1.open(_idioma+".bgr");
    if(fichero1.is_open()){
        fichero1 << _idioma;
        fichero1 << _nBigramas;
        for(int i = 0;i < _nBigramas; i++)
        fichero1 << _conjunto[i].getBigrama() << ' ' << _conjunto[i].getFrecuencia() << endl;
        fichero1.close();
        return true;
    }
    else return false;
}

bool Idioma::cargarDeFichero(const char *fichero) {
    ifstream fichero1;
    string idioma;
    string bigrama;
    int lineas;
    int frecuencia;
    Bigrama bigrama_enuso;
    fichero1.open(fichero);
    if(fichero1.is_open()){
        fichero1 >> idioma;
        fichero1 >> idioma;
        setIdioma(idioma);
        fichero1 >> lineas;
        reservarMemoria(lineas);
        for(int i = 0;i < lineas;i++){
            fichero1 >> bigrama;
            bigrama_enuso.setBigrama(bigrama.c_str());
            fichero1 >> frecuencia;
            bigrama_enuso.setFrecuencia(frecuencia);
            insertarBigrama(bigrama_enuso);
        }
        fichero1.close();    
        return(true);
        
    }
    else
        return(false);
}

 
void Idioma::reservarMemoria(int n) {
    if (_conjunto != nullptr)
        delete[] _conjunto;
        
        _conjunto = new Bigrama[n];
}
