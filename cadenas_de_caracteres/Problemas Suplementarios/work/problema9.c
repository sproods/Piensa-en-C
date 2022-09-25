#include <stdio.h>
#include <string.h>

// Inversión de una cadena de caracteres por palabras.

void main(void)
{
    char string[50], array[50][50];
    int len, i, j = 0, k;

    printf("Digite la cadena de caracteres de su preferencia: ");
    gets(string);

    len = strlen(string);

    for (i = 0; i < len; i++)
    {
        k = 0;
        while ((string[i] != ' ') && (string[i] != '\0'))
        {
            array[j][k] = string[i];
            i++;
            k++;
        }

        array[j][i] = '\0';

        j++;
    }

    printf("\n");
    for(i = j - 1; i >= 0; i--)
        printf("%s ", array[i]);
    printf("\n");
}