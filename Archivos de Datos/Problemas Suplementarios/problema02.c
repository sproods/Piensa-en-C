// El programa realiza el conteo del número de veces que aparece cada vocal en un archivo de acceso secuencial.

#include <stdio.h>

void conteo(FILE *);

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("arc.txt", "r")) != NULL)
    {
        conteo(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido se abierto.\n");
}

void conteo(FILE *arc)
{
    int k, a = 0, e = 0, i = 0, o = 0, u = 0;
    char cadena[250], cad;

    while (!feof(arc))
    {
        cad = fgetc(arc);

        if (cad == 'a' || cad == 'A')
            a++;
        if (cad == 'e' || cad == 'E')
            e++;
        if (cad == 'i' || cad == 'I')
            i++;
        if (cad == 'o' || cad == 'O')
            o++;
        if (cad == 'u' || cad == 'U')
            u++;
    }

    if (a == 0 && e == 0 && i == 0 && o == 0 && u == 0)
        printf("\nEl archivo no tiene vocales.\n");
    else
    {
        printf("\nConteo de vocales:\n");
        printf("\ta: %d\n\te: %d\n\ti: %d\n\to: %d\n\tu: %d\n", a, e, i, o, u);
    }
}