#include <stdio.h>

/* Funciones para el manejo de caracteres de la biblioteca stdio.h */

void main(void)
{
	char p1, p2, p3 = '$';
	char letra1, letra2, letra3, letra4;
	/* Declaración de las variables tipo caracter p1, p2, p3. Observa que a p3 se le asigna el símbolo $. */

	printf("\nDigite un caracter: ");
	p1 = getchar();		/* Se utiliza la función getchar para leer un caracter. */
	putchar(p1);		/* Se utiliza la función putchar para escribir un caracter. */
	printf("\n");
	fflush(stdin);		/* Luego de leer un caracter siempre es conveniente escribir la función fflush para limpiar el búfer, porque generalmente queda con basura y genera un error en la ejecución del programa. El error se produce porque cuando se ingresa un dato se oprime el return y luego cuando volvemos a leer un caracter o una cadena de caracteres se toma a ese return como el nuevo dato ingreso. */

	printf("\nEl caracter p3 es: ");
	putchar(p3);		/* Se utiliza la función putchar para escribir el caracter almacenado en p3. */
	printf("\n");

	printf("\nDigite otro caracter: ");
	fflush(stdin);
	scanf("%c", &p2);	/* Se puede utilizar scanf con el formato de variable %c para leer un caracter. */
	printf("%c", p2);	/* Se puede utilizar printf con el formato de variable %c para escribir un caracter. */
	fflush(stdin);

	printf("\nDigite el primer caracter de la palabra: ");
	letra1 = getchar();
	fflush(stdin);

	printf("\nDigite el segundo caracter de la palabra: ");
	letra2 = getchar();
	fflush(stdin);

	printf("\nDigite el tercer caracter de la palabra: ");
	letra3 = getchar();
	fflush(stdin);

	printf("\nDigite el cuarto caracter de la palabra: ");
	letra4 = getchar();
	fflush(stdin);

	printf("\n");
	putchar(letra1);
	putchar(letra2);
	putchar(letra3);
	putchar(letra4);
	printf("\n");
}
