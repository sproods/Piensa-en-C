#include <stdio.h>
#include <string.h>

// Intercambio de cadenas de caracteres.

#define FIL 20
#define COL 30

void Cambia(char [][COL], int);

void main(void)
{
    char string[FIL][COL];
    int N, i;

    printf("Digite el número de cadenas de caracteres que va a escribir: ");
    scanf("%d", &N);
    fflush(stdin);

    for (i = 0; i < N; i++)
    {
        printf("Digite la cadena de caracteres %d -máximo 30 caracteres- ", i + 1);
        gets(string[i]);
        fflush(stdin);
    }

    Cambia(string, N);
    printf("\n");

    for (i = 0; i < N; i++)
        puts(string[i]);
}

void Cambia(char cadena[][COL], int N)
{
    int i;
    char *aux;

    for (i = 0; i < (N - 1) / 2; i++)
    {
        strcpy(aux, cadena[i]);
        strcpy(cadena[i], cadena[N - i- 1]);
        strcpy(cadena[N - i - 1], aux);
    }
}