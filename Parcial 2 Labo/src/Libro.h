
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct
{
	int  id;
    char  titulo[128];
    char  autor[128];
    float  precio;
    int  idEditorial;
}eLibro;


#include "Editorial.h"
#include "Input.h"
#include "LinkedList.h"
eLibro* Libro_new();
eLibro* Libro_newParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial);
void Libro_delete();

int Libro_setId(eLibro* this,int id);
int Libro_getId(eLibro* this,int* id);

int Libro_setIdEditorial(eLibro* this,int idEditorial);
int Libro_getIdEditorial(eLibro* this,int* idEditorial);

int Libro_setTitulo(eLibro* this,char* titulo);
int Libro_getTitulo(eLibro* this,char* titulo);

int Libro_setPrecio(eLibro* this,float precio);
int Libro_getPrecio(eLibro* this,float* precio);

int Libro_setTAutor(eLibro* this,char* autor);
int Libro_getAutor(eLibro* this,char* autor);

void imprimirUnLibro(eLibro* this,LinkedList* listaEditoriales);
eLibro* CrearNuevoLibro(int* idAsignar);
int UltimoId(char* PATH, char* cadena);

int libro_CompararPorAutor(void* valor1, void* valor2);
int filtrarMinotauro(void*libro);
int mapearEditorial(void*libro);
int DeterminarLibroMayorPrecio (void*libro);
float SumarPreciosPearson (void*libro);


#endif // employee_H_INCLUDED
