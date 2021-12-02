#include "Libro.h"

/// @fn eLibro Libro_newParametros*(char*, char*, char*, char*, char*)
/// @brief
///
/// @param id
/// @param titulo
/// @param autor
/// @param precio
/// @param idEditorial
/// @return
eLibro* Libro_newParametros(char* id,char* titulo,char* autor,char* precio,char* idEditorial)
{
	eLibro* pLibro;

	pLibro = Libro_new();

	if (pLibro != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial)
		{
			if (
				Libro_setId(pLibro,atoi(id))!= 0 ||
		        Libro_setTitulo(pLibro,titulo) != 0 ||
				Libro_setTAutor(pLibro,autor) != 0 ||
		        Libro_setPrecio(pLibro,atof(precio))!=0||
				Libro_setIdEditorial(pLibro,atoi(idEditorial))!= 0 )
			{
				Libro_delete(pLibro);

			}
		}
	return pLibro;
}


/// @fn int Libro_setId(eLibro*, int)
/// @brief
///
/// @param this
/// @param id
/// @return
int Libro_setId(eLibro* this,int id)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && id > 0)
	{
		this->id =id;
		retorno = 0;
	}


	return retorno;
}
/// @fn int Libro_getId(eLibro*, int*)
/// @brief
///
/// @param this
/// @param id
/// @return
int Libro_getId(eLibro* this,int* id)
{
	int retorno;
	retorno = -1;
	if(this!=NULL && id !=NULL)
	{
		*id = this->id;
		retorno=0;
	}

	return retorno;
}
/// @fn int Libro_setIdEditorial(eLibro*, int)
/// @brief
///
/// @param this
/// @param idEditorial
/// @return
int Libro_setIdEditorial(eLibro* this,int idEditorial)
{
	int retorno;
	retorno = -1;

	if(this !=NULL && idEditorial > 0)
	{
		this->idEditorial =idEditorial;
		retorno = 0;
	}


	return retorno;
}
/// @fn int Libro_getIdEditorial(eLibro*, int*)
/// @brief
///
/// @param this
/// @param idEditorial
/// @return
int Libro_getIdEditorial(eLibro* this,int* idEditorial)
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
/// @fn int Libro_setTitulo(eLibro*, char*)
/// @brief
///
/// @param this
/// @param titulo
/// @return
int Libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && titulo!=NULL)
	    {
	        strcpy(this->titulo,titulo);
	        retorno = 0;;
	    }

	    return retorno;
}
/// @fn int Libro_getTitulo(eLibro*, char*)
/// @brief
///
/// @param this
/// @param titulo
/// @return
int Libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && titulo!=NULL)
	    {
	        strcpy(titulo,this->titulo);
	        retorno = 0;
	    }

	return retorno;
}
/// @fn int Libro_setTAutor(eLibro*, char*)
/// @brief
///
/// @param this
/// @param autor
/// @return
int Libro_setTAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno =-1;

	    if(this!=NULL && autor!=NULL)
	    {
	        strcpy(this->autor,autor);
	        retorno = 0;;
	    }

	    return retorno;
}
/// @fn int Libro_getAutor(eLibro*, char*)
/// @brief
///
/// @param this
/// @param autor
/// @return
int Libro_getAutor(eLibro* this,char* autor)
{
	int retorno;
	retorno =-1;
	if(this!=NULL && autor!=NULL)
	    {
	        strcpy(autor,this->autor);
	        retorno = 0;
	    }

	return retorno;
}
/// @fn int Libro_setPrecio(eLibro*, float)
/// @brief
///
/// @param this
/// @param precio
/// @return
int Libro_setPrecio(eLibro* this,float precio)
{
	int retorno;
	retorno =-1;

	if(this!=NULL)
	{
	     this->precio = precio;
	     retorno = 0;
	}

	return retorno;
}
/// @fn int Libro_getPrecio(eLibro*, float*)
/// @brief
///
/// @param this
/// @param precio
/// @return
int Libro_getPrecio(eLibro* this,float* precio)
{
	int retorno;
	retorno =-1;

	if (this!=NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}


	return retorno;
}

/*int Libro_setSueldo(eLibro* this,int sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		this->precio = sueldo;
		retorno = 0;
	}
	return retorno;
}
int Libro_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno =-1;
	if (this!=NULL)
	{
		*sueldo= this->precio;
		retorno = 0;
	}
	return retorno;
}*/
/// @fn eLibro Libro_new*()
/// @brief
///
/// @return
eLibro* Libro_new()
{
	eLibro* pLibro;

	pLibro = (eLibro*) calloc(sizeof(eLibro),1);

	return pLibro;
}
/// @fn void Libro_delete(eLibro*)
/// @brief
///
/// @param this
void Libro_delete(eLibro* this)
{
	if(this!=NULL)
	    {
	        free(this);
	        this=NULL;
	    }
}
/// @fn void imprimirUnLibro(eLibro*, LinkedList*)
/// @brief
///
/// @param this
/// @param listaEditoriales
void imprimirUnLibro(eLibro* this, LinkedList* listaEditoriales)
{
	int   id;
	char  titulo[30];
	char  autor[30];
	float precio;
	int   idEditorial;
	int   len;
	char  nombreAux[30];
	int idEditorialAux;


	eEditorial* pEditorial;

	if (this != NULL)
	{
	   if(Libro_getId(this, &id)!=-1
		  &&Libro_getTitulo(this, titulo) !=-1
		  &&Libro_getAutor(this, autor) !=-1
		  &&Libro_getPrecio(this, &precio) !=-1
		  &&Libro_getIdEditorial(this, &idEditorial)!=-1)
	   {
		 len = ll_len(listaEditoriales);

	   	 for (int i = 0; i < len; ++i)
	   	 {
	   		 pEditorial =(eEditorial*)ll_get(listaEditoriales,i);
	   		 Editorial_getId(pEditorial, &idEditorialAux);

	   		 if(idEditorial == idEditorialAux)
	   		 {

	   			Editorial_getNombre(pEditorial,nombreAux);
	   		 }
		 }
	   	printf("%d\t%15s\t%15st\t%.2f\t\t%s\n",id,titulo,autor,precio,nombreAux);
	   }
	}
}





