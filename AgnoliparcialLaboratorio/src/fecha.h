#ifndef FECHA_H_
#define FECHA_H_

struct
{
	int dia;
	int mes;
	int anio;
}typedef eFecha;

#endif /* FECHA_H_ */

/**
 * @fn int validarFecha(eFecha*)
 * @brief Recibe una fecha y valida que sea correcta.
 *
 * @param fecha puntero de la estructura eFecha.
 * @return todoOk(-1) si hay error. todoOk(0) Si no hay error.
 */
int validarFecha(eFecha* fecha);
