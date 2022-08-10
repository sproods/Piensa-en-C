#include <stdio.h>

/* El programa realiza el análisis y la muestra en pantalla de algunos datos estadísticos a tomar en cuenta para la mejora sustanciosa de una fábrica de la que se toman los datos de sus respectivos cinco departamentos. */

void Lectura(float [][12]);
void Imprime(float [][12]);
void ventasMes(float [][12]);
void ventasJulio(float [][12], int);
void departamento(float [][12], int);

void main(void)
{
	float VEN[5][12];

	Lectura(VEN);
	Imprime(VEN);
	ventasMes(VEN);
	ventasJulio(VEN, 7);
	departamento(VEN, 3);
}

void Lectura(float A[][12])
{
	int I, J;
	for(I = 0; I < 5; I++)
		for(J = 0; J < 12; J++)
		{
			printf("Ventas del Departamento %d en el Mes %d:\n", I + 1, J + 1);
			scanf("%f", &A[I][J]);
		}
}

void Imprime(float A[][12])
{
	int I, J;
	printf("\n");
	for(I = 0; I < 5; I++)
	{
		printf("|");
		for(J = 0; J < 12; J++)
			printf(" %.2f |", A[I][J]);
		printf("\n");
	}
}

void ventasMes(float A[][12])
{
	int I, J;
	float SUM, SUMT = 0.0;

	printf("\nVentas mensuales y monto total:\n\n");
	for(J = 0; J < 12; J++)
	{
		SUM = 0.0;
		for(I = 0; I < 5; I++)
			SUM += A[I][J];
		printf("MES %d: %.2f\n", J + 1, SUM);
		SUMT += SUM;
	}
	printf("\nMonto total del año: %.2f\n", SUMT);
}

void ventasJulio(float A[][12], int M)
{
	int I, J, MAY = 0;
	float VENMA = A[0][M - 1];
	for(I = 1; I < 5; I++)
	{
		if(A[I][M - 1] > VENMA)
		{
			VENMA = A[I][M - 1];
			MAY = I;
		}
	}
	printf("\nEn el mes de julio, el departamento que obtuvo mayor ventas fue: %d, con ventas de: %.2f\n", MAY + 1, VENMA);
}

void departamento(float A[][12], int D)
{
	int I, J, MESMEN = 0, MESMAY = 0;
	float VENMEN = A[D - 1][0], VENMAY = A[D - 1][0];
	for(J = 1; J < 12; J++)
	{
		if(A[D - 1][J] < VENMEN)
		{
			VENMEN = A[D - 1][J];
			MESMEN = J;
		}
		if(A[D - 1][J] > VENMAY)
		{
			VENMAY = A[D - 1][J];
			MESMAY = J;
		}
	}
	printf("\nEl mes en el que el departamento 3 tuvo mayores ventas fue el: %d, con %.2f en ventas", MESMAY + 1, VENMAY);
	printf("\nEl mes en el que el departamento 3 tuvo menores ventas fue el: %d, con %.2f en ventas\n", MESMEN + 1, VENMEN);
}
