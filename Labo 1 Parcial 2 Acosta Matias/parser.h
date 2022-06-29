#include "LinkedList.h"
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED

/** \brief permite realizar la carga del contenido en un archivo de texto y asignarla a un nuevo campo en el linkedlist
 *
 * \param pFile FILE* puntero a la estructura file
 * \param movieList LinkedList*w lista de peliculas donde se guardara la informacion del archivo
 * \return int 0 en caso de error, 1 si se pudo realizar la carga ok
 *
 */int parser_loadFile(FILE* pFile, LinkedList* movieList);

/** \brief permite realizar el guardado del contenido del linkedlist en un archivo de texto.
 *
 * \param pFile FILE* puntero a la estructura file
 * \param movieList LinkedList* lista de peliculas que sera guardada en un archivo
 * \return  int 0 en caso de error, 1 si se pudo realizar la carga ok
 *
 */int parser_saveFile(FILE* pFile, LinkedList* movieList);
