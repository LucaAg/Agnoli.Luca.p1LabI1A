#include "auto.h"
#include "color.h"
#include "marca.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXS 20

int iniciarAutos(eAut* autos,int tamAuto)
{
	int todoOk=-1;
	if(autos!=NULL && tamAuto>0)
	{
		for(int i=0; i<tamAuto;i++)
		{
			autos[i].isEmpty=1;
		}
		todoOk=0;
	}
	return todoOk;
}

int buscarAutosLibre(eAut autos[],int tamAuto)
{
	int libre=-1;
	if(autos!=NULL && tamAuto > 0)
	{
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==1)
			{
				libre=i;
				break;
			}
		}
	}
	return libre;
}


int altaAuto(eAut autos[],int tamAuto,int* id,eMarca marcas[],int tamMarca,eColor colores[],int tamColor)
{
	int indice;
	int todoOk=-1;
	eAut auxAuto;

	if(autos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{
		indice=buscarAutosLibre(autos,tamAuto);
		//REFACTORIZAR
		if(indice>=0)
		{
			system("cls");
			printf("*-----------------------------------------------------------------------*\n");
			printf("                            *** ALTA AUTOS ***                          \n");
			printf("*-----------------------------------------------------------------------*\n");

			auxAuto.id=*id;
			(*id)++;
//ID MARCA
			mostrarMarcas(marcas, tamMarca);
			pedirEntero(&auxAuto.idMarca, "Ingrese el id de la marcada deseada(1000-1004): \n", "Error, id no valido, vuelva a ingresarlo(1000-1004): \n", 1000, 1004);

//ID COLOR
			mostrarColores(colores, tamColor);
			pedirEntero(&auxAuto.idColor, "Ingrese el id del color que desee para su auto(5000-5004): \n", "Error, id no valido. Vuelva a ingresarlo(5000-5004): \n", 5000, 5004);

//CAJA CAMBIOS
			pedirCaracter(&auxAuto.caja, "Ingrese si desea una caja manual(a) o automatica(m): ", "Error, caja no valida(a/m), vuelva a ingresarlo: \n", 'a', 'm');

            auxAuto.isEmpty=0;

            autos[indice]=auxAuto;

			printf("Alta exitosa!\n");
		}
		else
		{
			printf("Hubo un error al iniciar el alta!\n");
		}
		todoOk=0;

	}
	return todoOk;
}

void mostrarAuto(eAut unAuto,eMarca marcas[],int tamAuto,eColor colores[],int tamColor)
{
	char descMarca[MAXS];
	char descColor[MAXS];
	cargarDescripcionColor(colores, tamColor, unAuto.idColor, descColor);
	cargarDescripcionMarca(marcas, tamAuto, unAuto.idMarca, descMarca);

	printf("%-5d%-15s%-7s %-3c \n",
			unAuto.id,
			descMarca,
			descColor,
			unAuto.caja);
}


int validarAutosId(eAut autos[],int tamAuto,int idAutos)
{
	int todoOk=0;
	if(autos!=NULL && tamAuto>0)
	{
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].id ==idAutos)
			{
				todoOk=1;
			}
		}
	}
	return todoOk;
}

int imprimirAutos(eAut autos[],int tamAuto,eMarca marcas[],int tamMarca,eColor colores[],int tamColor)
{
	int todoOk=0;
	int flag=1;
	if(autos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{
		system("cls");
		printf("*-------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0)
			{
				mostrarAuto(autos[i],marcas,tamMarca,colores,tamColor);
				flag=0;
			}
		}
		if(flag==1)
		{
			printf("No hay autos para mostrar\n");
		}
		todoOk=1;
	}
	return todoOk;
}

int encontrarAutoId(eAut autos[],int iD,int tamAuto)
{
	int indice=-1;

	if(autos!=NULL && tamAuto >0)
	{
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].id==iD)
			{
				indice=i;
				break;
			}
		}
	}
	return indice;
}

