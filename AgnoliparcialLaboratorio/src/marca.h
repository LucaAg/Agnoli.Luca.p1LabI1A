#ifndef SECTOR_H_
#define SECTOR_H_

typedef struct
{
	int id;
	char descripcionMarca[20];
}eMarca;

#endif  /* SECTOR_H_ */

/**
 * @fn int cargarDescripcionMarca(eMarca[], int, int, char[])
 * @brief Iguala un id existente(isEmpty=0), ingresado por el usuario, con un vector de char ,y muestra su nombre segun id.
 *
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @param idMarca
 * @param descripcionMarca
 * @return todoOk(-1) si hay error. todoOk(0) Si no hay error.
 */
int cargarDescripcionMarca(eMarca marcas[],int tamMarca, int idMarca, char descripcionMarca[]);

/**
 * @fn int mostrarMarcas(eMarca[], int)
 * @brief Muestra los datos de las marcas.
 *
 * @param marcas array de la estructura eMarca.
 * @param tamMarca tamaño del vector a mostrar.
 * @return todoOk(-1) si hay error. todoOk(0) Si no hay error.
 */
int mostrarMarcas(eMarca marcas[],int tamMarca);

