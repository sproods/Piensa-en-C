// El programa escribe cadenas de caracteres en un archivo.

#include <stdio.h>
#include <stdbool.h>

void main(void)
{
    int res;
    char words[100];
    FILE *arxiv;

    arxiv = fopen("myWords.txt", "w");          // se abre el archivo para escritura en la variable arxiv.
    
    if (arxiv != NULL)
    {
        while (true)
        {
            printf("\nDigite la frase inspiradora que tiene en mente:\n");
    
            // Se almacena la cadena de caracteres en la variable 'words'.
            gets(words);
            fflush(stdin);

            // Se escribe la variable de tipo cadena de caracteres 'words' en la variable de tipo FILE 'arxiv'.
            fputs(words, arxiv);

            printf("\n¿Desea digitar más frases inspiradoras? (sí-1   no(salir)-0)\n");
            scanf("%d", &res);
            fflush(stdin);

            if (res)
                fputc('\n', arxiv);
            else
                break;
        }

        // Se cierra el archivo.
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir.\n");
}
