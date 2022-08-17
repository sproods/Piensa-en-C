#include <stdio.h>
#include <stdlib.h>

/* Suma y promedio.
El programa, al recibir somo datos varias cadenas de caracteres que contienen reales, los suma y obtiene el promedio de los mismos. */

void main(void)
{
    char c, cad[10];
    int i = 0;
    float sum = 0.0;

    printf("\n¿Desea ingresar una cadena de caracteres (S/N)? ");
    c = getchar();

    while(c == 'S')
    {
        printf("\nDigite la cadena de caracteres: ");
        fflush(stdin);
        gets(cad);
        i++;
        sum += atof(cad);
        printf("\n¿Desea ingresar otra cadena de caracteres (S/N)? ");
        c = getchar();
    }
    printf("\nSuma: %.2f", sum);
    printf("\nPromedio: %.2f\n", sum / i);
}