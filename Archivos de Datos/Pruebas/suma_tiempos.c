#include <stdio.h>

// El programa lee los datos de un archivo y obtiene la suma de los tiempos.

void main(void)
{
    int i, j, num;
    float sum, time;
    FILE *arxiv;

    if ((arxiv = fopen("meditacion.txt", "r")) != NULL)
    {
        fscanf(arxiv, "%d", &num);         // Se lee el primer elemento que corresponde con el número de días que he meditado.

        if (num == 1)
            printf("\nHe meditado %d vez al día.\n", num);
        else
            if (num > 1)
                printf("\nHe meditado %d veces al día.\n", num);
            else
                if (num < 1)
                    printf("\nNo se ha meditado abosolutamente nada.\n");

        sum = 0;

        for (i = 0; i < num; i++)
        {
            fscanf(arxiv, "%f", &time);     // Se lee el primer registro de tiempo.
            printf("\tEl tiempo %1d fue de %5.2f minutos.\n", i + 1, time);
            sum += time;
        }
        printf("\nEl tiempo total de meditación fue de %.2f minutos.\n", sum);

        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}