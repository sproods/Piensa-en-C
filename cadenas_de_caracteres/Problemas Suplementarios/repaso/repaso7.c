#include <stdio.h>
#include <string.h>

// El programa verifica cuantas veces una cadena de caracteres contine a otra cadena de caracteres más pequeña.

void main(void)
{
    char string[50], sub[50], *cad = "";
    int i = 0;

    printf("Digite una cadena de caracteres (que será el superconjunto): \n");
    gets(string);
    fflush(stdin);
    printf("Digite la segunda cadena de caracteres (que será el subconjunto): \n");
    gets(sub);
    fflush(stdin);
    printf("\n");

    cad = strstr(string, sub);
    puts(cad);

    while (cad != NULL)
    {
        i++;
        cad = strstr(cad + 1, sub);
        puts(cad);
    }

    printf("\nEl número de veces que la cadena \"%s\" se repite en la cadena \"%s\" es %d\n",sub, string, i);
}