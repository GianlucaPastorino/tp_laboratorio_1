#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"

int menu()
{
    int option;

    system("cls");
    printf("**********EMPLEADOS**********\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Informe\n");
    printf("5. Salir\n\n");

    printf("Ingrese opcion (1-5): ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int initEmployees(Employee* list, int len)
{
    int okay = -1;
    if(list!=NULL && len>0)
    {
        for(int i = 0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
        okay=0;
    }
    return okay;
}

int findEmpty(Employee* list, int len)
{
    int index = -1;

    for(int i = 0; i<len; i++)
    {
        if(list[i].isEmpty)
        {
            index=i;
            break;
        }
    }

    return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int ok = -1;
    int index;

    if(list != NULL && len > 0)
    {
        index = findEmpty(list, len);
        if(index != -1)
        {
            list[index].id = id;
            strcpy(list[index].name, name);
            strcpy(list[index].lastName, lastName);
            list[index].salary = salary;
            list[index].sector = sector;
            list[index].isEmpty = 0;
            ok = 0;
        }
    }
    return ok;
}

int getEmployee(Employee* list, int len, int* id)
{
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int ok = 0;

    if(list != NULL && len > 0 && id != NULL)
    {
        system("cls");
        printf("*****ALTA EMPLEADO*****\n\n");
        printf("ID: %d\n", *id);
        getString(name, "Ingrese nombre: ", "Error. ", 2, 51);
        getString(lastName, "Ingrese apellido: ", "Error. ", 2, 51);
        getFloat(&salary, "Ingrese sueldo: ", "Error. ", 1, 100000000);
        printf("Sectores:\n1: Sistemas\n2: Legales\n3: RRHH\n4: Ventas\n5: Contable\n\n");
        getInt(&sector, "Ingrese sector (1-5): ", "Error. ", 1, 5);

        if(!addEmployee(list, len, *id, name, lastName, salary, sector))
        {
            *id+=1;
            ok = 1;
        }
        else
        {
            printf("No se pudo realizar el alta.\n\n");
        }
    }
    else
    {
        printf("Error. No hay mas espacio en el sistema.\n\n");
    }

    return ok;
}

int findEmployeeById(Employee* list, int len,int id)
{
    int index = -1;

    for(int i = 0; i<len; i++)
    {
        if(list[i].id == id && !list[i].isEmpty)
        {
            index=i;
            break;
        }
    }

    return index;
}

int modifyMenu()
{
    int option;

    system ("cls");
    printf("Que desea modificar?\n\n");
    printf("1. Nombre\n");
    printf("2. Apellido\n");
    printf("3. Salario\n");
    printf("4. Sector\n");
    printf("5. Volver al inicio\n");
    printf("\n");
    printf("Ingrese opcion (1-5): ");
    scanf("%d", &option);
    printf("\n");

    return option;
}

int modifyEmployee(Employee* list, int len)
{
    int id;
    int index;
    int exit='n';
    int answer;
    int ok = 0;
    Employee aux;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("Modificar empleado\n\n");
        printEmployees(list, len);
        getInt(&id, "Ingrese el id del empleado a modificar: ", "Error. ", 100, 1100);

        index = findEmployeeById(list, len, id);

        if(index == -1)
        {
            printf("El ID indicado no existe.\n\n");
        }
        else
        {
            printf("El empleado a modificar es:\n");
            printEmployee(list[index]);
            printf("\n");
            answer = confirm();

            if(answer=='s')
            {
                do
                {
                    switch(modifyMenu())
                    {
                    case 1:
                        getString(aux.name, "Ingrese nuevo nombre: ", "Error. ", 2, 51);
                        if(confirm()=='s')
                        {
                            strcpy(list[index].name, aux.name);
                            printf("Nombre modificado exitosamente.\n");
                            ok = 1;
                        }
                        else
                        {
                            printf("Modificacion de nombre cancelada.\n");
                        }
                        break;
                    case 2:
                        getString(aux.lastName, "Ingrese nuevo apellido: ", "Error. ", 2, 51);
                        if(confirm()=='s')
                        {
                            strcpy(list[index].lastName, aux.lastName);
                            printf("Apellido modificado exitosamente.\n");
                            ok = 1;
                        }
                        else
                        {
                            printf("Modificacion de apellido cancelada.\n");
                        }
                        break;
                    case 3:
                        getFloat(&aux.salary, "Ingrese nuevo sueldo: ", "Error. ", 1, 1000000000);
                        if(confirm()=='s')
                        {
                            list[index].salary = aux.salary;
                            printf("Sueldo modificado exitosamente.\n");
                            ok = 1;
                        }
                        else
                        {
                            printf("Modificacion de sueldo cancelada.\n");
                        }
                        break;
                    case 4:
                        getInt(&aux.sector, "Ingrese nuevo sector(1-5)", "Error. ", 1, 5);
                        if(confirm()=='s')
                        {
                            list[index].sector = aux.sector;
                            printf("Sector modificado exitosamente.\n");
                        }
                        else
                        {
                            printf("Modificacion de sector cancelada.\n");
                        }
                        break;
                    case 5:
                        exit=confirm();
                    }
                    printf("\n");
                    system("pause");

                }
                while(exit == 'n');
            }
            else
            {
                printf("Modificacion cancelada.\n\n");
            }
        }
    }

    return ok;
}

int removeEmployee(Employee* list, int len, int id)
{
    int ok = 0;
    int index;

    if(list != NULL && len > 0)
    {
        index = findEmployeeById(list, len, id);

        if(index == -1)
        {
            printf("El ID indicado no existe.\n\n");
        }
        else
        {
            printf("El empleado a dar de baja es:\n");
            printEmployee(list[index]);
            printf("\n");

            if(confirm() == 's')
            {
                list[index].isEmpty = 1;
                ok = 1;
            }
            else
            {
                printf("Baja cancelada.\n");
            }
            printf("\n");
        }
    }

    return ok;
}

int reportsMenu()
{
    int option;

    system("cls");
    printf("*****Informes*****\n\n");
    printf("1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2. Total y promedio de los sueldos, y cuantos empleados superan el salario promedio.\n");
    printf("3. Volver al menu de inicio.\n\n");

    printf("Ingrese opcion (1-3): ");
    fflush(stdin);
    scanf("%d", &option);
    printf("\n");

    return option;
}

int reports(Employee* list, int len)
{
    int ok = 0;
    char exit = 'n';
    int order;

    if(list != NULL && len >0)
    {
        do
        {

            switch(reportsMenu())
            {
            case 1:
                getInt(&order, "Elija el orden (1 Ascendente, 0 Descendente): ", "Error", 0, 1);

                if(sortEmployees(list,len,order))
                {
                    printEmployees(list, len);
                    ok = 1;
                }
                else
                {
                    printf("Hubo un error.\n");
                }
                system("pause");
                break;
            case 2:
                reportSalary(list,len);
                ok = 1;
                system("pause");
                break;
            case 3:
                exit = confirm();
                break;
            }
        }
        while(exit == 'n');
    }
    return ok;
}

int sortEmployees(Employee* list, int len, int order)
{
    int ok = 0;
    Employee aux;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                if(order == 1)
                {
                    if(strcmp(list[i].lastName, list[j].lastName) > 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector > list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
                else
                {
                    if(strcmp(list[i].lastName, list[j].lastName) < 0 || (strcmp(list[i].lastName, list[j].lastName) == 0 && list[i].sector < list[j].sector))
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        ok =1;
    }

    return ok;
}

int reportSalary(Employee* list, int len)
{
    int ok = 0;
    float total = 0;
    int employees = 0;
    int overAverage = 0;
    float average;

    if(list != NULL && len)
    {
        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty)
            {
                total += list[i].salary;
                employees++;
            }
        }
        average = (float) total/employees;

        for(int i = 0; i < len; i++)
        {
            if(!list[i].isEmpty && list[i].salary > average)
            {
                overAverage++;
                ok=1;
            }
        }

        printf("Total sueldos: %.2f\n", total);
        printf("Promedio sueldos: %.2f\n", average);
        printf("Cantidad de empleados que superan el sueldo promedio: %d\n\n", overAverage);
    }

    return ok;
}

int printEmployee(Employee x)
{
    printf("%d  %8s %8s  %6.2f   %d\n",
           x.id,
           x.name,
           x.lastName,
           x.salary,
           x.sector
          );
    return 0;
}

int printEmployees(Employee* list, int length)
{
    int flag=0;

    printf("         Listado de Empleados\n");
    printf("ID     Nombre  Apellido   Sueldo  Sector\n");

    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            printEmployee(list[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("       No hay empleados para mostrar.\n");
    }
    printf("\n");
    return 0;
}
