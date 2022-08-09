#include <stdio.h>

/* Resolución del problema 1 del libro. */

const int MAX = 100;

void App(int [][MAX], int);		/* Prototipo de la función. */
void Imprime(int [][MAX], int);

void main(void)
{
	int MAT[MAX][MAX], N;

	do
	{
		printf("\nDigite el tamaño de la matriz: ");
		scanf("%d", &N);
	}
	while(N > MAX || N < 1);

	App(MAT, N);
	Imprime(MAT, N);
}

void App(int A[][MAX], int T)
{
	int I, J;
	for(I = 0; I < T; I++)
		for(J = 0; J < T; J++)
			if(I == J || (I + J) == (T - 1))
				A[I][J] = 1;
			else
				A[I][J] = 0;
}

void Imprime(int A[][MAX], int T)
{
	int I, J;
	
	printf("\n");
	for(I = 0; I < T; I++)
	{
		printf("|");
		for(J = 0; J < T; J++)
			printf(" %d |", A[I][J]);
		printf("\n");
		for(J = 0; J < T; J++)
			printf(" ---");
		printf("\n");
	}
}
