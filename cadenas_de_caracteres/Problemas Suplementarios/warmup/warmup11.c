#include <stdio.h>
#include <string.h>

// Segunda y última parte del entrenamiento en el estudio de las funciones de la librería <string.h>

void main(void)
{
    int cmp;
    char texto1[50], texto2[50];

    printf("Digite la primera cadena de texto: ");
    gets(texto1);
    fflush(stdin);

    printf("Digite la segunda cadena de texto: ");
    gets(texto2);
    fflush(stdin);

    cmp = strcmp(texto1, texto2);

    if (cmp == 1)
        printf("La primera cadena digitada va después que la segunda.\n");
    else if (cmp == -1)
        printf("La segunda cadena digitada va después que la primera.\n");
    else
        printf("Las dos cadenas digitadas son exactamente iguales.\n");
}