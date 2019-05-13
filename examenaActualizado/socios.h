/**---------------ESTRUCTURAS-----------------*/
typedef struct
{
   int dia;
   int mes;
   int anio;

}t_FechaPrestamo;
typedef struct
{
  int dia;
  int mes;
  int anio;

}t_Fecha;
typedef struct
{
   int idAutor;
   char nombreAutor[61];

}t_Autores;

typedef struct
{
    int idLibro;
    char tituloDelLibro[61];
    int idAutor;
    t_Autores autor;

}t_Libros;

typedef struct
{
   int idSocio;
   int estado;
   char nombre[51];
   char apellido[51];
   char sexo;
   char telefono[51];
   char eMail[51];

    t_Fecha fechaDelSocio;
}t_Socios;

typedef struct
{
   int idPrestamo;
   int idLibro;
   int idSocio;
   int estado;

   t_FechaPrestamo fechaPrestamo;

}t_Prestamos;
/**-----------PROTOTIPOS DEL EXAMEN----------------------------*/
void inicializarArraySocios(t_Socios str[],int cantidadElementos);
void hardcodearLibros(t_Libros str[],int cantidadElementos);
void menuPrincipal(int *resultado);
void menuSocios(int *resultado);
int buscarEspacioLibreSocios(t_Socios str[],int cantidadElementos,int valor);
void altaDeSocios(t_Socios str[],int cantidadElementos,int idIncremental);
void baja(t_Socios str[],int cantidadElementos);
void modificacionDeSocio(t_Socios str[],int cantidadElementos);
void mostrarListaSocios(t_Socios str[],int cantidadElementos,int valorOcupado);
int buscarDatoValidoSocios(t_Socios str[],int cantidadElementos,int valor);
void menuModificacion(int *resultado);
void ordenarApellidos(t_Socios str[],int cantidadElementos);
void ordenarNombres(t_Socios str[],int cantidadElementos);
void menuListaOrdenada(t_Socios str[],int cantidadElementos);
void menuPrestamo(int *resultado);
void mostrarListaLibros(t_Libros str[],int cantidadElementos);
int buscarPosicionPrestamo(t_Prestamos str[],int cantidadElementos,int valor);
void altaDePrestamo(t_Prestamos str[],t_Socios str2[],t_Libros str3[],int cantidadSocios,int cantidadLibros
                    ,int idIncremental);
void inicializarEstadoPrestamo(t_Prestamos str[],int cantidadElementos);
void hardcodearSocios(t_Socios str[],int *idIncremental);
void hardcodearPrestamosAsocios(t_Prestamos str[],int *idIncremental);
void listarPrestamosActivos(t_Socios str[],t_Prestamos str3[],t_Libros str2[],int cantidadSocios,int cantidadLibros);
void listarSocioMayorPrestamos(t_Socios str[],t_Prestamos str2[],int cantidadSocios,int cantidadPrestamos);
void menuInformes(int *resultado);
void listarLibroMasSolicidato(t_Libros str[],t_Prestamos str2[],
                              int cantidadLibros,int cantidadPrestamos);
void listarTotalGeneralYpromedio(t_Prestamos str[],int cantidadPrestamos);
void listarLibroMenosSolicidato(t_Libros str[],t_Prestamos str2[],
                                int cantidadLibros,int cantidadPrestamos);
void listarLibrosPrestamoMasFecha(t_Prestamos str[],t_Libros str2[]
                                  ,int cantidadLibros,int cantidadPrestamos);
void ordenarLibros(t_Libros str[],int cantidadLibros);
void listarSocioPrestamoMasFecha(t_Prestamos str[],t_Socios str2[],
                                  int cantidadSocios,int cantidadPrestamos);
void ordenarApellidosDescendente(t_Socios str[],int cantidadElementos);

