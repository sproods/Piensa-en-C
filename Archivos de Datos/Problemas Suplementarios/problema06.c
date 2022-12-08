/* programa que realiza la corrección ortográfica de las letras b y v en la escritura española. */

#include <stdio.h>
#include <string.h>

#define MAX 50

void correction(FILE *);            // prototipo de función

void main(void)
{
    FILE *arxiv;

    arxiv = fopen("doc.dat", "r");

    if (arxiv != NULL)
    {
        correction(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto. :(\n");
}

void correction(FILE *arc)
{
	char cad[250];
	int i, fila = 0, res = 0;
	
	while (!feof(arc))
	{
		fila++;
		fgets(cad, 250, arc);
		
		i = 0;
		while (cad[i] != '\n')
		{
			if ((cad[i] == 'n') && (cad[i + 1] == 'p'))
			{
				res++;
				printf("\nEn la línea %d, la letra \'n\' en la posición %d, debe ser \'m\'\n", fila, i + 1);
			}
			
			if ((cad[i] == 'n') && (cad[i + 1] == 'b'))
			{
				res++;
				printf("\nEn la línea %d, la letra \'n\' en la posición %d, debe ser \'m\'\n", fila, i + 1);
			}
			
			if ((cad[i] == 'm') && (cad[i + 1] == 'v'))
			{
				res++;
				printf("\nEn la línea %d, la letra \'n\' en la posición %d. debe ser \'m\'\n", fila, i + 1);
			}
			
			i++;
		}
	}
	
	if (res)
		printf("\nHubieron %d errores ortográficos en el archivo.\nRevisión terminada.\n", res);
	else
		printf("\nNo hubo ningún error ortográfico en el archivo.\nRevisión terminada\n");
}