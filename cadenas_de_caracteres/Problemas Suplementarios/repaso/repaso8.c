#include <stdio.h>
#include <string.h>

// Inversor de cadena de caracteres.

void main(void)
{
    char string[50], rever[50];
    int length, i;

    printf("Digite la cadena de caracteres de su preferencia: ");
    gets(string);

    length = strlen(string);

    for (i = length - 1; i >= 0; i--)
    {
        rever[length - i - 1] = string[i];
    }

    printf("\n");
    puts(rever);
}