#ifndef GIANLUCA_H_INCLUDED
#define GIANLUCA_H_INCLUDED



#endif // GIANLUCA_H_INCLUDED

/** \brief muestra el menu de opciones
 *
 * \param flag1 int recibe el valor de la bandera 1
 * \param flag2 int recibe el valor de la bandera 2
 * \param num1 int recibe el valor del primer numero
 * \param num2 int recibe el valor del segundo numero
 * \return int devuelve la opcion seleccionada
 *
 */
int menu(int flag1, int flag2, int num1, int num2);

/** \brief realiza una suma entre dos numeros
 *
 * \param a int recibe el primer numero
 * \param b int recibe el segundo numero
 * \return int devuelve el resultado de la suma
 *
 */
int suma(int a, int b);

/** \brief realiza una resta entre dos numeros
 *
 * \param a int recibe el primer numero
 * \param b int recibe el segundo numero
 * \return int devuelve el resultado de la resta
 *
 */
int resta (int a, int b);

/** \brief realiza una multiplicacion entre dos numeros
 *
 * \param int a recibe el primer numero
 * \param int b recibe el segundo numero
 * \return int devuelve el resultado de la multiplicacion
 *
 */
int multiplicacion (int a, int b);

/** \brief realiza una division entre dos numeros
 *
 * \param int a recibe el primer numero
 * \param int b recibe el segundo numero
 * \param float *c carga el resultado de la division en la variable correspondiente
 * \return int devuelve 1 si se pudo realizar la division o 0 si no fue posible
 *
 */
float division (int a, int b, float *c);

/** \brief calcula el factorial de un numero
 *
 * \param n int recibe el numero
 * \return int devuelve el resultado del factorial
 *
 */
int factorial(int n);

