#include <stdio.h>
#include <string.h>

void main(void)
{
    char cad[30];

    printf("Digite un texto: ");
    gets(cad);

    if (strcmp(cad, "hola") == 0 || strcmp(cad, "holi") == 0 || strcmp(cad, "Hola") == 0 || strcmp(cad, "Holi") == 0)
        puts("cómo estás?");
    else
        puts("no está en el registro...");
}