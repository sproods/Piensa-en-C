// El programa lee el contenido, en este caso una cadena de caracteres, que se encuentra en el archivo de acceso secuencial myWords.txt.

#include <stdio.h>

void main(void)
{
    char character;
    FILE *arxiv;

    // Abriendo el archivo en la variable de tipo FILE.
    arxiv = fopen("myWords.txt", "r");

    // Verificando que el archivo de texto exista para poder abrirlo.
    if (arxiv != NULL)
    {
        // Utilizando una estructura repetitiva while para leer cada caracter.
        while (!feof(arxiv))
        // se asegura de que se lean cada uno de los caracteres hasta el final del archivo, por lo que se usa la función feof, que vendría a ser como una función 'función de fin de línea (EOF)'.
        {
            character = fgetc(arxiv);
            putchar(character);
        }

        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir.\n");
}

