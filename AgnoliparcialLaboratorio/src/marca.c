#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marca.h"

int cargarDescripcionMarca(eMarca marcas[],int tamMarca, int idMarca, char descripcionMarca[])
{
	int todoOk=0;
	if(marcas!=NULL && tamMarca>0 && descripcionMarca!=NULL)
	{
		for(int i=0;i<tamMarca;i++)
		{
			if(marcas[i].id==idMarca)
			{
				strcpy(descripcionMarca, marcas[i].descripcionMarca);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;

}

int mostrarMarcas(eMarca marcas[],int tamMarca)
{
	int todoOk=0;
	if(marcas!=NULL && tamMarca>0)
	{
		printf("--------------------------------------\n");
		printf("        ***TIPO DE AUTOS***      \n");
		printf("--------------------------------------\n");
		printf(" ID |    DESCRIPCIÓN     \n");
		printf("-------------------------------\n");
		for(int i=0;i<tamMarca;i++)
		{
			printf("%-5d%-20s\n",marcas[i].id,marcas[i].descripcionMarca);
		}
		todoOk=1;
	}
	return todoOk;
}

