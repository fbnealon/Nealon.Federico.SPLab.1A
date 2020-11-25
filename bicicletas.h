#ifndef BICICLETAS_H_INCLUDED
#define BICICLETAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "LinkedList.h"
#include "parser.h"

typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}eBicicleta;

int cargarArchivoBicicletas(char* path, LinkedList* pArrayBicicletas);
eBicicleta* bicicleta_new();
eBicicleta* bicicleta_newParametros(char* idPilotoStr, char* nombreStr, char* tipoStr, char* tiempoStr);
void bicicleta_delete(eBicicleta* unaBici);
void bicicleta_printOne(eBicicleta* unaBici);
int bicicleta_printAll(LinkedList* pArrayBicicletas);
int bicicleta_setId(eBicicleta* unaBici, int idBici);
int bicicleta_getId(eBicicleta* unaBici, int* idBici);
int bicicleta_setNombre(eBicicleta* unaBici, char* nombre);
int bicicleta_getNombre(eBicicleta* unaBici, char* nombre);
int bicicleta_setTipo(eBicicleta* unaBici, char* tipo);
int bicicleta_getTipo(eBicicleta* unaBici, char* tipo);
int bicicleta_setTiempo(eBicicleta* unaBici, int tiempo);
int bicicleta_getTiempo(eBicicleta* unaBici, int* tiempo);
int bicicleta_filtrarXTipo(void* pElement, char* tipo);
int bicicleta_ordenarXTipoYTiempo(void* pElementA, void* pElementB);



#endif // BICICLETAS_H_INCLUDED
