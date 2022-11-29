// el programa realiza la modificación de algunos datos en la escritura de los guiones almacenada en el archivo estructura.dat

#include <stdio.h>
#include <stdbool.h>

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

void modifica(FILE *);
void g();

void main(void)
{
    FILE *arxiv;

    if ((arxiv = fopen("estructura.dat", "r+")) != NULL)
    {
        modifica(arxiv);
        fclose(arxiv);
    }
    else
        printf("\nEl archivo no ha podido ser abierto.\n");
}

void modifica(FILE *arc)
{
    int res = 1, n_guion, op;
    Guion miGuion;

    printf("\nBienvenido al modificador del programa de escritura de guiones.\n");

    while (true)
    {
        printf("\n¿Qué número de guión desea modificar? (respecto al orden en el que fue archivado): ");
        scanf("%d", &n_guion);
        fflush(stdin);

        fseek(arc, (n_guion - 1) * sizeof(Guion), 0);           // nos posicionamos en la estructura conveniente

        fread(&miGuion, sizeof(Guion), 1, arc);                 // leemos la estructura del archivo en la ubicación determinada

        printf("\n¿Qué desea modificar?");
        printf("\n1. Título\n2. Número de páginas\n3. Tema\n4. Planteamiento\n5. Páginas del planteamiento\n6. I plot point\n7. Confrontación");
        printf("\n8. Páginas de la confrontación\n9. II plot point\n10. Resolución\n11. Páginas de la resolución\n...Digite aquí su elección: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op)
        {
            case 1: printf("\nDigite el nuevo título:\n");
                    gets(miGuion.title);
                    fflush(stdin);
                    g();
                    break;
            case 2: printf("\nDigite las páginas del guión:\n");
                    scanf("%d", &miGuion.n_pages);
                    fflush(stdin);
                    g();
                    break;
            case 3: printf("\nDigite el nuevo tema:\n");
                    gets(miGuion.plot);
                    fflush(stdin);
                    g();
                    break;
            case 4: printf("\nDigite el nuevo planteamiento:\n");
                    gets(miGuion.plant);
                    fflush(stdin);
                    g();
                    break;
            case 5: printf("\nDigite el número de páginas del planteamiento:\n");
                    scanf("%d", &miGuion.plant_npages);
                    fflush(stdin);
                    g();
                    break;
            case 6: printf("\nDigite el nuevo primer plot point:\n");
                    gets(miGuion.plotpoint1);
                    fflush(stdin);
                    g();
                    break;
            case 7: printf("\nDigite la nueva confrontación:\n");
                    gets(miGuion.conf);
                    fflush(stdin);
                    g();
                    break;
            case 8: printf("\nDigite el número de páginas de la confrontación:\n");
                    scanf("%d", &miGuion.conf_npages);
                    fflush(stdin);
                    g();
                    break;
            case 9: printf("\nDigite el nuevo segundo plot point:\n");
                    gets(miGuion.plotpoint2);
                    fflush(stdin);
                    g();
                    break;
            case 10: printf("\nDigite la nueva resolución:\n");
                    gets(miGuion.reso);
                    fflush(stdin);
                    g();
                    break;
            case 11: printf("\nDigite el número de páginas de la resolución:\n");
                    scanf("%d", &miGuion.res_npages);
                    fflush(stdin);
                    g();
                    break;
        }

        fseek(arc, (n_guion - 1) * sizeof(Guion), 0);

        fwrite(&miGuion, sizeof(Guion), 1, arc);            // se escriben los datos modificados en el archivo

        printf("\nDigite cero (0) para salir o cualquier tecla para seguir editando: ");
        scanf("%d", &res);
        fflush(stdin);

        if (res == 0)
            break;
    }
}

void g()
{
    printf("\n¡Hecho!\n");
}