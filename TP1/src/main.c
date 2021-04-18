#include <stdio.h>
#include <stdlib.h>
#include "gianluca.h"

int main()
{
	setbuf(stdout, NULL);
    char salir = 'n';
    int a;
    int b;
    int flagNum1 = 0;
    int flagNum2 = 0;
    int flagCalculos = 0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoMultiplicacion;
    int divisionValida;
    float resultadoDivision;
    int resultadoFactorial1;
    int resultadoFactorial2;

     do
    {
        switch(menu(flagNum1, flagNum2, a, b))
        {
            case 1:
                printf("\nIngrese el primer operando: ");
                while(scanf("%d", &a)==0)
                {
                    printf("Error. Debe ingresar un numero: ");
                    fflush(stdin);
                }
                printf("\n");
                flagNum1=1;
                system("pause");
                break;
            case 2:
                if(flagNum1)
                {
                    printf("\nIngrese el segundo operando: ");
                    while(scanf("%d", &b)==0)
                    {
                        printf("Error. Debe ingresar un numero: ");
                        fflush(stdin);
                    }
                    flagNum2=1;
                }
                else
                {
                    printf("\nPara ingresar el segundo operando, antes debe ingresar el primero.");
                }
                printf("\n");
                system("pause");
                break;
            case 3:
                if(!flagNum1)
                {
                    printf("Primero debes ingresar los operandos.\n");
                }
                else
                {
                    if(!flagNum2)
                    {
                        printf("Primero debes ingresar el segundo operando.\n");
                    }
                    else
                    {
                        resultadoSuma=suma(a,b);
                        resultadoResta=resta(a,b);
                        divisionValida=division(a,b, &resultadoDivision);
                        resultadoMultiplicacion=multiplicacion(a,b);
                        resultadoFactorial1=factorial(a);
                        resultadoFactorial2=factorial(b);
                        flagCalculos=1;
                        printf("Las operaciones fueron realizadas con exito.\n\n");
                    }
                }
                system("pause");
                break;
            case 4:
                if(flagCalculos)
                {
                    printf("El resultado de %d+%d es: %d\n", a, b, resultadoSuma);
                    printf("El resultado de %d-%d es: %d\n", a, b, resultadoResta);
                    if(divisionValida)
                    {
                        printf("El resultado de %d/%d es: %.2f\n", a, b, resultadoDivision);
                    }
                    else
                    {
                        printf("No es posible dividir por 0.\n");
                    }
                    printf("El resultado de %d*%d es: %d\n", a, b, resultadoMultiplicacion);
                    if((a<0 || a>=17) && (b<0 || b>=17))
                    {
                        printf("No es posible calcular los factoriales.\n");
                    }
                    else
                    {
                        if(a>=0 && a<=16 && b>=0 && b<=16)
                        {
                            printf("El factorial de %d es: %d y el factorial de %d es: %d\n", a, resultadoFactorial1, b, resultadoFactorial2);
                        }
                        else
                        {
                            if((a>=0 && a<=16) && (b<0 || b>=17))
                            {
                                printf("El factorial de %d es %d y no es posible calcular el factorial de %d\n", a, resultadoFactorial1, b);
                            }
                            else
                            {
                                printf("No es posible calcular el factorial de %d y el factorial de %d es %d.\n", a, b, resultadoFactorial2);
                            }
                        }
                    }
                    flagNum1=0;
                    flagNum2=0;
                    flagCalculos=0;
                }
                else
                {
                    if(!flagNum1)
                    {
                        printf("Primero debes ingresar los operandos.\n");
                    }
                    else
                    {
                        if(!flagNum2)
                        {
                            printf("Primero debes ingresar el segundo operando.\n");
                        }
                        else
                        {
                            printf("Primero debes hacer los calculos.\n");
                        }
                    }
                }
                printf("\n");
                system("pause");
                break;
            case 5:
                printf("Seguro que desea salir? Presione cualquier tecla para confirmar, o 'n' para cancelar: ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("Opcion invalida!\n");
                system("pause");
                break;
        }
    }
    while(salir == 'n');

    return 0;
}
