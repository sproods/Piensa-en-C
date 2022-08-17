#include <stdio.h>

/* Cuenta caracteres.
El programa, al recibir como datos una cadena de caracteres y un caracter, cuenta cuántas veces se encuentra el caracter en la cadena. */

int cuenta(char *, char);           /* Prototipo de funciones. */

void main(void)
{
    char car, cad[50];
    int res;

    printf("\nDigite la cadena de caracteres: ");
    gets(cad);
    fflush(stdin);
    printf("\nDigite el caracter: ");
    car = getchar();
    res = cuenta(cad, car);
    printf("\n\n%c se encuentra %d veces en la cadena %s\n", car, res, cad);
}

int cuenta (char *cad, char car)
/* Esta función se utiliza para obtener el número de veces que se encuentra el caracter en la cadena. */
{
    int i = 0, r = 0;
    while(cad[i] != '\0')
    {
        if (cad[i] == car)
            r++;
        i++;
    }
    return (r);
}