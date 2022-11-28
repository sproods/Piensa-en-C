/* Programa de verificación del uso de la librería conio.h y de la opción de cambio de nombre de archivo de un archivo */

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

typedef struct
{
	int id;
	int note[3];
	float rank;
	char name[30];
} Datos;

void main(void)
{
	FILE *arxiv;
	char arc_name[20];
	Datos myDates;
	int i = 0;
	
	printf("\nDigite el nombre del archivo en el que desea trabajar: ");
	gets(arc_name);

	arxiv = fopen(arc_name, "w");

	if (arxiv != NULL)
	{
		printf("\nDigite el número de identificación: ");
		scanf("%d", &myDates.id);
		for (i = 0; i < 3; i++)
		{
			printf("Digite la nota %d: ", i + 1);
			scanf("%d", &myDates.note[i]);
		}
		printf("\nDigite el número de valoración que tiene este registro: ");
		scanf("%f", &myDates.rank);

		fflush(stdin);
		printf("\nDigite su nick, por favor: ");
		gets(myDates.name);

		// Escritura de los datos en el archivo.
		fwrite(&myDates, sizeof(Datos), 1, arxiv);
	}
	else
		printf("\nEl archivo no ha podido se abierto.\n");

	fclose(arxiv);
}