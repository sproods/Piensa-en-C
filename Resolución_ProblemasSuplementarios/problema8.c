#include <stdio.h>

/* El programa realiza un recorrido de un arreglo de manera que recorra por cada columna en un movimiento de zig-zag. */

#define MAX 50

void Recorrido(int [][MAX], int, int);          /* Prototipo de funciones. */
void Imprime(int [][MAX], int, int);

void main(void)
{
    int M, N, MAT[MAX][MAX];

    do
    {
        printf("Digite el tamaño de las filas del arreglo: \n");
        scanf("%d", &M);
    }
    while(M < 1 || M > 50);

    do
    {
        printf("Digite el número de columnas del arreglo: \n");
        scanf("%d", &N);
    }
    while(N < 1 || N > 50);

    Recorrido(MAT, M, N);
    Imprime(MAT, M, N);
}

void Imprime(int A[][MAX], int F, int C)
{
    int i, j;

    printf("\n");
    for (i = 0; i < F; i++)
    {
        printf("|");
        for (j = 0; j < C; j++)
            printf(" %d |", A[i][j]);
        printf("\n");
    }
}

void Recorrido(int A[][MAX], int F, int C)
{
    int maximo, i, j, N;

    maximo = F * C;
    N = 1;
    i = -1;
    j = 0;

    while (N < maximo)
    {
        for (i = 0; i < F; i++)
            A[i][j] = N++;

        j++;

        for (i = F - 1; i >= 0; i--)
            A[i][j] = N++;

        j++;
    }
}