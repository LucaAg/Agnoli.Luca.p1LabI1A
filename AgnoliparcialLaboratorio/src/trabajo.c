#include "trabajo.h"
#include "input.h"
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "auto.h"

#define MAXS 20
#define TAM_SERVICIO 4

int iniciarTrabajos(eTrabajo* trabajos,int tamTrabajo)
{
	int todoOk=-1;
	if(trabajos!=NULL && tamTrabajo>0)
	{
		for(int i=0; i<tamTrabajo;i++)
		{
			trabajos[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}

int buscarTrabajoLibre(eTrabajo* trabajos,int tamTrabajo)
{
	int libre=-1;
	if(trabajos!=NULL && tamTrabajo > 0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			if(trabajos[i].isEmpty==1)
			{
				libre=i;
				break;
			}
		}
	}
	return libre;
}

int altaTrabajo(eTrabajo* trabajos,int tamTrabajo,int* id,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int indice;
	int todoOk=-1;
	eTrabajo auxTrabajo;

	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		indice=buscarTrabajoLibre(trabajos,tamTrabajo);

		if(indice>=0)
		{
			system("cls");
			printf("*----------------------------------------------------------------------------*\n");
			printf("                            *** ALTA TRABAJO ***                           \n");
			printf("*---------------------------------------------------------------------------*\n");

			auxTrabajo.id=*id;
			(*id)++;
//PATENTE
			imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
			printf("Ingrese el ID del auto: \n");
			scanf("%d",&auxTrabajo.patente);
			while(encontrarAutoId(autos, auxTrabajo.patente, tamAuto)==-1)
			{
				imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
				printf("Error, reingrese el ID del auto: \n");
				fflush(stdin);
				scanf("%d",&auxTrabajo.patente);
			}

//ID SERVICIO
			mostrarServicios(servicio, tamServicio);
			pedirEntero(&auxTrabajo.idServicio,"Ingrese el id del servicio(20000-20003): ","Error al ingresar el ID del servicio. Ingrese el tipo de auto correspondiente(20000-20003): ",servicio[0].id,servicio[tamServicio-1].id);

//FECHA
			validarFecha(&auxTrabajo.fecha);

			auxTrabajo.isEmpty=0;

			trabajos[indice]=auxTrabajo;

			printf("\nAlta exitosa!!\n");
			printf(" IDT|            AUTOS            |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
			printf("----------------------------------------------------------------------\n");
			printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
			printf("------------------------------------------------------------------------\n");
			mostrarTrabajo(trabajos[indice], autos, tamAuto, marca, tamMarca,colores, tamColor, servicio, tamServicio);
		}
		else
		{
			printf("Hubo un error al iniciar el alta!\n");
		}
		todoOk=0;
	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio)
{
	char descServicio[MAXS];
	char descMarca[MAXS];
	char descColor[MAXS];
	int indiceAuto;
	int indiceServ;


	if(autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && servicio!=NULL && tamServicio>0)
	{
		indiceAuto=encontrarAutoId(autos, unTrabajo.patente, tamAuto);
		indiceServ=encontrarServicioId(servicio, unTrabajo.idServicio, tamServicio);


		cargarDescripcionServicio(servicio, tamServicio, unTrabajo.idServicio, descServicio);
		cargarDescripcionMarca(marca, tamMarca, autos[indiceAuto].idMarca, descMarca);
		cargarDescripcionColor(colores, tamColor, autos[indiceAuto].idColor, descColor);

		printf("%-5d%-5d%-11s%-9s%-5c%-8d%-9s%-7d%02d/%02d/%02d\n",
		unTrabajo.id,
		autos[indiceAuto].id,
		descMarca,
		descColor,
		autos[indiceAuto].caja,
		unTrabajo.patente,
		descServicio,
		servicio[indiceServ].precio,
		unTrabajo.fecha.dia,
		unTrabajo.fecha.mes,
		unTrabajo.fecha.anio);
	}

}

int imprimirTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int flag=1;
	int indiceAutoLibre;
	if(trabajos!=NULL && tamTrabajo>0 && autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && servicio!=NULL && tamServicio>0)
	{
		system("cls");
		printf("\n");
		printf(" IDT|               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("----------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------\n");
		for(int i=0;i<tamTrabajo;i++)
		{
			indiceAutoLibre=encontrarAutoId(autos, trabajos[i].patente, tamAuto);
			if(trabajos[i].isEmpty==0 && autos[indiceAutoLibre].isEmpty==0)
			{

				mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca,colores, tamColor, servicio, tamServicio);
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("No hay trabajos para mostrar\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int permitirIngresoTrabajo(eTrabajo trabajo[], int tamTrabajo,int* flag)
{
	int todoOk;

	if(trabajo!=NULL && tamTrabajo>0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			if(trabajo[i].isEmpty==0)
			{
				*flag=0;
				break;
			}
			else
			{
				*flag=1;
			}
		}
		todoOk=1;
	}
	return todoOk;
}

int encontrarTrabajoId(eTrabajo trabajo[],int iD,int tamTrabajo)
{
	int indice=-1;

	if(trabajo!=NULL && tamTrabajo >0)
	{
		for(int i=0;i<tamTrabajo;i++)
		{
			if(trabajo[i].isEmpty==0 && trabajo[i].id==iD)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}


int informeTrabajo(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	char opcion='s';
	if(trabajos!=NULL && tamTrabajo>0 && autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && servicio!=NULL && tamServicio>0)
	{
		do
		{
			system("cls");
			switch(subMenuTrabajoServicio())
			{
				case 1:
					mostrarTrabajosAuto(trabajos, tamTrabajo, servicio, tamServicio, marca, tamMarca, colores, tamColor, autos, tamAuto);
					break;
				case 2:
					pedirImporteAuto(trabajos, tamTrabajo, servicio, tamServicio, marca, tamMarca, colores, tamColor, autos, tamAuto);
					break;
				case 3:
					autoServicioFecha(trabajos, tamTrabajo, servicio, tamServicio, marca, tamMarca, colores, tamColor, autos, tamAuto);
					break;
				case 4:
					pedirFechaTrabajos(trabajos, tamTrabajo, servicio, tamServicio, marca, tamMarca, colores, tamColor, autos, tamAuto);
					break;
				case 5:
					pedirCaracter(&opcion, "Desea continuar(s/n): \n", "Error, ingreso invalido(s/n),Vuelva a intentarlo(s/n): \n", 's', 'n');
					 break;
				default:
					printf("Opcion invalida!\n");
					break;


			}

		}while(opcion=='s');

		todoOk=1;
	}

	return todoOk;

}

int mostrarTrabajosAuto(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int idAuto;
	int indiceAuto;
	int flagEntro=0;
	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
		printf("Ingrese el id del auto, en el cual quiera observar los trabajos realizados: \n");
		scanf("%d",&idAuto);
		while(encontrarAutoId(autos, idAuto, tamAuto)<0)
		{
			imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
			printf("Error, id no valido. Ingrese un id valido: \n");
			fflush(stdin);
			scanf("%d",&idAuto);
		}

		indiceAuto=encontrarAutoId(autos, idAuto, tamAuto);

		system("cls");
		printf("\n");
		printf(" IDT|               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("----------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------*\n");

		for(int i=0;i<tamTrabajo;i++)
		{
			if(autos[indiceAuto].isEmpty==0 && trabajos[i].isEmpty==0 && trabajos[i].patente==autos[indiceAuto].id)
			{
				mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca,colores, tamColor, servicio, tamServicio);
				flagEntro=1;
			}
		}

		if(flagEntro==0)
		{
			printf("El auto seleccionado no ha recibido trabajos. Gracias por usar nuestro servicio.\n");
		}

		todoOk=1;
	}

	return todoOk;
}


int pedirImporteAuto(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int indiceAuto;
	int idAuto;
	int indiceServicio;
	int acumuladorPrecio=0;
	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
		printf("Ingrese el id del auto, en el cual quiera observar los trabajos realizados: \n");
		scanf("%d",&idAuto);
		while(encontrarAutoId(autos, idAuto, tamAuto)<0)
		{
			imprimirAutos(autos, tamAuto, marca, tamMarca, colores, tamColor);
			printf("Error, id no valido. Ingrese un id valido: \n");
			fflush(stdin);
			scanf("%d",&idAuto);
		}

		indiceAuto=encontrarAutoId(autos, idAuto, tamAuto);

		system("cls");
		printf("\n");
		printf(" IDT|               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("----------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------*\n");
		for(int i=0;i<tamTrabajo;i++)
		{
			if(autos[indiceAuto].isEmpty==0 && trabajos[i].isEmpty==0 &&  trabajos[i].patente==autos[indiceAuto].id)
			{
				indiceServicio=encontrarServicioId(servicio, trabajos[i].idServicio, tamServicio);
				acumuladorPrecio+=servicio[indiceServicio].precio;
				mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca, colores, tamColor, servicio, tamServicio);
			}
		}
		printf("\n\n");
		printf("La suma total de los importes que se realizaron en el auto es de %d\n\n",acumuladorPrecio);

		todoOk=1;
	}
	return todoOk;
}


int autoServicioFecha(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int idServicio;
	int flag=0;
	int autoIndice;
	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		mostrarServicios(servicio, tamServicio);
		pedirEntero(&idServicio,"Ingrese el id del servicio(20000-20003): ",
							"Error al ingresar el ID del servicio. Ingrese el tipo de auto correspondiente(20000-20003): ",servicio[0].id,servicio[tamServicio-1].id);


		system("cls");
		printf("\n");
		printf(" IDT|               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("----------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------*\n");

		for(int i=0;i<tamTrabajo;i++)
		{
			autoIndice=encontrarAutoId(autos, trabajos[i].patente, tamAuto);
			if(trabajos[i].isEmpty==0 && autos[autoIndice].isEmpty==0 && trabajos[i].idServicio==idServicio)
			{
				mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca, colores, tamColor, servicio, tamServicio);
				flag=1;
			}

		}
		if(flag==0)
		{
			printf("No hay autos a los que se les haya realizaod este servicio\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int pedirFechaTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto)
{
	int todoOk=0;
	int flagEntra=0;
	eFecha auxFecha;
	int autoIndice;
	char descServicio[20];
	if(trabajos!=NULL && tamTrabajo>0 && servicio!=NULL && tamServicio>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && autos!=NULL && tamAuto>0)
	{
		validarFecha(&auxFecha);
		printf("----------------------------------------------------------------------\n");
		printf("                  SERVICIOS REALIZADOS EN UNA FECHA                  \n");
		printf("----------------------------------------------------------------------\n");

		system("cls");
		printf("\n");
		printf(" IDT|               AUTOS         |PATENTE|SERVICIO|PRECIO|FECHA     | \n");
		printf("------------------------------------------------------------------------\n");
		printf("    | ID |  MARCA   | COLOR  |CAJA|\n");
		printf("------------------------------------------------------------------------*\n");

		for(int i=0;i<tamTrabajo;i++)
		{
			autoIndice=encontrarAutoId(autos, trabajos[i].patente, tamAuto);
			if(trabajos[i].isEmpty==0 && autos[autoIndice].isEmpty==0)
			{

				if(trabajos[i].fecha.dia==auxFecha.dia && trabajos[i].fecha.mes==auxFecha.mes && trabajos[i].fecha.anio==auxFecha.anio)
				{
					mostrarTrabajo(trabajos[i], autos, tamAuto, marca, tamMarca, colores, tamColor, servicio, tamServicio);
					flagEntra=1;
				}
			}

		}
		printf("\nLos servicios realizados en la fecha %02d/%02d/%d fueron: \n",auxFecha.dia,auxFecha.mes,auxFecha.anio);
		for(int i=0;i<tamTrabajo;i++)
		{
			autoIndice=encontrarAutoId(autos, trabajos[i].patente, tamAuto);
			if(trabajos[i].isEmpty==0 && autos[autoIndice].isEmpty==0)
			{
				if(trabajos[i].fecha.dia==auxFecha.dia && trabajos[i].fecha.mes==auxFecha.mes && trabajos[i].fecha.anio==auxFecha.anio)
				{
					cargarDescripcionServicio(servicio, tamServicio, trabajos[i].idServicio, descServicio);
					printf("%s\n",descServicio);
				}
			}
		}
		if(flagEntra==0)
		{
			system("cls");
			printf("\nNo se realizaron servicios en la fecha %02d/%02d/%d !\n",auxFecha.dia,auxFecha.mes,auxFecha.anio);
		}

		todoOk=1;
	}
	return todoOk;
}


