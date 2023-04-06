/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "Bigrama.h"
#include "Idioma.h"
#include "ContadorBigramas.h"

using namespace std;
int main(int narg, char * args[]){
   
    ContadorBigramas idi;
    idi.EstablecerFrecuencias(args[1]);
    Idioma idiomadesc=idi.CrearIdioma("unknown");
    int tam= narg-2;
    Idioma idioma[tam];
    for (int i = 0; i < tam; i++)
    {
        idioma[i].cargarDeFichero(args[i+2]);
        idioma[i].ordenar();
        
    }
    double distancia = 1;
    string idioma_archivo;
    double dis = 0;
    for (int i = 0; i<tam; i++ )
    {
        
        dis = idiomadesc.distancia(idioma[i]);
        
        if (dis<distancia){
            distancia = dis;
            idioma_archivo = idioma[i].getIdioma();
        }
            cout << "La distancia al idioma " << idioma[i].getIdioma() << " es: " << dis << endl;
    }
    cout << "El archivo " << args[1] << " esta escrito en: " << idioma_archivo;
}