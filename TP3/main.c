#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    char salir = 'n';


    LinkedList* listaEmpleados = ll_newLinkedList();
    if(listaEmpleados == NULL)
    {
        printf("Error al crear la lista.\n\n");
        exit(1);
    }

    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("data.csv", listaEmpleados))
            {
                printf("Archivo cargado correctamente.\n\n");
            }
            else
            {
                printf("Error al cargar el archivo.\n\n");
            }
            system("pause");
            break;
        case 2:
            if(controller_loadFromText("data.bin", listaEmpleados))
            {
                printf("Archivo cargado correctamente.\n\n");
            }
            else
            {
                printf("Error al cargar el archivo.\n\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(controller_addEmployee(listaEmpleados))
            {
                printf("Alta exitosa.\n\n");
            }
            else
            {
                printf("Error al realizar el alta.\n\n");
            }
            system("pause");
            break;
        case 4:
            if(ll_len(listaEmpleados)>0)
            {
                system("cls");
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Modificacion exitosa.\n\n");
                }
                else
                {
                    printf("Error al realizar la modificacion.\n\n");
                }
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 5:
            if(ll_len(listaEmpleados)>0)
            {
                system("cls");
                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("Baja exitosa.\n\n");
                }
                else
                {
                    printf("Error al realizar la baja.\n\n");
                }
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 6:
            if(ll_len(listaEmpleados)>0)
            {
                system("cls");
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 7:
            if(ll_len(listaEmpleados)>0)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 8:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("Archivo guardado correctamente.\n\n");
                }
                else
                {
                    printf("Error al guardar el archivo.\n\n");
                }
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 9:
            if(ll_len(listaEmpleados)>0)
            {
                if(controller_saveAsBinary("data.bin", listaEmpleados))
                {
                    printf("Archivo guardado correctamente.\n\n");
                }
                else
                {
                    printf("Error al guardar el archivo.\n\n");
                }
            }
            else
            {
                printf("No hay empleados en la lista.\n\n");
            }
            system("pause");
            break;
        case 10:
            salir = confirm();
            break;
        }

    }
    while(salir == 'n');

    return 0;
}
