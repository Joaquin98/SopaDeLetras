#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.c"

// main : None -> Int
// Es la funcion principal que se encarga de llamar
// a las demas funciones para poder ingresar y buscar
// las palabras en la sopa de letras.

int main()
{
    int tamanioUniverso, numeroFilas, numeroColumnas, op = -1;
    char **Universo, **tabla;

    ingresoTamanios(&tamanioUniverso, &numeroFilas, &numeroColumnas, &op);

    Universo = ingresoUniverso(tamanioUniverso,op);

    tabla = ingresoTabla(numeroFilas,numeroColumnas,op);


    for(int i = 0 ; i < tamanioUniverso ; i++)
        mostrarOrientacionPalabra(Universo[i],dirPalabra(Universo[i],numeroFilas,numeroColumnas,tabla));


    return 0;
}
