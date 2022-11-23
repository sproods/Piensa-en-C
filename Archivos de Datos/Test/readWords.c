// El programa lee cadenas de caracteres de un archivo de acceso directo.

#include <stdio.h>

void main(void)
{
    char words[100];
    FILE *arxiv;

    arxiv = fopen("myWords.txt", "r");

    if (arxiv != NULL)
    {
        putchar('\n');

        while (!feof(arxiv))        // Se leen las cadenas hasta el final del archivo.
        {
            // Cogemos la cadena de caracteres del archivo y la almacenamos en la variable words.
            fgets(words, 100, arxiv);

            // Escribimos la cadena almacenada en la pantalla con la clásica puts().
            // puts(words);
            
            // Variante de la escritura de una cadena de caracteres sin salto de línea.
            printf("%s", words);
        }
        puts("\n");

        // Cerramos el archivo de texto.
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}
