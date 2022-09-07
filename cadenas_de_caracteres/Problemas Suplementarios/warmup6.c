#include <stdio.h>

// Capitalizador de textos.

void main(void)
{
    int i, cont = 0;
    char letter, texto[1000];

    printf("Escriba, por favor, el texto de su preferencia: ");
    gets(texto);
    fflush(stdin);

    i = 0;
    while((letter = texto[i]) != '\n')
    {
        cont++;
        i++;
    }

    printf("El tamaño del texto es de %d caracteres.", cont);
}
