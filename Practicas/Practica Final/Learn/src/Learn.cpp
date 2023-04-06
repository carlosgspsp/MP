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
        //PRE: Para args[1] = -a el usuario debe asegurar la existencia del arhivo del idioma
int main(int narg, char * args[])
{
    ContadorBigramas idi;
        for (int i = 6; i < narg; i++)
    {
        idi.EstablecerFrecuencias(args[i]);
       
    }
    
    string arg1(args[1]);
    if (arg1 == "-c")
    {
        string arg2(args[2]);
        if (arg2 == "-l")
        {
              
            
    string nombre(args[3]);
    Idioma idioma = idi.CrearIdioma(nombre);
    idioma.ordenar();
    idioma.salvarAFichero(args[5]);
    }
        else if (arg2 == "-f")
        {
                      
    string nombre(args[5]);
    Idioma idioma = idi.CrearIdioma(nombre);
    idioma.ordenar();
    idioma.salvarAFichero(args[3]); 
        }
    }
    else if (arg1 == "-a")
    {
            string arg2(args[2]);
        if (arg2 == "-l")
        {
              
    
            string nombre(args[3]);
           const char *cnombre = nombre.c_str();
    Idioma idioma = idi.ActualizarIdioma(cnombre);
    idioma.ordenar();
    idioma.salvarAFichero(args[5]);
    }
        else if (arg2 == "-f")
        {
                  string nombre(args[5]);
            nombre += ".bgr";
           const char *cnombre = nombre.c_str();
    Idioma idioma = idi.ActualizarIdioma(cnombre);
    idioma.ordenar();
    idioma.salvarAFichero(args[3]);     
    
        }
    }
}