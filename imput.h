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

   int dia;
   int mes;
   int anio;

}t_Prestamos;





int getString(int minimo,int maximo,char *resultado);
void getName(char *msg,char *msgError,int minimo,int maximo,char *resultado);
int isValidName(char str[]);
void getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,char *resultado);
int isValidNumber(char strNumber[]);
int isValidRange(int desde,int hasta,int numero);
void getSexo(char *msg,char *msgError,char* resultado);
int getDni(char* msg,char* msgError,int minimo,int maximo,char* resultado);
int isValidDni(char str[]);
int getCuit(    char* msg,
                char* msgError,
                char* msgError2,
                char* msgError3,
                int minimo,
                int maximo,
                char* resultado);
int isValidCuitA(char str[]);
int isValidCuitB(char str[]);





