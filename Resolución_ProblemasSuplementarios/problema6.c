#include <stdio.h>

/* Suma de una matriz por su transpuesta. */

#define MAX 50

void Lectura(float [][MAX], int, int);
void Imprime(float [][MAX], int, int);
void Transpuesta(float [][MAX], float [][MAX], int, int);
void Suma(float [][MAX], float [][MAX], int, int);

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
    Tranpuesta(MAT, TRA, M, N);
    Suma(MAT, TRA, M, N);
    printf("\nLA MATRIZ:\n");
    Imprime(MAT, M, N);
    printf("\nSU TRASPUESTA:\n");
    Imprime(TRA, N, M);
    printf("\nLA SUMA DE LA MATRIZ MÁS SU TRANSPUESTA:\n");
    Imprime(SUM, M, N);
}