#include "marca.h"
#include "color.h"
#ifndef PRINCIPAL_H_
#define PRINCIPAL_H_

struct{
	int id;
	int idMarca;
	int idColor;
	char caja;
	int isEmpty;
}typedef eAut;

#endif /* PRINCIPAL_H_ */
/**
 * @fn int iniciarAutos(eAut*, int)
 * @brief Inicicializa la autos en el indice i en 0.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return todoOk(-1) si hay error. todoOk(0) si no hay errores.
 */
int iniciarAutos(eAut* autos,int tamAuto);

/**
 * @fn int buscarautosLibre(eAut[], int)
 * @brief Busca en la autos un indice libre(isEmpty=1).
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @return libre(-1) si ha error. Libre(indice libre) si no hay errores.
 */
int buscarAutosLibre(eAut autos[],int tamAuto);

/**
 * @fn int altaAuto(eAut[], int, int*, eMarca[], int, eColor[], int)
 * @brief Da de alta un auto en el indice libre.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param id id puntero a entero, almacena un id, y luego lo incrementa en main(pasaje por referencia).
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @return todoOk(-1) si hay error. todoOk(0) si no hay errores.
 */
int altaAuto(eAut autos[],int tamAuto,int* id,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn void mostrarAuto(eAut, eMarca[], int, eColor[], int)
 * @brief Muestra un auto junto a todos sus datos.
 *
 * @param unAuto variable de la estructura eAut.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 */
void mostrarAuto(eAut unAuto,eMarca marcas[],int tamAuto,eColor colores[],int tamColor);


/**
 * @fn int imprimirAutos(eAut[], int, eMarca[], int, eColor[], int)
 * @brief
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int imprimirAutos(eAut autos[],int tamAuto,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn int encontrarAutoId(eAut[], int, int)
 * @brief Compara el id ingresado en la llamada a la función,y verifica que sea un id existente.
 *
 * @param autos array de la estructura eAut.
 * @param iD variable que guarda el valor del id ingresada en la llamada a la función.
 * @param tamAuto tamaño del vector a mostrar.
 * @return indice(-1) si ha error. Indice(indice libre) si no hay errores.
 */
int encontrarAutoId(eAut autos[],int iD,int tamAuto);

/**
 * @fn int modificarAuto(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Pide al usuario el id del auto que desea modificar. Checkea que ese auto exista. Luego modifica su color o marca.
 *
 * @param autos array de la estructura eAut.
 * @param tamAutos tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int modificarAuto(eAut autos[],int tamAutos,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);


/**
 * @fn int removerAuto(eAut[], int, int, eMarca[], int, eColor[], int)
 * @brief Permite remover permanentemente los datos en el id indicado, del auto seleccionado por el usuario.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param idautos entero que almacena el id ingresado en la llamada a la función.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int removerAuto(eAut autos[],int tamAuto, int idautos ,eMarca marcas[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn int validarAutosId(eAut[], int, int)
 * @brief Verifica que exista el auto en el id indicado
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param idAuto entero que almacena la id ingresada en la llamada.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int validarAutosId(eAut autos[],int tamAuto,int idAuto);


/**
 * @fn int permitirIngreso(autos[], int, int*)
 * @brief Recibe una bandera y la retorna por referencia.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param flag puntero a entero, retorna el valor por referencia.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int permitirIngreso(eAut autos[], int tamAuto,int* flag);

/**
 * @fn int ordenarAutosMarcaxPatente(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Ordena los autos por marca, y en caso de ser iguales por patente.
 *
 * @param autos vector de autos, en la estructura autos.
 * @param tamAuto tamaño de la estructura de autos.
 * @param marca vector de la estructura eMarca.
 * @param tamMarca tamaño de la estructura eMarca.
 * @param colores vector de la estructura eColores.
 * @param tamColor tamaño del a estructura eColor.
 * @return todoOk(-1) si hay un error. todoOk(0) si no hay errores.
 */
int ordenarAutosMarcaxPatente(eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor);

/**
 * @fn int informeAuto(eAut[], int, eMarca[], int, eColor[], int)
 * @brief Despliega un menu de opciones, referida a los informes sobre autos.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param marca array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño de la estructura a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int informeAuto(eAut autos[],int tamAuto,eMarca marca[],int tamMarca,eColor colores[],int tamColor);


/**
 * @fn int mostrarAutosColor(eAut[], int, eColor[], int, eMarca[], int)
 * @brief Pide un color al usuario y muestra los autos del color ingresado.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int mostrarAutosColor(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);

/**
 * @fn int mostrarAutosMarca(eAut[], int, eColor[], int, eMarca[], int)
 * @brief Pide una marca al usuario y muestra los autos de la marca ingresada.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int mostrarAutosMarca(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);

/**
 * @fn int promedioCajaManualxAuto(eAut[], int, eColor[], int, eMarca[], int)
 * @brief Recorre el array de autos en busca de las cantidades de autos con caja automatica o manual. Luego, calcula los promedios.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int promedioCajaManualxAuto(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);

/**
 * @fn int informeAutosPorCaja(eAut[], int, eColor[], int, eMarca[], int)
 * @brief Muestra los autos separados por distintos tipo de caja(automatica/manual).
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int informeAutosPorCaja(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);


/**
 * @fn int inrformeAutoColorMarca(eAut[], int, eColor[], int, eMarca[], int)
 * @brief El usuario ingresa un color y una marca. Luego, cuenta la cantidad de autos con esa marca y color.
 *
 * @param autos array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int inrformeAutoColorMarca(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);

/**
 * @fn int marcaMasElegida(eAut[], int, eColor[], int, eMarca[], int)
 * @brief Muestra la marca mas elegida entre los autos. En caso de igualdad de cantidad, se muestran ambas marcas.
 *
 * @param autos  array de la estructura eAut.
 * @param tamAuto tamaño del vector a mostrar.
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del vector a mostrar.
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) si no hay errores.
 */
int marcaMasElegida(eAut autos[],int tamAuto,eColor colores[],int tamColor, eMarca marcas[], int tamMarca);


