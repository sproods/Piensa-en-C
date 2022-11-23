// El programa realiza la escritura en un archivo de acceso secuencial, caracter por caracter.

#include <stdio.h>

void main(void)
{
    char character;
    FILE *arxiv;

    arxiv = fopen("myWords.txt", "w");

    if (arxiv != NULL)
    {
        printf("\nEscriba, a continuación, la frase inspiradora que alberga en su memoria:\n");

        while (character = getchar() != '\n')
            fputc(character, arxiv);

        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha sido encontrado en la carpeta.\n");
}
