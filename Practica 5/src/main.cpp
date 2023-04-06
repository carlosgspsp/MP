/** 
 * @file main.cpp
 * @author DECSAI
 */
#include <iostream>
#include <cstring>
#include <fstream>
#include "Bigrama.h"
#include "Idioma.h"
 
using namespace std;
 

int main(int narg, char * args[]) {
    char cadena[3];
    Idioma id;
    int frec, pos;
   
    cout << "Has llamado al programa como:"<< endl;
    for (int i=0;i<narg;i++){
        cout<< args[i]<< " ";
    }
    cout << endl;
     
    if (narg  < 3)  {
        cerr << "Error en la llamada.\n puebaIdioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 1;
    }
    strncpy(cadena, args[1],2); // copiamos el bigrama pasado como argumento en cadena
    cadena[2]='\0';
    for(int i=2; i<narg; i++)  {
        cout << "Paso a leer fichero " << args[i] << endl;
      if (id.cargarDeFichero(args[i]))  {
         pos = id.findBigrama(cadena);
         if (pos >= 0)
           cout << endl << "El bigrama "<<cadena << " tiene una frecuencia de "  << id.getPosicion(pos).getFrecuencia() << " en el idioma " << id.getIdioma() << endl;
             else
           cerr << endl << "El bigrama "<<cadena << " no aparece en el idioma " << id.getIdioma() << endl;
        
       
        Bigrama bg;
        cadena[0]='x';
        bg.setFrecuencia(100);
        for (int i=0;i<5;i++){
           cadena[1]='a'+i; cadena[2]='\0';
           bg.setBigrama(cadena);
           id.insertarBigrama(bg);
        }
       
        id.salvarAFichero(args[i]);        
        }
      else cout << "Error al cargar fichero " << args[i] << endl;
    }
    id.liberarMemoria();
    return 0;
}