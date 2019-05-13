#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "imput.h"
#include "socios.h"

#define LIBRE -1
#define OCUPADO 1
//-------------------------BUSCAR ESPACIO LIBRE-----------------------------------
/**
  *\brief busca una igualdad entre dos datos pasados por parametro.
  *\param datos de la estructura , la cantidad de elementos del array estructura y el valor que queremos encontrar.
  *\return la posicion del valor encontrado, en caso de no encontrar el valor, retorna -1.
**/
int buscarEspacioLibreSocios(t_Socios str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

int buscarDatoValidoSocios(t_Socios str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].idSocio == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}
int buscarPosicionPrestamo(t_Prestamos str[],int cantidadElementos,int valor)
{
    int i;
    for(i=0;i < cantidadElementos; i++)
    {
        if(str[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

//-----------------------------INICIALIZAR ESTADOS E ID-----------------------
/**
  *\brief inicializa los valores unicos  con LIBRE(-1).
  *\param el array  y la cantidad de elementos del array.
**/
void inicializarArraySocios(t_Socios str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;

    }
}

void inicializarEstadoPrestamo(t_Prestamos str[],int cantidadElementos)
{
    int i;
    for(i=0;i<cantidadElementos;i++)
    {
        str[i].estado = LIBRE;

    }
}

/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearLibros(t_Libros str[],int cantidadElementos)
{
    int i;
    int id[5]={1,2,3,4,5};
    int idAutor[5]={1,2,3,4,5};
    char libro[5][50]={"Programacion","matematica","Ciencias Sociales","Ciencias Naturales","Algebra"};
    char autor[5][50]={"Maria","Jose","Nicolas","Eduardo","Leonardo"};

    for(i=0; i<5; i++)
    {
        str[i].idLibro = id[i];
        str[i].idAutor = idAutor[i];
        strcpy(str[i].tituloDelLibro,libro[i]);
        strcpy(str[i].autor.nombreAutor,autor[i]);
    }
}

/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearSocios(t_Socios str[],int *idIncremental)
{
    int i;
    int estado[]={1,1,1,1,1};
    int idSocio[]={1,2,3,4,5};
    char apellido[][50]={"Zabala","Reinaga","Alegre","Palacios","Veron"};
    char nombre[][50]={"Lucia","Mario","Fabian","Alexis","Damaris"};
    int dia[]={13,5,2,28,14};
    int mes[]={2,12,6,4,9};
    int anio[]={2000,2002,2010,2011,2018};
    char eMail[][50]={"Lucia@.com","mario@.com","fabian@.com","alexis@.com","damaris@.com"};
    char telefono[][50]={"42114966","1159463518","1129478563","42123729","1142252222"};
    char sexo[]={'F','M','M','M','M','F'};
    for(i=0; i<5; i++)
    {
        str[i].idSocio = idSocio[i];
        str[i].estado = estado[i];
        strcpy(str[i].nombre,nombre[i]);
        strcpy(str[i].apellido,apellido[i]);
        strcpy(str[i].eMail,eMail[i]);
        str[i].fechaDelSocio.dia = dia[i];
        str[i].fechaDelSocio.mes = mes[i];
        str[i].fechaDelSocio.anio = anio[i];
        str[i].sexo = sexo[i];
        strcpy(str[i].telefono,telefono);
        idIncremental = &idIncremental + 1;
    }
}
/**
  *\brief Simula una carga de datos para la prueba del programa.
  *\param el array donde cargar los datos.
**/
void hardcodearPrestamosAsocios(t_Prestamos str[],int *idIncremental)
{
    int i;
    int id[5]={1,2,3,4,5};
    int idLibro[]={1,2,3,4,5};
    int idSocio[]={1,2,3,4,5};
    int dia[]={7,7,7,6,6};
    int mes[]={5,5,5,5,5};
    int anio[]={2019,2019,2019,2019,2019};

    for(i=0; i<5; i++)
    {
        str[i].idLibro = idLibro[i];
        str[i].idSocio = idSocio[i];
        str[i].fechaPrestamo.dia = dia[i];
        str[i].fechaPrestamo.mes = mes[i];
        str[i].fechaPrestamo.anio = anio[i];
        str[i].idPrestamo = id[i];
        str[i].estado = 1;
        *++idIncremental;
    }
}

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menuSocios(int *resultado)
{
    char aux[15];
    getNumber("\n1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTAR\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);
}
void menuPrestamo(int *resultado)
{
    char aux[15];
    getNumber("\n1:ALTA PRESTAMO\n2:LISTAR PRESTAMOS ACTIVOS\n3:SALIR: ","opcion incorrecta: ",1,3,1,2,aux);
    *resultado = atoi(aux);
}


void menuModificacion(int *resultado)
{
    char aux[15];
    getNumber("\nMODIFICAR:\n 1:NOMBRE Y APELLIDO\n2:SEXO\n3:TELEFONO\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);
}

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menuPrincipal(int *resultado)
{
    char aux[15];
    getNumber("\n1:SOCIOS\n2:LISTAR LIBROS Y AUTORES\n3:PRESTAMOS\n4:INFORMES\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);
}

void menuListaOrdenada(t_Socios str[],int cantidadElementos)
{
    char auxiliar[15];
    int opcion2;
    getNumber("\nOrdenar por 1:NOMBRE o 2:APELLIDO: ","opcion incorrecta",1,2,1,2,auxiliar);
                    opcion2 = atoi(auxiliar);
                    switch(opcion2)
                    {
                      case 1:
                        ordenarNombres(str,cantidadElementos);
                        mostrarListaSocios(str,cantidadElementos,-1);
                        break;
                      case 2:
                        ordenarApellidos(str,cantidadElementos);
                        mostrarListaSocios(str,cantidadElementos,-1);
                        break;
                    }
}
void menuInformes(int *resultado)
{
    char aux[15];
    printf("\n1:TOTAL DE SOLICITUDES A PRESTAMOS DE LIBROS\n2:NO LO PUDE HACER\n");
    printf("3:SOCIOS Y LIBROS QUE FUERON SOLICITADO(C Y D JUNTAS)\n");
    printf("4:TITULO MENOS SOLICITADO\n5:SOCIOS CON MAS SOLICITUDES A PRESTAMO\n");
    printf("6:LIBROS A PRESTAMO CON FECHA DETERMINADA\n");
    printf("7:SOCIOS QUE SOLICITARON PRESTAMO AL MENOS 1 EN FECHA DETERMINADA\n");
    printf("8:LIBROS ORDENADOS POR TITULO(DESCENDENTE)\n");
    getNumber("9:SOCIOS ORDENADOS POR APELLIDO: ",
              "caracter incorrecto",1,10,1,3,aux);
    *resultado = atoi(aux);
}
//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void altaDeSocios(t_Socios str[],int cantidadElementos,int idIncremental)
{
    int espacioLibre; //variable donde se guarda la ubicacion del array donde hay un espacio libre.
    char auxiliar[51];
    char auxSexo;
    espacioLibre = buscarEspacioLibreSocios(str,cantidadElementos,-1);/**Busco espacio libre ántes de cargar el dato.**/

    if(espacioLibre != -1)
    {
        /**TOMO TODOS LOS DATOS NECESARIOS Y LOS GUARDO EN LAS ESTRUCTURAS**/
        getName("Ingrese el nombre: ","caracteres incorrecto",1,51,str[espacioLibre].nombre);
        getName("Ingrese apellido: ","caracteres incorrecto",1,51,str[espacioLibre].apellido);
        getSexo("Ingrese el sexo M o F: ","caracter incorrecto",&auxSexo);
        fflush(stdin);
        getNumber("Ingrese telefono(minimo 8 caracteres): ","telefono incorrecto",
                  1,9999999999,8,11,str[espacioLibre].telefono);
        getEmail("Ingrese eMail: "," eMail incorrecto",6,20,str[espacioLibre].eMail);

        getNumber("Dia: ","dia incorrecto",1,31,1,10,auxiliar);
        str[espacioLibre].fechaDelSocio.dia = atoi(auxiliar);
        getNumber("Mes: ","mes incorrecto",1,12,1,10,auxiliar);
        str[espacioLibre].fechaDelSocio.mes = atoi(auxiliar);
        getNumber("(2000 - 2019)Anio: ","anio incorrecto",2000,2019,1,20,auxiliar);
        str[espacioLibre].fechaDelSocio.anio = atoi(auxiliar);
        str[espacioLibre].sexo = auxSexo;
        str[espacioLibre].idSocio = idIncremental;
        str[espacioLibre].estado = 1;

        printf("\nALTA EXITOSA");
    }
    else
    {
        printf("No encontro lugar");
    }
}

/**
  *\brief Da el alta , pidiendo al usuario todos los datos necesarios.
  *\param El array Y la cantidad de elementos del array.
**/
void baja(t_Socios str[],int cantidadElementos)
{
   int espacioLibre;
   char auxDato[51];
   espacioLibre = buscarEspacioLibreSocios(str,5,1);
   if(espacioLibre != -1)
   {
    mostrarListaSocios(str,cantidadElementos,-1);
    getNumber("Que id desea dar de baja: ","caracter incorrecto",1,1000,1,cantidadElementos,auxDato);
    espacioLibre = buscarDatoValidoSocios(str,cantidadElementos,atoi(auxDato));

        if(espacioLibre != -1)
        {
            str[espacioLibre].estado = -1;
            printf("\nBaja exitosa");
        }
        else
        {
            printf("\nEl dato no existe");
        }
   }
   else
   {
       printf("\nno hay datos cargados");
   }
}
/**
  *\brief Modifica un dato del array.
  *\param El array , la cantidad de elementos.
**/
void modificacionDeSocio(t_Socios str[],int cantidadElementos)
{
    int espacioLibre;
    char auxDato[51];
    espacioLibre = buscarEspacioLibreSocios(str,5,1);
    int opcion;
    if(espacioLibre != -1)
    {
        mostrarListaSocios(str,cantidadElementos,-1);
        getNumber("Ingrese la id a modificar: ","error",1,cantidadElementos,1,cantidadElementos,auxDato);
        espacioLibre = buscarDatoValidoSocios(str,5,atoi(auxDato));
        if(espacioLibre != -1)
        {
            menuModificacion(&opcion);
            do
            {
            switch(opcion)
            {
            case 1:
                getName("\nIngrese nuevo nombre:  ","error",1,51,str[espacioLibre].nombre);
                getName("\nIngrese nuevo apellido:  ","error",1,51,str[espacioLibre].apellido);
                printf("\MODIFICACION EXITOSA");
                break;
            case 2:
                getSexo("\nIngrese el nuevo sexo M o F: ","dato incorrecto",str[espacioLibre].sexo);
                printf("\nMODIFICACION EXITOSA");
                break;
            case 3:
                getName("\nIngrese el nuevo telefono: ","telefono incorrecto",9,10,str[espacioLibre].telefono);
                printf("\nMODIFICACION EXITOSA");
                break;
            }
            break;
            }while(opcion != 4);

        }
        else
        {
            printf("El dato no existe");
        }
    }
    else
    {
        printf("no hay datos cargados");
    }
}
/**-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------**/

void mostrarListaSocios(t_Socios str[],int cantidadElementos,int valorLibre)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != valorLibre)
        {
           printf("\n%d %s %s %c %s %s",str[i].idSocio,str[i].nombre,str[i].apellido,str[i].sexo,str[i].telefono,str[i].eMail);
           printf(" dia: %d mes: %d anio: %d",str[i].fechaDelSocio.dia,str[i].fechaDelSocio.mes,str[i].fechaDelSocio.anio);
        }
    }
}
/**
  *\brief Lista todos los libros y sus autores
  *\param la cantidad de libros
**/
void mostrarListaLibros(t_Libros str[],int cantidadElementos)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        printf("\nID: %d TITULO: %s AUTOR: %s",str[i].idLibro,str[i].tituloDelLibro,str[i].autor.nombreAutor);
    }
}
/**
  *\brief lista los prestamos activos, mostrando el socio y el libro que solicito
  *\param las tres estructuras
**/
void listarPrestamosActivos(t_Socios str[],t_Prestamos str3[],t_Libros str2[],int cantidadSocios,int cantidadLibros)
{
    int i, j, k;

    for( i = 0; i < cantidadLibros; i++)
    {
        for( j = 0; j < (cantidadSocios * cantidadLibros); j++ )
        {
            if( str2[i].idLibro == str3[j].idLibro && str3[j].estado == 1)
            {
                for( k = 0; k<cantidadSocios;k++)
                {
                    if( str[k].estado != -1 && str3[j].idSocio == str[k].idSocio )
                    {
                        printf("\nID del Prestamo:%d  %d %s %s libro: %s autor: %s", str3[j].idPrestamo,str[k].idSocio,
                               str[k].nombre,str[k].apellido,str2[i].tituloDelLibro,str2[i].autor.nombreAutor);
                    }
                }
            }
        }
    }
}

//----------------------ORDENAMIENTO--------------------------
/**
  *\brief Ordena por apellido ascendente el array de socios.
  *\param el array a ordenar, la cantidad de elementos, y un auxiliar para hacer el movimiento de lugares.
**/
void ordenarApellidos(t_Socios str[],int cantidadElementos)
{
    int i,j;
    t_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(str[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(str[j].idSocio == -1)
                        {
                            continue;
                        }
                        if(strcmp(str[i].apellido,str[j].apellido) > 0)
                        {
                            auxSocios = str[j];
                            str[j] = str[i];
                            str[i] = auxSocios;

                        }
                    }
                }
}

/**
  *\brief Ordena por apellido ascendente el array de socios.
  *\param el array a ordenar, la cantidad de elementos, y un auxiliar para hacer el movimiento de lugares.
**/
void ordenarNombres(t_Socios str[],int cantidadElementos)
{
    int i,j;
    t_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(str[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(str[j].idSocio == -1)
                        {
                            continue;
                        }
                        if(strcmp(str[i].nombre,str[j].nombre) > 0)
                        {
                            auxSocios = str[j];
                            str[j] = str[i];
                            str[i] = auxSocios;

                        }
                    }
                }
}
/**
  *\brief Hace un alta de una solicitud a prestamo, tomndo la id del libro y la del socio.
  *\param las tres estructuras y sus cantidades
**/
void altaDePrestamo(t_Prestamos str[],t_Socios str2[],t_Libros str3[],int cantidadSocios,int cantidadLibros
                    ,int idIncremental)
{
    int espacioLibre;
    char auxiliar[51];
    int i;
    espacioLibre = buscarPosicionPrestamo(str,cantidadSocios*cantidadLibros,-1);
    i = buscarEspacioLibreSocios(str2,cantidadSocios,1);
    if(espacioLibre != -1 && i != -1)
    {
        mostrarListaLibros(str3,cantidadLibros);
        getNumber("\nQue libro desea(seleccione ID)? ","id incorrecta",1,cantidadLibros,1,10,auxiliar);
        str[espacioLibre].idLibro = atoi(auxiliar);
        mostrarListaSocios(str2,cantidadSocios,-1);
        getNumber("\nSeleccione el socio: ","caracter incorrecto",1,1000,1,4,auxiliar);
        i = buscarDatoValidoSocios(str2,cantidadSocios,atoi(auxiliar));
        while(i == -1)
        {
            getNumber("\nDato Inexistente\nSeleccione el socio: ","caracter incorrecto",1,1000,1,4,auxiliar);
            i = buscarDatoValidoSocios(str2,cantidadSocios,atoi(auxiliar));
        }
        str[espacioLibre].idSocio = atoi(auxiliar);
        str[espacioLibre].idPrestamo = idIncremental;
        str[espacioLibre].estado = 1;

        printf("\nALTA EXITOSA");
    }
    else
    {
        printf("NO HAY SOCIOS CARGADOS");
    }
}
/**
  *\brief Lista el socio con mayor solicitudes a prestamo.
  *\param array de prestamos y de socios y sus cantidades.
**/
void listarSocioMayorPrestamos(t_Socios str[],t_Prestamos str2[],int cantidadSocios,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadSocios];//contador que guarda en +1 cada vez que encuentra una id de un socio que posee un prestamo
    for(i=0;i<cantidadSocios;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadSocios];//array paralelo de buscarMayor guardando la posicion donde el contador aumento en 1
    int maximo = 0;
    int aux;
    for( i = 0; i < cantidadPrestamos; i++)//Buscamos en las ID de los prestamos una igualdad con las ID de los socios.
    {
        for( j = 0; j<cantidadSocios; j++ )
        {
            if(str[j].estado != -1 && str[j].idSocio == str2[i].idSocio)
            {
                buscarMayor[j]++;//aumentamos la cantidad en la misma posicion donde se encuentra el socio
                posicion[j] = j;//guardamos la posicion del socio que aumento en 1
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadSocios-1;i++)//colocamos al socio con mayor cantidad de prestamos en la posicion 0
        {
            for(j=i+1;j<cantidadSocios;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;
                /**La posicion 0 del array "posicion" va a tener como valor la posicion del array socio
                    con mas prestamos otorgados*/
                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }
        printf("\nLa persona con mayor prestamos es: %s %s",str[posicion[0]].nombre,str[posicion[0]].apellido);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}
void listarLibroMasSolicidato(t_Libros str[],t_Prestamos str2[],int cantidadLibros,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadLibros];/**contador que guarda en +1 cada vez que encuentra una id de un libro que posee un prestamo*/
    for(i=0;i<cantidadLibros;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadLibros];/**array paralelo de buscarMayor guardando la posicion donde el contador aumento en 1*/
    int maximo = 0;
    int aux;
    for( i = 0; i < cantidadPrestamos; i++)/**Buscamos en las ID de los prestamos una igualdad con las ID de los LIBROS.*/
    {
        for( j = 0; j<cantidadLibros; j++ )
        {
            if(str[j].idLibro == str2[i].idLibro)
            {
                buscarMayor[j]++;/**aumentamos la cantidad en la misma posicion donde se encuentra el libro*/
                posicion[j] = j;/**guardamos la posicion del socio que aumento en 1*/
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadLibros-1;i++)/**colocamos al libro con mayor cantidad de prestamos en la posicion 0*/
        {
            for(j=i+1;j<cantidadLibros;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;
                /**La posicion 0 del array "posicion" va a tener como valor la posicion del array libro
                    con mas prestamos otorgados*/
                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }
        printf("\nEl libro mas solicitado es: %s autor: %s",str[posicion[0]].tituloDelLibro,
               str[posicion[0]].autor.nombreAutor);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}
/**
  \brief Lista el total de solicitudes a prestamo
  \param array prestamo y su cantidad
**/
void listarTotalGeneralYpromedio(t_Prestamos str[],int cantidadPrestamos)
{
    int i, j;
    int acumulador = 0;
    int aux;
    int fecha;
    for( i = 0; i<cantidadPrestamos;i++)
    {
        if(str[i].estado != -1)
        {
            acumulador++;
        }
    }
    printf("\nLa cantidad de prestamos es: %d\n",acumulador);

}
/**
  *\brief Lista el libro menos solicitado
  *\param el array de libros, el de prestamos y sus cantidades.
**/

void listarLibroMenosSolicidato(t_Libros str[],t_Prestamos str2[],int cantidadLibros,int cantidadPrestamos)
{
    int i, j;
    int buscarMayor[cantidadLibros];/**contador que guarda en +1 cada vez que encuentra una id de un libro que posee un prestamo**/
    for(i=0;i<cantidadLibros;i++)
    {
        buscarMayor[i] = 0;
    }
    int posicion[cantidadLibros];/**array paralelo de buscarMayor guardando la posicion donde el contador aumento en 1**/
    int maximo = 0;
    int aux;
    for( i = 0; i < cantidadPrestamos; i++)/**Buscamos en las ID de los prestamos una igualdad con las ID de los LIBROS.**/
    {
        for( j = 0; j<cantidadLibros; j++ )
        {
            if(str[j].idLibro == str2[i].idLibro)
            {
                buscarMayor[j]++;/**aumentamos la cantidad en la misma posicion donde se encuentra el libro**/
                posicion[j] = j;/**guardamos la posicion del socio que aumento en 1**/
            }
        }
    }
    if(buscarMayor[0])
    {
        for(i=0;i<cantidadLibros-1;i++)/**colocamos al libro con mayor cantidad de prestamos en la posicion 0**/
        {
            for(j=i+1;j<cantidadLibros;j++)
            {
                if(buscarMayor[i] < buscarMayor[j])
                {
                    aux = buscarMayor[i];
                    buscarMayor[i] = buscarMayor[j];
                    buscarMayor[j] = aux;
                /**La posicion 0 del array "posicion" va a tener como valor la posicion del array libro
                    con mas prestamos otorgados**/
                    aux = posicion[i];
                    posicion[i] = posicion[j];
                    posicion[j] = aux;
                }
            }
        }
        /**La ultima posicion del array posicion, tiene cargada la posicion menos solicitada**/
        printf("\nEl libro menos solicitado es: %s autor: %s",str[posicion[cantidadLibros-1]].tituloDelLibro,
               str[posicion[cantidadLibros-1]].autor.nombreAutor);
    }
    else
    {
        printf("\nNo se cargaron prestamos");
    }
}
/**
  *\brief Lista los libros que fueron solicitados a prestamo con la fecha de solicitud
  *\param el array de prestamos, el de libros y sus cantidades.
**/
void listarLibrosPrestamoMasFecha(t_Prestamos str[],t_Libros str2[],
                                  int cantidadLibros,int cantidadPrestamos)
{
    int i, j;

    for( i = 0; i < cantidadLibros; i++)
    {
        for( j = 0; j < cantidadPrestamos; j++ )
        {
            if( str2[i].idLibro == str[j].idLibro && str[j].estado != -1)
            {
                printf("\nLibro en prestamo : %s %s fecha de prestamo: ",
                       str2[i].tituloDelLibro,str2[i].autor.nombreAutor);
                printf("dia: %d mes: %d anio: %d",str[j].fechaPrestamo.dia,
                       str[j].fechaPrestamo.mes,str[j].fechaPrestamo.anio);
            }
        }
    }
}
/**
  *\brief Ordena los libros por titulo ascendente.
  *\param El array de libros y su cantidad.
**/
void ordenarLibros(t_Libros str[],int cantidadLibros)
{
    int i,j;
    t_Libros auxLibros;
    for(i=0; i < cantidadLibros - 1; i++)
    {
        for(j=i+1; j < cantidadLibros; j++)
        {
            if(strcmp(str[i].tituloDelLibro,str[j].tituloDelLibro) < 0)
            {
                auxLibros = str[j];
                str[j] = str[i];
                str[i] = auxLibros;
            }
        }
    }
}
/**
  *\brief lista los socios que solicitaron un libro a prestamo
  *\brief con la fecha en que la solicitaron.
  *\param el array de prestamos, de socios y sus cantidades
**/
void listarSocioPrestamoMasFecha(t_Prestamos str[],t_Socios str2[],
                                  int cantidadSocios,int cantidadPrestamos)
{
    int i, j;

    for( i = 0; i < cantidadSocios; i++)
    {
        if(str[i].estado != -1)
        {
            for( j = 0; j < cantidadPrestamos; j++ )
            {
                if( str2[i].idSocio == str[j].idSocio)
                {
                    printf("\nID %d nombre: %s %s fecha de prestamo: ",
                       str2[i].idSocio,str2[i].nombre,str2[i].apellido);
                    printf("dia: %d mes: %d anio: %d",str[j].fechaPrestamo.dia,
                       str[j].fechaPrestamo.mes,str[j].fechaPrestamo.anio);
                }
            }
        }
    }
}
/**
  *\brief Ordena por apellido descendente la lista de socios
  *\param el array de socios y su cantidad
**/
void ordenarApellidosDescendente(t_Socios str[],int cantidadElementos)
{
    int i,j;
    t_Socios auxSocios;
    for(i=0; i < cantidadElementos - 1; i++)
    {
        if(str[i].estado == -1)
        {
            continue;
        }
        for(j=i+1; j < cantidadElementos; j++)
        {
            if(str[j].idSocio == -1)
            {
                continue;
            }
            if(strcmp(str[i].apellido,str[j].apellido) < 0)
            {
                auxSocios = str[j];
                str[j] = str[i];
                str[i] = auxSocios;
            }
        }
    }
}
