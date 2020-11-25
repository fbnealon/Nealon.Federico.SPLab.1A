#include "bicicletas.h"

/** \brief Carga un archivo con una lista de bicicletas
 *
 * \param path char*
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int cargarArchivoBicicletas(char* path, LinkedList* pArrayBicicletas)
{
    int ok=0;
    FILE* pFile;
    if(path!=NULL && pArrayBicicletas!=NULL)
    {
        pFile=fopen(path, "r");
        if(pFile!=NULL)
        {
            if(!parser_BicicletaTexto(pFile, pArrayBicicletas))
            {
                ok=1;
            }
            fclose(pFile);
        }
    }
    return ok;
}

/** \brief Crea una bicicleta nueva con los campos vacios
 *
 * \return eBicicleta*
 *
 */
eBicicleta* bicicleta_new()
{
    eBicicleta* newBicicleta=(eBicicleta*) malloc(sizeof(eBicicleta));
    if(newBicicleta!=NULL)
    {
        newBicicleta->id_bike=0;
        strcpy(newBicicleta->nombre, "N/A");
        strcpy(newBicicleta->tipo, "N/A");
        newBicicleta->tiempo=0;
    }
    return newBicicleta;
}

/** \brief Crea una bicicleta con parametros
 *
 * \param idPilotoStr char*
 * \param nombreStr char*
 * \param tipoStr char*
 * \param tiempoStr char*
 * \return eBicicleta*
 *
 */
eBicicleta* bicicleta_newParametros(char* idPilotoStr, char* nombreStr, char* tipoStr, char* tiempoStr)
{
    eBicicleta* newBici=bicicleta_new();

    int auxIdBici = atoi(idPilotoStr);
    int auxTiempoBici= atoi(tiempoStr);

    if(newBici!=NULL)
    {
        if(!(bicicleta_setId(newBici, auxIdBici) && bicicleta_setNombre(newBici, nombreStr) && bicicleta_setTipo(newBici, tipoStr) && bicicleta_setTiempo(newBici, auxTiempoBici)))
        {
            free(newBici);
            newBici=NULL;
        }
    }
    return newBici;
}

/** \brief Eliomina de memoria una bicicleta
 *
 * \param unaBici eBicicleta*
 * \return void
 *
 */
void bicicleta_delete(eBicicleta* unaBici)
{
    free(unaBici);
}

/** \brief Imprime una bicicleta
 *
 * \param unaBici eBicicleta*
 * \return void
 *
 */
void bicicleta_printOne(eBicicleta* unaBici)
{
    if(unaBici!=NULL)
    {
        printf("%4d\t%20s\t%20s\t%4d\n", unaBici->id_bike, unaBici->nombre, unaBici->tipo, unaBici->tiempo);
    }
}

/** \brief Imprime todas las bicicletas de una lista
 *
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int bicicleta_printAll(LinkedList* pArrayBicicletas)
{
    int ok=0, f=0;
    eBicicleta* auxBici;
    int tam=ll_len(pArrayBicicletas);

    if(pArrayBicicletas!=NULL)
    {
        ok=1;
        printf("  ID                  NOMBRE                    TIPO  TIEMPO\n");
        printf("------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            auxBici=(eBicicleta*)ll_get(pArrayBicicletas, i);
            if(auxBici!=NULL)
            {
                f=1;
                bicicleta_printOne(auxBici);
            }
        }
        if(!f)
        {
            ok=0;
        }
        printf("\n");
    }
    return ok;
}

/** \brief Setea el id de unaBici
 *
 * \param unaBici eBicicleta*
 * \param idBici int
 * \return int
 *
 */
int bicicleta_setId(eBicicleta* unaBici, int idBici)
{
    int ok=0;
    if(unaBici!=NULL && idBici>0)
    {
        unaBici->id_bike=idBici;
        ok=1;
    }
    return ok;
}

/** \brief Asigna a idBici el id de unaBici
 *
 * \param unaBici eBicicleta*
 * \param idBici int*
 * \return int
 *
 */
int bicicleta_getId(eBicicleta* unaBici, int* idBici)
{
    int ok=0;
    if(unaBici!=NULL && idBici!=NULL)
    {
        *idBici=unaBici->id_bike;
        ok=1;
    }
    return ok;
}

