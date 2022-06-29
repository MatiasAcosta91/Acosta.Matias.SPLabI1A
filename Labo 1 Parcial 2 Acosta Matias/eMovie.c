#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eMovie.h"
#include "LinkedList.h"
#include <ctype.h>
//constructor
ePelicula* movie_new()
{
    return (ePelicula*) calloc (1,sizeof(ePelicula));
}
ePelicula* movie_newParam(int id, char* name, char* genre, float rating)
{

    ePelicula* retorno;
    if (id >0 && name != NULL && strlen(name)<= 50 && genre != NULL && strlen(genre)<= 50 && rating >= 0 && rating <10)
    {
        retorno = movie_new();
        if (retorno != NULL)
        {
            if ( !(movie_setId(retorno,id) &&(movie_setName(retorno,name))&&(movie_setGenre(retorno,genre))&&(movie_setRating(retorno,rating)) ))
            {
                movie_Destroy(retorno);
            }
        }
    }
    return retorno;
}
//destructor
void movie_Destroy(ePelicula* movie)
{
    free(movie);
}
//Setter
int movie_setId (ePelicula* movie, int id)
{
    int retorno = 0;
    if (movie != NULL && id > 0 )
    {
        movie->id = id;
        retorno = 1;
    }
    return retorno;
}
int movie_setName (ePelicula* movie, char* name)
{
    int retorno = 0;
    if (movie != NULL && name != NULL && strlen(name)<50 && esStringConEspacio(name) )
    {
        strcpy(movie->name,name);
        retorno = 1;
    }
    return retorno;
}
int movie_setGenre (ePelicula* movie, char* genre)
{
    int retorno = 0;
    if (movie != NULL && genre != NULL && strlen(genre) < 50 && esStringConEspacio(genre) )
    {
        strcpy(movie->genre,genre);
        retorno = 1;
    }
    return retorno;
}
int movie_setRating (ePelicula* movie, float rating)
{
    int retorno = 0;
    if (movie != NULL && rating >= 0 && rating <= 10)
    {
        movie->rating = rating;
        retorno = 1;
    }
    return retorno;
}
//show
int movie_showMovie(ePelicula* movie)
{
    int retorno = 0;
    if (movie != NULL)
    {
        printf("%4d %30s %20s %10.1f\n",movie->id,movie->name,movie->genre,movie->rating);
        retorno = 1;
    }
    return retorno;
}
int movie_showMovies(LinkedList* movies)
{
    int retorno = -1;
    int len;
    ePelicula* auxMovie = NULL;
    if(movies != NULL)
    {
        retorno = 0;
        len = ll_len(movies);
        printf("  ID                    NOMBRE                  GENERO       RATING\n");
        printf("--------------------------------------------------------------------\n");
        for (int i = 0; i < len; i++)
        {
            auxMovie = (ePelicula*)ll_get(movies,i);
            if(movie_showMovie(auxMovie))
            {
                retorno++;
            }
        }
        auxMovie = NULL;
    }
    return retorno;
}
//getters
int movie_getId (ePelicula* movie, int* id)
{
    int retorno = 0;
    if (movie != NULL && id != NULL)
    {
        *id = movie->id;
        retorno = 1;
    }
    return retorno;
}
int movie_getName (ePelicula* movie, char* name)
{
    int retorno = 0;
    if (movie != NULL && name != NULL)
    {
        strcpy(name,movie->name);
        retorno = 1;
    }
    return retorno;
}
int movie_getGenre (ePelicula* movie, char* genre)
{
    int retorno = 0;
    if (movie != NULL && genre != NULL)
    {
        strcpy(genre,movie->genre);
        retorno = 1;
    }
    return retorno;
}
int movie_getRating (ePelicula* movie, float* rating)
{
    int retorno = 0;
    if (movie != NULL && rating != NULL)
    {
        *rating = movie->rating;
        retorno = 1;
    }
    return retorno;
}
//map
void* movie_mapRating (void* element)
{
    void* retorno = element;
    ePelicula* auxElement = NULL;
    ePelicula* auxNewMovie = NULL;
    float ratingRandom;
    auxNewMovie = movie_new();
    if (auxNewMovie != NULL)
    {
        auxElement = (ePelicula*)element;
        *auxNewMovie = *auxElement;
        do
        {
            ratingRandom =(float) (10+rand()% 100) / 10;
        }
        while (ratingRandom> 10.0);
        movie_setRating(auxNewMovie,ratingRandom);
        retorno = auxNewMovie;
    }

    return retorno;
}
void* movie_mapGenre (void* element)
{
    void* retorno = element;
    ePelicula* auxElement = NULL;
    ePelicula* auxNewMovie = NULL;
    int genreRandom;
    auxNewMovie = movie_new();
    char drama[]="Drama";
    char comedia[]="Comedia";
    char accion[]="Accion";
    char terror[]="Terror";
    if (auxNewMovie != NULL)
    {
        auxElement = (ePelicula*)element;
        *auxNewMovie = *auxElement;
        genreRandom = 1+rand() % 4;
        switch(genreRandom)
        {
        case 1://drama
            movie_setGenre(auxNewMovie,drama);
            break;
        case 2://comedia
             movie_setGenre(auxNewMovie,comedia);
            break;
        case 3://accion
             movie_setGenre(auxNewMovie,accion);
            break;
        case 4://terror
             movie_setGenre(auxNewMovie,terror);
            break;
        }
        retorno = auxNewMovie;
    }

    return retorno;
}
//filter
int movie_filterDrama(void* element)
{
    int retorno = 0;
    ePelicula* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (ePelicula*) element;
        if(stricmp(auxMovie->genre,"Drama")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterComedia(void* element)
{
    int retorno = 0;
    ePelicula* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (ePelicula*) element;
        if(stricmp(auxMovie->genre,"Comedia")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterAccion(void* element)
{
    int retorno = 0;
    ePelicula* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (ePelicula*) element;
        if(stricmp(auxMovie->genre,"Accion")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
int movie_filterTerror(void* element)
{
    int retorno = 0;
    ePelicula* auxMovie = NULL;
    if (element != NULL)
    {
        auxMovie = (ePelicula*) element;
        if(stricmp(auxMovie->genre,"Terror")==0)
        {
            retorno = 1;
        }
    }
    return retorno;
}
//sort
int movie_sortGenreAndRating(void* a, void* b)
{
    int retorno = 0;
    ePelicula* movieA;
    ePelicula* movieB;
    if (a != NULL && b != NULL)
    {
      movieA = (ePelicula*)a;
      movieB = (ePelicula*)b;
      if( (stricmp(movieA->genre,movieB->genre)>0) || (stricmp(movieA->genre,movieB->genre) == 0 && movieA->rating<movieB->rating)  )
      {
          retorno = 1;
      }
    }
    return retorno;
}

