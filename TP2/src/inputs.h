#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED


#endif // INPUTS_H_INCLUDED

/** \brief pide un numero entero y lo valida
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \return void
 *
 */
void getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief
 *
 * \param pResultado float*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo float
 * \param maximo float
 * \return void
 *
 */
void getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo);

/** \brief valida que un array sea de caracteres
 *
 * \param cadena[] char
 * \return int
 *
 */
int arrayLetras(char cadena[]);

/** \brief valida una cadena de caracteres
 *
 * \param cadena[] char
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \return void
 *
 */
void getString(char cadena[], char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief pregunta si desea confirmar
 *
 * \return char
 *
 */
char confirm();
