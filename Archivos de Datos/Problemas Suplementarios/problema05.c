// programa que realiza la inversión en la posición de cada línea de de texto en un archivo de acceso directo.

#include <stdio.h>

void invierte(FILE *, FILE *);			// prototipo de función

void main(void)
{
	FILE *arxiv1, *arxiv2;
	
	arxiv1 = fopen("arc4.txt", "r");
	arxiv2 = fopen("arc5.txt", "a+");
	
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
	char cadena[250];
	
	while (!feof(arc1))
	{
		fgets(cadena, 250, arc1);
		//rewind(arc2);
		//fputs("\n", arc2);
		fputs(cadena, arc2);
	}
}