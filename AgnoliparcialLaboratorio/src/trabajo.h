#include "auto.h"
#include "fecha.h"
#include "servicio.h"
#ifndef TRABAJO_H_
#define TRABAJO_H_

struct{
	int id;
	int patente;
	int idServicio;
	eFecha fecha;
	int isEmpty;
}typedef eTrabajo;

#endif /* TRABAJO_H_ */


/**
 * @fn void mostrarTrabajo(eTrabajo, eAut[], int, eMarca[], int, eColor[], int, eServicio[], int)
 * @brief Muestra los datos de los trabajos recibidos.
 *
 * @param unTrabajo de la estructura trabajo.
 * @param autos vector de la estructura eAut.
 * @param tamAuto tamaño del array a mostrar.
 * @param marca vector de la estrucutra marca.
 * @param tamMarca tamaño del array a mostrar.
 * @param colores vector de la estructura eColor.
 * @param tamColor tamaño del array a mostrar.
 * @param servicio vector de la estructura eServicio.
 * @param tamServicio tamaño del array a mostrar.
 */
void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio);

/**
 * @fn int iniciarTrabajos(eTrabajo*, int)
 * @brief inicializa todos los campos isEmpty en 1.
 *
 * @param trabajos vector de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array a mostrar.
 * @return todoOk(-1) si hay error. todoOk(0) si no hay error.
 */
int iniciarTrabajos(eTrabajo* trabajos,int tamTrabajo);

/**
 * @fn int buscarTrabajoLibre(eTrabajo*, int)
 * @brief compara los campos isEmpty, y si es igual a 1 retorna el indice libre.
 *
 * @param trabajos vector de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array a mostrar.
 * @return todoOk(-1) si hay error. todoOk(0) Si no hay error.
 */
int buscarTrabajoLibre(eTrabajo* trabajos,int tamTrabajo);

/**
 * @fn int altaTrabajo(eTrabajo*, int, int*, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Pide los datos al usuario e incorpora los datos al listado de trabajos.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array a mostrar.
 * @param id puntero a entero, guarda el valor de la id.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del array de la estructura eServicio.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del array de la estructura eMarca.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array de la estructura eColor.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del array de la estructura eAut.
 * @return libre(-1) si no existe. libre(i) retorna la posicion del indice existente.
 */
int altaTrabajo(eTrabajo* trabajos,int tamTrabajo,int* id,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**´
 * @fn void mostrarTrabajo(eTrabajo, eAut[], int, eMarca[], int, eColor[], int, eServicio[], int)
 * @brief Muestra los datos recibidos de alta trabajo.
 *
 * @param unTrabajo variable de la estructura eTrabajo.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del array de la estructura eAut.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del array de la estructura eMarca.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array de la estructura eColor.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del array de la estructura eServicio.
 */
void mostrarTrabajo(eTrabajo unTrabajo,eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eServicio servicio[],int tamServicio);

/**
 * @fn int imprimirTrabajos(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Muestra todos los datos recibididos en alta trabajo.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array de la estructura eAut.
 * @param servicio tamaño del array de la estructura eServicio.
 * @param tamServicio tamaño del array de la estructura eServicio.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del array de la estructura eMarca.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array de la estructura eColor.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del array de la estructura eAut.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int imprimirTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);


/**
 * @fn int permitirIngresoTrabajo(eTrabajo[], int, int*)
 * @brief No permite ingresar a las ultimas opciones del menu, sin antes haber ingresado un auto.
 *
 * @param trabajo array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array de la estructura eAut.
 * @param flag puntero a entero, guarda 0/1.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int permitirIngresoTrabajo(eTrabajo trabajo[], int tamTrabajo,int* flag);

/**
 * @fn int encontrarTrabajoId(eTrabajo[], int, int)
 * @brief Compara id ingresda, y valida que este dentro de los trabajos ya ingresados.
 *
 * @param trabajo array de la estructura eTrabajo.
 * @param iD id a validar.
 * @param tamTrabajo tamaño del array de la estructura eTrabajo.
 * @return libre(-1) si no existe. libre(i) retorna la posicion del indice existente.
 */
int encontrarTrabajoId(eTrabajo trabajo[],int iD,int tamTrabajo);

/**
 * @fn int informeTrabajo(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Despliega una serie de opciones referia a los informes sobre trabajos.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del array de la estructura eTrabajo.
 * @param servicio tamaño del array de la estructura eServicio.
 * @param tamServicio tamaño del array de la estructura eServicio.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del array de la estructura eMarca.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array de la estructura eColor.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del array de la estructura eAut.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int informeTrabajo(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**
 * @fn int mostrarTrabajosAuto(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Pide al usuario seleccionar un auto. Luego, muestra todos los trabajos realizados en el mismo.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del vector a mostrar.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio  tamaño del vector a mostrar.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int mostrarTrabajosAuto(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**
 * @fn int pedirImporteAuto(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Pide al usuario seleccionar un auto. Luego, se muestra la suma de importes del mismo.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del vector a mostrar.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del vector a mostrar.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor  tamaño del vector a mostrar.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int pedirImporteAuto(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**
 * @fn int autoServicioFecha(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del vector a mostrar.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del vector a mostrar.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int autoServicioFecha(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);

/**
 * @fn int pedirFechaTrabajos(eTrabajo[], int, eServicio[], int, eMarca[], int, eColor[], int, eAut[], int)
 * @brief Pide al usuario seleccionar un servicio. Luego, muestra el servicio realizado junto a su fecha.
 *
 * @param trabajos array de la estructura eTrabajo.
 * @param tamTrabajo tamaño del vector a mostrar.
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del vector a mostrar.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return todoOk(0) Si hay error. TodoOk(1) Si no hay error.
 */
int pedirFechaTrabajos(eTrabajo trabajos[],int tamTrabajo,eServicio servicio[],int tamServicio,eMarca marca[],int tamMarca,eColor colores[],int tamColor,eAut autos[],int tamAuto);


