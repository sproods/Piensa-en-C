#include <stdio.h>
#include <string.h>

// Impresión de la cadena de caracteres que tenga la fecha actual o digitada por el usuario.

#define FIL 30
#define COL 50

void main(void)
{
    char cad[FIL][COL], date[10], check, *fecha;
    int i = 0, j;

    printf("¿Desea digitar una cadena de texto?: - S/N - ");
    scanf("%c", &check);
    fflush(stdin);

    while (check == 's' || check == 'S' || check == 'y' || check == 'Y')
    {
        printf("Digite una cadena de caracteres anteponiendo una fecha: ");
        gets(cad[i]);
        fflush(stdin);

        i++;

        printf("¿Desea digitar otra cadena de texto? - S/N - ");
        scanf("%c", &check);
        fflush(stdin);
    }

    printf("Digite, por favor, la fecha actual: ");
    gets(date);
    fflush(stdin);

    printf("\n");

    for (j = 0; j < i; j++)
    {
        strncpy(fecha, cad[j], 8);

        if (strcmp(fecha, date) == 0)
            puts(cad[j]);
    }
}