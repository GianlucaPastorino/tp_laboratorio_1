#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int menu()
{
    int option;

    system ("cls");
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

int emptyIndex(Employee* list, int len)
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

int loadName(char* name)
{
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(name);
    return 0;
}

int loadLastName(char* lastName)
{
    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(lastName);
    return 0;
}

int loadSalary(float* salary)
{
    printf("Ingrese sueldo: ");
    fflush(stdin);
    scanf("%f", salary);
    return 0;
}

int loadSector(int* sector)
{
    printf("Ingrese sector: ");
    fflush(stdin);
    scanf("%d", sector);
    return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int ok = -1;
    int index;

    if(list != NULL && len > 0)
    {
        index = emptyIndex(list, len);
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
        else
        {
            printf("No hay mas lugar en el sistema.\n");
        }
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
    int ok = 0;
    Employee aux;

    system("cls");
    printf("Modificar empleado\n\n");
    printEmployees(list, len);
    printf("Ingrese el ID del empleado a modificar: ");
    scanf("%d", &id);
    printf("\n");

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

        do
        {
            switch(modifyMenu())
            {
            case 1:
                printf("Ingrese nuevo nombre: ");
                fflush(stdin);
                gets(aux.name);

                strcpy(list[index].name, aux.name);
                ok = 1;
                break;
            case 2:
                printf("Ingrese nuevo apellido: ");
                fflush(stdin);
                gets(aux.lastName);

                strcpy(list[index].lastName, aux.lastName);
                ok = 1;
                break;
            case 3:
                printf("Ingrese nuevo sueldo: ");
                scanf("%f", &aux.salary);

                list[index].salary = aux.salary;
                ok = 1;
                break;
            case 4:
                printf("Ingrese nuevo sector: ");
                scanf("%d", &aux.sector);

                list[index].sector=aux.sector;
                ok = 1;
                break;
            case 5:
                exit=confirm();
            }

            printf("\n");
            system("pause");
            system("cls");

        }
        while(exit == 'n');
    }
    return ok;
}

int loadEmployeeToRemove(int* idToRemove)
{
    printf("Ingrese el ID del empleado a dar de baja: ");
    scanf("%d", idToRemove);
    printf("\n");

    return 0;
}

int removeEmployee(Employee* list, int len, int id)
{
    int ok = 0;
    int index;

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
        printf("\n");
    }

    return ok;
}

int sortEmployees(Employee* list, int len, int order)
{
    Employee aux;
    if(order==1)
    {
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i].sector> list[j].sector||(list[i].sector == list[j].sector &&strcasecmp(list[i].lastName, list[j].lastName)>0))
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }

        }
    }
    else
    {
        for(int i=0; i<len; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(list[i].sector< list[j].sector||(list[i].sector == list[j].sector &&strcasecmp(list[i].lastName, list[j].lastName)<0))
                {
                    aux=list[i];
                    list[i]=list[j];
                    list[j]=aux;
                }
            }

        }
    }

    return 0;
}

int printEmployee(Employee x)
{
    printf("%4d     %s     %s     %9.2f     %4d\n",
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
    printf("ID  Nombre  Apellido Sueldo  Sector\n");

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

char confirm()
{
    char answer;

    printf("Presione s para confirmar o n para cancelar: ");
    fflush(stdin);
    answer = getchar();

    while(answer != 's' && answer != 'n')
    {
        printf("Error. Presione s para confirmar o n para cancelar: ");
        fflush(stdin);
        answer = getchar();
    }

    return answer;
}

