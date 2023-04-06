/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ContadorBigramas.h
 * Author: carlosgspsp
 *
 * Created on 14 de mayo de 2018, 19:22
 */

#ifndef CONTADORBIGRAMAS_H
#define CONTADORBIGRAMAS_H

#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include "Bigrama.h"
#include "Idioma.h"



class ContadorBigramas{
private:
    int** _bigramas;
   std::string validos;
   int tam;


public:
    
    ContadorBigramas();
    void Limpiar();
    void EstablecerFrecuencias(const char *fichero);
    Idioma CrearIdioma(const std::string &idioma);
    Idioma ActualizarIdioma(const char *idioma);
};

#endif /* CONTADORBIGRAMAS_H */
