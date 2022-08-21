#include <stdio.h>

/* El programa muestra en pantalla el número de caracteres de una cadena de caracres dada por el usuario, sin contar con los espacios. */

int cuenta(char *);         /* Prototipo de la función. */

void main(void)
{
    char cad[50];
    int i;

    printf("Digite la cadena de caracteres de su agrado: ");
    gets(cad);
    i = cuenta(cad);
    printf("\nEl número de letras de la cadena digitada es: %d", i);
}

int cuenta(char cadena[])
{
    int len = 0, a = 0;
    while(cadena[a] != '\0')
    {
        if(cadena[a] != ' ')
            len++;
        a++;
    }
    return(len);
}