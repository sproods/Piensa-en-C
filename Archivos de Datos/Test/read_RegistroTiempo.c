// El programa realiza la lectura de los datos del archivo habitos.txt y los imprime en pantalla, además realiza el cálculo del promedio de los tiempos.

#include <stdio.h>
#include <string.h>

#define N 30
#define M 50

void main(void)
{
    int i, j, n_Time, n_Act;
    char char_Tiempo[15], activity[N][30];
    float tiempo[M];
    FILE *arxiv;

    arxiv = fopen("habitos.txt", "r");

    if (arxiv != NULL)
    {
        putchar('\n');

        while (!feof(arxiv))
        {
            // Obtenemos el tiempo que hemos puesto como control.
            fgets(char_Tiempo, 15, arxiv);

            // Escribimos en pantalla la cadena de caracteres que obtenemos.
            puts(char_Tiempo);

            // Obtenemos el número del tiempo en que se van a registrar las actividades.
            fscanf(arxiv, "%d", &n_Time);
            fflush(stdin);

            // Imprimimos en pantalla el valor de n_Time.
            printf("%d", n_Time);

            // Obtenemos el número de actividades.
            fscanf(arxiv, "%d", &n_Act);
            fflush(stdin);

            // Imprimimos en pantalla el valor de n_Act.
            printf("\n%d", n_Act);

            for (i = 0; i < n_Act; i++)
            {
                putchar('\n');
                fgets(activity[i], 30, arxiv);          // Obtenemos y almacenamos el nombre de cada una de las actividades.
                puts(activity[i]);                      // Imprimimos en pantalla el nombre de las actividades.

                for (j = 0; j < n_Time; j++)
                {
                    fscanf(arxiv, "%f", &tiempo[j]);     // Obtenemos el valor de cada uno de los tiempos escritos en el archivo.
                    fflush(stdin);
                    printf("\n%.2f", tiempo[j]);          // Escribimos en pantalla el valor de cada uno de los tiempos.
                }
            }

        }
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no se ha podido abrir.\n");
}
