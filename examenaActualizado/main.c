#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "socios.h"


#define CANTIDAD_SOCIOS  10
#define CANTIDAD_LIBROS 5
#define CANTIDAD_AUTORES 5

int main()
{
    t_Socios arraySocios[CANTIDAD_SOCIOS];//DECLARO LOS ARRAYS DE ESTRUCTURAS
    t_Libros arrayLibros[CANTIDAD_LIBROS];
    t_Prestamos arrayPrestamo[CANTIDAD_SOCIOS*CANTIDAD_LIBROS];

    inicializarArraySocios(arraySocios,CANTIDAD_SOCIOS);//INICIALIZO LOS ESPACIOS LIBRES
    inicializarEstadoPrestamo(arrayPrestamo,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);

    hardcodearLibros(arrayLibros,CANTIDAD_LIBROS);//HARDCODEO LIBROS Y AUTORES

    int opcion,opcion2;
    int idIncrementalSocios = 1;  //ID INCREMENTAL DE LOS SOCIOS
    int idIncrementalPrestamo = 1;  //ID INCREMENTAL DE LAS SOLICITUDES A PRESTAMO
    char auxiliar[51];

    /**PARA HARDCODEAR SOCIOS PARA EL TEST DEL PROGRAMA, DESCOMENTAR LA SIGUIENTE LINEA**/
    //hardcodearSocios(arraySocios,&idIncrementalSocios); idIncrementalSocios = 6;
    /**PARA HARDCODEAR PRESTAMOS DE LIBROS A LOS SOCIOS PARA EL TEST DEL PROGRAMA, DESCOMENTAR LA SIGUIENTE LINEA**/
    //hardcodearPrestamosAsocios(arrayPrestamo,&idIncrementalPrestamo); idIncrementalPrestamo = 6;
do
{
    menuPrincipal(&opcion); //MENU PRINCIPAL
    switch(opcion)
    {
        case 1:
           do
            {
                menuSocios(&opcion2); //MENU DE ABM SOCIOS
                switch(opcion2)
                {
                case 1:
                    altaDeSocios(arraySocios,CANTIDAD_SOCIOS,idIncrementalSocios);
                    ++idIncrementalSocios;
                    break;
                case 2:
                    baja(arraySocios,CANTIDAD_SOCIOS);
                    break;
                case 3:
                    modificacionDeSocio(arraySocios,CANTIDAD_SOCIOS);
                    break;
                case 4:
                    menuListaOrdenada(arraySocios,CANTIDAD_SOCIOS);
                    break;
                }
            }while(opcion2 != 5);
            break; /**FINALIZA EL CASE 1 PRINCIPAL.**/
        case 2:
            mostrarListaLibros(arrayLibros,CANTIDAD_LIBROS);
            break;
        case 3:
            menuPrestamo(&opcion2); //MENU DE ALTA DE SOLICITUDES A PRESTAMO
            switch(opcion2)
            {
            case 1:
                altaDePrestamo(arrayPrestamo,arraySocios,arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS,idIncrementalPrestamo);
                idIncrementalPrestamo++;
                break;
            }
            break;/**FINALIZA EL CASE 3 DEL SWICHT PRINCIPAL.**/
        case 4:
            menuInformes(&opcion2); //MENU DE INFORMES PEDIDOS EN EL EXAMEN
            switch(opcion2)
            {
            case 1:
                listarTotalGeneralYpromedio(arrayPrestamo,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                break;
            case 2:
                printf("\nNo sabia colocar un contador cuando encuentra una fecha");
                break;
            case 3:
                listarPrestamosActivos(arraySocios,arrayPrestamo,
                                       arrayLibros,CANTIDAD_SOCIOS,CANTIDAD_LIBROS);
                break;
            case 4:
                listarLibroMenosSolicidato(arrayLibros,arrayPrestamo,CANTIDAD_LIBROS
                                           ,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                break;
            case 5:
                listarSocioMayorPrestamos(arraySocios,arrayPrestamo,
                                          CANTIDAD_SOCIOS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                break;
            case 6:
                listarLibrosPrestamoMasFecha(arrayPrestamo,arrayLibros,
                                             CANTIDAD_LIBROS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                break;
            case 7:
                listarSocioPrestamoMasFecha(arrayPrestamo,arraySocios,
                                                CANTIDAD_SOCIOS,CANTIDAD_SOCIOS*CANTIDAD_LIBROS);
                break;
            case 8:
                ordenarLibros(arrayLibros,CANTIDAD_LIBROS);
                mostrarListaLibros(arrayLibros,CANTIDAD_LIBROS);
                break;
            case 9:
                ordenarApellidosDescendente(arraySocios,CANTIDAD_SOCIOS);
                mostrarListaSocios(arraySocios,CANTIDAD_SOCIOS,-1);
                break;
            }
            break;/**FINALIZA EL CASE 4 DEL SWITCH PRINCIPAL**/

    }

}while(opcion != 5);


    return 0;
}

