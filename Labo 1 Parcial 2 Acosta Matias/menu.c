#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menu()
{
    int opcion;
    system("cls");
    printf("1.Cargar archivo.\n");
    printf("2.Imprimir Lista\n");
    printf("3.Asignar Rating.\n");
    printf("4.Asignar Generos.\n");
    printf("5.Filtrar por genero.\n");
    printf("6.Ordenar Peliculas.\n");
    printf("7.Guardar Peliculas\n");
    printf("8.Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
int menuFilter()
{
    int opcion;
    system("cls");
    printf("1.Filtrar Drama.\n");
    printf("2.Filtrar Comedia\n");
    printf("3.Filtrar Accion.\n");
    printf("4.Filtrar Terror.\n");
    printf("5.Salir.\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);
    return opcion;
}
