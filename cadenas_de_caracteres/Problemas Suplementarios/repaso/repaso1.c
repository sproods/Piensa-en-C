#include <stdio.h>

// Dado un caracter, el programa cuenta cuántas veces aparece dicho caracter en la cadena de caracteres digitada.

int Conteo(char *, char);

void main(void)
{
    int count;
    char letter, string[70];

    printf("Digite el texto de su elección: ");
    gets(string);
    fflush(stdin);

    printf("Digite la letra la cual desea saber cuántas veces se repite en el texto: ");
    letter = getchar();

    count = Conteo(string, letter);

    printf("%d son las veces que la letra %c se repite en \"%s\"\n", count, letter, string);
}

int Conteo(char *string, char letter)
{
    int reps = 0, i = 0;

    while (string[i] != '\0')
    {
        if (string[i] == letter)
            reps++;

        i++;
    }

    return reps;
}