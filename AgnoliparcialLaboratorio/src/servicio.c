#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cargarDescripcionServicio(eServicio servicio[],int tamServicio, int iServicio, char descripcionServicio[])
{
	int todoOk=0;
	if(servicio!=NULL && tamServicio>0 && descripcionServicio!=NULL)
	{
		for(int i=0;i<tamServicio;i++)
		{
			if(servicio[i].id==iServicio)
			{
				strcpy(descripcionServicio, servicio[i].descripcionServicio);
				break;
			}
		}
		todoOk=1;
	}

	return todoOk;

}

int mostrarServicios(eServicio servicio[],int tamServicio)
{
	int todoOk=0;
	if(servicio!=NULL && tamServicio>0)
	{
		printf("--------------------------------------\n");
		printf("            ***SERVICIOS***           \n");
		printf("-------------------------------------\n");
		printf(" ID    |    DESCRIPCIÓN     |  PRECIO\n");
		printf("-------------------------------------\n");
		for(int i=0;i<tamServicio;i++)
		{
			printf("%-7d%-21s %-5d\n",servicio[i].id,servicio[i].descripcionServicio,servicio[i].precio);
		}
		todoOk=1;
	}


	return todoOk;
}


int encontrarServicioId(eServicio servicio[],int iD,int tamServicio)
{
	int indice=-1;

	if(servicio!=NULL && tamServicio >0)
	{
		for(int i=0;i<tamServicio;i++)
		{
			if(servicio[i].id==iD)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}
