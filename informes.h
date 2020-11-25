#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "input.h"
#include "bicicletas.h"
#include "LinkedList.h"
#include "parser.h"

int informe_imprimirBicicletas(LinkedList* pArrayBicicletas);
int informe_asignarTiempos(LinkedList* pArrayBicicletas, int aleatorio);
int informe_filtrarBicicletasXTipo(LinkedList* pArrayBicicletas);
int informe_guardarBicicletasTexto(char* path, LinkedList* pArrayBicicletas);
int informe_MostrarPosiciones(LinkedList* pArrayBicicletas);
int informe_guardarPosiciones(LinkedList* bicicletasOrdenadas, char* path);


#endif // INFORMES_H_INCLUDED
