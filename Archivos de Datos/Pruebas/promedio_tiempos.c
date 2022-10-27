#include <stdio.h>

// El programa realiza el cálculo del promedio del tiempo de meditación utilizando una función.

float promedio(FILE *);         // Prototipo de la función.

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("meditacion.txt", "r")) != NULL)
    {
        promedio(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nNo se ha podido abrir el archivo.\n");
}

float promedio(FILE *archivo)
{
    int i, num;
    float time, sum, prom;

    fscanf(archivo, "%d", &num);

    sum = 0;

    for (i = 0; i < num; i++)
    {
        fscanf(archivo, "%f", &time);
        sum += time;
    }

    prom = sum / num;

    printf("\nEl promedio en los %d días de meditación es de %.2f minutos de meditación por día.\n", num, prom);
}