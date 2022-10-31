// El programa escribe en un archivo binario una serie de frases de grandes mentes de la humanidad. Aunque podría tratarse de cualquier frase. Tambien escribe el año en el que se pronunció dicha frase y el autor o autora de dicha frase.

#include <stdio.h>

typedef struct
{
    char frase[1000];       // Frase.
    int year;               // Año en que se dijo o se escribió esa frase.
    char author[100];       // Nombre del autor de la frase.
} text;

void Write(FILE *);         // Prototipo de la función que escribe en el archivo.
void Read(FILE *);          // Prototipo de la función que lee el archivo dat.
void modFrase(FILE *);      // Prototipo de la función que modifica solo la frase.
void modAuthor(FILE *);     // Prototipo de la función que modifica el nombre del autor.
void modYear(FILE *);       // Prototipo de la función que modifica solo el año.

void main(void)
{
    FILE *arxiv;
    int op1, op2;

    printf("\nEscoja una de las siguientes opcionnes:\n");
    do
    {
        printf("\t1. Escribir un archivo   2. Leer un archivo   3. Modificar un archivo\n");
        scanf("%d", &op1);
        fflush(stdin);
    } while(op1 < 1 || op1 > 3);

    switch(op1)
    {
        case 1: Write(arxiv);
            break;
        case 2: Read(arxiv);
            break;
        case 3:
            {
                printf("\n¿Qué desea modificar?\n");

                do
                {
                    printf("\t1. La frase   2. El año   3. El nombre del autor\n");
                    scanf("%d", &op2);
                    fflush(stdin);
                } while(op2 < 1 || op2 > 3);

                switch(op2)
                {
                    case 1: modFrase(arxiv);
                        break;
                    case 2: modYear(arxiv);
                        break;
                    case 3: modAuthor(arxiv);
                        break;
                }
            }
            break;
    }
}

void Write(FILE *arc)
{
    text lines;
}

void Read(FILE *arc)
{
    text lines;
}

void modFrase(FILE *arc)
{
    text lines;
}

void modAuthor(FILE *arc)
{
    text lines;
}

void modYear(FILE *arc)
{
    text lines;
}