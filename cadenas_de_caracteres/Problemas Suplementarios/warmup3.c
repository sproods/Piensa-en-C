#include <stdio.h>

// Ejercicios de entrenamiento para la comprensión de las cadenas de caracteres.

#define MAX 50

void main(void)
{
    char *cadenaMenor, cadenaMayor[] = {'S', 'p', 'r', 'o', 'o', 'd', 's', '\0'}, string1[] = "I am the best programmer in the World...", *firstName;

    cadenaMenor = "The dream of my life";

    puts(cadenaMenor);
    puts(cadenaMayor);
    puts(string1);

    printf("What's your name?: ");
    gets(firstName);
    fflush(stdin);
    printf("\nHello Mr. ");
    puts(firstName);
}