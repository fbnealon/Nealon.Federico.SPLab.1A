#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "bicicletas.h"
#include "parser.h"

/** \brief Parseador
 *
 * \param pFile FILE*
 * \param pArrayBicicletas LinkedList*
 * \return int
 *
 */
int parser_BicicletaTexto(FILE* pFile, LinkedList* pArrayBicicletas)
{
    int ok=-1;
    int r;
    char buffer[4][30];
    eBicicleta* unaBici;
    if(pFile!=NULL)
    {
        r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        do
        {
            r=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(r==4)
            {
                unaBici=bicicleta_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(unaBici!=NULL)
                {
                    ll_add(pArrayBicicletas, unaBici);
                }
            }
            else
            {
                break;
            }
        }while(!feof(pFile));
        fclose(pFile);
    }
    return ok;
}
