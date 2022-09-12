#include <stdio.h>
#include <string.h>

// Estudio de la función strlen de la librería <string.h>

void main(void)
{
    int length, a, b;
    char texto[50], cadena1[50], cadena2[50];

    printf("Digite la cadena de texto de su preferencia: ");
    gets(texto);
    fflush(stdin);

    length = strlen(texto);
    printf("El texto: \"%s\" tiene una longitud de %d caracteres.\n\n", texto, length);
    
    printf("Digite la segunda cadena de caracteres: ");
    gets(cadena1);
    fflush(stdin);
    printf("Digite la tercera cadena de caracteres: ");
    gets(cadena2);
    fflush(stdin);

    a = strlen(cadena1);
    b = strlen(cadena2);

    if (a > b)
        printf("La cadena \"%s\" es más grande que la cadena \"%s\"\nya que su longitud es de %d caracteres frente a %d caracteres, respectivamente.\n", cadena1, cadena2, a, b);
    else
        printf("La cadena \"%s\" es más grande que la cadena \"%s\"\nya que su longitud es de %d caracteres frente a %d caracteres, respectivamente.\n", cadena2, cadena1, b, a);
}