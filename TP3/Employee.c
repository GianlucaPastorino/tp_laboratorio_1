#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre, "");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee = employee_new();

    if(newEmployee!=NULL)
    {
        if(!(employee_setId(newEmployee, atoi(idStr)) &&
                employee_setNombre(newEmployee, nombreStr) &&
                employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr)) &&
                employee_setSueldo(newEmployee, atoi(sueldoStr))))
        {
            employee_delete(newEmployee);
            newEmployee = NULL;
        }
    }
    return newEmployee;
}

void employee_delete(Employee* p)
{
    free(p);
}

int employee_setId(Employee* this,int id)
{
    int ok =0;
    if(this!=NULL && id > 0)
    {
        this->id = id;
        ok=1;
    }
    return ok;
}
int employee_getId(Employee* this,int* id)
{
    int ok =0;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        ok =1;
    }
    return ok;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int ok =0;
    if(this != NULL && nombre != NULL && strlen(nombre)<128)
    {
        strcpy(this->nombre, nombre);
        ok=1;
    }
    return ok;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int ok =0;
    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        ok =1;
    }
    return ok;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int ok = 0;
    if(this!= NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        ok=1;
    }
    return ok;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ok =0;
    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        ok =1;
    }
    return ok;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int ok =0;
    if(this!= NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        ok=1;
    }
    return ok;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int ok =0;
    if(this!= NULL)
    {
        *sueldo = this->sueldo;
        ok=1;
    }
    return ok;
}

int employee_nextId(LinkedList* list, int* nextId)
{
    int ok = 0;
    int max=0;
    Employee* aux = NULL;

    if(list != NULL)
    {
        for(int i = 0; i<ll_len(list); i++)
        {
            aux = (Employee*) ll_get(list, i);
            if(i == 0 || aux->id > max)
            {
                max = aux->id;
            }
        }
        *nextId = max+1;
        ok = 1;
    }
    return ok;
}

int employee_findEmpById(LinkedList* list,int id)
{
    int index = -1;
    int auxId;
    Employee* aux = NULL;

    if(list != NULL && id > 0)
    {
        for(int i = 0; i < ll_len(list); i++)
        {
            aux = ll_get(list, i);
            employee_getId(aux, &auxId);
            if(id == auxId)
            {
                index = i;
                break;
            }
        }
    }
    return index;
}

int menu()
{
    int opcion;

    system ("cls");
    printf("**********EMPLEADOS**********\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir\n\n");

    printf("Ingrese opcion (1-10): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuModificar()
{
    int opcion;

    printf("****MODIFICAR****\n\n");
    printf("1. Nombre\n");
    printf("2. Horas trabajadas\n");
    printf("3. Sueldo\n");
    printf("4. Volver al menu inicial\n\n");

    printf("Ingrese opcion (1-4): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuSort()
{
    int option;

    printf("*****ORDENAR EMPLEADOS*****\n\n");
    printf("1. Id\n");
    printf("2. Nombre\n");
    printf("3. Horas Trabajadas\n");
    printf("4. Sueldo\n");
    printf("5. Volver al menu inicial\n\n");

    printf("Ingrese opcion (1-5): ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int employee_cmpIds(void* id1, void* id2)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;
    if(id1 != NULL && id2 != NULL)
    {
        emp1 = (Employee*) id1;
        emp2 = (Employee*) id2;
        if(emp1->id > emp2->id)
        {
            retorno = 1;
        }
        else
        {
            if(emp1->id < emp2->id)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

int employee_cmpNombres(void* nombre1, void* nombre2)
{
    int retorno = -2;
    Employee* emp1;
    Employee* emp2;
    if(nombre1 != NULL && nombre2 != NULL)
    {
        emp1 = (Employee*) nombre1;
        emp2 = (Employee*) nombre2;
        retorno = strcmp(emp1->nombre,emp2->nombre);
    }
    return retorno;
}

int employee_cmpHorasTrabajadas(void* horas1, void* horas2)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;
    if(horas1 != NULL && horas2 != NULL)
    {
        emp1 = (Employee*) horas1;
        emp2 = (Employee*) horas2;
        if(emp1->horasTrabajadas > emp2->horasTrabajadas)
        {
            retorno = 1;
        }
        else
        {
            if(emp1->horasTrabajadas < emp2->horasTrabajadas)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}

int employee_cmpSueldos(void* sueldo1, void* sueldo2)
{
    int retorno = 0;
    Employee* emp1;
    Employee* emp2;
    if(sueldo1 != NULL && sueldo2 != NULL)
    {
        emp1 = (Employee*) sueldo1;
        emp2 = (Employee*) sueldo2;
        if(emp1->sueldo > emp2->sueldo)
        {
            retorno = 1;
        }
        else
        {
            if(emp1->sueldo < emp2->sueldo)
            {
                retorno = -1;
            }
        }
    }
    return retorno;
}
