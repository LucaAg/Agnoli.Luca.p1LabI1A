#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"

int validarString(char frase[],int tam)
{
	int flag;
	int esString;
	int i=0;
	if(frase!=NULL)
	{
		flag=0;

		while(i<strlen(frase))
		{
			esString=isalpha(frase[i]);
			if(esString!=0 || frase[i]==' ')
			{
				i++;
			}
			else
			{
				flag=1;
				printf("Error, no puede ingresar numeros, ni simbolos. \nPor favor vuelva a ingresarlo: \n");
				fflush(stdin);
				gets(frase);
				i=0;
			}
			rangoString(frase,tam);
		}
		if(!validarStringOrdenado(frase))
		{
			flag=1;
		}
	}
	return flag;
}

int rangoString(char frase[],int tam)
{
	int todoOk=0;
	if(frase!= NULL && tam>0)
	{
		while(strlen(frase) > tam)
		{
			printf("Error, lo que usted ingreso supera el maximo de caracteres (%d)."
					"\nPor favor, reingreselo: \n",tam);
			fflush(stdin);
			gets(frase);
		}
		todoOk=1;
	}
	return todoOk;
}

int validarStringOrdenado(char frase[])
{
	int todoOk=0;
	int i=0;
	if(frase!=NULL)
	{
		strlwr(frase);
		frase[0]=toupper(frase[0]);
		while(frase[i]!='\0')
		{
			if(frase[i]==' ')
			{
				frase[i+1]=toupper(frase[i+1]);
			}
			i++;
		}

		todoOk=1;
	}
	return todoOk;
}




int pedirEntero(int* entero, char* mensaje, char* mensajeError, int min, int max)
{
	int retorno = -1;
	char auxEntero[150];

	if(entero != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxEntero);


		while( validarNumeros(auxEntero)==0 ||  atoi(auxEntero) < min || atoi(auxEntero) > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(auxEntero);

		}
		*entero = atoi(auxEntero);
		retorno = 0;
	}

	return retorno;
}

int pedirFlotante(float* numero, char mensaje[], char mensajeError[], float min, float max)
{
    int todoOk=0;
    float numeroIngresado;

	if(numero!=NULL && mensaje!=NULL && mensajeError!=NULL && min<max)
	{
		printf("%s", mensaje);
		scanf("%f", &numeroIngresado);
		fflush(stdin);

		while(numeroIngresado<min || numeroIngresado>max)
		{
			printf("%s",mensajeError);
			scanf("%f", &numeroIngresado);
			fflush(stdin);
		}

		*numero=numeroIngresado;
		todoOk=1;
	}

	return todoOk;
}

int menu()
{
	char opcion;

	system("cls");
	printf("\n");
	printf("---------------------------------------------------------\n");
	printf("               ***  TALLER LO DE ANTONIO ***                \n");
	printf("----------------------------------------------------------\n");
	printf("     A-ALTA AUTO\n");
	printf("     B-MODIFICAR AUTO\n");
	printf("     C-BAJA AUTO\n");
	printf("     D-LISTAR AUTOS\n");
	printf("     E-LISTAR  MARCAS\n");
	printf("     F-LISTAR COLORES\n");
	printf("     G-LISTAR SERVICIOS\n");
	printf("     H-ALTA TRABAJO\n");
	printf("     I-LISTAR TRABAJOS\n");
	printf("     J-INFORMES\n");
	printf("     K-Salir\n");

	printf("Ingrese opcion: \n");
	fflush(stdin);
	scanf("%c",&opcion);
	opcion=toupper(opcion);
	return opcion;
}

int subMenuInformesIngreso()
{
	int opcion;

	system("cls");
	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("              ***  INFORMES : TALLER LO DE ANTONIO ***              \n");
	printf("--------------------------------------------------------------------\n");
	printf("    1-INFORMES SOBRE AUTOS.\n");
	printf("    2-INFORMES DE TRABAJOS Y SERVICIOS.\n");
	printf("    3-SALIR.\n");

	printf("Seleccione una opcion: \n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}

int subMenuInformes()
{
	int opcion;

	system("cls");
	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("            ***  INFORMES AUTOS: TALLER LO DE ANTONIO ***           \n");
	printf("--------------------------------------------------------------------\n");
	printf("    1-AUTOS POR COLOR.\n");
	printf("    2-AUTOS POR MARCA.\n");
	printf("    3-PROMEDIO POR CAJA DE CAMBIO.\n");
	printf("    4-AUTOS POR TIPO DE CAJA.\n");
	printf("    5-AUTO(S) POR COLOR Y MARCA.\n");
	printf("    6-MARCA(S) MA(S) ELEGIDA(S).\n");
	printf("    7-Salir.\n");

	printf("Seleccione una opcion: \n");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;
}

int subMenuTrabajoServicio()
{
	int opcion;

	system("cls");
	printf("\n");
	printf("--------------------------------------------------------------------\n");
	printf("     ***  INFORMES TRABAJOS/SERVICIOS: TALLER LO DE ANTONIO ***     \n");
	printf("--------------------------------------------------------------------\n");
	printf("    1-TRABAJOS DE UN AUTO.\n");
	printf("    2-TOTAL DE IMPORTES DE UN AUTO.\n");
	printf("    3-AUTOS QUE RECIBIERON UN SERVICIO(CON SU FECHA).\n");
	printf("    4-SERVICIOS REALIZADOS EN LA FECHA.\n");
	printf("    5-Salir.\n");

	printf("Seleccione una opcion: \n");
	fflush(stdin);
	scanf("%d",&opcion);

	return opcion;
}

int menuModificar()
{
	char opcion;
	system("cls");
	printf("--------------------------------------------------------\n");
	printf("              *** MODIFICAR AUTO  ***                 \n");
	printf("---------------------------------------------------------\n");
	printf("A     -MODIFICAR COLOR \n");
	printf("B     -MODIFICAR MODELO \n");
	printf("C     -Salir\n");

	printf("Ingrese opcion: ");
	fflush(stdin);
	scanf("%c",&opcion);
	opcion=toupper(opcion);

	return opcion;
}

int pedirCaracter(char* caracter, char* mensaje, char* mensajeError, char caracterVal1, char caracterVal2)
{
	int todoOk=-1;
	char caracterIngresado;

	if(caracter!=NULL && mensaje!=NULL && mensajeError!=NULL)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&caracterIngresado);
		caracterIngresado=tolower(caracterIngresado);

		while(caracterIngresado!= caracterVal1 && caracterIngresado!=caracterVal2)
		{
			printf("%s",mensajeError);
			fflush(stdin);
			scanf("%c",&caracterIngresado);
			caracterIngresado=tolower(caracterIngresado);
		}
		*caracter=caracterIngresado;
		todoOk=0;
	}
	return todoOk;
}


int validarNumeros(char numeros[])
{
	int todoOk=1;
	if(strlen(numeros) > 0)
		{
			for(int i = 0;i< strlen(numeros);i++)
			{
				if(isdigit(numeros[i]) == 0)
				{
					if(i == 0 && numeros[0] == '-')
					{
	                    todoOk = 1;
					}
					else
					{
						todoOk =0;
					}
				}
			}
		}
	    else
	    {
	        todoOk=0;
	    }
	return todoOk;
}
