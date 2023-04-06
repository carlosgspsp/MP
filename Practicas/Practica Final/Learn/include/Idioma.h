
/** 
 * @file Idioma.h
 * @author DECSAI
*/

#ifndef IDIOMA_H
#define IDIOMA_H


#include <iostream>
#include "Bigrama.h"

/**
 * @class Idioma
 * @brief Representa el conjunto los bigramas asociados a un idioma junto con el 
 * identificador del idioma
 */
class Idioma {
public:

    /**
     * @brief Constructor base
     */
    Idioma();
    
    /**
     * @brief Constructor para pre-reservar memoria
     * @param nbg Número de bigramas pre-reservados
     */
    Idioma(int nbg);
    
   /**
    * @brief reserva memoria para @a n bigramas
    * @param n número de bigramas a reservar
    * @todo implementar esta funcion
    */
    void reservarMemoria(int n);

    /**
     * @brief Libera la memoria
     */
    void liberarMemoria();
    
    /**
     * @brief Consulta el ID del idioma
     * @return ID del idioma
     */
    std::string getIdioma() const;  
    
    /**
     * @brief Establece el ID del idioma
     * @param id Nuevo ID del idioma
     */
    void setIdioma(const std::string& id);
    
    /**
     * @brief Consulta la lista de bigramas
     * @param p La posición de la lista que se quiere consultar
     * @precond La posición @p p es correcta
     * @return El bigrama que ocupa la posición @p p
     * @todo implementar esta funcion
     */
    Bigrama getPosicion(int p) const;
    
     /**
     * @brief Modificar un  bigrama en el idioma
     * @param p La posición en la que se quiere modificar el bigrama
     * @precond La posición @p p es correcta
     * @param bg El bigrama 
      * @todo implementar esta funcion
     * 
     * Cambia el bigrama de la posición @p del idioma por el bigrama @bg
     */
    void setPosicion(int p, const Bigrama & bg);
    
    /**
     * @brief Inserta un nuevo bigrama en el idioma
     * @param bg bigrama a insertar-
     * @return true si el numero de bigramas en el idioma aumenta, false en caso contrario
     *       * @todo implementar esta funcion

     * Busca el Bigrama representado por  bg.getBigrama() en el idioma. Si lo encuentra
     * actualiza su frecuencia a la de bg.getFrecuencia(). En caso contrario, añade un nuevo
     * Bigrama al idioma, aumentando su tamaño (número de Bigramas distintos) en 1. 
     *  
     */
    bool insertarBigrama(const Bigrama & bg);
    
    /**
     * @brief Consulta el número de bigramas existentes. 
     * @return El tamaño de la lista de bigramas
     */
    inline int getSize() const { return _nBigramas; };

    
    /**
     * @brief Serializa y guarda un idioma en un fichero
     * @param fichero El fichero de salida
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     * @todo implementar esta funcion

     */
    bool salvarAFichero(const char *fichero) const;
    
    /**
     * @brief Recupera una serialización de un idioma desde un fichero y 
     * reconstruye el idioma. Muestra en pantalla el idioma cargado
     * @param fichero Fichero que contiene un idioma serializado
     * @return @b false si ha habido algún tipo de error, @b true en otro caso
     * @todo implementar esta funcion

     */
    bool cargarDeFichero(const char *fichero);
	 
    /**
     * @brief Busca un bigrama en la lista de bigramas
     * @param bg El bigrama que se está buscando
     * @return La posición que ocupa @p bg en la lista, -1 si no está en la lista
     * @todo implementar esta funcion

     */
    int findBigrama(const char bg[]) const; 
    void ordenar();
    int ranking(const char bg[]);
    double distancia(Idioma u, Idioma c);
    
    
private:
    std::string _idioma;    /// Identificador del idioma
    Bigrama* _conjunto;     /// Vector dinámico de bigramas
    int _nBigramas;         /// Número de bigramas en el vector dinámico

};

#endif