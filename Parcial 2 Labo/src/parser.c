#include <stdio.h>
#include <stdlib.h>

#include "Libro.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Editorial.h"
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno;
	retorno = -1;
	char id[50];
	char titulo[50];
    char autor[50];
    char precio[50];
    char idEditorial[50];

	eLibro* pLibro;

	int contadorLineas;

	 fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio);

	 while(!feof(pFile))
		    {
		 	    contadorLineas = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id,titulo,autor,precio,idEditorial);

		 	 	if (contadorLineas == 5 && validarCadenaConEspacios(titulo) && validarCadenaConEspacios(autor)
		 	 			&&ValidarEntero(id) && ValidarEntero(idEditorial))
		 	 	{
		 	 		pLibro = Libro_newParametros(id,titulo,autor,precio,idEditorial);
		 	 		retorno =0;

		 	 	}
		 	 	if (pLibro!=NULL)
		 	 	{
		 	 		ll_add(pArrayListLibros,pLibro);
		 	 	}


		    }

		    return retorno;
}




/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)


{
	int retorno = -1;

	  if (pFile != NULL && pArrayListEmployee != NULL)
	    {
	        while (!feof(pFile))
	        {

	            {
	                eLibro *pLibro = Libro_new();

	                retorno = fread(pLibro, sizeof(eLibro), 1, pFile);

	                if (retorno == 1)
	                {
	                    ll_add(pArrayListEmployee, pLibro);
	                }

	            }
	        }

	        retorno = 0;
	    }

	    fclose(pFile);

	    return retorno;
}


//---------------------------------------------------------------------------
/// @fn int parser_EditorialFromText(FILE*, LinkedList*)
/// @brief
///
/// @param pFile
/// @param pArrayListEditorial
/// @return
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int retorno;
	retorno =-1;
	char nombre[50];
    char idEditorial[50];


	eEditorial* pEditorial;

	int contadorLineas;

	 fscanf(pFile,"%[^,],%[^\n]\n",idEditorial,nombre);

	 printf("%s %s \n",idEditorial,nombre);

	 while(!feof(pFile))
		    {
		 	  contadorLineas = fscanf(pFile,"%[^,],%[^\n]\n",idEditorial,nombre);

		 	 	if (contadorLineas == 2 && ValidarEntero(idEditorial) && validarCadenaConEspacios(nombre))
		 	 	{
		 	 		pEditorial = Editorial_newParametros(idEditorial,nombre);
		 	 		retorno =0;
		 	 	}

		 	 	if (pEditorial!=NULL)
		 	 	{
		 	 		ll_add(pArrayListEditorial,pEditorial);
		 	 	}


		    }

		    return retorno;
}
