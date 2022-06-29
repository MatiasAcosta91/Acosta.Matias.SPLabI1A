#include "LinkedList.h"
#ifndef EMOVIE_H_INCLUDED
#define EMOVIE_H_INCLUDED
typedef struct
{
    int id;
    char name[50];
    char genre[50];
    float rating;
}ePelicula;




#endif // EMOVIE_H_INCLUDED

/** \brief permite crear en memoria dinamica una estructuca del tipo ePelicula
 *
 * \return ePelicula* retorna la referencia a la nueva pelicula, NULL en caso de no haber memoria disponible para crearla
 *
 */ePelicula* movie_new();
/** \brief permite crear en memoria dinamica una estructuca del tipo ePelicula y a la misma se le asignara valores.
 *
 * \param id int id de la pelicula
 * \param name char* nombre de la pelicula
 * \param genre char* genero de la pelicula
 * \param rating float rating de la pelicula
 * \return ePelicula* retorna la referencia a la nueva pelicula, NULL en caso de no haber memoria disponible para crearla
 *
 */
ePelicula* movie_newParam(int id, char* name, char* genre,float rating);
//destrctor

/** \brief permite liberar el espacio de la referencia del tipo *ePelicula pasada por parametro
 *
 * \param movie ePelicula* referencia a la estructura ePelicula
 * \return voidw
 *
 */void movie_Destroy(ePelicula* movie);
//setter

/** \brief asigna un valor en el campo id a la estructura ePelicula pasada como referencia
 *
 * \param movie ePelicula* referencia a la estructura pelicula
 * \param id int id que se le asignara a la pelicula
 * \return 1 en casi de asignacion correcta, 0 en caso de error
 *
 */int movie_setId (ePelicula* movie, int id);

 /** \brief asigna un valor en el campo name a la estructura ePelicula pasada como referencia
 *
 * \param movie ePelicula* referencia a la estructura pelicula
 * \param name char*  nombre que se le asignara a la pelicula
 * \return 1 en casi de asignacion correcta, 0 en caso de error
 *
 */int movie_setName (ePelicula* movie, char* name);

 /** \brief asigna un valor en el campo genre a la estructura ePelicula pasada como referencia
 *
 * \param movie ePelicula* referencia a la estructura pelicula
 * \param char* genre genero que se le asignara a la pelicula
 * \return 1 en casi de asignacion correcta, 0 en caso de error
 *
 */int movie_setGenre (ePelicula* movie, char* genre);

 /** \brief asigna un valor al campo rating de la estructura ePelicula pasada como referencia
 *
 * \param movie ePelicula* referencia a la estructura pelicula
 * \param rating float, rating que se le asignara a la pelicula
 * \return 1 en casi de asignacion correcta, 0 en caso de error
 *
 */int movie_setRating (ePelicula* movie, float rating);
//getters

/** \brief permite obtener el campo id contenido en la estructura ePelicula
 *
 * \param ePelicula* movie referencia a la estructura pelicula.
 * \param int* id referencia donde se le asignara el valor contenido en el capo id de la pelicula
 * \return 0 en casi de error, 1 si se realizo la asignacion correctamente
 *
 */int movie_getId (ePelicula* movie, int* id);

/** \brief permite obtener el campo name contenido en la estructura ePelicula
 *
 * \param ePelicula* movie referencia a la estructura pelicula.
 * \param char* name referencia donde se le asignara el valor contenido en el capo name de la pelicula
 * \return 0 en casi de error, 1 si se realizo la asignacion correctamente
 *
 */int movie_getName (ePelicula* movie, char* name);

/** \brief permite obtener el campo genre contenido en la estructura ePelicula
 *
 * \param ePelicula* movie referencia a la estructura pelicula.
 * \param char* genre referencia donde se le asignara el valor contenido en el capo genre de la pelicula
 * \return 0 en casi de error, 1 si se realizo la asignacion correctamente
 *
 */int movie_getGenre (ePelicula* movie, char* genre);

/** \brief permite obtener el campo rating contenido en la estructura ePelicula
 *
 * \param ePelicula* movie referencia a la estructura pelicula.
 * \param float* referencia donde se le asignara el valor contenido en el capo float de la pelicula
 * \return 0 en casi de error, 1 si se realizo la asignacion correctamente
 *
 */int movie_getRating (ePelicula* movie, float* rating);
//show

/** \brief Realiza la muestra de una de los campos contenidos en una estructura ePelicula pasada por referencia.
 *
 * \param movie ePelicula* referencia de la estructura pelicula
 * \return int 0 en caso de error, 1 en caso de realizar la muestra Ok;
 *
 */int movie_showMovie(ePelicula* movie);
/** \brief realiza la mustra de todas las peliculas almacenadas en el linkedList
 *
 * \param movies LinkedList* lista de peliculas
 * \return int -1 en caso de error. 0 si parametros Ok pero no se pudo realizar ninguna muestra. numero entero equivalente a la cantidad de muestras realizadas
 *
 */int movie_showMovies(LinkedList* movies);
// map
/** \brief copia un elemento pasado por parametro, le realiza la asignacion del campo rating, devuelve el nuevo elemento
 *
 * \param  element* void, puntero al elemento que sera copiado
 * \return void* retorna un nuevo elemento con rating asignado
 *
 */void* movie_mapRating (void* element);

/** \brief copia un elemento pasado por parametro, le realiza la asignacion del campo rgenre, devuelve el nuevo elemento
 *
 * \param element* void, puntero al elemento que sera copiado
 * \return void* retorna un nuevo elemento con genre asignado
 *
 */     void* movie_mapGenre (void* element);
//filters

/** \brief analiza el elemento pasado por parametro para verificar si corresponde al genero drama
 *
 * \param element void* elemento a ser analizado
 * \return int 1 en cassssssssssss
 *
 */int movie_filterDrama(void* element);

/** \brief analiza el elemento pasado por parametro para verificar si corresponde al genero Comedia
 *
 * \param element void* elemento a ser analizado
 * \return int 1 en cassssssssssss
 *
 */int movie_filterComedia(void* element);

/** \brief analiza el elemento pasado por parametro para verificar si corresponde al genero Accion
 *
 * \param element void* elemento a ser analizado
 * \return int 1 en cassssssssssss
 *
 */int movie_filterAccion(void* element);

/** \brief analiza el elemento pasado por parametro para verificar si corresponde al genero Terror
 *
 * \param element void* elemento a ser analizado
 * \return int 1 en cassssssssssss
 *
 */int movie_filterTerror(void* element);

//sort

/** \brief permite realizar una comparacion de genero y rating de los elementos pasados por parametros.
 *
 * \param a void* primer elemento a ser comparado
 * \param b void* segundo elemento a ser comparado
 * \return int 1 en caso de que el genero de 'a' este antes en el abecedario que 'b', en caso de ser del mismo genero compara los rating, si el rating de a<b tambien retorna 1, 0 en caso de error
 o que ambos generos y rating sean iguales
 *
 */
int movie_sortGenreAndRating(void* a, void* b);
