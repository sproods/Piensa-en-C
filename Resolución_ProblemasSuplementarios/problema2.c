#include <stdio.h>

/* El programa realiza el análisis y la muestra en pantalla de algunos datos estadísticos a tomar en cuenta para la mejora sustanciosa de una fábrica de la que se toman los datos de sus respectivos cinco departamentos. */

void Lectura(float [][12]);
void Imprime(float [][12]);
void ventasMes(float [][12]);
void VentasJulio(float [][12]);
void departamento3(float [][12]);

void main(void)
{
	float VEN[5][12];

	Lectura(VEN);
	Imprime(VEN);
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
