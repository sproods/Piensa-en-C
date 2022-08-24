#include <stdio.h>

/* El programa imprime números desde el uno hasta la multiplicación del tamaño de filas por las columnas de manera espiral. */

#define MAX 50

void Espiral(int [][MAX], int, int);            /* Prototipo de función */
void Imprime(int [][MAX], int, int);

void main(void)
{
    int MAT[MAX][MAX], FIL, COL;

    do
    {
        printf("Digite el tamaño de las filas del arreglo: \n");
        scanf("%d", &FIL);
    }
    while(FIL < 1 || FIL > 50);

    do
    {
        printf("Digite el tamaño de las columnas del arreglo: \n");
        scanf("%d", &COL);
    }
    while(COL < 1 || COL > 50);

    Espiral(MAT, FIL, COL);
    Imprime(MAT, FIL, COL);
}

void Espiral(int A[][MAX], int F, int C)
{
    int i, j, inicio, limitecol, limitefil, maximo, n;

    inicio = 0;
    maximo = C * F;
    limitefil = F;
    limitecol = C;
    n = 1;
    i = 0;

    while(n <= maximo)
    {
        for(j = inicio; j < limitecol; j++)
            A[i][j] = n++;

        for(i = inicio + 1; i < limitefil; i++)
            A[i][j - 1] = n++;

        for(j = limitecol - 1; j > inicio && i > inicio + 1; j--)
            A[i - 1][j - 1] = n++;

        for(i = limitefil - 1; i > inicio + 1; i--)
            A[i - 1][j] = n++;

        inicio++;
        limitefil--;
        limitecol--;
    }
}

void Imprime(int A[][MAX], int F, int C)
{
    int i, j;

    printf("\n");
    for(i = 0; i < F; i++)
    {
        printf("|");
        for(j = 0; j < C; j++)
            printf(" %2d |", A[i][j]);
        printf("\n");
    }
}