/* el programa lee los datos almacenados en el archivo que se escribio utilizando el programa archivo01.c */

#include <stdio.h>

typedef struct
{
	int id;
	int notas[3];
	float ranking;
	char name[30];
} Datos;

void main(void)
{
	FILE *arxiv;
	char arc_name[20];
	Datos myDates;
	int i = 0;

	printf("\nDigite el nombre del archivo que desea leer: ");
	gets(arc_name);

	arxiv = fopen(arc_name, "r");

	if (arxiv != NULL)
	{
		fread(&myDates, sizeof(Datos), 1, arxiv);

		while(!feof(arxiv))
		{
			printf("\nNúmero de identificación: %d", myDates.id);

			printf("\nNotas:");
			for (i = 0; i < 3; i++)
			{
				printf("\n\tNota %d: %d", i + 1, myDates.notas[i]);
			}

			printf("\nEl ranking dado por el usuario es: %.2f\n", myDates.ranking);

			printf("\n\t¡Gracias señor %s!\n", myDates.name);
			// puts(myDates.name);

			fread(&myDates, sizeof(Datos), 1, arxiv);
		}

		fclose(arxiv);
	}
	else
		printf("\nEl archivo no ha podido se abierto.\n");
}