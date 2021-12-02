/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Libro.h"
#include "Editorial.h"
#include "Input.h"
#include "Parser.h"

int main(void)
{
	setbuf(stdout,NULL);

    int option = 0;

    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditoriales = ll_newLinkedList();


    int flagCargaLibros;
    int flagCargaEditoriales;

    flagCargaEditoriales = 0;
    flagCargaLibros = 0;

	printf("\n---------------------------------------------------------------- \n");
	printf("\n Bienvenido al Parcial 2 de Laboratorio Creado por Cristian Illi \n");
	printf("\n----------------------------------------------------------------\n");

    do
      {
    	option = MostrarMenu();

    	switch (option) {
			case 1:

				if(flagCargaLibros == 0 && controller_loadFromText(listaLibros,parser_LibroFromText)!=-1)
				{
					printf("\nCarga Completada \n");
					flagCargaLibros =1;
				}
				else
				{
					printf("\n No se cargo la lista \n");//lk
				}

				break;

			case 2:

				if(flagCargaEditoriales == 0 &&controller_loadFromText(listaEditoriales,parser_EditorialFromText)!=-1)

				{
					printf("\nSe cargaron los datos \n");
					flagCargaEditoriales =1;
				}
				else
				{
					printf("\nNo se carga la lista \n");
				}

				break;
			case 3:
					if(flagCargaLibros == 1 &&controller_sortLibros(listaLibros,listaEditoriales))
					{
						printf("\nSe muestra la lista Ordenada");
					}
					else
					{
						printf("\nTiene que cargar las listas para poder verla ordenada\n");
					}
				break;
			case 4:
				if(flagCargaLibros == 1 && controller_ListLibros(listaLibros,listaEditoriales)!=-1)
				{
					printf("\n Se muestra la lista \n");
				}else
				{
					printf("\nTiene que cargar la lista para poder mostrarla \n");
				}
				break;
			case 5:

				if(flagCargaLibros == 1 && controller_filtrarLibros(listaLibros,listaEditoriales)!=-1)
				{
					printf("\n Se muestra la lista filtrada \n");
				}else
				{
					printf("\nCargue la lista para poder mostrarla\n");
				}

				break;

			case 6:

				if(flagCargaLibros == 1 && controller_MapearLibros(listaLibros)!=-1)
				{
					printf("\nSe genero la lista correctamente \n");
				}else
				{
					printf("\nCargue la lista para poder mostrarla\n");
				}

				break;


			case 7:
				if(flagCargaLibros == 1)
				{
					controller_cantLibros(listaLibros);
				}else
				{
					printf("\nCargue la lista para poder mostrarla\n");
				}

				break;

			case 8:

				if(flagCargaLibros == 1)
				{
					controller_Precios_ePearson(listaLibros);
				}else
				{
					printf("\nCargue la lista para poder mostrarla\n");
				}
				break;
			case 9:
    			if(ll_deleteLinkedList(listaLibros)!=-1)
    			{
    				printf("Cerrado exitoso \n");
    			}
    			if(ll_deleteLinkedList(listaEditoriales)!=-1)
    			 {
    			    printf("Cerrado exitoso \n");
    			 }
				break;

		}


	  } while (option != 9);



	return EXIT_SUCCESS;
}
