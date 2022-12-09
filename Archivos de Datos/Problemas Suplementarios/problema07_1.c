/* programa que ordena una lista y elimina los archivos repetidos de una estructura en un
 * archivo de acceso directo .dat */

// este programa escribe en el archivo dat, ad5.dat, toda la información determinada.
 
 #include <stdio.h>
 #include <stdbool.h>
 
 typedef struct
 {
	 int mat;			// matrícula del alumno.
	 char name[30];		// nombre del alumno.
	 int career;		// carrera en la que está inscrito el alumno.
	 float prom;		// promedio del alumno. 
 } Datos;
 
 void registra(FILE *);
 
 void main(void)
 {
	 FILE *arxiv;
	 
	 if ((arxiv = fopen("ad5.dat", "w")) != NULL)
	 {
		 registra(arxiv);
		 fclose(arxiv);
	 }
	 else
		 printf("\nEl archivo no ha podido ser abierto.\n");
 }
 
 void registra(FILE *arc)
 {
	 int i = 0, res;
	 Datos datos_alumno;
	 
	 printf("\n\tRegistro de datos de los alumnos.\n");
	 printf("Digite por favor los datos seguientes:\n");
	 
	 while (true)
	 {
		 i++;
		 
		 printf("\nDatos del alumno %d:\n", i);
		 
		 printf("\nMatrícula del alumno: ");
		 scanf("%d", &datos_alumno.mat);
		 fflush(stdin);
		 
		 printf("\nNombre del alumno:\n");
		 gets(datos_alumno.name);
		 
		 do
		 {
			 printf("\nCarrera del alumno (1, 2, 3, o 4): ");
			 scanf("%d", &datos_alumno.career);
			 fflush(stdin);
		 }
		 while (datos_alumno.career < 1 || datos_alumno.career > 4);
			 
		 printf("\nPromedio del alumno: ");
		 scanf("%f", &datos_alumno.prom);
		 fflush(stdin);
		 
		 fwrite(&datos_alumno, sizeof(Datos), 1, arc);
		 
		 printf("\n¿Desea ingresar más datos de otro alumno? (1. sí   0. no (salir))\n");
		 scanf("%d", &res);
		 fflush(stdin);
		 
		 if (res == 0)
			 break;
	 }
	 
	 printf("\nDatos registrados satisfactoriamente.\n");
 }