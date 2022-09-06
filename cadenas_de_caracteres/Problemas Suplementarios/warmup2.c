#include <stdio.h>
#include <ctype.h>

//  Entrenamiento de las principales funciones de la biblioteca ctype.h de C.

void main(void)
{
    int i, c;
    char a, M;

    do
    {
        printf("Digite un caracter de su preferencia: ");
        M = getchar();
        fflush(stdin);
    }
    while(isdigit(M));

    do
    {
        printf("Digite un número, por favor: ");
        a = getchar();
        fflush(stdin);
    }
    while(isalpha(a));

    c = a - '0';

    if(islower(M))
    {
        for(i = 0; i < c; i++)
            printf("%c", toupper(M));
    }

}