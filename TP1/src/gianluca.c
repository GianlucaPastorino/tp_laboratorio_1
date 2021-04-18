#include "gianluca.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int menu(int flag1, int flag2, int num1, int num2)
{
   int opcion;
   system("cls");
   printf("*** Menu de opciones ***\n\n");
   if(flag1)
   {
       printf("1. Ingresar 1er operando (A=%d)\n", num1);
   }
   else
   {
       printf("1. Ingresar 1er operando (A=x)\n");
   }
   if(flag2)
   {
       printf("1. Ingresar 2do operando (B=%d)\n", num2);
   }
   else
   {
        printf("2. Ingresar 2do operando (B=y)\n");
   }
   printf("3. Calcular todas las operaciones\n");
   printf(" a) Calcular la suma\n");
   printf(" b) Calcular la resta\n");
   printf(" c) Calcular la division\n");
   printf(" d) Calcular la multiplicacion\n");
   printf(" e) Calcular el factorial\n");
   printf("4. Informar resultados\n");
   printf("5. Salir\n\n");
   printf("Ingrese opcion: ");
   fflush(stdin);
   scanf("%d", &opcion);

   return opcion;
}

int suma(int a, int b)
{
    return a+b;
}

int resta (int a, int b)
{
    return a-b;
}

int multiplicacion (int a, int b)
{
    return a*b;
}

float division (int a, int b, float *c)
{
    int realizadaConExito=0;

    if(b!=0 && c!=NULL)
    {
        *c = (float) a/b;
        realizadaConExito=1;
    }
    return realizadaConExito;
}

int factorial(int n)
{
    int fact = 1;
    for(int i=1; i<=n; i++)
    {
        fact *= i;
    }
    return fact;
}
