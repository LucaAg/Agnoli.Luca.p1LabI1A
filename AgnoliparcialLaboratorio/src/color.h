#ifndef COLOR_H_
#define COLOR_H_

struct{
	int id;
	char descripcionColor[20];
}typedef eColor;

#endif /* COLOR_H_ */

/**
 * @fn int cargarDescripcionColor(eColor[], int, int, char[])
 * @brief Carga los datos del array char descripcion, reemplazando el entero id, según el id ingresado por el usuario(el cual sea un id existente).
 *
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array a mostrar.
 * @param idColor entero id, que recibe la funcion en llamada.
 * @param descripcionColor vector de caracteres que carga la descripcion segun la id.
 * @return todoOk(0) si hay error. todoOk(1) Si no hay error.
 */
int cargarDescripcionColor(eColor colores[],int tamColor, int idColor, char descripcionColor[]);

/**
 * @fn int mostrarColores(eColor[], int)
 * @brief Muestra los datos de los colores presentes.
 *
 * @param colores array de la estructura eColor.
 * @param tamColor tamaño del array a mostrar.
 * @return todoOk(0) si hay error. todoOk(1) Si no hay error.
 */
int mostrarColores(eColor colores[],int tamColor);
