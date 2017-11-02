#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "funciones.c"

int main()
{
	assert(!entraEnEstaDireccion(1,-1,2,2));
	assert(entraEnEstaDireccion(10,5,10,5));
	printf("Todos los test han pasado con exito!\n");
	return 0;
}