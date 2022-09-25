#include <stdio.h>

// Conteo de frecuencias de cada palabra en un arreglo de cadena de carecteres.

void main(void)
{
    char texto[22][80];
    int ncad, i, j, words, frec[30] = {0};

    printf("Digite el número de cadenas que va a escribir: ");
    scanf("%d", &ncad);
    fflush(stdin);

    for (i = 0; i < ncad; i++)
    {
        printf("Digite la cadena %d: ", i + 1);
        gets(texto[i]);
    }

    for (i = 0; i < ncad; i++)
    {
        j = 0;

        while (texto[i][j] != '\0')
        {
            words = 0;

            while (texto[i][j] != ' ' && texto[i][j] != '\0')
            {
                words++;
                j++;
            }

            frec[words]++;

            if (texto[i][j] != '\0')
                j++;
        }
    }

    printf("\nLongitud de la palabra\t\tFrecuencia\n");

    for (i = 0; i < 22; i++)
    {
        printf("%12d\t\t%12d\n", i + 1, frec[i + 1]);
    }
}