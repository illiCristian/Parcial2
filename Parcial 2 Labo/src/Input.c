#include "input.h"
//------------------------------------------------

int MostrarMenu ()
{
        int opcionIngresada;


         printf("\n Elija una opcion \n");
         printf("1. Cargar los datos de libros. \n");
         printf("2. Cargar los datos de editoriales. \n");
         printf("3. Ordenar la lista generada �Autor� de manera ascendente.. \n");
         printf("4. Imprimir por pantalla todos los datos de los libros. \n");
         printf("5. Realizar un listado de los libros de la editorial MINOTAURO.. \n");

         printf("6. Mapear PLANETA: 20 (si el monto es mayor o igual a $300)\n"
        		 "SIGLO XXI EDITORES: 10 (si el monto es menor o igual a $200)\n");

         printf("7. Determinar cu�ntos libros cuestan mas de $500.\n");
         printf("8. Determinar la sumatoria de precios de los libros de la editorial PEARSON\n");
         printf("9. Salir \n");

        // printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto). \n");

         fflush(stdin);

         opcionIngresada = PedirUnEnteroRango("Ingrese una opcion:", 1, 9);

         return opcionIngresada;
}

//-------------------------------------------

int ValidarEntero (char numero[])
{
    int retorno;
    int tamArray;

    retorno = -1;  //cero es falso

    tamArray = strlen(numero);  // guardo en tamArray el tama�o


    if (isdigit(numero[0]) != 0 || (tamArray > 1 && (numero[0] == '-' || numero [0]== '+')))
    {
    for (int i = 1; i < tamArray && retorno == 1; i++)
    {
        if (isdigit(numero[i]) == 0) // cero = no es un numero, !isdigit negado devuelve un 1 y entra al if (si no encuentra un numero)
        {
            retorno = 0;
        }

    }

    }
    else
    {
    	retorno = 0;
    }

    return retorno;
}

//---------------------------------------------------------------------------------------------------------


int PedirUnEntero(char mensaje[])
{
    char numeroIngresado[11];

    int numeroValidado;
    int numeroARetornar;
    int retornoDeMyGets;

    printf("%s",mensaje);

    retornoDeMyGets = myGets(numeroIngresado,11);

    numeroValidado = ValidarEntero(numeroIngresado);

    while (retornoDeMyGets == -1 || numeroValidado == 0)
    {
       printf("Error: %s \n",mensaje);
       retornoDeMyGets = myGets(numeroIngresado,11);
       numeroValidado = ValidarEntero(numeroIngresado);
    }

    numeroARetornar = atoi(numeroIngresado);

    return numeroARetornar;
}

//------------------------------------------------------------------------------
int myGets(char cadena [], int longitud)
{  // Recibo una cadena y la longitud de la misma
   int retorno = -1;
   char bufferString[4096];

   if (cadena != NULL && longitud > 0)
   {
       fflush(stdin); // Limpio el stdin
       //Leo el stdin hasta que el usuario ingresa un "Enter" o Hasta el limite del bufferstring con ziseof
       if (fgets(bufferString,sizeof(bufferString),stdin) != NULL)
       { //Si se llego al limite no remplazo con un \0
           if (bufferString[strlen(bufferString)-1] == '\n')
           {  //Si no se llego al limite remplazo con un \0
               bufferString[strlen(bufferString)-1] = '\0';
           }
         //Si la longitud  resultante de la cadena ingresada es menor que la longitud
           if (strlen(bufferString) <= longitud && strlen(bufferString)>0)
           {  //Copio lo ingresado a la cadena (al espacio de memoria que me paso el usuario)
               strncpy(cadena,bufferString,longitud);
               retorno = 0;
           }
       }
   }
    return retorno;
}

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
float PedirFlotante(char mensaje[])
{
    float numero;

    printf("%s",mensaje);
	scanf("%f",&numero );

	return numero;
}
//------------------------------------------------------------------------------------------------
void PedirCadena(char array[],char message[],char messageError[])
{
    char buffer[100];

     printf("%s",message);
    while(myGets(buffer, sizeof(buffer))== -1 || !validateStringOfLetters(buffer))
    {
    	printf("%s",messageError);

    }
    strcpy(array,buffer);

}