/** \brief Setea el nombre de unaBici
 *
 * \param unaBici eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int bicicleta_setNombre(eBicicleta* unaBici, char* nombre)
{
    int ok=0;
    if(unaBici!=NULL && nombre!=NULL && strlen(nombre)<20)
    {
        strcpy(unaBici->nombre, nombre);
        ok=1;
    }
    return ok;
}

/** \brief Asigna a nombre el nombre de unaBici
 *
 * \param unaBici eBicicleta*
 * \param nombre char*
 * \return int
 *
 */
int bicicleta_getNombre(eBicicleta* unaBici, char* nombre)
{
    int ok=0;
    if(unaBici!=NULL && nombre!=NULL)
    {
        strcpy(nombre, unaBici->nombre);
        ok=1;
    }
    return ok;
}

/** \brief Setea el tipo de unaBici
 *
 * \param unaBici eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int bicicleta_setTipo(eBicicleta* unaBici, char* tipo)
{
    int ok=0;
    if(unaBici!=NULL && tipo!=NULL && strlen(tipo)<20)
    {
        strcpy(unaBici->tipo, tipo);
        ok=1;
    }
    return ok;
}

/** \brief Asigna a tipo el tipo de unaBici
 *
 * \param unaBici eBicicleta*
 * \param tipo char*
 * \return int
 *
 */
int bicicleta_getTipo(eBicicleta* unaBici, char* tipo)
{
    int ok=0;
    if(unaBici!=NULL && tipo!=NULL)
    {
        strcpy(tipo, unaBici->tipo);
        ok=1;
    }
    return ok;
}

/** \brief Setea el tiempo de unaBici
 *
 * \param unaBici eBicicleta*
 * \param tiempo int
 * \return int
 *
 */
int bicicleta_setTiempo(eBicicleta* unaBici, int tiempo)
{
    int ok=0;
    if(unaBici!=NULL && tiempo>=0)
    {
        unaBici->tiempo=tiempo;
        ok=1;
    }
    return ok;
}

/** \brief Asigna a tiempo el tiempo de unaBici
 *
 * \param unaBici eBicicleta*
 * \param tiempo int*
 * \return int
 *
 */
int bicicleta_getTiempo(eBicicleta* unaBici, int* tiempo)
{
    int ok=0;
    if(unaBici!=NULL && tiempo!=NULL)
    {
        *tiempo=unaBici->id_bike;
        ok=1;
    }
    return ok;
}

/** \brief Retorna ok si el tipo de unaBici es igual al tipo pasado por parametro
 *
 * \param pElement void*
 * \param tipo char*
 * \return int
 *
 */
int bicicleta_filtrarXTipo(void* pElement, char* tipo)
{
    int ok=0;
    eBicicleta* auxBici= (eBicicleta*)pElement;
    if(pElement!=NULL)
    {
        if(stricmp(auxBici->tipo, tipo)==0)
        {
            ok=1;
        }
    }
    return ok;
}

/** \brief Compara dos elementos y los ordena por tipo y tiempo
 *
 * \param pElementA void*
 * \param pElementB void*
 * \return int
 *
 */
int bicicleta_ordenarXTipoYTiempo(void* pElementA, void* pElementB)
{
    int retorno=0;
    eBicicleta* biciA = (eBicicleta*) pElementA;
    eBicicleta* biciB = (eBicicleta*) pElementB;
    if(biciA!=NULL && biciB!=NULL)
    {
        retorno=strcmp(biciA->tipo, biciB->tipo);
        if(!retorno)
        {
            retorno=biciA->tiempo-biciB->tiempo;
        }
    }
    return retorno;
}

int bicicleta_mapeo(void* pElement)
{
    int ok=0;
    eBicicleta* unaBici=NULL;
    int aleatorio;

    if(pElement != NULL)
    {
        unaBici=(eBicicleta*) pElement;

        if(unaBici != NULL)
        {
            aleatorio = rand()%(71)+50;
            bicicleta_setTiempo(unaBici,aleatorio);
            ok=1;
        }
    }

    return ok;
}
