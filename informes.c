#include "informes.h"

/** \brief Imprime las bicicletas cargadas en la lista
 *
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int informe_imprimirBicicletas(LinkedList* pArrayBicicletas)
{
    int ok=0;
    printf("-------------------------------------------------------------------------------\n");
    printf("-------------------------------LISTA DE BICICLETAS-----------------------------\n");
    printf("-------------------------------------------------------------------------------\n");
    printf("\n\n");
    if(pArrayBicicletas!=NULL)
    {
        if(ll_len(pArrayBicicletas)>0)
        {
            bicicleta_printAll(pArrayBicicletas);
            ok=1;
        }
        else
        {
            printf("No hay bicicletas cargadas\n\n");
        }
    }
    return ok;
}

/** \brief Asigna tiempos de manera aleatoria al campo tiempo de cada bicicleta cargada en la lista
 *
 * \param pArrayBicicletas LinkedList*
 * \param aleatorio int
 * \return int
 *
 */
int informe_asignarTiempos(LinkedList* pArrayBicicletas, int aleatorio)
{
    int ok=0, size;
    //LinkedList* mappedList=NULL;
    if(pArrayBicicletas!=NULL)
    {
        size=ll_len(pArrayBicicletas);
        for(int i=0; i<size; i++)
        {
            pArrayBicicletas= ll_map(pArrayBicicletas, bicicleta_mapeo);
            informe_guardarBicicletasTexto("bicicletas.csv", pArrayBicicletas);
        }
        printf("Tiempos asignados exitosamente\n\n");
    }
    return ok;
}

/** \brief filtra las bicicletas por tipo, indica si no hay bicicletas del tipo ingresado
 *
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int informe_filtrarBicicletasXTipo(LinkedList* pArrayBicicletas)
{
    int ok=0;
    char auxTipo[20];
    if(pArrayBicicletas!=NULL)
    {
        if(informe_imprimirBicicletas(pArrayBicicletas))
        {
            getAlphaString("Ingrese tipo de bicicleta a filtrar: ", "Caracteres invalidos, intente de nuevo: ", auxTipo);
            LinkedList* bicicletasFiltradasXTipo=ll_newLinkedList();
            if(bicicletasFiltradasXTipo!=NULL)
            {
                bicicletasFiltradasXTipo=ll_filter_parametro(pArrayBicicletas, bicicleta_filtrarXTipo, auxTipo);
                if(ll_len(bicicletasFiltradasXTipo)>0)
                {
                    system("cls");
                    informe_imprimirBicicletas(bicicletasFiltradasXTipo);
                    informe_guardarBicicletasTexto("filtradas.csv", bicicletasFiltradasXTipo);
                    ok=1;
                }
                else
                {
                    printf("No hay bicicletas con el tipo indicado\n\n");
                }
                free(bicicletasFiltradasXTipo);
            }
        }
    }
    return ok;
}

/** \brief Sobreescribe un archivo donde guarda las bicicletas, o lo crea si no existe
 *
 * \param path char*
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int informe_guardarBicicletasTexto(char* path, LinkedList* pArrayBicicletas)
{
    int ok=0, size;
    FILE* pFile;
    eBicicleta* unaBici;
    if(path!=NULL && pArrayBicicletas!=NULL)
    {
        pFile=fopen(path, "w");
        if(pFile!=NULL)
        {
            fprintf(pFile, "ID_BIKE,NOMBRE,TIPO,TIEMPO\n");
        }
        size=ll_len(pArrayBicicletas);
        for(int i=0; i<size; i++)
        {
            unaBici=(eBicicleta*)ll_get(pArrayBicicletas, i);
            if(unaBici!=NULL)
            {
                fprintf(pFile, "%d,%s,%s,%d\n", unaBici->id_bike, unaBici->nombre, unaBici->tipo, unaBici->tiempo);
            }
        }
        ok=1;
        fclose(pFile);
        free(unaBici);
        printf("Archivo de bicicletas generado\n\n");
    }
    return ok;
}

/** \brief Muestra la lista de bicicletas ordenada por tipo y tiempo
 *
 * \param pArrayBicicletas LinkedList*
 * \return LinkedList*
 *
 */
int informe_MostrarPosiciones(LinkedList* pArrayBicicletas)
{
    int ok=0;
    if(pArrayBicicletas!=NULL)
    {
        ll_sort(pArrayBicicletas, bicicleta_ordenarXTipoYTiempo, 1); //1=ASCENDENTE, 0=DESCENDENTE
        informe_imprimirBicicletas(pArrayBicicletas);
        ok=1;
    }
    return ok;
}

/** \brief Guarda un archivo con las bicicletas ordenadas por tipo y tiempo
 *
 * \param bicicletasOrdenadas LinkedList*
 * \param path char*
 * \return int
 *
 */
int informe_guardarPosiciones(LinkedList* pArrayBicicletas, char* path)
{
    int ok=0;
    if(pArrayBicicletas!=NULL)
    {
        informe_guardarBicicletasTexto(path, pArrayBicicletas);
        ok=1;
    }
    return ok;
}
