/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContadorBigramas.cpp
 * Author: carlosgspsp
 * 
 * Created on 15 de mayo de 2018, 12:54
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"
#include "ContadorBigramas.h"
using namespace std;

ContadorBigramas::ContadorBigramas() {
    
    validos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    tam = validos.size();
    
    _bigramas =new int*[tam];
    for (int i = 0; i < tam; i++)
        _bigramas[i]=new int[tam];
    Limpiar();
    
    
}

void ContadorBigramas::Limpiar()
{
      for (int f = 0; f < tam; f++)
    {
        for (int c = 0; c <tam; c++ )
        {
        _bigramas[f][c]=0;    
        }
    }
}
void ContadorBigramas::EstablecerFrecuencias (const char *fichero)
{
    ifstream fichero1;
    char bigrama[2];
    fichero1.open(fichero);
    char f;
    char c;
    
    if(fichero1.is_open()){
    fichero1.get(f);
    while (fichero1.get(c)){

    if  (validos.find(f) == string::npos)
    {
       f = c;
    }
    else if (validos.find(c) != string::npos)
        _bigramas[validos.find(f)][validos.find(c)]++;
    f = c;
    }
    
    fichero1.close();
    }
    
    else
    {
        string nombre = fichero;
        cout << "error al abrir archivo " << nombre << endl;
    }
    }
Idioma ContadorBigramas::CrearIdioma(const string &idioma)
{
    Idioma v;
    Bigrama x;
    char cad[3];
    cad[2] = '\0';
    v.setIdioma(idioma);
    for (int f = 0; f<tam;f++)
        for (int c = 0; c<tam; c++)
        {
            if (_bigramas[f][c]!=0){
            cad[0]= validos[f];
            cad[1]= validos[c];
           x.setBigrama(cad);
           x.setFrecuencia(_bigramas[f][c]);
           v.insertarBigrama(x);
            }
        }
    return v;
    
}
Idioma ContadorBigramas::ActualizarIdioma(const char *idioma)
{
  Idioma v;
    Bigrama x;
    char cad[3];
    cad[2] = '\0';
    v.cargarDeFichero(idioma);
    for (int f = 0; f<tam;f++)
        for (int c = 0; c<tam; c++)
        {
            if (_bigramas[f][c]!=0){
            cad[0]= validos[f];
            cad[1]= validos[c];
           x.setBigrama(cad);
           x.setFrecuencia(_bigramas[f][c]+v.getPosicion(v.findBigrama(cad)).getFrecuencia());
           v.insertarBigrama(x);
            }
        }
    return v;
    
}