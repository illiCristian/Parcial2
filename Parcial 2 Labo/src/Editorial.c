/*
 * Editorial.c
 *
 *  Created on: 27 nov 2021
 *      Author: Cris
 */

#include "Editorial.h"

eEditorial* Editorial_new()
{
	eEditorial* pEditorial;

	pEditorial = (eEditorial*) calloc(sizeof(eEditorial),1);

	return pEditorial;
}

eEditorial* Editorial_newParametros(char* id, char* nombre)
{
	eEditorial* pEditorial;

	pEditorial = Editorial_new();

	if (pEditorial != NULL && nombre != NULL && id!= NULL)
		{

		if(Editorial_setId(pEditorial,atoi(id))!= 0 || Editorial_setNombre(pEditorial,nombre) != 0)
			{
				Editorial_delete(pEditorial);
			}

		}
	return pEditorial;
}


int Editorial_setId(eEditorial* this,int idEditorial)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}


	return retorno;
}
int Editorial_getId(eEditorial* this,int* idEditorial)
{
	int retorno;
	retorno = -1;

	if(this!=NULL && idEditorial !=NULL)
	{
		*idEditorial = this->idEditorial;
		retorno=0;
	}

	return retorno;
}
int Editorial_setNombre(eEditorial* this,char* nombre)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && nombre!=NULL)
	    {
	        strcpy(this->nombre,nombre);
	        retorno = 0;;
	    }

	    return retorno;
}
int Editorial_getNombre(eEditorial* this,char* nombre)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && nombre!=NULL)
	    {
	        strcpy(nombre,this->nombre);
	        retorno = 0;
	    }

	return retorno;
}

void Editorial_delete(eEditorial* this)
{
	if(this!=NULL)
	    {
	        free(this);
	        this=NULL;
	    }
}

void imprimirUnaEditorial(eEditorial* this)
{
	int   idEditorial;
	char  nombre[25];

	if (this != NULL)
	{
	   if(Editorial_getId(this, &idEditorial)!=-1
		  &&Editorial_getNombre(this, nombre) !=-1)
		{
		    printf("%d\t%15s d\n",idEditorial,nombre);
		}
	}
}


