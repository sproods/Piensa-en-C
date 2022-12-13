/* programa que escribe en un archivo dat un lista ordenada procedente de otro archivo dat. */

#include <stdio.h>

#define MAX 100

void ordena(FILE *, FILE *);

void main(void)
{
	FILE *arxiv, *arxiv1;
	
	arxiv = fopen("arc.dat", "r");
	arxiv1 = fopen("arc1.dat", "w");
	
	if ((arxiv != NULL) && (arxiv1 != NULL))
	{
		ordena(arxiv, arxiv1);
		fclose(arxiv);
		fclose(arxiv1);
	}
	else
		printf("\nUno o los dos archivos no han podido ser abiertos.\n");
}

void ordena(FILE *ar, FILE *ar1)
{
	int mat, tam = 0, i, j, a, Mats[MAX], min, aux, index;
	float cal, cali[3];
	
	while (!feof(ar))			// realizamos un conteo de filas
	{
		fscanf(ar, "%d", &mat);
		for (i = 0; i < 3; i++)
			fscanf(ar, "%f", &cal);
		tam++;
	}
	
	rewind(ar);
	for (i = 0; i < tam; i++)		// copiamos loas matriculas en un arreglo unidimensional
	{
		fscanf(ar, "%d", &Mats[i]);
		for (j = 0; j < 3; j++)
			fscanf(ar, "%f", &cal);
	}
	
	// hacemos un odenamiento interno en el arreglo Mats
	for (i = 0; i < tam - 1; i++)
	{
		min = Mats[i];
		index = i;
		for (j = i + 1; j < tam; j++)
		{
			if (min > Mats[j])
			{
				min = Mats[j];
				index = j;
			}
		}
		
		aux = Mats[i];
		Mats[i] = Mats[index];
		Mats[index] = aux;
	}
	
	// realizamos, finalmente, la escritura ordenada de las matrículas con sus respectivas notas en el nuevo archivo
	for (i = 0; i < tam; i++)
	{
		rewind(ar);
		for (j = 0; j < tam; j++)
		{
			fscanf(ar, "%d", &mat);
			for (a = 0; a < 3; a++)
				fscanf(ar, "%f", &cali[a]);
			if (mat == Mats[i])
			{
				fprintf(ar1, "%d", mat);
				for (a = 0; a < 3; a++)
					fprintf(ar1, "\t%.2f", cali[a]);
				break;
			}
		}
		if (i < tam - 1)
			fputs("\n", ar1);
	}
	
	printf("Archivo creado y ordenado satisfactoriamente.\n\tby Sproods---");
}