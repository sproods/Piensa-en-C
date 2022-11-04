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

void Write(FILE *arc)           // Función que escribe en un archivo un registro.
{
    text lines;
    int r;

    if ((arc = fopen("caja_textos.dat", "w")) != NULL)
    {
        r = 1;

        while(r)
        {
            printf("\nDigite la frase:\n");
            gets(lines.frase);
            fflush(stdin),

            printf("\nDigite el autor de la frase:\n");
            gets(lines.author);
            fflush(stdin);

            printf("\nDigite el año en que %s pronunció dicha frase:\n", lines.author);
            scanf("%d", &lines.year);
            fflush(stdin);

            fwrite(&lines, sizeof(text), 1, arc);

            printf("\n¿Desea ingresar más frases? (Sí- 1   No- 0)");
            scanf("\n%d", &r);
            fflush(stdin);
        }
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");

    fclose(arc);

    printf("\n¡Gracias por dejar las mejores frases digitadas en una archivo .dat!\n");
}

void Read(FILE *arc)            // Función que lee los datos de un archivo de acceso directo.
{
    text lines;
    int i = 0;

    if ((arc = fopen("caja_textos.dat", "r")) != NULL)
    {
        fread(&lines, sizeof(text), 1, arc);

        while(!feof(arc))
        {
            printf("\nFRASE %d:\n\t<<%s>>", i + 1, lines.frase);
            printf("\n\n\t\tAUTOR: %s", lines.author);
            printf("\n\t\t%7d", lines.year);

            i++;

            fread(&lines, sizeof(text), 1, arc);
        }

        printf("\n\nÉstas son todas las frases hasta el momento.\n¡Gracias por su atención!\n");
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");

    fclose(arc);
}

void modFrase(FILE *arc)
{
    text lines;
    int d;

    if ((arc = fopen("caja_textos.dat", "r+")) != NULL)
    {
        printf("\nDigite el número del registro que desea modificar: ");
        scanf("%d", &d);
        fflush(stdin);

        fseek(arc, (d - 1) * sizeof(text), 0);      // Nos posicionamos en el archivo correspondiente.

        fread(&lines, sizeof(text), 1, arc);        // Leemos el archivo correspondiente.

        printf("\nDigite la frase, que desea modificar, del autor %s:\n", lines.author);
        gets(lines.frase);
        fflush(stdin);

        fseek(arc, (d - 1) * sizeof(text), 0);      // Nos volvemos a posicionar en el lugar correcto.

        fwrite(&lines, sizeof(text), 1, arc);
    }

    else
        printf("\nEl archivo no se ha podido abrir.\n");

    fclose(arc);
}

void modAuthor(FILE *arc)
{
    text lines;
}

void modYear(FILE *arc)
{
    text lines;
}