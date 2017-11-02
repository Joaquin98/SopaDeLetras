#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "funciones.c"


void estaEnEstaDireccionTest(){
	printf("Testeando la funcion estaEnEstaDireccion ... \n");

	assert(!entraEnEstaDireccion(1,-1,2,2));
	assert(entraEnEstaDireccion(10,5,10,5));

	printf("Los test han pasado con exito!\n");
}

void dirPalabraTest(){
	printf("Testeando la funcion dirPalabraTest ... \n");

	char palabra [50] = {"HS"};
	char **tabla = malloc(sizeof(char *)*2);
	for(int i=0; i<2; i++){tabla[i] = malloc(50);}
	tabla[0] = "HOLAS";
	tabla[1] = "FSDFD";

	assert(7 == dirPalabra(palabra,2,5,tabla));

	printf("Los test han pasado con exito!\n");
}





int main()
{
	estaEnEstaDireccionTest();
	dirPalabraTest();
	printf("Todos los test han pasado con exito!\n");
	return 0;
}