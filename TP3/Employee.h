#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} Employee;

/** \brief
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief
 *
 * \param p Employee*
 * \return void
 *
 */
void employee_delete(Employee* p);

/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief
 *
 * \param this LinkedList*
 * \param nextId int*
 * \return int
 *
 */
int employee_nextId(LinkedList* this, int* nextId);

/** \brief
 *
 * \param list LinkedList*
 * \param id int
 * \return int
 *
 */
int employee_findEmpById(LinkedList* list,int id);

/** \brief
 *
 * \return int
 *
 */
int menu();

/** \brief
 *
 * \return int
 *
 */
int menuModificar();

/** \brief
 *
 * \return int
 *
 */
int menuSort();

/** \brief
 *
 * \param id1 void*
 * \param id2 void*
 * \return int
 *
 */
int employee_cmpIds(void* id1, void* id2);

/** \brief
 *
 * \param nombre1 void*
 * \param nombre2 void*
 * \return int
 *
 */
int employee_cmpNombres(void* nombre1, void* nombre2);

/** \brief
 *
 * \param horas1 void*
 * \param horas2 void*
 * \return int
 *
 */
int employee_cmpHorasTrabajadas(void* horas1, void* horas2);

/** \brief
 *
 * \param sueldo1 void*
 * \param sueldo2 void*
 * \return int
 *
 */
int employee_cmpSueldos(void* sueldo1, void* sueldo2);


#endif // employee_H_INCLUDED
