// Programa que realiza el conteo de las paáginas totales en cada guión establecido por el usuario.
// Suma el tatal de cada una de las partes (planteamiento, confrontación y resolución) para obtener el total y corregir cada uno de sus componentes.
// veinticinco por ciento del total para el planteamiento; cincuenta por ciento del total para la confrontación y veinticinco por ciento del total para la resolución.

#include <stdio.h>

typedef struct
{
    int number;
    char title[50];
    int n_pages;
    char plot[250];
    char plant[250];
    int plant_npages;
    char plotpoint1[250];
    char conf[250];
    int conf_npages;
    char plotpoint2[250];
    char reso[250];
    int res_npages;
} Guion;

void Countpages(FILE *);

void main(void)
{
    FILE * arxiv;

    if ((arxiv = fopen("estructura.dat", "r+")) != NULL)
    {
        Countpages(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void Countpages(FILE *arc)
{
    int total, tam, i;
    Guion miguion;

    tam = sizeof(Guion);            // determinamos el tamaño de la estructura
    printf("\nEl tamaño de la estructura es: %d", tam);

    fseek(arc, 0, 0);
    fread(&miguion, sizeof(Guion), 1, arc);     // leemos los datos de la primera estructura

    while (!feof(arc))
    {
        i = ftell(arc) / tam;       // determinamos el tamaño de cada bloque debajo del apuntador
        printf("\nEl tamaño de los bloques debajo del apuntador actual es: %d", i);

        printf("\n\tEl valor de este ftell es %d\n", ftell(arc));           // vemos el valor de ftell, si podemos.

        total = miguion.plant_npages + miguion.conf_npages + miguion.res_npages;
        printf("\nEl total de páginas real es: %d", total);

        // asignamos los nuevos valores a cada número de páginas
        miguion.n_pages = total;
        if (total % 2 == 0)
        {
            miguion.conf_npages = total * 0.5;
            if ((total / 2) % 2 == 0)
            {
                miguion.plant_npages = total * 0.25;
                miguion.res_npages = total * 0.25;
            }
            else
            {
                miguion.plant_npages = (total * 0.25) + 1;
                miguion.res_npages = (total * 0.25);
            }
        }
        else
        {
            miguion.plant_npages = total * 0.25;
            miguion.conf_npages = (total * 0.5) + 1;
            miguion.res_npages = total * 0.25;
        }

        printf("\nLos nuevos valores de páginas de cada parte de la línea argumental son:");
        printf("\n\tPlanteamiento: %d páginas\n\tConfrontación: %d páginas\n\tResolución: %d páginas\n", miguion.plant_npages, miguion.conf_npages, miguion.res_npages);

        fseek(arc, (i - 1) * sizeof(Guion), 0);     // nos posicionamos para escribir el registro actualizado

        fwrite(&miguion, sizeof(Guion), 1, arc);    // escribimos el registro actualizado

        fseek(arc, i * sizeof(Guion), 0);           // nos posicionamos para leer el siguiente registro

        fread(&miguion, sizeof(Guion), 1, arc);
    }

    printf("\n¡Registros actualizados!\n");
}
