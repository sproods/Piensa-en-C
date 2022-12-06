/* programa que escribe en un archivo de texto varias cadenas de caracteres para ser de ayuda en la resolución del problema cinco. */

#include <stdio.h>
#include <stdbool.h>

void write(FILE *);

void main(void)
{
    FILE *arxiv;
	
	if ((arxiv = fopen("arc4.txt", "w")) != NULL)
	{
		write(arxiv);
		fclose(arxiv);
	}
	else
		printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *arc)
{
	int i = 0, res;
	char string[250];
	
	while (true)
	{
		i++;
		printf("\nDigite la cadena de texto %d:\n", i);
		gets(string);
		fputs(string, arc);
		
		printf("\n¿Desea digitar otra cadena de caracteres? (1. sí   0. no-salir): ");
		scanf("%d", &res);
		fflush(stdin);
		
		if (res == 0)
			break;
		
		fputs("\n", arc);
	}
}