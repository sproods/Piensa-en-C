#include <stdio.h>

/* Incorpora caracteres.
 * El programa agrega caracteres al archivo libro.txt. */

void main(void)
{
    char p1;
    FILE *ar;

    ar = fopen("libro.txt", "a");
    /* Se abre el archivo con la opción para incorporar caracteres. */
    if (ar != NULL)
    {
        printf("\nDigite la cadena de texto de su preferencia:\n");

        while ((p1 = getchar()) != '\n')
            fputc(p1, ar);
        fputc('\n', ar);
        fclose(ar);
    }
    else
        printf("\nNo se puede abrir el archivo.\n");
}