//--------------------------------------------------------------------------
/*eLibro* CrearNuevoLibro(int* idAsignar)
{
	eLibro* pLibro;
	char id[128];
	char titulo[128];
    char autor[128];
    char precio[128];
    char idEditorial[128];
    int nuevaId;
    int auxId;
	pLibro = NULL;

	PedirCadena(titulo, "Ingrese el Titulo del libro","Error");
	PedirCadenaB(autor, "Ingrese el autor del libro");
	PedirCadenaB(precio, "Ingrese el precio del libro");
	//PedirUnEnteroRango("Ingrese la id de la editorial", 0, 500);
	PedirCadenaB(idEditorial, "Ingrese la id de la editorial");
	UltimoId("ArchivoId.txt",nuevaId);
	auxId = atoi(nuevaId)+1;

	itoa(auxId,nuevaId,10);

	printf("%d",auxId);

	pLibro = Libro_newParametros(nuevaId,titulo,autor,precio,idEditorial);
	if(pLibro != NULL)
	{
		*idAsignar = auxId;
	}

	return pLibro;
}

*/
/// @fn int UltimoId(char*, char*)
/// @brief
///
/// @param PATH
/// @param cadena
/// @return
int UltimoId(char* PATH, char* cadena)
{
	int retorno;
	retorno =-1;
	FILE* pFile;

	if(PATH != NULL)
	{
		pFile = fopen(PATH,"r");
		fgets(cadena,10,pFile);
		fclose(pFile);
		retorno = 0;
	}


	return retorno;
}
//-----------------------------------------------------------------------------------------------------
/// @fn int libro_CompararPorAutor(void*, void*)
/// @brief
///
/// @param valor1
/// @param valor2
/// @return
int libro_CompararPorAutor(void* valor1, void* valor2) // respeta el prototipo que pide el sort
{
	int rtn;

	eLibro*e1;
	eLibro*e2;

	e1 = (eLibro*) valor1; //castea
	e2 = (eLibro*) valor2;

	rtn = strcmp(e1->autor, e2->autor); //comparo 2 cadenas a-z. el orden lo determina el sort.

	return rtn;
}
/// @fn int empleado_CompararPorId(void*, void*)
/// @brief
///
/// @param valor1
/// @param valor2
/// @return
int empleado_CompararPorId(void* valor1, void* valor2)
{
	int retorno = 0;
	eLibro*e1;
	eLibro*e2;

	e1 = (eLibro*) valor1; //castea
	e2 = (eLibro*) valor2;

	if (e1->id > e2->id) // ordena numericamente.
	{
		retorno = 1;
	}
	else
	{
		if (e1->id < e2->id)
		{
			retorno = -1;
		}

	}
	return retorno;
}

//--------------------------------------------------------------------------
/// @fn int filtrarMinotauro(void*)
/// @brief
///
/// @param libro
/// @return
int filtrarMinotauro(void*libro)
{
	int retorno = 0;

	eLibro* pLibro;


	if(libro!=NULL)
	{
		pLibro = (eLibro*)libro;

		if(pLibro->idEditorial == 4)
		{
			retorno = 1;
		}
	}

	return retorno;
}
//----------------------------------------------------------------------------------
int mapearEditorial(void*libro)
{
	int retorno = -1;
	int idEditorialAux;
	float precioAux;
	float precioNuevo;

	/*
	 *  PLANETA: 20% (si el monto es mayor o igual a $300)
	 * SIGLO XXI EDITORES: 10% (si el monto es menor o igual a $200)
	 */
	if(libro != NULL)
	{
		Libro_getIdEditorial(libro, &idEditorialAux);
		Libro_getPrecio(libro, &precioAux);

		if(idEditorialAux == 1 && precioAux >= 300)
		{
			precioNuevo = precioAux - precioAux*20/100;
			retorno = Libro_setPrecio(libro,precioNuevo);
		}
		else
		{
			if (idEditorialAux == 2 && precioAux <= 200)
			{
			precioNuevo = precioAux - precioAux*10/100;
			retorno = Libro_setPrecio(libro, precioNuevo);
			}
		}
	}

	return retorno;
}

int DeterminarLibroMayorPrecio (void*libro)
{
	int retorno;

	retorno = 0;

	float precio;

	if(libro != NULL)
	{
		Libro_getPrecio(libro, &precio);
		if(precio > 500)
		{
			retorno = 1;
		}
	}
	return retorno;
}

float SumarPreciosPearson (void* libro)
{
	float retorno;

	retorno = 0;

	int idEditorial;

	if(libro != NULL)
	{
	  Libro_getIdEditorial(libro,&idEditorial);

	  if (idEditorial == 3)
	  {
		  Libro_getPrecio(libro,&retorno);
	  }
	}
	return retorno;
}



//int filtrarMinotauro2(void*libro, void*Criterio)
//{
//	int retorno = 0;
//	int* editorial;
//	editorial = (int*) Criterio; //casteo mi parametro recibido
//
//
//	eLibro* pLibro;
//
//
//	if(libro!=NULL)
//	{
//		pLibro = (eLibro*)libro;
//
//		if(pLibro->idEditorial == *editorial)
//		{
//			//printf("%d \n",pLibro->idEditorial);
//			retorno = 1;
//		}
//	}
//
//	return retorno;
//}





