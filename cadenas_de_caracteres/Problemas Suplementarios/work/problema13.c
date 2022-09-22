#include <stdio.h>
#include <string.h>

// Conteo del número de palabras que hay en un arreglo de cadena de caracteres.

void main(void)
{
    char cad[10][50];
    int ncad, i, j, nwords;

    printf("Digite la cantidad de cadenas de caracteres que va a digitar: ");
    scanf("%d", &ncad);
    fflush(stdin);

    for (i = 0; i < ncad; i++)
    {
        printf("Digite la cadena %d de caracteres: ", i + 1);
        gets(cad[i]);
        fflush(stdin);
    }

    for (i = 0; i < ncad; i++)
    {
        j = 0;
        nwords = 0;
        
        while (cad[i][j] != '\0')
        {
            if (cad[i][j] == ' ')
                nwords++;

            j++;
        }

        printf("\nLa cadena \"%s\" tiene %d palabras.\n", cad[i], nwords + 1);
    }
}