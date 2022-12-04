/* El programa realiza la prueba de la función strstr de la librería string.h en C. */

#include <stdio.h>
#include <string.h>

void main(void)
{
    char string_1[250], string_2[50], *string_3;

    printf("Digite la cadena de caracteres de su preferencia:\n");
    gets(string_1);

    printf("Digite la cadena que desea buscar en la cadena de caracteres antes escrita:\n");
    gets(string_2);

    string_3 = strstr(string_1, string_2);
    puts(string_3);

    while (string_3 != NULL)
    {
        string_3 = strstr(string_3 + 1, string_2);
        puts(string_3);
    }
}