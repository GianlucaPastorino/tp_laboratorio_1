#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "inputs.h"
#include "parser.h"
#include "Controller.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    char respuesta;

    FILE* f = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"r");
        if(f != NULL)
        {
            if(ll_len(pArrayListEmployee) > 0)
            {
                printf("Hay empleados en la lista y los va a sobrescribir.\n");
                respuesta = confirm();
            }
            if(ll_len(pArrayListEmployee) == 0 || respuesta == 's')
            {
                ll_clear(pArrayListEmployee);
                if(parser_EmployeeFromText(f, pArrayListEmployee))
                {
                    ok = 1;
                }
            }
        }
        fclose(f);
    }

    return ok;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    char respuesta;

    FILE* f = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path,"rb");
        if(f != NULL)
        {
            if(ll_len(pArrayListEmployee) > 0)
            {
                printf("Hay empleados en la lista y los va a sobrescribir. ");
                respuesta = confirm();
            }
            if(ll_len(pArrayListEmployee) == 0 || respuesta == 's')
            {
                ll_clear(pArrayListEmployee);
                if(parser_EmployeeFromBinary(f, pArrayListEmployee))
                {
                    ok = 1;
                }
            }
        }
        fclose(f);
    }

    return ok;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int nextId = 0;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int ok = 0;
    Employee* newEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
        printf("*****ALTA EMPLEADO*****\n\n");
        employee_nextId(pArrayListEmployee, &nextId);
        newEmployee = employee_new();

        getString(nombre, "Ingrese nombre: ", "Error. ", 128);
        getInt(&horasTrabajadas, "Ingrese horas trabajadas: ", "Error. ", 0, 40000);
        getInt(&sueldo, "Ingrese sueldo: ", "Error. ", 1, 1000000000);

        if(employee_setId(newEmployee, nextId) &&
                employee_setNombre(newEmployee, nombre) &&
                employee_setHorasTrabajadas(newEmployee, horasTrabajadas) &&
                employee_setSueldo(newEmployee, sueldo))
        {
            ll_add(pArrayListEmployee, newEmployee);
            ok = 1;
        }
    }

    return ok;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int id;
    int index;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    char salir = 'n';
    Employee* emp;

    if(pArrayListEmployee!=NULL)
    {
        printf("*****MODIFICAR EMPLEADO*****\n\n");
        controller_ListEmployee(pArrayListEmployee);
        getInt(&id, "Ingrese el id del empleado a modificar: ", "Error. ", 0, 10000000);
        printf("\n");
        index = employee_findEmpById(pArrayListEmployee, id);

        if(index != -1)
        {
            printf("El empleado a editar es el #%d.\n", id);

            if(confirm() == 's')
            {
                emp = (Employee*) ll_get(pArrayListEmployee, index);
                do
                {
                    system("cls");
                    if(employee_getNombre(emp, nombre) &&
                            employee_getHorasTrabajadas(emp, &horasTrabajadas) &&
                            employee_getSueldo(emp, &sueldo))
                    {
                        printf("Id     Nombre      Horas     Sueldo\n");
                        printf("%4d    %-10s   %3d  %8d\n\n", id, nombre, horasTrabajadas, sueldo);
                    }

                    switch(menuModificar())
                    {
                    case 1:
                        getString(nombre, "Ingrese nombre: ", "Error. ", 128);
                        while(!employee_setNombre(emp, nombre))
                        {
                            getString("Error. Ingrese nombre: ", " ", nombre, 128);
                        }
                        ok = 1;
                        system("pause");
                        break;
                    case 2:
                        getInt(&horasTrabajadas, "Ingrese horas trabajadas: ", "Error. ", 0, 40000);
                        while(!employee_setHorasTrabajadas(emp, horasTrabajadas))
                        {
                            getInt(&horasTrabajadas, "Error. Ingrese horas trabajadas: ", " ", 0, 40000);
                        }
                        ok = 1;
                        system("pause");
                        break;
                    case 3:
                        getInt(&sueldo, "Ingrese sueldo: ", "Error. ", 1, 1000000000);
                        while(!employee_setSueldo(emp, sueldo))
                        {
                            getInt(&sueldo, "Error. Ingrese sueldo: ", " ", 1, 1000000000);
                        }
                        ok = 1;
                        system("pause");
                        break;
                    case 4:
                        salir = confirm();
                        break;
                    default:
                        printf("Opcion invalida!!\n");
                        system("pause");
                        break;
                    }

                }
                while(salir == 'n');
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
            }
        }
        else
        {
            printf("El id indicado no existe.\n\n");
        }
    }
    return ok;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int id;
    int index;

    if(pArrayListEmployee != NULL)
    {
        printf("   ****BAJA EMPLEADO****\n\n");
        controller_ListEmployee(pArrayListEmployee);
        getInt(&id, "Ingrese el id del empleado a dar de baja: ", "Error. ", 0, 10000000);
        index = employee_findEmpById(pArrayListEmployee, id);

        if(index != -1)
        {
            printf("El empleado a eliminar es el #%d.\n", id);

            if(confirm() == 's')
            {
                ll_remove(pArrayListEmployee,index);
                ok = 1;
            }
            else
            {
                printf("Baja cancelada.\n\n");
            }
        }
        else
        {
            printf("El id indicado no existe.\n\n");
        }
    }

    return ok;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int ok =0;
    Employee* aux = NULL;

    if(pArrayListEmployee != NULL)
    {
        printf("       *****EMPLEADOS*****\n");
        printf(" ID      Nombre     Horas    Sueldo\n");

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee, i);
            if(employee_getId(aux, &id)
                    && employee_getNombre(aux, nombre)
                    && employee_getHorasTrabajadas(aux, &horasTrabajadas)
                    && employee_getSueldo(aux, &sueldo))
            {
                printf("%04d    %-10s   %3d   %8d\n", id, nombre, horasTrabajadas, sueldo);
            }
        }
        ok = 1;
    }
    printf("\n");
    return ok;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ok = 0;
    int order;
    char salir = 'n';

    if(pArrayListEmployee!=NULL)
    {
        do
        {
            system("cls");
            getInt(&order, "Elija el orden (0 descendiente, 1 ascendente): ", "Error", 0, 1);
            printf("\n");

            switch(menuSort())
            {
            case 1:
                ll_sort(pArrayListEmployee,employee_cmpIds,order);
                ok = 1;
                break;
            case 2:
                ll_sort(pArrayListEmployee,employee_cmpNombres,order);
                ok = 1;
                break;
            case 3:
                ll_sort(pArrayListEmployee,employee_cmpHorasTrabajadas,order);
                ok = 1;
                break;
            case 4:
                ll_sort(pArrayListEmployee,employee_cmpSueldos,order);
                ok = 1;
                break;
            case 5:
                salir = confirm();
                break;
            }

            if(ok)
            {
                system("cls");
                printf("     ****Lista ordenada****\n\n");
                controller_ListEmployee(pArrayListEmployee);
                system("pause");
            }
        }
        while(salir != 's');
    }

    return ok;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    char respuesta = 's';
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    FILE* f = NULL;
    Employee* auxEmp = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            printf("El archivo existe y se va a sobreescribir.\n");
            respuesta = confirm();
        }
        fclose(f);

        if(respuesta == 's')
        {
            f = fopen(path, "w");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo.\n\n");
            }
            else
            {
                fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
                for(int i=0; i < ll_len(pArrayListEmployee); i++)
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    if(auxEmp != NULL)
                    {
                        if(employee_getId(auxEmp, &id) &&
                                employee_getNombre(auxEmp, nombre) &&
                                employee_getHorasTrabajadas(auxEmp, &horas) &&
                                employee_getSueldo(auxEmp, &sueldo))
                        {
                            fprintf(f, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
                        }
                    }
                }
                fclose(f);
                ok = 1;
            }
        }
    }
    return ok;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    char respuesta = 's';
    Employee* auxEmp;
    FILE* f = NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        f = fopen(path, "rb");
        if(f != NULL)
        {
            printf("El archivo existe y se va a sobreescribir.\n");
            respuesta = confirm();
        }
        fclose(f);

        if(respuesta == 's')
        {
            f = fopen(path, "wb");
            if(f == NULL)
            {
                printf("No se pudo abrir el archivo.\n\n");
            }
            else
            {
                for(int i=0; i< ll_len(pArrayListEmployee); i++)
                {
                    auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
                    fwrite(auxEmp, sizeof(Employee),1, f);
                }
                ok = 1;
            }
            fclose(f);
        }
    }
    return ok;
}