int modificarAuto(eAut autos[],int tamAutos,eMarca marcas[],int tamMarca,eColor colores[],int tamColor)
{
	int todoOk=0;
	int indice;
	int tomarId;
	char respuesta;
	eAut auxAuto;

	if(autos!=NULL && tamAutos>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{

		system("cls");
		printf("*------------------------------------------------------------------------------\n");
		printf("                         ***  MODIFICAR AUTOS(S)  ***                          \n\n");
		printf("*------------------------------------------------------------------------------\n\n");

		imprimirAutos(autos,tamAutos,marcas,tamMarca,colores,tamColor);
		printf("\nIngrese el ID del auto que desee modificar: \n");
		scanf("%d",&tomarId);
		indice=encontrarAutoId(autos,tomarId,tamAutos);

		if(indice==-1)
		{
			printf("Error, la persona no se ha inicializado en la lista. \n");
		}
		else
		{
			system("cls");
			printf("*-------------------------------------*\n");
			printf("       ***  MODIFICAR AUTO(S)   ***  \n\n");
			printf("*-------------------------------------*\n\n");
			printf("*------------------------------------*\n");
			printf(" ID |    MARCA     | COLOR  |CAJA|\n");
			printf("--------------------------------------\n");
			mostrarAuto(autos[indice],marcas,tamMarca,colores,tamColor);
			pedirCaracter(&respuesta, "Seguro desea modificar los datos de este auto?(s/n): \n", "Error, vuelva a intentarlo(s/n): \n"
						"Por favor, vuelva a ingresarlo: \n", 's', 'n');


			if(respuesta=='s')
			{
				do
				{
					auxAuto=autos[indice];
					switch(menuModificar())
					{
						case 'A':
							mostrarColores(colores, tamColor);
							pedirEntero(&auxAuto.idColor, "Ingrese el id del color que desee modificar(5000-5004): \n", "Error, id no valido. Vuelva a ingresarlo(5000-50004): \n", 5000, 50004);
							autos[indice].idColor=auxAuto.idColor;
							printf("Modificacion exitosa!\n");
							break;

						case 'B':
							mostrarMarcas(marcas, tamMarca);
							pedirEntero(&auxAuto.idMarca, "Ingrese el id de la marcada que see modificar(1000-1004): \n", "Error, id no valido, vuelva a ingresarlo(1000-1004): \n", 1000, 1004);
							autos[indice].idMarca=auxAuto.idMarca;
							printf("Modificacion exitosa!\n");
							break;

						case 'C':
							pedirCaracter(&respuesta, "Desea continuar?(s/n) \n", "Error opcion no válida(s/n). \n"
													"Por favor, vuelva a ingresarlo(s/n): \n", 's', 'n');
							break;

						default:
							printf("Opción incorrecta, seleccione una opción valida.\n Gracias!\n");
							break;
					}

				}while(respuesta=='s');

			}
			else
			{
				printf("Se ha cancelado la modoficación\n");
			}
		}


		todoOk=1;
	}
	return todoOk;
}

int removerAuto(eAut autos[],int tamAuto, int idautos ,eMarca marcas[],int tamMarca,eColor colores[],int tamColor)
{
	int todoOk=-1;
	int indice;
	char respuesta;

	if(autos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{

		system("cls");
		printf("*---------------------------------------------------------*\n");
		printf("              ***  REMOVER AUTO(S)   ***            \n\n");
		printf("*-------------------------------------------------------*\n\n");

		imprimirAutos(autos,tamAuto,marcas,tamMarca,colores,tamColor);
		printf("\nIngrese el ID del auto a dar de baja: \n");
		scanf("%d",&idautos);
		indice=encontrarAutoId(autos,idautos,tamAuto);

		if(indice==-1)
		{
			printf("Error, el auto no se ha inicializado en la lista. \n");
		}
		else
		{
			system("cls");
			printf("\n");
			printf("*--------------------------------------*\n");
			printf("       *** LISTADO DE AUTOS ***         \n");
			printf("*-------------------------------------*\n");
			printf(" ID |    MARCA     | COLOR  |CAJA|\n");
			printf("--------------------------------------\n");

			mostrarAuto(autos[indice],marcas,tamMarca,colores,tamColor);

			pedirCaracter(&respuesta,"Desea borrar los datos de este auto?(s/n)","Error, debe ingresar s o n. Vuelva a ingresarlo: ",'s','n');

			if(respuesta=='s')
			{

				autos[indice].isEmpty=1;
				printf("Se han removido los datos del auto correctamente!\n"
							"Gracias por usar nuestro sistema!\n");
			}
			else
			{
				printf("No se han removido los datos del auto.\n"
						"Gracias por usar nuestro sistema!\n");
			}
		  }
		todoOk=0;

	}
	return todoOk;
}

int permitirIngreso(eAut autos[], int tamAuto,int* flag)
{
	int todoOk;

	if(autos!=NULL && tamAuto>0)
	{
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0)
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

int ordenarAutosMarcaxPatente(eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor)
{
	eAut auxAuto;
	int todoOk=-1;
	char desc1[20];
	char desc2[20];
	if(autos!=NULL && tamAuto>0 && marca!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
	{
		printf("*----------------------------------------------------------------------------------------*\n");
		printf("                               *** LISTADO DE AUTOS ***                              \n");
		printf("*--------------------------------------------------------------------------------------*\n");
		for(int i=0;i<tamAuto-1;i++)
		{
			for(int j=i+1;j<tamAuto;j++)
			{
				cargarDescripcionMarca(marca, tamMarca, autos[i].idMarca, desc1);
				cargarDescripcionMarca(marca, tamMarca, autos[j].idMarca, desc2);
				if( (strcmp(desc1,desc2)>0) ||
						(strcmp(desc1,desc2)==0 && autos[i].id>autos[j].id) )
					{
						auxAuto=autos[i];
						autos[i]=autos[j];
						autos[j]=auxAuto;
					}
			}
		}
		imprimirAutos(autos,tamAuto,marca,tamMarca,colores,tamColor);
		printf("Ordenamiento exitoso!\n");

		todoOk=0;
	}
	return todoOk;
}

int informeAuto(eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor)
{
	int todoOk=0;
	char opcion='s';
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marca!=NULL && tamMarca>0)
	{
		do
		{
			system("cls");
			switch(subMenuInformes())
			{
				case 1:
					mostrarAutosColor(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 2:
					mostrarAutosMarca(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 3:
					promedioCajaManualxAuto(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 4:
					informeAutosPorCaja(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 5:
					inrformeAutoColorMarca(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 6:
					marcaMasElegida(autos, tamAuto, colores, tamColor, marca, tamMarca);
					break;
				case 7:
					pedirCaracter(&opcion, "Desea continuar(s/n): \n", "Error, ingreso invalido(s/n),Vuelva a intentarlo(s/n): \n", 's', 'n');
					 break;
				default:
					printf("Error, opcion no valida!\n");
					break;
			}

		}while(opcion=='s');
		todoOk=1;
	}

	return todoOk;

}

int mostrarAutosColor(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	int idColor;
	char descripcionColor[20];
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		system("cls");
		mostrarColores(colores, tamColor);
		pedirEntero(&idColor, "Seleccione el color, y a continuación se mostrará los autos con ese tipo de color(5000-5004): \n", "Error, id no valido. Vuelva a ingresarlo(5000-5004): \n", 5000, 5004);
		cargarDescripcionColor(colores, tamColor, idColor, descripcionColor);
		strupr(descripcionColor);
		printf("*--------------------------------------*\n");
		printf("      *** AUTO(S) DE COLOR: %s ***      \n",descripcionColor);
		printf("*-------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].idColor==idColor)
			{
				mostrarAuto(autos[i],marcas,tamMarca,colores,tamColor);
			}
		}
		todoOk=1;
	}
	return todoOk;
}


int mostrarAutosMarca(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	int idMarcaSolicitada;
	char descripcionMarca[20];
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		system("cls");
		mostrarMarcas(marcas, tamMarca);
		pedirEntero(&idMarcaSolicitada, "Seleccione id de la marca deseada, y a continuación se desplegarán los autos con ese tipo de marca(1000-1004): \n", "Error, id no valido. Vuelva a ingresarlo(1000-1004): \n", 1000, 1004);
		cargarDescripcionMarca(marcas, tamMarca, idMarcaSolicitada, descripcionMarca);
		strupr(descripcionMarca);
		printf("*--------------------------------------*\n");
		printf("      *** AUTO(S) DE MARCA: %s ***      \n",descripcionMarca);
		printf("*-------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].idMarca==idMarcaSolicitada)
			{
				mostrarAuto(autos[i],marcas,tamMarca,colores,tamColor);
			}
		}
		todoOk=1;
	}
	return todoOk;
}


int promedioCajaManualxAuto(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	int contadorA=0;
	int contadorM=0;
	int totalContadores=0;
	float promedioA;
	float promedioM;
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		system("cls");

		printf("*-----------------------------------------*\n");
		printf("      *** PROMEDIOS CAJA MANUAL AUTO***      \n");
		printf("*----------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("-----------------------------------------\n");
		imprimirAutos(autos, tamAuto, marcas, tamMarca, colores, tamColor);
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].caja=='a')
			{
				contadorA++;
			}
			else if(autos[i].isEmpty==0 && autos[i].caja=='m')
			{
				contadorM++;
			}
		}
		totalContadores=contadorA+contadorM;

		if(totalContadores>0)
		{
			promedioA = (float)contadorA / totalContadores;
			promedioM = (float)contadorM / totalContadores;
			printf("\nEl promedio de autos con caja automatica(total de %d) es de: %.2f .\n"
					"El promedio de autos con caja manual(total de %d) es de: %.2f\n",contadorA,promedioA,contadorM,promedioM);
		}
		else
		{
			printf("Error al calcular los promedios. Gracias por usar nuestro sistema!\n");
		}


		todoOk=1;
	}

	return todoOk;
}


int informeAutosPorCaja(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		system("cls");
		printf("*--------------------------------------*\n");
		printf("      *** AUTO(S) CAJA: A ***        \n");
		printf("*-------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].caja=='a')
			{
				mostrarAuto(autos[i], marcas, tamAuto, colores, tamColor);
			}

		}
		printf("\n\n");

		printf("*--------------------------------------\n");
		printf("      *** AUTO(S) CAJA: M ***        \n");
		printf("*-------------------------------------\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].caja=='m')
			{
				mostrarAuto(autos[i], marcas, tamAuto, colores, tamColor);

			}
		}
		printf("\n\n");
		todoOk=1;
	}
	return todoOk;
}


int inrformeAutoColorMarca(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	int idColor;
	int idMarca;
	char descripcionColor[20];
	char descripcionMarca[20];
	int contadorMarcaColor=0;
	int hayAutos=0;
	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		mostrarColores(colores, tamColor);
		pedirEntero(&idColor, "Ingrese el id del color que desee(5000-5004): \n",
				"Error, id no valido. Vuelva a ingresarlo(5000-5004): \n", 5000, 5004);
		cargarDescripcionColor(colores, tamColor, idColor, descripcionColor);

		mostrarMarcas(marcas, tamMarca);
		pedirEntero(&idMarca, "Ingrese el id de la marcada que desee(1000-1004): \n",
				"Error, id no valido, vuelva a ingresarlo(1000-1004): \n", 1000, 1004);
		cargarDescripcionMarca(marcas, tamMarca, idMarca, descripcionMarca);

		printf("*--------------------------------------*\n");
		printf("    *** AUTO POR COLOR Y MARCA  ***    \n");
		printf("*-------------------------------------*\n");
		printf(" ID |    MARCA     | COLOR  |CAJA|\n");
		printf("--------------------------------------\n");
		for(int i=0;i<tamAuto;i++)
		{
			if(autos[i].isEmpty==0 && autos[i].idColor==idColor && autos[i].idMarca==idMarca)
			{
				mostrarAuto(autos[i], marcas, tamAuto, colores, tamColor);
				contadorMarcaColor++;
				hayAutos=1;
			}
		}
		printf("\n");
		if(hayAutos==1)
		{
			printf("CANTIDAD DE AUTOS DE COLOR %s Y MARCA %s: %d\n",descripcionColor,descripcionMarca,contadorMarcaColor);
		}
		else
		{
			printf("No hay autos del color %s y marca %s\n",descripcionColor,descripcionMarca);
		}
		todoOk=1;
	}
	return todoOk;
}


int marcaMasElegida(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca)
{
	int todoOk=0;
	int contador[5]={0};
	int marcaMasElegida;

	if(autos!=NULL && tamAuto>0 && colores!=NULL && tamColor>0 && marcas!=NULL && tamMarca>0)
	{
		printf("----------------------------------------------\n");
		printf("   *** MARCA(S) DE AUTO(S) MAS ELEGIDA(S)  ***\n");
		printf("-----------------------------------------------\n");
		for(int i=0;i<tamMarca;i++)
		{
			for(int j=0;j<tamAuto;j++)
			{
				if(autos[i].isEmpty==0 && marcas[i].id==autos[j].idMarca)
				{
					contador[i]++;
				}
			}
		}

		for(int i=0;i<tamMarca;i++)
		{
			if(contador[i]>marcaMasElegida || i==0)
			{
				marcaMasElegida=contador[i];
			}
		}

		printf("La marca mas solicida es: \n");

		for(int i=0;i<tamMarca;i++)
		{
			if(contador[i]==marcaMasElegida)
			{
				printf("%s\n",marcas[i].descripcionMarca);
			}
		}
		printf("\n\n");
		todoOk=1;
	}
	return todoOk;
}
