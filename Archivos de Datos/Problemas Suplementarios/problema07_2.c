/* el programa lee el registro en el cual se almacena la información de los alumnos del problema siete. */

#include <stdio.h>

typedef struct
{
	int mat;
	char name[30];
	int car;
	float prom;
} Datos;

void lee(FILE *);

void main(void)
{
	FILE *arxiv;
	
	if ((arxiv = fopen("ad5.dat", "r")))
	{
		lee(arxiv);
		fclose(arxiv);
	}
	else
		printf("\nEl archivo no se ha podido abrir.\n");
}

void lee(FILE *arc)
{
	int i = 0;
	Datos datos_alumno;
	
	fread(&datos_alumno, sizeof(Datos), 1, arc);
	
	while(!feof(arc))
	{
		i++;
		
		printf("\nDatos del alumno %d\n", i);
		printf("\nMatrícula: \t%d", datos_alumno.mat);
		printf("\nNombre: \t%s", datos_alumno.name);
		printf("\nCarrera: \t%d", datos_alumno.car);
		printf("\nPromedio: \t%.2f\n", datos_alumno.prom);
		
		fread(&datos_alumno, sizeof(Datos), 1, arc);
	}
}