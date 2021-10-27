#include "auto.h"
#include "fecha.h"
#include "trabajo.h"
#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_



#endif /* DATAWAREHOUSE_H_ */

/**
 * @fn int hardcodearAutos(eAut[], int, int, int*)
 * @brief Ingreso forzado de datos a la estructura eAut.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del array a mostrar.
 * @param cant cantidad de datos que se desea ingresar.
 * @param pId puntero a entero que incrementa el id.
 * @return contador(-1) si hay error. Contador(cantidad de entradas) si no hay error.
 */
int hardcodearAutos(eAut autos[], int tamAuto, int cant, int* pId);

/**
 * @fn int hardcodearTrabajos(eTrabajo[], int, int, int*)
 * @brief Ingreso forzado de datos a la estructura eTrabajo.
 *
 * @param trabajo array de la estructura eTrabajo.
 * @param tamTrabajo tamAuto tamaño del array a mostrar.
 * @param cant cantidad de datos que se desea ingresar.
 * @param pId pId puntero a entero que incrementa el id.
 * @return contador(-1) si hay error. Contador(cantidad de entradas) si no hay error.
 */
int hardcodearTrabajos(eTrabajo trabajo[], int tamTrabajo, int cant, int* pId);
