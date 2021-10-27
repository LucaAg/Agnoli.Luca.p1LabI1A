#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cargarDescripcionColor(eColor colores[],int tamColor, int idColor, char descripcionColor[])
{
	int todoOk=0;
	if(colores!=NULL && tamColor>0 && descripcionColor!=NULL)
	{
		for(int i=0;i<tamColor;i++)
		{
			if(colores[i].id==idColor)
			{
				strcpy(descripcionColor, colores[i].descripcionColor);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;

}

int mostrarColores(eColor colores[],int tamColor)
{
	int todoOk=0;
	if(colores!=NULL && tamColor>0)
	{
		printf("--------------------------------------\n");
		printf("        ***COLORES DE AUTOS***        \n");
		printf("--------------------------------------\n");
		printf(" ID |    DESCRIPCIÓN                  \n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamColor;i++)
		{
			printf("%-5d%-20s\n",colores[i].id,colores[i].descripcionColor);
		}
		todoOk=1;
	}


	return todoOk;
}
