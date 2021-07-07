/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
} eEmpleado;

void mostrarEmpleado(eEmpleado* emp);
void mostrarEmpleados(LinkedList* lista);
int ordenarPorId(void* emp1, void* emp2);

int main(void)
{
    eEmpleado emp1 = {1,"Juan",20,30000};
    eEmpleado emp2 = {2,"Pedro",5,25000};
    eEmpleado emp3 = {3,"Marta",12,32000};
    eEmpleado emp4 = {4,"Camila",3,27000};

    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleados2 = NULL;
    LinkedList* listaEmpleados3 = NULL;
    eEmpleado* empleado = NULL;
    eEmpleado* retornoPop = NULL;
    if(listaEmpleados == NULL)
    {
        printf("Error al crear la lista.\n\n");
        exit(1);
    }
    else
    {
        printf("**Lista de empleados creada utilizando la funcion ll_newLinkedList**\n\n");
    }

    printf("**Confirmo que este vacia con ll_isEmpty**\n\n");
    if(ll_isEmpty(listaEmpleados2))
    {
        printf("AFIRMATIVO.\n\n");
    }
    else
    {
        printf("NEGATIVO.\n\n");
    }

    if(!ll_add(listaEmpleados, &emp1) && !ll_add(listaEmpleados, &emp2))
    {
        printf("**Empleados agregados a la lista con ll_add**\n\n");
        mostrarEmpleados(listaEmpleados);
    }

    printf("**Tamanio actual de la lista (ll_len): %d**\n\n", ll_len(listaEmpleados));

    if(!ll_push(listaEmpleados, 1, &emp3))
    {
        printf("**Agrego un empleado en la segunda fila de la lista con ll_push**\n\n");
    }

    empleado = (eEmpleado*) ll_get(listaEmpleados, 1);
    if(empleado != NULL)
    {
        printf("**Obtengo el empleado agregado en la lista con ll_get y lo muestro**\n\n");
        mostrarEmpleado(empleado);
        printf("\n");
        mostrarEmpleados(listaEmpleados);
    }

    if(!ll_remove(listaEmpleados, 0))
    {
        printf("**Elimino el primer empleado de la lista con ll_remove**\n\n");
        mostrarEmpleados(listaEmpleados);
    }

    if(!ll_set(listaEmpleados, 1, &emp4))
    {
        printf("**Reemplazo el segundo empleado de la fila con ll_set**\n\n");
        mostrarEmpleados(listaEmpleados);
    }

    printf("**Averiguo si Pedro (emp2) esta en la lista con ll_contains**\n\n");
    if(ll_contains(listaEmpleados, &emp2))
    {
        printf("Pedro se encuentra en la lista.\n\n");
    }
    else
    {
        printf("Pedro no se encuentra en la lista.\n\n");
    }

    printf("**Averiguo el indice de Camila (emp4) con ll_indexOf**\n\n");
    if(ll_indexOf(listaEmpleados, &emp4) == -1)
    {
        printf("Camila no esta en la lista.\n\n");
    }
    else
    {
        printf("El indice de Camila es el: %d\n\n", ll_indexOf(listaEmpleados, &emp4));
    }

    if(!ll_add(listaEmpleados, &emp1) && !ll_add(listaEmpleados, &emp2))
    {
        printf("**Vuelvo a cargar a Juan y Pedro en la lista**\n\n");
        mostrarEmpleados(listaEmpleados);
    }

    if(!ll_sort(listaEmpleados, ordenarPorId, 1))
    {
        printf("**Ordeno los empleados por ID de forma ascendente con ll_sort**\n\n");
        mostrarEmpleados(listaEmpleados);
    }

    listaEmpleados2 = ll_clone(listaEmpleados);

    if(listaEmpleados2 != NULL)
    {
        printf("**Clono la lista de empleados en la nueva lista con ll_clone**\n\n");
    }

    printf("**Compruebo que todos los elementos de la nueva lista se encuentren en mi lista original con ll_containsAll**\n\n");
    if(ll_containsAll(listaEmpleados, listaEmpleados2))
    {
        printf("AFIRMATIVO.\n\n");
        mostrarEmpleados(listaEmpleados2);
    }
    else
    {
        printf("NEGATIVO.\n\n");
        mostrarEmpleados(listaEmpleados2);
    }

    if(!ll_clear(listaEmpleados2))
    {
        printf("**Elimino los elementos de la lista clon con ll_clear**\n\n");
    }

    if(!ll_deleteLinkedList(listaEmpleados2))
    {
        printf("**Elimino la lista clon con ll_deleteLinkedList**\n\n");
    }

    listaEmpleados3 = ll_subList(listaEmpleados, 0,2);

    if(listaEmpleados3 != NULL)
    {
        printf("**Creo una lista con los primeros 2 empleados de mi lista original con ll_subList**\n\n");
        mostrarEmpleados(listaEmpleados3);
    }

    retornoPop = (eEmpleado*) ll_pop(listaEmpleados3, 0);

    if(retornoPop != NULL)
    {
        printf("**Elimino un empleado de mi sublista y guardo su direccion de memoria con ll_pop**\n\n");
        printf("Empleado eliminado:\n");
        mostrarEmpleado(retornoPop);
        printf("\nLista:\n");
        mostrarEmpleados(listaEmpleados3);
    }

    if(!ll_deleteLinkedList(listaEmpleados) && !ll_deleteLinkedList(listaEmpleados3))
    {
        printf("**Elimino mi lista original y mi sublista**\n\n");
    }

    return 0;
}


void mostrarEmpleado(eEmpleado* emp)
{
    if(emp != NULL)
    {
        printf("%04d %-8s %3d  %5d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

void mostrarEmpleados(LinkedList* lista)
{
    if(lista != NULL)
    {
        printf(" Id  Nombre  Horas Sueldo\n");
        for(int i = 0; i < ll_len(lista); i++)
        {
            mostrarEmpleado((eEmpleado*) ll_get(lista, i));
        }
        printf("\n");
    }
}

int ordenarPorId(void* emp1, void* emp2)
{
    int retorno = 0;

    if(((eEmpleado*)emp1)->id > ((eEmpleado*)emp2)->id)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }
    return retorno;
}































