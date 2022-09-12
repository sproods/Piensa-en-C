#include <stdio.h>
#include <stdlib.h>

// Dado unas cadenas de caracteres que contienen números reales, se realiza la suma de todos ellos así como su correspondiente cálculo del promedio.

void main(void)
{
    int i = 0; 
    double num, sum = 0, prom;
    char string[10], confirm;

    printf("¿Desea digitar una cadena de texto?- S/N para confirmar: ");
    confirm = getchar();
    fflush(stdin);

    while (confirm == 'S' || confirm == 's' || confirm == 'Y' || confirm == 'y')
    {
        printf("Digite la cadena de números de su preferencia: ");
        gets(string);
        fflush(stdin);

        sum += atof(string);
        i++;

        printf("¿Desea digitar otra cadena de texto?- S/N para confirmar: ");
        confirm = getchar();
        fflush(stdin);
    }

    prom = sum / i;

    printf("La suma total de los números es: %.2f\n", sum);
    printf("El promedio del total de los números es: %.2f\n", prom);
}