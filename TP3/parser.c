#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    char buffer[4][128];
    Employee* aux = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
        while(!feof(pFile))
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4)
            {
                aux = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                if(aux != NULL)
                {
                    ll_add(pArrayListEmployee, aux);
                    ok=1;
                }
            }
        }
    }
    return ok;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int ok = 0;
    Employee* aux = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            aux = employee_new();
            if(aux != NULL)
            {
                if(fread(aux, sizeof(Employee), 1, pFile) < 1)
                {
                    break;
                }
                ll_add(pArrayListEmployee, aux);
                ok = 1;
            }
        }
    }
    return ok;
}
