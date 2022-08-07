#include <stdio.h>

/* Transpuesta.
 * El programa calcula la transpuesta de una matriz. */

const int MAX = 50;

void Lectura(int [][MAX], int, int);
void Transpuesta(int [][MAX], int [][MAX], int, int);
void Imprime(int [][MAX], int, int);

void main(void)
{
	int MAT[MAX][MAX], TRA[MAX][MAX];
	int FIL, COL;

	do
	{
		printf("Digite el número de filas de la matriz: ");
		scanf("%d", &FIL);
	}
	while(FIL > MAX || FIL < 1);
	/* Se verifica que el número de filas sea correcto. */

	do
	{
		printf("Digire el número de columnas de la matriz: ");
		scanf("%d", &COL);
	}
	while(COL > MAX || COL < 1);
	/* Se verifiva que el número de columnas sea correto. */

	Lectura(MAT, FIL, COL);
	Transpuesta(MAT, TRA, FIL, COL);
	Imprime(TRA, COL, FIL);
}

void Lectura(int A[][MAX], int F, int C)
/* Esta función se utiliza para una matriz de tipo entero de F filas y C columnas. */
{
	int I, J;
	for (I = 0; I < F; I++)
		for (J = 0; J < C; J++)
		{
			printf("Digite el elemento %d %d: ", I + 1, J + 1);
			scanf("%d", &A[I][J]);
		}
}

void Transpuesta(int M1[][MAX], int M2[][MAX], int F, int C)
/* Esta función se utiliza para calcular la transpuesta. */
{
	int I, J;
	for (I = 0; I < F; I++)
		for (J = 0; J < C; J++)
			M2[J][I] = M1[I][J];
}

void Imprime(int A[][MAX], int F, int C)
/* Esta función se utiliza para escribir una matriz de tipo entero de F filas y C columnas -en este caso las transpuesta. */
{
	int I, J;
	for (I = 0; I < F; I++)
		for (J = 0; J < C; J++)
			printf("\nElemento %d %d: %d", I + 1, J + 1, A[I][J]);
}
