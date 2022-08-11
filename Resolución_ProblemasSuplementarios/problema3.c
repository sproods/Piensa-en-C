#include <stdio.h>

/* El programa realiza el intercambio de los elementos de la primera fila con la última, la segunda con la penúltima y así sucesivamente. */

const int MAX = 50;

void Lectura(float [][MAX], int, int);
void Intercambia(float [][MAX], int, int);
void Imprime(float [][MAX], int, int);

void main(void)
{
	int M, N;
	float MAT[MAX][MAX];

	do
	{
		printf("Digite el número de filas de la matriz: ");
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
	Imprime(MAT, M, N);
	Intercambia(MAT, M, N);
	Imprime(MAT, M, N);
}

void Lectura(float A[][MAX], int F, int C)
{
	int I, J;
	for(I = 0; I < F; I++)
		for(J = 0; J < C; J++)
		{
			printf("\nDigite el elemento %d %d: ", I + 1, J + 1);
			scanf("%f", &A[I][J]);
		}
}

void Intercambia(float A[][MAX], int F, int C)
{
	int I, J;
	float AUX;
	for(J = 0; J < C; J++)
	{
		for(I = 0; I < (F / 2); I++)
		{
			AUX = A[I][J];
			A[I][J] = A[F - 1 - I][J];
			A[F - 1 - I][J] = AUX;
		}
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
