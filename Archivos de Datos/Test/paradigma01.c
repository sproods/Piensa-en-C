// El programa escribe, en un archivo de acceso directo, los datos correspondientes a la escritura del paradigma de un guión.

#include <stdio.h>
#include <stdbool.h>

typedef struct                  // variable de tipo estructura screenplay
{
    int number;                 // número de guión.
    char title[50];             // título del guión.
    int n_pages;                // número de páginas de guión.
    char plot[250];            // tema del guión.
    char plant[250];           // planteamiento (acto I).
    int plant_npages;           // número de páginas del planteamiento.
    char plotpoint1[250];      // primer plot point.
    char conf[250];            // confontración (acto II).
    int conf_npages;            // número de páginas de la confrontación.
    char plotpoint2[250];      // segundo plot point.
    char reso[250];            // resolución (acto III).
    int res_npages;             // número de páginas de la resolución.
} Screenplay;

void write(FILE *);             // Prototipo de la función que escribirá en el archivo .dat

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("estructura.dat", "w")) != NULL)
    {
        write(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void write(FILE *arc)
{
    int i = 0, res = 1;
    Screenplay my_screenplay;

    printf("\nSea bienvenido al registro personal de su guión\n\nPor favor escriba en los campos correspondientes cada uno de las descripciones que se le pidan.\n");

    while (true)
    {
        i++;
        printf("\nGuión %d\n", i);
        fflush(stdin);

        printf("\nDigite el número de guión: ");
        scanf("%d", &my_screenplay.number);
        fflush(stdin);

        printf("\nTítulo del guión:\n");
        gets(my_screenplay.title);
        fflush(stdin);

        printf("\nNúmero de páginas de \"%s\": ", my_screenplay.title);
        scanf("%d", &my_screenplay.n_pages);
        fflush(stdin);

        printf("\nTema:\n");
        gets(my_screenplay.plot);
        fflush(stdin);

        printf("\nPlanteamiento:\n");
        gets(my_screenplay.plant);
        fflush(stdin);

        printf("\nNúmero de páginas del planteamiento: ");
        scanf("%d", &my_screenplay.plant_npages);
        fflush(stdin);

        printf("\nPrimer \"Plot Point\":\n");
        gets(my_screenplay.plotpoint1);
        fflush(stdin);

        printf("\nConfrontación:\n");
        gets(my_screenplay.conf);
        fflush(stdin);

        printf("\nNúmero de páginas de la confrontación: ");
        scanf("%d", &my_screenplay.conf_npages);
        fflush(stdin);

        printf("\nSegundo \"Plot Point\":\n");
        gets(my_screenplay.plotpoint2);
        fflush(stdin);

        printf("\nResolución:\n");
        gets(my_screenplay.reso);
        fflush(stdin);

        printf("\nNúmero de páginas de la resolución: ");
        scanf("%d", &my_screenplay.res_npages);
        fflush(stdin);

        /* A continuación, se escriben todos estos datos utilizando la función fwrite. */
        fwrite(&my_screenplay, sizeof(Screenplay), 1, arc);

        printf("\n¿Desea continuar escribiendo el paradigma de otro guión? (sí - 1   no - 0): ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;
    }
}
