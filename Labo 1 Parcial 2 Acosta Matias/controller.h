
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
/** \brief Controlador que permite realizar la carga de la informacion contenida en un archivo .csv
 *
 * \param path char* nombre del archivo o ruta
 * \param movieList LinkedList* lista donde sera cargada la informacion del archivo
 * \return int 0 en caso de error en los parametros o no realizar ninguna carga. 1 en caso de realizar la carga OK.
 *
 */     int controller_loadFile(char* path,LinkedList* movieList);
/** \brief controlador que permite realizar el guardado del contenido de la lista en un archivo.csv
 *
 * \param path char* nombre o ruta del archivo donde se realizara el guardado
 * \param movieList LinkedList* lista que contiene la informacion a guardar
 * \return int int 0 en caso de error en los parametros o no realizar ninguna carga. 1 en caso de realizar el guardado OK.
 *
 */int controller_saveFile(char* path,LinkedList* movieList);

/** \brief muestra el listado de peliculas cargada en el linkedList
 *
 * \param movieList LinkedList* lista con las peliculas
 * \return int 1 en caso de poder realizar la muestra ok, 0 en caso de error en los parametros o no haber podido realizar ninguna muestra
 *
 */int controller_printList(LinkedList* movieList);

/** \brief a partir de una lista ingresada devolvera una nueva lista con algun campo modificado y ademas realiza la muestra de la lista modificada
 *
 * \param movieList LinkedList* lista original
 * \param movieListRating LinkedList** es donde se escrbira la nueva lista generada
 * \return int 0 en caso de error en los parametros, 1 si se pudo crear la lista Ok.
 *
 */int controller_setRating(LinkedList* movieList,LinkedList** movieListRating);

/** \brief a partir de una lista ingresada devolvera una nueva lista con algun campo modificado y ademas realiza la muestra de la lista modificada
 *
 * \param movieList LinkedList* lista original
 * \param movieListRating LinkedList** es donde se escrbira la nueva lista generada
 * \return int 0 en caso de error en los parametros, 1 si se pudo crear la lista Ok.
 *
 */int controller_setGenre(LinkedList* movieList,LinkedList** movieListGenre);

/** \brief mediante un menu de seleccion permite realizar el filtrado de peliculas segun genero. por cada filtrado se generara una nueva lista segun el genero, ademas dicha lista sera mostrada
 *
 * \param movieList LinkedList* lista original de peliculas
 * \param arrayListGenre LinkedList** array de punteros a linkedlist, sobre cada elemento del array se generara un nuevo linkedlist segun el filtrado.
 * \return int 0 en caso de error en los parametros, 1 si se pudo crear la lista Ok.
 *
 */int controller_filterGenre(LinkedList* movieList,LinkedList** arrayListGenre);

/** \brief permite realizar el ordenamiento de peliculas y ademas realiza la muestra del ordenamiento
 *
 * \param movieList LinkedList* lista de peliculas a ordenar
 * \return int 0 en caso de parametro invalido, 1 en caso de realizar la muestra
 *
 */int controller_sortMovies(LinkedList* movieList);

