#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "eMovie.h"
#include "controller.h"
#include "time.h"
#define TAM 4
//
/*
Materia: Laboratorio 1
Parcial: 2
Profesor: Christian Baus
Alumno: Acosta Matias
DNI: 36401197
Divison: 1A
Turno: Mañana
*/

int main()
{
    //flags
    int flagLoad = 0;
    int flagRating = 0;
    int flagGenre = 0;
    int flagSort = 0;
    //rand
    srand(time(NULL));
    //linkedList y punteros a linkedList
    LinkedList* movieList = ll_newLinkedList();
    if (movieList == NULL)
    {
        printf("No se consiguio memoria.\n");
        exit(1);
    }
    LinkedList* movieListRating = NULL;
    LinkedList* movieListRatingGenre = NULL;
    LinkedList*  arrayListGenres[TAM];
    //init array punteros
    ll_initArrayLinkedList(arrayListGenres,TAM);

    int seguir = 1;
    do
    {
        switch(menu())
        {
        case 1:
            if (!flagLoad)
            {
                controller_loadFile("movies.csv",movieList);
                flagLoad = 1;
            }
            else
            {
                printf("Ya se realiazo la carga.\n");
            }
            break;
        case 2:
            if (flagLoad)
            {
                controller_printList(movieList);
            }
            else
            {
                printf("Primero se debe realizar la carga (opcion 1)\n");
            }
            break;
        case 3:
            if (flagLoad && !flagRating)
            {
                controller_setRating(movieList,&movieListRating);
                flagRating = 1;
            }
            else
            {
                printf("Primero se debe realizar la carga (opcion 1) o bien el rating ya fue asignado.\n");
            }

            break;
        case 4:
            if (flagRating && !flagGenre)
            {
                controller_setGenre(movieListRating,&movieListRatingGenre);
                flagGenre = 1;
            }
            else
            {
                printf("primer se debe asignar el rating (opcion 3) o bien el genero ya fue asignado.\n");
            }

            break;
        case 5:
            if (flagGenre)
            {
                controller_filterGenre(movieListRatingGenre, arrayListGenres);
            }
            else
            {
                printf("primero se debe asignar el genero (opcion 4).\n");
            }
            break;
        case 6:
            if (flagGenre)
            {
                controller_sortMovies(movieListRatingGenre);
                flagSort = 1;
            }
            else
            {
                printf("primero se debe asignar el genero (opcion 4).\n");
            }
            break;
        case 7:
            if (flagSort)
            {
                controller_saveFile("sortMovies.csv",movieListRatingGenre);
            }
            else
            {
                printf("primero debe realizarse el ordenamiento (opcion 6)\n");
            }

            break;
        case 8:
            seguir = 0;
            ll_deleteLinkedList(movieList);
            ll_deleteLinkedList(movieListRating);
            ll_deleteLinkedList(movieListRatingGenre);
            ll_deleteArrayLinkedList(arrayListGenres,TAM);
            break;
        default:
            printf("Opcion invalida.\n");
            break;
        }
        system("pause");
    }
    while(seguir == 1);

    return 0;
}
