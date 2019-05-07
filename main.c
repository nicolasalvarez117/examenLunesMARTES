#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "socios.h"


#define CANTIDAD 10
#define CANTIDAD2 5
#define CANTIDAD3 5

int main()
{
    t_Socios arraySOCIOS[CANTIDAD];
    t_Libros arrayLIBROS[CANTIDAD2];
    t_Prestamos arrayPRESTAMO[CANTIDAD*CANTIDAD2];

    inicializarArraySocios(arraySOCIOS,CANTIDAD);
    inicializarEstadoPrestamo(arrayPRESTAMO,CANTIDAD*CANTIDAD2);

    hardcodearLibros(arrayLIBROS,CANTIDAD2);

    int opcion,opcion2;
    int idIncrementalSocios = 1;
    int idIncrementalPrestamo = 1;
    char auxiliar[51];

do
{
    menuPrincipal(&opcion);
    switch(opcion)
    {
        case 1:
           do
            {
                menuSocios(&opcion2);
                switch(opcion2)
                {
                case 1:
                    altaDeSocios(arraySOCIOS,CANTIDAD,&idIncrementalSocios);
                    idIncrementalSocios++;
                    break;
                case 2:
                    baja(arraySOCIOS,CANTIDAD);
                    break;
                case 3:
                    modificacionDeSocio(arraySOCIOS,CANTIDAD);
                    break;
                case 4:
                    getNumber("\nOrdenar por 1:NOMBRE o 2:APELLIDO: ","opcion incorrecta",1,2,1,2,auxiliar);
                    opcion2 = atoi(auxiliar);
                    if(opcion2 = 1)
                    {
                      ordenarNombres(arraySOCIOS,CANTIDAD);
                      mostrarListaSocios(arraySOCIOS,CANTIDAD,-1);
                    }
                    else
                    {
                        ordenarApellidos(arraySOCIOS,CANTIDAD);
                        mostrarListaSocios(arraySOCIOS,CANTIDAD,-1);
                    }
                }
            }while(opcion2 != 5);
            break; /**FINALIZA EL CASE 1 PRINCIPAL.**/
        case 2:
            mostrarListaLibros(arrayLIBROS,CANTIDAD2);
            break;
        case 3:
            menuPrestamo(&opcion2);
            if(opcion2 == 1)
            {
                altaDePrestamo(arrayPRESTAMO,arraySOCIOS,arrayLIBROS,CANTIDAD,CANTIDAD2,idIncrementalPrestamo);
                idIncrementalPrestamo++;
            }
            break;

    }

}while(opcion != 4);


    return 0;
}

