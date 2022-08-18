#include <stdio.h>

/* Suma de una matriz por su transpuesta. */

#define MAX 50

void Lectura(float [][MAX], int, int);
void Imprime(float [][MAX], int, int);
void Transpuesta(float [][MAX], float [][MAX], int, int);
void Suma(float [][MAX], float [][MAX], float [][MAX], int, int);

void main(void)
{
    int M, N;
    float MAT[MAX][MAX], TRA[MAX][MAX], SUM[MAX][MAX];

    do
    {
        printf("\nDigite el número de filas de la matriz: ");
        scanf("%d", &M);
    }
    while(M < 1 || M > 50);

    do
    {
        printf("\nDigite el número de columnas de la matriz: ");
        scanf("%d", &N);
    }
    while(N < 1 || N > 50);

    Lectura(MAT, M, N);
    Transpuesta(MAT, TRA, M, N);
    Suma(MAT, TRA, SUM, M, N);
    printf("\nLA MATRIZ:\n");
    Imprime(MAT, M, N);
    printf("\nSU TRASPUESTA:\n");
    Imprime(TRA, N, M);
    printf("\nLA SUMA DE LA MATRIZ MÁS SU TRANSPUESTA:\n");
    Imprime(SUM, M, N);
}

void Lectura(float A[][MAX], int F, int C)
{
    int I, J;

    for(I = 0; I < F; I++)
        for(J = 0; J < C; J++)
        {
            printf("\nDigite el conponente de %d %d: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
}

void Imprime(float A[][MAX], int F, int C)
{
    int I, J;

    printf("\n");
    for(I = 0; I < F; I++)
    {
        printf("|");
        for(J = 0; J < C; J++)
            printf(" %.2f |", A[I][J]);
        printf("\n");
    }
}

void Transpuesta(float A[][MAX], float B[][MAX], int F, int C)
{
    int I, J;

    for(I = 0; I < F; I++)
        for(J = 0; J < C; J++)
            B[J][I] = A[I][J];
}

void Suma(float A[][MAX], float B[][MAX], float S[][MAX], int F, int C)
{
    int I, J;

    for(I = 0; I < F; I++)
        for(J = 0; J < C; J++)
            S[I][J] = A[I][J] + B[J][I];
}