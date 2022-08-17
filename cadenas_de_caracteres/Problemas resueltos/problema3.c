#include <stdio.h>
#include <ctype.h>

/* Verifica.
El programa, al recibir como datos una cadena de caracteres y una posición y específica en la cadena, determina si el caracter correspondiente es una letra minúscula. */

void main(void)
{
    char p, cad[50];
    int n;

    printf("\nDigite la cadena de caracteres (máximo 50): ");
    gets(cad);
    printf("\nDigite la posición en la cadena que desea verificar: ");
    scanf("%d", &n);
    if((n >= 0) && (n < 50))
    {
        p = cad[n - 1];
        if(islower(p))
            printf("\n%c es una letra minúscula", p);
        else
            printf("\n%c no es una letra minúscula", p);
    }
    else
        printf("\nEl valor ingresado de n es incorrecto");
}