//------------------------------------------------------------------------------------------------
int validateStringOfLetters(char cadena[]) {

    int esSoloLetras;
    int longitud;

    esSoloLetras = 1;
    longitud = strlen(cadena);

    for (int i = 0; i < longitud; i++)
    {
        if (!isalpha(cadena[i]))
        {
            esSoloLetras = 0;
        }
    }


    return esSoloLetras;
}
//-----------------------------------------------------------------------------------------------
// PARA VALIDAR FLOTANTES

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0){
		for(i=0 ; cadena[i] != '\0'; i++){
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+')){
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' ){
				if(cadena[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError,
							float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

int getString(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0){
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL){
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud){
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
//------------------------------------------------------------------------------------------------
void PedirCadenaB(char array[],char message[])
{

    char buffer[100];
    printf("%s",message);
    myGets(buffer, sizeof(buffer));
    strcpy(array,buffer);
}
//------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------

int PedirUnEnteroRango(char mensaje[],int minimo, int maximo)
{
    char numeroAverificar[11];
    int numeroIngresado;

    printf("%s",mensaje);


    while(myGets(numeroAverificar,sizeof(numeroAverificar))== -1 || !ValidarEntero(numeroAverificar) || !VerificarRangoInt(numeroAverificar, &numeroIngresado, minimo, maximo))
    	{
    	printf("Error:  %s",mensaje);
		}
    //numeroARetornar = atoi(numeroIngresado);

    return numeroIngresado;
}

//-------------------------------------------------------------------------
int VerificarRangoInt (char numeroAverificar[], int *numeroAretornar, int minimo ,int maximo)
{
	int enRango;
	int numeroAuxiliar;

	enRango = 0;
	numeroAuxiliar = atoi(numeroAverificar);

	if (numeroAuxiliar >= minimo && numeroAuxiliar <=maximo)
	{
		enRango =1;
		*numeroAretornar = numeroAuxiliar;
	}
	return enRango;
}
//-----------------------------------------------------------------------------
int GenerarId(int id)
{
    id++;
    return id;
}

int MostrarMenuB()
{
	int opcion;
	opcion =-1;

	opcion = PedirUnEnteroRango(
								"1. ordenar por Nombre de Autor a-z\n"
								"2. ordenar por Nombre de Autor z-a\n"
								"3.salir", 1, 3);

	return opcion;
}



int validarCadenaConEspacios(char nombre[])
{
		int retorno;
		int longitud;
		int contador=0;

		retorno = 1;
		longitud = strlen(nombre);

		for (int i = 0; i < longitud; i++)
		{
			if(nombre[0]==' '|| nombre[i]!=' ' )
			{

			if (!isalpha(nombre[i]) || longitud == 0||contador>3)
			{
				retorno = 0;
				break;
			}
			}
			if(nombre[i]==' ')
			{
				contador++;
			}
		}

		return retorno;

}

int ValidarCharNumerofloat(char numero[])
{
	int bandera = 1;
	int auxstr;

	auxstr = strlen(numero);
	int i;
	//if ((numero[0] == '-' && auxstr != 1 )|| (isdigit(numero[0]) && (numero[1] == '.' && auxstr > 2)) || (isdigit(numero[0])))
	if ((isdigit(numero[0]) && (numero[1] == '.' && auxstr > 2)) || (isdigit(numero[0])))
	{

		for (i = 2; i < auxstr; i++)
		{

			if (!(isdigit(numero[i])))

			{

				bandera = 0;
				break;

			}

		}

	}
	else
	{

		bandera = 0;

	}

	return bandera;
}


