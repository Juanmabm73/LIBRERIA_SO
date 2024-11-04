#include "libreria.c" // libreria propia con comillas porque es nuestra no de c
#include <stdio.h>    //manejo de entrada salida
#include <stdlib.h>   //para poder hacer uso de memoria dinamica
#include <string.h>   //para poder manejar cadenas string

int main(int argc, char *argv[])
{
    int N = 10;            // lineas que se muestran por defecto
    char *function = NULL; // guardaremos el nombre de la funcion que nos pidan

    if (argc <= 1)
    {
        fprintf(stderr, "Error debes escribir el nombre de la función -head/-tail/-longlines \n");
        return 1;
    }
    else
    {
        function = argv[1]; // guardamos el nombre de la función que ocupa la segunda posicion(1 en el array) en argv

        if (argc > 2)
        {
            N = atoi(argv[2]); // guardamos el numero de lineas a leer en caso de que nos lo ponga
            if (N < 1)
            {
                fprintf(stderr, "Error el número de líneas es negativo o cero \n");
                return 1;
            }
        }


        // strcmp devuelve 0 si las cadenas son iguales diferente de 0 en caso contrario
        if (strcmp(function, "-head") == 0)
        {
            printf("Vamos a ejecutar la función %s \n", function);
            head(N);
        }
        else if (strcmp(function, "-tail") == 0)
        {
            printf("Vamos a ejecutar la función %s\n", function);
            tail(N);
        }
        else if (strcmp(function, "-longlines") == 0)
        {
            printf("Vamos a ejecutar la función %s \n", function);
            longlines(N);
        }
        else
        {
            fprintf(stderr, "El argumento pasado %s es incorrecto \n", argv[1]);
        }
    }

    return 0;
}
