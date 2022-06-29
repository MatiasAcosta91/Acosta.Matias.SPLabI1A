#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "eMovie.h"
#include "parser.h"
#include"LinkedList.h"
#include "controller.h"

int controller_loadFile(char* path,LinkedList* movieList)
{
    int retorno = 0;
    int loadOk = 0;
    FILE* f = NULL;
    if(path != NULL && movieList != NULL)
    {

        f = fopen(path,"r");
        if (f!= NULL)
        {

            loadOk = parser_loadFile(f,movieList);
            if (loadOk >0)
            {
                printf("Se cargaron correctamente un total de %d peliculas.\n",loadOk);
                retorno = 1;
            }
        }
        fclose(f);
    }
    return retorno;
}
int controller_saveFile(char* path,LinkedList* movieList)
{
    int retorno = 0;
    int saveOk = 0;
    FILE* f = NULL;
    if(path != NULL && movieList != NULL)
    {
        f = fopen(path,"w");
        if (f != NULL)
        {
            saveOk = parser_saveFile(f,movieList);
            if (saveOk >0)
            {
                printf("Se guardaron correctamente %d peliculas\n",saveOk);
            }
        }
        fclose(f);
    }
    return retorno;
}
int controller_printList(LinkedList* movieList)
{
    int retorno = 0;
    int showOk = 0;
    if (movieList != NULL)
    {
        showOk = movie_showMovies(movieList);
        if(showOk > 0)
        {
            printf("\n\nSe mostraron un total de %d peliculas.\n",showOk);
            retorno = 1;
        }
    }
    return retorno;
}
int controller_setRating(LinkedList* movieList,LinkedList** movieListRating)
{
    int retorno = 0;
    if (movieList != NULL && movieListRating != NULL)
    {
        *movieListRating = ll_map(movieList,movie_mapRating);
        movie_showMovies(*movieListRating);
        retorno = 1;
    }
    return retorno;
}
int controller_setGenre(LinkedList* movieList,LinkedList** movieListGenre)
{
    int retorno = 0;
    if (movieList != NULL && movieListGenre != NULL)
    {
        *movieListGenre= ll_map(movieList,movie_mapGenre);
        movie_showMovies(*movieListGenre);
        retorno = 1;
    }
    return retorno;
}
int controller_filterGenre(LinkedList* movieList,LinkedList** arrayListGenre)
{
    int retorno = 0;
    int continuar = 1;
    if (movieList != NULL && arrayListGenre != NULL)
    {
        do
        {
            switch(menuFilter())
            {
            case 1:
                arrayListGenre[0] = ll_filter(movieList,movie_filterDrama);
                controller_saveFile("Drama.csv",arrayListGenre[0]);
                movie_showMovies(arrayListGenre[0]);
                break;
            case 2:
                arrayListGenre[1] = ll_filter(movieList,movie_filterComedia);
                controller_saveFile("Comedia.csv",arrayListGenre[1]);
                movie_showMovies(arrayListGenre[1]);
                break;
            case 3:
                arrayListGenre[2] = ll_filter(movieList,movie_filterAccion);
                controller_saveFile("Accion.csv",arrayListGenre[2]);
                movie_showMovies(arrayListGenre[2]);
                break;
            case 4:
                arrayListGenre[3] = ll_filter(movieList,movie_filterTerror);
                controller_saveFile("Terror.csv",arrayListGenre[3]);
                movie_showMovies(arrayListGenre[3]);
                break;
            case 5:
                continuar = 0;
                break;
            default:
                printf("Opcion invalida\n");
                break;
            }
            printf("\n\nSe guardo un archivo con la lista mostrada en pantalla.\n");
            system("pause");
        }
        while (continuar == 1);
    }
    return retorno;
}
int controller_sortMovies(LinkedList* movieList)
{
    int retorno = 0;
    if (movieList != NULL)
    {
        if(ll_sort(movieList,movie_sortGenreAndRating,1) == 0)
        {
            movie_showMovies(movieList);
            retorno = 1;
        }
    }
    return retorno;
}
