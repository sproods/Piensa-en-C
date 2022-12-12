/* Programa que escribe los datos necesarios para la resolución del problema ocho. */

#include <stdio.h>
#include <stdbool.h>

void write(FILE *);

void main(void)
{
	FILE *arxiv;
	
	if ((arxiv = fopen("arc.dat", "w")) != NULL)
	{
		write(arxiv);
		fclose(arxiv);
	}
	else
		printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *ar)
{
	int i, mat, res = 1;
	float cal;
	
	while (true)
	{
		printf("Digite la matrícula del alumno: ");
		scanf("%d", &mat);
		fflush(stdin);
		fprintf(ar, "%d\t", mat);
		
		for (i = 0; i < 3; i++)
		{
			printf("\nDigite la calificación %d: ", i + 1);
			scanf("%f", &cal);
			fflush(stdin);
			fprintf(ar, "%.2f\t", cal);
		}
		
		printf("\nDigite cero para dejar de registrar o culquier tecla para continuar con otras notas: ");
		scanf("%d", &res);
		fflush(stdin);
		
		if (res == 0)
			break;
		fputs("\n", ar);
	}
	
	printf("\nArchivo registrado...");
}