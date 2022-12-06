// programa que registra en un archivo tipo dat varias cadenas de caracteres para la resolución del problema seis.

#include <stdio.h>
#include <stdbool.h>

void write(FILE *);

void main(void)
{
	FILE *arxiv;
	
	if ((arxiv = fopen("doc.dat", "w")) != NULL)
	{
		write(arxiv);
		fclose(arxiv);
	}
	else
		printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *arc)
{
	int res, i = 0;
	char string[250];
	
	while (true)
	{
		i++;
		printf("Digite la cadena de caracteres %d de su preferencia:\n", i);
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