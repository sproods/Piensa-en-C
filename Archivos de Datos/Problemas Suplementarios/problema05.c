// programa que realiza la inversión en la posición de cada línea de de texto en un archivo de acceso directo.

#include <stdio.h>
#include <string.h>

#define MAX 50

void invierte(FILE *, FILE *);			// prototipo de función

void main(void)
{
	FILE *arxiv1, *arxiv2;
	
	arxiv1 = fopen("arc4.txt", "r");
	arxiv2 = fopen("arc5.txt", "w");
	
	if ((arxiv1 != NULL) && (arxiv2 != NULL))
	{
		invierte(arxiv1, arxiv2);
		fclose(arxiv1);
		fclose(arxiv2);
	}
	else
		printf("\nAlguno de los archivos, o ambos, no han podido ser abiertos.\n");
}

void invierte(FILE *arc1, FILE *arc2)
{
	int lines = 0, i;
	char dance[250], strings[MAX][250];
	
	// determinamos el número de líneas de texto que hay en el archivo.
	while (!feof(arc1))
	{
		fgets(dance, 250, arc1);
		lines++;
	}
	printf("La cantidad de líneas de texto es: %d", lines);
	
	rewind(arc1);
	
	// almacenamos cada cadena de caracteres en un arreglo de tipo cadena de caracteres
	while (!feof(arc1))
	{
		for (i = lines - 1; i >= 0; i--)
		{
			fgets(dance, 250, arc1);
			strcpy(strings[i], dance);
		}
	}
	
	// segundo método de almacenar
	/* for (i = lines - 1; i >= 0; i--)
	{
		fgets(dance, 250, arc1);
		strcpy(strings[i], dance);
	} */
	
	// escribimos las cadenas, invertidas, en el segundo archivo
	for (i = 0; i < lines; i++)
	{
		if (i == 0)
		{
			fputs(strings[i], arc2);
			fputs("\n", arc2);
		}
		else
			fprintf(arc2, "%s", strings[i]);
	}
}