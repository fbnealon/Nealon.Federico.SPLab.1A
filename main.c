#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "informes.h"
int main()
{
    srand (time(NULL));
    int opcion, primera=1, aleatorio=0, ordenado=0;
    LinkedList* bicicletas=ll_newLinkedList();
    do
    {
        opcion=menu();
        switch(opcion)
        {
        case 1:
            if(primera)
            {
                cargarArchivoBicicletas("bicicletas.csv", bicicletas);
                printf("Cargado, cantidad: %d\n", ll_len(bicicletas));
                primera=0;
            }
            else
            {
                printf("Lista de bicicletas ya cargada\n\n");
            }
            break;
        case 2:
            informe_imprimirBicicletas(bicicletas);
            break;
        case 3:
            informe_asignarTiempos(bicicletas, aleatorio);
            break;
        case 4:
            informe_filtrarBicicletasXTipo(bicicletas);
            break;
        case 5:
            informe_MostrarPosiciones(bicicletas);
            ordenado=1;
            break;
        case 6:
            if(ordenado)
            {
                informe_guardarPosiciones(bicicletas, "bicicletasOrdenadas.csv");
            }
            else
            {
                printf("Debe ordenar el listado de bicicletas primero\n\n");
            }
            break;
        case 7:
            ll_deleteLinkedList(bicicletas);
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=7);
    return 0;
}
