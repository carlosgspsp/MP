/** 
 * @file Bigrama.cpp
 * @author DECSAI
*/

#include <cstring>
#include <iostream>
#include <cctype>
#include "Bigrama.h"

using namespace std;


Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char * Bigrama::getBigrama() const {
    return _bigrama;
}
int Bigrama::getFrecuencia() const {
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]) {
    if (strlen(cadena) <= 2)
        strcpy(_bigrama, cadena);
//    strncpy(_bigrama, cadena, 2); // Diferencias, violaciones de _bigrama[] o de cadena[]
}

void Bigrama::setFrecuencia(int frec) {
    _frecuencia = frec;
}

void ordenaAscFrec(Bigrama *v, int n)  {
        Bigrama minimo;
	Bigrama intercambio;
	int posicion_minimo;
	for(int i = 0; i < n; i++){
		minimo = v[i];
		posicion_minimo=i;
		for(int j = i + 1; j<= n;j++){
			if(v[j].getFrecuencia()<minimo.getFrecuencia()){
				minimo = v[j];
				posicion_minimo = j;
			}
		}
		intercambio = v[i];
		v[i]=v[posicion_minimo];
		v[posicion_minimo]=intercambio;
	}
		
}
 void ordenaDesFrec(Bigrama *v, int n)  {
        Bigrama maximo;
	Bigrama intercambio;
	int posicion_maximo;
	for(int i = 0; i < n; i++){
		maximo = v[i];
		posicion_maximo=i;
		for(int j = i + 1; j<= n;j++){
			if(v[j].getFrecuencia()>maximo.getFrecuencia()){
				maximo = v[j];
				posicion_maximo = j;
			}
		}
		intercambio = v[i];
		v[i]=v[posicion_maximo];
		v[posicion_maximo]=intercambio;
	}
		
}


void ordenaAscBigr(Bigrama *v, int n) {
    char menor = 'a'+27;
    char menor1 = menor;
    Bigrama *menorp;
    for (Bigrama *k = v; k<v+n; k++)
        
    {
        for (Bigrama *p= k; p<v+n;p++)
        {
            if(tolower(*(p->getBigrama()))< menor)
            {  
            menor = *p->getBigrama();
            for (Bigrama *i= k; i<v+n;i++)
        {
            if(*((i+1)->getBigrama())< menor1)
            {  
            menor1 = *((i+1)->getBigrama());
            }  
            else if (tolower(*(p->getBigrama())) == menor)
            for (Bigrama *i= k; i<v+n;i++)
        {
            if(tolower(*((i+1)->getBigrama()))< menor1)
            {  
            menor1 = *((i+1)->getBigrama());
            menorp = i;
            }  
        }
            }
    
    }
        }
       for (Bigrama *i= v+n-1; i<=k; i--)
        {
            *i = *(i-1);
            *k= *menorp;
        }
        
    }
    
}

void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama() << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}

void sumaBigramas( Bigrama *v1, int nv1, Bigrama *v2, int nv2, Bigrama *&res, int & nres)  {
    Bigrama *pos = res;
    int n = nres;
    for (Bigrama *k = v1; k< v1+nv1; k++)
    {
        for (Bigrama *p=v2; p< v2+nv2; p++)
        {
            if (*(p->getBigrama()) == *(k->getBigrama())){
                int nfrec = p->getFrecuencia() + k->getFrecuencia();
            res->setFrecuencia(nfrec);
            res->setBigrama((k->getBigrama()));
            res++;
            }
        }
    
    }
    
}


