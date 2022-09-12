#include <stdio.h>
#include <ctype.h>

// Conprensión de los arreglos de cadenas de caracteres.

void Calcula(char *cadena, int n);

void main(void)
{
    int i, N;
    char FRA[20][50];

    printf("Digite el número de frases que quiere calcular: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        printf("Digite la frase %d: ", i + 1);
        fflush(stdin);
        gets(FRA[i]);
    }

    printf("\n\n");
    for (i = 0; i < N; i++)
        Calcula(FRA[i], i);
}

void Calcula(char *cadena, int n)
{
    int i = 0, min = 0, may = 0;

    while (cadena[i] != '\0')
    {
        if (islower(cadena[i]))
            min++;
        else if (isupper(cadena[i]))
            may++;
        i++;
    }

    printf("La cadena %d: \"%s\" tienes %d minúsculas y %d mayúsculas.\n", n + 1, cadena, min, may);
}