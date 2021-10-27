#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int validarFecha(eFecha* fecha)
{
    int todoOk=-1;

    printf("\nIngrese la fecha (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
    fflush(stdin);

    while(todoOk==-1)
    {
        if(fecha->anio>=1950 && fecha->anio<=2021)
        {
            if(fecha->mes>=1 && fecha->mes<=12)
            {
                switch(fecha->mes)
                {
                    case 1:
                    case 3:
                    case 5:
                    case 7:
                    case 8:
                    case 10:
                    case 12:
                        if(fecha->dia<1 || fecha->dia>31)
                        {
                            printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            fflush(stdin);
                        }
                        else
                        {
                            todoOk=0;
                        }
                        break;
                    case 4:
                    case 6:
                    case 9:
                    case 11:
                        if(fecha->dia<1 || fecha->dia>30)
                        {
                            printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                            fflush(stdin);
                        }
                        else
                        {
                            todoOk=0;
                        }
                        break;
                    case 2:
                        if(fecha->anio%4==0 || (fecha->anio%100!=0 && fecha->anio%400==0))
                        {
                            if(fecha->dia<1 || fecha->dia>29)
                            {
                               printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                                fflush(stdin);
                            }
                            else
                            {
                                todoOk=0;
                            }
                        }
                        else
                        {
                            if(fecha->dia<1 || fecha->dia>28)
                            {
                               printf("Dia invalido para el mes %0d. Ingrese la fecha (DD/MM/AAAA): ", fecha->mes);
                                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                                fflush(stdin);
                            }
                            else
                            {
                                todoOk=0;
                            }
                        }
                        break;
                }
            }
            else
            {
                printf("Mes invalido. Ingrese la fecha (DD/MM/AAAA): ");
                scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
                fflush(stdin);
            }
        }
        else
        {
            printf("A�o invalido. Ingrese la fecha (DD/MM/AAAA): ");
            scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
            fflush(stdin);
        }
    }
    return todoOk;
}


