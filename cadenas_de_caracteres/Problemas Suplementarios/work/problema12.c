#include <stdio.h>
#include <ctype.h>

// Elección de la cadena de caracteres que contenga mayor número de letras mayúsculas.

void main(void)
{
    char cad[10][50];
    int ncad, mayCad = 0, maxMay = 0, i, nMay, j;

    printf("Digite el número de cadenas de caracteres que desea ingresar: ");
    scanf("%d", &ncad);
    fflush(stdin);

    for (i = 0; i < ncad; i++)
    {
        printf("Digite la cadena %d: ", i + 1);
        gets(cad[i]);
        fflush(stdin);
    }

    for (i = 0; i < ncad; i++)
    {
        j = 0;
        nMay = 0;

        while(cad[i][j] != '\0')
        {
            if (isupper(cad[i][j]))
            {
                nMay++;
            }
            j++;
        }

        if (nMay > maxMay)
        {
            maxMay = nMay;
            mayCad = i;
        }
    }

    printf("\nLa cadena con mayor número de mayúsculas es la cadena %d: \"%s\" que tiene %d mayúsculas.\n", mayCad + 1, cad[mayCad], maxMay);
}