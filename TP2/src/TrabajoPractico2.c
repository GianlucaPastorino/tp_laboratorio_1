#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define LEN 1000

int main()
{
	setbuf(stdout, NULL);
    Employee arrayEmployees[LEN];

    initEmployees(arrayEmployees, LEN);

    int id = 0;
    int IDemployeeToRemove;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int order;

    char exit = 'n';
    do
    {
        switch(menu())
        {
        case 1:
            loadName(&name);
            loadLastName(&lastName);
            loadSalary(&salary);
            loadSector(&sector);

            if(addEmployee(arrayEmployees, LEN, id, name, lastName, salary, sector)==0)
            {
                printf("Alta exitosa!\n\n");
                id++;
            }
            else
            {
                printf("Hubo un problema al realizar el alta.\n\n");
            }
            break;
        case 2:
            if(modifyEmployee(arrayEmployees, LEN))
            {
                printf("Modificacion exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar la modificacion.\n\n");
            }
            break;
        case 3:
            loadEmployeeToRemove(&IDemployeeToRemove);
            removeEmployee(arrayEmployees, LEN, IDemployeeToRemove);

            break;
        case 4:
            if(sortEmployees(arrayEmployees, LEN, 1))
            {
                printf("Ordenamiento exitosa!\n\n");
            }
            else
            {
                printf("No se pudo realizar el ordenamiento.\n\n");
            }

            break;
        case 5:
            exit=confirm();
            break;

        }
        system("pause");
    }
    while(exit == 'n');
    return 0;
}
