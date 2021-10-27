#include "dataWarehouse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int idMarca[10]={1002,1003,1004,1000,1001,1003,1002,1004,1000,1002};

int idColor[10]={5000, 5002, 5003, 5004, 5001, 5002, 5003, 5001, 5002, 5001};

char caja[10]={'a','m','m','a','m','a','m','m','a','m'};

//TRABAJO
int idAuto[10]={1,8,4,6,5,4,4,6,5,4};

int idServ[10]={20001,20003,20002,20001,20000,20003,20002,20001,20002,20003};

eFecha fecha[10]={
			{15,7,2021},
			{18,6,2020},
			{9,5,2019},
			{2,2,2020},
			{20,3,2021},
			{21,1,2021},
			{30,6,2020},
			{9,12,2019},
			{16,6,2019},
			{15,4,2020},
	};

int hardcodearAutos(eAut autos[], int tamAuto, int cant, int* pId)
{
	int contador=-1;

	if(autos!=NULL && tamAuto>0 && cant>=0 && cant <=tamAuto && pId!=NULL)
	{
		contador=0;

		for(int i=0; i < cant; i++)
		{
			autos[i].id= *pId;
			(*pId)++;
			autos[i].idMarca=idMarca[i];
			autos[i].idColor=idColor[i];
			autos[i].caja=caja[i];
			autos[i].isEmpty=0;
			contador++;
		}
	}
	return contador;
}

int hardcodearTrabajos(eTrabajo trabajo[], int tamTrabajo, int cant, int* pId)
{
	int contador=-1;
	if(trabajo!=NULL && tamTrabajo>0 && cant>=0 && cant <=tamTrabajo && pId!=NULL)
	{
		for(int i=0; i < cant; i++)
		{
			trabajo[i].id= *pId;
			(*pId)++;
			trabajo[i].patente=idAuto[i];
			trabajo[i].idServicio=idServ[i];
			trabajo[i].fecha=fecha[i];
			trabajo[i].isEmpty=0;
			contador++;

		}
	}
	return contador;
}
