#include <stdio.h>
#include <string.h>

// Comparación entre las longitudes de varias cadenas de caracteres.

#define MAX 100
#define N 20

int masLargo(char [][MAX], int);

void main(void)
{
    char cad[N][MAX], check;
    int i = 0, index;

    printf("Desea digitar una cadena de texto? - S/N -: ");
    check = getchar();
    fflush(stdin);

    while (check == 'S' || check == 's' || check == 'Y' || check == 'y')
    {
        i++;
        printf("Digite una cadena de caracteres número %d: ", i);
        gets(cad[i]);
        fflush(stdin);

        printf("¿Desea digitar otra cadena de caracteres? - S/N -: ");
        check = getchar();
        fflush(stdin);
    }

    index = masLargo(cad, i);

    printf("\nLa cadena de caracteres más larga es: \"%s\" que cuenta con %d caracteres.\n", cad[index], strlen(cad[index]));
}

int masLargo(char cadena[N][MAX], int I)
{
    int max = 0, i, index;

    for (i = 0; i <= I; i++)
    {
        if (strlen(cadena[i]) > max)
        {
            max = strlen(cadena[i]);
            index = i;
        }
    }

    return (index);
}