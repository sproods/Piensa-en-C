#include <stdio.h>

// Elección de la cadena de caracteres que contenga el mayor número de vocales.

void main(void)
{
    char cad[10][50], car;
    int ncad, i, j, vocales, maxVocales = 0, index = 0;

    printf("Digite la cantidad de cadenas que va a escribir: ");
    scanf("%d", &ncad);
    fflush(stdin);

    for (i = 0; i < ncad; i++)
    {
        printf("Digite la cadena %d: ", i + 1);
        gets(cad[i]);
    }

    for (i = 0; i < ncad; i++)
    {
        j = 0;
        vocales = 0;

        while (cad[i][j] != '\0')
        {
            car = cad[i][j];
            if (car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u' || car == 'A' || car == 'E' || car == 'I' || car == 'O' || car == 'U')
            {
                vocales++;
            }

            j++;
        }

        if (vocales > maxVocales)
        {
            maxVocales = vocales;
            index = i;
        }
    }

    printf("\nLa cadena con más vocales es la %d: \"%s\", que cuenta con %d vocales.\n", index + 1, cad[index], maxVocales);
}