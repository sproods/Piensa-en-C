// El programa lee el contenido almacenado en el archivo .dat

#include <stdio.h>
#include <stdbool.h>

typedef struct                  // variable de tipo estructura
{
    char title[50];             // título del guión
    int n_pages;                // número de páginas del guión
    char plot[1500];            // tema del [guión
    char plant[1000];           // planteamiento (acto I)
    int plant_npages;           // número de páginas del planteamiento
    char plotpoint1[1000];      // primer plot point
    char conf[1000];            // confrontación (acto II)
    int conf_npages;            // número de páginas de la confrontación
    char plotpoint2[1000];      // segungo plot point
    char reso[1000];          // resolución (acto III)
    int res_npages;             // número de páginas de la resolución
} Screenplay;

void read(FILE *);              // prototipo de la función que leerá los datos almacenados en el archivo

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("estructura.dat", "r")) != NULL)
    {
        read(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void read(FILE *arc)
{
    int i = 0;
    Screenplay my_screenplay;

    /* se efectúa una primera lectura de la estructura usando la función fread */
    fread(&my_screenplay, sizeof(Screenplay), 1, arc);

    while (!feof(arc))
    {
        printf("\nTítulo del guión %d:\n\t%s\n que tiene %d páginas.", i + 1, my_screenplay.title, my_screenplay.n_pages);
        printf("\nTema del guión:\n%s", my_screenplay.plot);
        printf("\nPlanteamiento:\n%s\ncon %d páginas.", my_screenplay.plant, my_screenplay.plant_npages);
        printf("\nPrimer Plot Point:\n%s", my_screenplay.plotpoint1);
        printf("\nConfrontación:\n%s\ncon %d páginas.", my_screenplay.conf, my_screenplay.conf_npages);
        printf("\nSegundo Plot Point:\n%s", my_screenplay.plotpoint2);
        printf("\nResolución:\n%s\ncon %d páginas.", my_screenplay.reso, my_screenplay.res_npages);

        /* se vuelve a leer otra estructura hasta el final del archivo */
        fread(&my_screenplay, sizeof(Screenplay), 1, arc);
        i++;
    }
}