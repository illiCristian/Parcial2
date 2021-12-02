/*
 * Editorial.h
 *
 *  Created on: 27 nov 2021
 *      Author: Cris
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include "Input.h"


typedef struct
{
	char nombre[128];
	int idEditorial;
}eEditorial;

void Editorial_delete(eEditorial* this);
int Editorial_getNombre(eEditorial* this,char* nombre);
int Editorial_setNombre(eEditorial* this,char* nombre);
int Editorial_getId(eEditorial* this,int* idEditorial);
int Editorial_setId(eEditorial* this,int idEditorial);
eEditorial* Editorial_newParametros(char* nombre, char* id);
eEditorial* Editorial_new();
void imprimirUnaEditorial(eEditorial* this);



#endif /* EDITORIAL_H_ */
