#include <stdio.h>

// Comparación de longitudes de varias cadenas de caracteres.

#define FIL 20
#define LET 50

void main(void)
{
    char string[FIL][LET];
    int i = 0, j, fil, count, max = 0, index = 0;

    printf("Digite la cantidad de cadenas de caracteres que va a ingresar: ");
    scanf("%d", &fil);
    fflush(stdin);

    while (i < fil)
    {
        printf("Digite la cadena de caracteres %d: ", i + 1);
        gets(string[i]);
        fflush(stdin);
        i++;
    }

    for(i = 0; i < fil; i++)
    {
        j = 0;
        count = 0;
        while (string[i][j] != '\0')
        {
            count++;
            j++;
        }

        if (count > max)
        {
            max = count;
            index = i;
        }
    }

    printf("\nLa cadena de caracteres con más longitud es \"%s\" que tiene %d caracteres.\n", string[index], max);
}