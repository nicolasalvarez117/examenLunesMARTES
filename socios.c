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

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menuSocios(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTAR\n5:SALIR: ","opcion incorrecta: ",1,5,1,2,aux);
    *resultado = atoi(aux);

}
void menuPrestamo(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:ALTA PRESTAMO\n2:SALIR: ","opcion incorrecta: ",1,2,1,2,aux);
    *resultado = atoi(aux);

}


void menuModificacion(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\MODIFICAR:\n 1:NOMBRE Y APELLIDO\n2:SEXO\n3:TELEFONO\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);

}

//----------------MENUS DE OPCIONES----------------------------
/**
  *\brief imprime por pantalla el menu de ABM .
  *\param la ubicacion donde guardar la eleccion del usuario.
**/
void menuPrincipal(int *resultado)
{
    int i;
    char aux[15];
    getNumber("\n1:SOCIOS\n2:LISTAR LIBROS Y AUTORES\n3:PRESTAMOS\n4:SALIR: ","opcion incorrecta: ",1,4,1,2,aux);
    *resultado = atoi(aux);

}

void menuListaOrdenada(t_Socios str[],int cantidadElementos)
{
    char auxiliar[15];
    int opcion2;
    getNumber("\nOrdenar por 1:NOMBRE o 2:APELLIDO: ","opcion incorrecta",1,2,1,2,auxiliar);
                    opcion2 = atoi(auxiliar);
                    if(opcion2 = 1)
                    {
                      ordenarNombres(str,cantidadElementos);
                      mostrarListaSocios(str,cantidadElementos,-1);
                    }
                    else
                    {
                        ordenarApellidos(str,cantidadElementos);
                        mostrarListaSocios(str,cantidadElementos,-1);
                    }
}
//---------------------------------ALTA BAJA Y MODIFICACION-----------------------------------
void altaDeSocios(t_Socios str[],int cantidadElementos,int *idIncremental)
{
    int espacioLibre;
    char auxiliar[51];
    char auxSexo;
    char auxDia[10];
    char auxMes[10];
    char auxAnio[10];

    espacioLibre = buscarEspacioLibreSocios(str,cantidadElementos,-1);

    if(espacioLibre != -1)
    {
        getName("Ingrese el nombre: ","caracteres incorrecto",1,51,str[espacioLibre].nombre);
        getName("Ingrese apellido: ","caracteres incorrecto",1,51,str[espacioLibre].apellido);
        getSexo("Ingrese el sexo M o F: ","caracter incorrecto",&auxSexo);
        getNumber("Ingrese telefono: ","telefono incorrecto",1,9999999999,8,11,str[espacioLibre].telefono);
        printf("Ingrese eMail: ");
        getString(1,40,auxiliar);
        strcpy(str[espacioLibre].eMail,auxiliar);
        getNumber("Dia: ","dia incorrecto",1,31,1,10,auxDia);
        str[espacioLibre].fechaDelSocio.dia = atoi(auxDia);
        getNumber("Mes: ","mes incorrecto",1,12,1,10,auxDia);
        str[espacioLibre].fechaDelSocio.mes = atoi(auxDia);
        getNumber("(2000 - 2019)Anio: ","anio incorrecto",2000,2019,1,20,auxAnio);

        str[espacioLibre].fechaDelSocio.anio = atoi(auxAnio);
        str[espacioLibre].sexo = auxSexo;

        str[espacioLibre].idSocio = *idIncremental;
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
                printf("\MODIFICACION EXITOSA");
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
//-----------------------------LISTAR DATOS POR PANTALLA---------------------------------------

void mostrarListaSocios(t_Socios str[],int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(str[i].estado != -1)
        {
           printf("\n%d %s %s %s ",str[i].idSocio,str[i].nombre,str[i].apellido,str[i].telefono);
           printf("dia: %d mes: %d anio: %d",str[i].fechaDelSocio.dia,str[i].fechaDelSocio.mes,str[i].fechaDelSocio.anio);
        }
    }
}

void mostrarListaLibros(t_Libros str[],int cantidadElementos)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        printf("\nID: %d TITULO: %s AUTOR: %s",str[i].idLibro,str[i].tituloDelLibro,str[i].autor.nombreAutor);
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
                        if(strcmp(str[i].apellido,str[j].apellido) < 0)
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

void altaDePrestamo(t_Prestamos str[],t_Socios str2[],t_Libros str3[],int cantidadSocios,int cantidadLibros
                    ,int *idIncremental)
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
        printf("NO HAY DATOS CARGADOS");
    }
}

