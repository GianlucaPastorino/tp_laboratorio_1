#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "inputs.h"

#define LEN 1000

int main()
{
	setbuf(stdout, NULL);
	Employee arrayEmployees[LEN];

	    initEmployees(arrayEmployees, LEN);

	    int id = 100;
	    int idToRemove;
	    int employees = 0;

	    char exit = 'n';
	    do
	    {
	        switch(menu())
	        {
	        case 1:
	            if(getEmployee(arrayEmployees, LEN, &id))
	            {
	                printf("Alta exitosa!\n\n");
	                employees++;
	            }
	            else
	            {
	                printf("No se pudo realizar el alta.\n\n");
	            }
	            break;
	        case 2:
	            if(employees>0)
	            {
	                if(modifyEmployee(arrayEmployees, LEN))
	                {
	                    printf("Modificacion exitosa!\n\n");
	                }
	                else
	                {
	                    printf("No se pudo realizar la modificacion.\n\n");
	                }
	            }
	            else
	            {
	                printf("No hay empleados cargados en el sistema.\n\n");
	            }

	            break;
	        case 3:
	            if(employees>0)
	            {
	                system("cls");
	                printEmployees(arrayEmployees, LEN);
	                getInt(&idToRemove, "Ingrese el ID del empleado a dar de baja: ", "Error. ", 100, 1100);
	                if(removeEmployee(arrayEmployees, LEN, idToRemove))
	                {
	                    printf("Baja exitosa!\n\n");
	                    employees--;
	                }
	                else
	                {
	                    printf("No se pudo realizar la baja.\n\n");
	                }
	            }
	           else
	            {
	                printf("No hay empleados cargados en el sistema.\n\n");
	            }

	            break;
	        case 4:
	            if(employees>0)
	            {
	                reports(arrayEmployees, LEN);
	            }
	            else
	            {
	                printf("No hay empleados cargados en el sistema.\n\n");
	            }

	            break;
	        case 5:
	            exit=confirm();
	            break;

	        }
	        system("pause");
	    }
	    while(exit == 'n');
	    return EXIT_SUCCESS;
	}
