#ifndef SERVICIOS_H_
#define SERVICIOS_H_

struct{
	int id;
	char descripcionServicio[20];
	int precio;
}typedef eServicio;

#endif /* SERVICIOS_H_ */

/**
 * @fn int cargarDescripcionServicio(eServicio[], int, int, char[])
 * @brief carga la descipcion del nombre del servicio, segun la id.
 *
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del array a mostrar.
 * @param iServicio entero que guarda la id del servicio en llamada.
 * @param descripcionServicio vector de caracteres que carga el nobmre del servicio.
 * @return todoOk(0) Si hay error. todoOk(1) si no hay error.
 */
int cargarDescripcionServicio(eServicio servicio[],int tamServicio, int iServicio, char descripcionServicio[]);

/**
 * @fn int mostrarServicios(eServicio[], int)
 * @brief muestra la categoria de servicios.
 *
 * @param servicio array de la estructura eServicio.
 * @param tamServicio tamaño del array a mostrar.
 * @return todoOk(0) Si hay error. todoOk(1) si no hay error.
 */
int mostrarServicios(eServicio servicio[],int tamServicio);

/**
 * @fn int encontrarServicioId(eServicio[], int, int)
 * @brief compara el id ingresado en la llamada a la función, para ver si es compatible con un id de servicio existente.
 *
 * @param servicio array de la estructura eServicio.
 * @param iD id ingresada en llamada a la funcion.
 * @param tamServicio tamaño del array a mostrar.
 * @return libre(-1) si no existe. libre(i) retorna la posicion del indice existente.
 */
int encontrarServicioId(eServicio servicio[],int iD,int tamServicio);
