/*
 * Parser.h
 *
 *  Created on: 16 nov 2021
 *      Author: Cris
 */

#ifndef PARSER_H_
#define PARSER_H_


int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);

#endif /* PARSER_H_ */
