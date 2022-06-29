#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "LinkedList.h"
#include "eMovie.h"

int parser_loadFile(FILE* pFile, LinkedList* movieList)
{
    int retorno = 0;
    char encabezado [50];
    char matriz[4][50];
    int lecturas;
    ePelicula* newMovie;
    if (pFile != NULL && movieList != NULL)
    {
        fscanf(pFile,"%[^\n]\n",encabezado);
        while (!feof(pFile))
        {
            //                                                      id     name     genre      rating
            lecturas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",matriz[0],matriz[1],matriz[2],matriz[3]);
            if (lecturas == 4)
            {
                newMovie = movie_new();
                if (newMovie != NULL)
                {
                    if(movie_setId(newMovie,atoi(matriz[0])) && movie_setName(newMovie,matriz[1]) && movie_setGenre(newMovie,matriz[2]) && movie_setRating(newMovie,atof(matriz[3]) ))
                    {
                        ll_add(movieList,newMovie);
                        retorno ++;
                    }
                }
            }
        }
    }
    return retorno;
}
int parser_saveFile(FILE* pFile, LinkedList* movieList)
{
    int retorno = 0;
    char encabezado [50]="id_peli,titulo,genero,rating\n";
    int len;
    ePelicula* auxMovie = NULL;
    int id;
    char genre[50];
    char name[50];
    float rating;
    if (pFile != NULL && movieList != NULL)
    {
        fprintf(pFile,encabezado);
        len = ll_len(movieList);
        for (int i = 0; i < len; i++)
        {
            auxMovie = (ePelicula*)ll_get(movieList,i);
            if( (movie_getId(auxMovie,&id) && movie_getName(auxMovie,name) && movie_getGenre(auxMovie,genre) &&movie_getRating(auxMovie,&rating)) )
            {
                fprintf(pFile,"%d,%s,%s,%1.1f\n",id,name,genre,rating);
                retorno ++;
            }
            else
            {
                printf("Hubo algun error en la carga de informacion");
                break;
            }
        }
    }
    return retorno;
}
