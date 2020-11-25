#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"

int menu()
{
    int opcion;
    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------------------GESTION DE BICICLETAS---------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n\n");
    printf("1. Cargar archivo\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar tiempos\n");
    printf("4. Filtrar por tipo\n");
    printf("5. Mostrar posiciones\n");
    printf("6. Guardar posiciones\n");
    printf("7. Salir\n");
    opcion=getInt("Elija una opcion: ", "Opcion invalida, intente de nuevo: ", 1, 20);

    return opcion;
}
