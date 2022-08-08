#include <stdio.h>

/* Cuadrado mágico.
 * El programa genera un cuadrado mágico siguiendo los criterios enunciodos anteriormente. */

const int MAX = 50;

void Cuadrado(int [][MAX], int);		/* Prototipos de funciones. */
void Imprime(int [][MAX], int);
void Imprime2(int [][MAX], int);

void main(void)
{
	int CMA[MAX][MAX], TAM;
	do
	{
		printf("Digite el tamaño impar de la matriz: ");
		scanf("%d", &TAM);
	}
	while((TAM > MAX && TAM % 2 == 0) || (TAM < 1 && TAM % 2 == 0));
	/* Se verifica el tamaño del arreglo y el orden (impar) del mismo. */

	Cuadrado(CMA, TAM);
	Imprime2(CMA, TAM);
}

void Cuadrado(int A[][MAX], int N)
/* Esta función se utiliza para formar el cuadrado mágico. */
{
	int I = 1, FIL = 0, COL = N / 2, NUM = N * N;
	while(I <= NUM)
	{
		A[FIL][COL] = I;
		if (I % N != 0)
		{
			FIL = (FIL - 1 + N) % N;
			COL = (COL + 1) % N;
		}
		else
			FIL++;
		I++;
	}
}

void Imprime(int A[][MAX], int N)
/* Esta función se utiliza para escribir el cuadrado mágico. */
{
	int I, J;
	for (I = 0; I < N; I++)
		for (J = 0; J < N; J++)
			printf("\nElemento %d %d: %d", I + 1, J + 1, A[I][J]);
}

void Imprime2(int A[][MAX], int N)
{
	int I, J;
	printf("\n");
	for (I = 0; I < N; I++)
	{
		printf("|");
		for (J = 0; J < N; J++)
			printf(" %d |", A[I][J]);
		printf("\n");
	}
}
