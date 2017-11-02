#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// mayusculas : Char * -> None
// Toma una palabra y cambia todas sus letras a 
// Mayusculas.

void mayusculas(char *palabra){
    int longPalabra = strlen(palabra);
    for(int i=0; i<longPalabra; i++) palabra[i] = toupper(palabra[i]);
}


// estaEnEstaDireccion : Int, Int, Int, Char *, Char **, Int, Int -> Int
// Toma la segunda posicion de una palabra y la direccion, y se fija si
// la palabra se encuentra en esa direccion en la tabla.


int estaEnEstaDireccion(int lPalabra, int i, int j, char *palabra, char **tabla,int dF, int dC){

    for(int posEnPalabra = 1; posEnPalabra<lPalabra; posEnPalabra++){

        if(tabla[i][j] != palabra[posEnPalabra])
            return 0;

        i += dF;
        j += dC;
    }

    return 1;
}

// entraEnEstaDireccion : Int, Int, Int, Int -> Int
// Toma las posicion del ultimo caracter de la palabra y se fija si
// la posicion es valida (que se encuentra dentro de la tabla),
// en caso de que sea valida retorna 1 (Verdadero) y en caso contrario
// retorna 0 (Falso).

int entraEnEstaDireccion(int posFinalFilas, int posFinalColumnas, int numeroFilas, int numeroColumnas){

    if(posFinalFilas >= numeroFilas  || posFinalFilas < 0)
        return 0;
    if(posFinalColumnas >= numeroColumnas  || posFinalColumnas < 0)
        return 0;

    return 1;
}



// estaLaPalabra: array of Char , Int , Int , array of array of Char -> Int
// Toma como parametro una palabra y una tabla, si la palabra se encuentra
// en la tabla retorna un numero entre 0 y 7 que indica en que orientacion
// se encuentra la palabra, en caso de que la palabra no se encuentre en
// la tabla retorna -1.
// La palabra se representa con una array de chars y la sopa de letras se
// representa con un array que contiene arrays de char.


int dirPalabra(char *palabra, int numeroFilas, int numeroColumnas, char ** tabla){

    int longPalabra = strlen(palabra);
    int dFilas[8]    = { -1,-1,-1, 0, 0, 1, 1, 1 }; // Desplazamiento en Filas.
    int dColumnas[8] = { -1, 0, 1,-1, 1,-1, 0, 1 }; // Desplazamiento en Columnas.

    for(int i = 0 ;  i<numeroFilas ; i++){
        for(int j = 0; j<numeroColumnas; j++){
            if(tabla[i][j] == palabra[0])

                for(int dir = 0; dir<8 ; dir++){

                    int posFinalFilas = i + (longPalabra-1) * dFilas[dir],
                    posFinalColumnas = j + (longPalabra-1) * dColumnas[dir];

                    if(entraEnEstaDireccion(posFinalFilas,posFinalColumnas,numeroFilas,numeroColumnas))
                        if(estaEnEstaDireccion(longPalabra,i+dFilas[dir],j+dColumnas[dir],palabra,tabla,dFilas[dir],dColumnas[dir]))
                            return dir;

                }
        }
    }
    return -1;
}


// mostrarOrientacionPalabra: array of Char, Int -> None
// Toma una palabra y un numero que representa la orientacion
// en la que se encuentra en la tabla, y muestra en pantalla
// con palabras en que direccion y sentido se encentra la palabra
// en caso que no se encuentre la palabra es aclarado.
// La palabra se representa con un array de char y la direccion
// con un numero.

void mostrarOrientacionPalabra(char *palabra, int dir){

    char direcciones [8][100] = {   "Diagonal -> arriba-izquierda",
                                    "Vertical -> abajo-arriba",
                                    "Diagonal -> derecha-arriba",
                                    "Horizontal -> derecha-izquierda",
                                    "Horizontal -> izquierda-derecha",
                                    "Diagonal -> abajo-izquierda",
                                    "Vertical -> arriba-abajo",
                                    "Diagonal -> abajo-derecha"  };


    printf("%s\t\t",palabra);

    if(dir == -1){
        printf("No se encuentra en la tabla.\n");
    } else {
        printf("%s\n",direcciones[dir]);
    }

}



// ingresoTabla : Int , Int , Int -> Char **
// Crea y reserva memoria para una "Tabla",
// guarda en ella lo que se ingresa por teclado o lo que se
// lee desde el archivo y retorna su direccion.

char ** ingresoTabla(int nFilas, int nColumnas, int op){

    char ** tabla = malloc(sizeof(char *) * nFilas);

    for(int i = 0 ; i < nFilas ; i++){
        *(tabla+i) = malloc(sizeof(char)*(nColumnas+1));
        if(op==1) printf("Ingrese la fila %d de la tabla: ",i+1);
        scanf("%s",tabla[i]);
        mayusculas(tabla[i]);
    }

    system("clear");

    return tabla;

}

// ingresoUniverso : Int , Int -> Char **
// Crea y reserva memoria para una lista de palabras,
// guarda en ella lo que se ingresa por teclado o lo que se
// lee desde el archivo y retorna su direccion.

char ** ingresoUniverso(int tUniverso, int op){

    int largoMaximo = 50;
    char ** Universo = malloc(sizeof(char *) * tUniverso);

    for(int i = 0 ; i < tUniverso ; i++){

        *(Universo+i) = malloc(sizeof(char) * largoMaximo);
        if(op==1) printf("\nIngrese la %d palabra del Universo: ",i+1);
        scanf("%s",Universo[i]);
        mayusculas(Universo[i]);

    }

    system("clear");

    return Universo;
}

// ingresoTamanios : Int *, Int *, Int *, Int * -> None
// Toma 4 punteros que apuntan a variables que son ingresadas
// y modificadas.

void ingresoTamanios(int *tamanioUniverso, int *numeroFilas, int *numeroColumnas, int *op){

    printf("(1)Realizar el ingreso por teclado.\n(2)Realizar el ingreso por medio del archivo 'SopaLetras.txt'\n");
    scanf("%d",op);

    if(*op==2)freopen("a1.in","r",stdin);

    if(*op==1)printf("Ingrese el tamanio del Universo: ");
    scanf("%d",tamanioUniverso);

    if(*op==1)printf("Ingrese el numero de filas: ");
    scanf("%d",numeroFilas);

    if(*op==1)printf("Ingrese el numero de columnas: ");
    scanf("%d",numeroColumnas);

    system("clear");

}

