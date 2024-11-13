#include "libreria.h" // libreria propia con comillas porque es nuestra no de c
#include <stdio.h>    // manejo de entrada salida
#include <stdlib.h>   // para poder hacer uso de memoria dinamica
#include <string.h>   // para poder manejar cadenas string
#include <stdbool.h>

// implementación

int head(int N)
{
    printf("Se esta ejecutando la funcion head \n");
    char *buffer = (char *)malloc(1024 * sizeof(char));
    int i = 0;

    while (i < N && fgets(buffer, 1024, stdin) != NULL)
    // fgets lee una linea desde la entrada estándar en este caso siendo
    // buffer donde queremos almacenar los caracteres
    // sizeof el tamaño que queremos leer
    // stdin de donde leemos las lineas
    {
        printf("%s", buffer); // imprimimos la linea por pant
        i++;                  // incrementamos el buffer
    }

    free(buffer);
}

int tail(int N)
{

    printf("Se esta ejecutando la funcion tail \n");
    int init = 0;
    char *buffer = (char *)malloc(1024 * (sizeof(char)));
    int count = 0;
    char **a = (char **)malloc(N * sizeof(char *)); // array de punteros a char (aqui guardaremos las lineas q leamos de stdin)
    int i;
    int j;

    // podriamos hacer una función de esto pero no la vemos necesaria para esta libreria en concreto ya que solo se usa en dos funciones pero sería una posible mejora    
    for (i = 0; i < N; i++)
    {
        a[i] = (char *)malloc(1024 * sizeof(char));
        if (a[i] == NULL)
        {
            fprintf(stderr, "Error al reservar memoria \n");

            // si ha dado error debemos hacer free del resto del array
            for (j = 0; j < i; j++)
            {
                free(a[j]);
            }
            return 1;
        }
    }

    // la idea es tener un array de N posiciones y tener localizada la primera línea que se debe de mostrar con tail
    // el orden de escritura es hacia la derecha de init si se acaba el array se da una especie de vuelta al principio del array
    // siguiendo en orden hasta init
    // init apunta a la línea más antigua

    while (fgets(buffer, 1024, stdin) != NULL)
    {
        if (count >= N) {                   // despues de las N primeras líneas cuando se completa el array
            strcpy(a[init], buffer);        // metemos en la posición más antigua machacando dicha línea
            init += 1;                     // avanzamos init a la siguiente frase la nueva más antigua

            if (init == N) {               // si llegamos al final del array con init el init pasa al principio
                init = 0;
            }
        }
        else {                             // primeras n lineas leidas
            strcpy(a[count], buffer);
        }
        count++;
    }

    // impresión por salida estándar

    if (count < N) {                       //contempla el caso de que no se haya llegado a llenar el array al completo
        for (i = 0; i < count; i++) {
            printf("%s \n", a[i]);
        }
    }
    else {
        for (i = 0; i < N; i++) {
            printf("%s \n", a[(init + i) % N]); // %N para que si llegamos al final del array volvamos al principio
        }
    }

    // vaciamos el buffer, el array, y cada posición del array
    for (i = 0; i < N; i++) {
        free(a[i]);
    }
    free(a);
    free(buffer);
}

int longlines(int N) {

    printf("Se esta ejecutando la funcion longlines \n");
    int j;
    char *buffer = (char *)malloc(1024 * (sizeof(char)));
    char **a = (char **)malloc(N * sizeof(char *));
    int i;
    int len;

    // reservamos memoria
    for (i = 0; i < N; i++) {
        a[i] = (char *)malloc(1024 * sizeof(char));
        if (a[i] == NULL) {
            fprintf(stderr, "Error al reservar memoria \n");

            // si ha dado error debemos hacer free del resto del array
            for (j = 0; j < i; j++) {
                free(a[j]);
            }
            return 1;
        }
    }

    i = 0;
    while (fgets(buffer, 1024, stdin) != NULL) {

        len = strlen(buffer);                               // nos guardamos la longitud de la nueva línea

        if (i < N) { // array sin llenar
            j = i - 1;                                      // con esto controlamos no entrar en punteros que apunten a basura y la inserción de la primera línea
            while (j >= 0 && len > strlen(a[j])) {
                strcpy(a[j + 1], a[j]);                     // adelantamos una posicion el mas pequeño para reemplazarlo fuera del bucle por el grande
                j--;                                        // vamos al anterior
            }

            strcpy(a[j + 1], buffer);                      // introducimos el valor mas grande en su sitio
            i++;
        } else {                                           // si el array ya está lleno
            if (len > strlen(a[N - 1])) {
                                                          // machacamos la ultima linea del array ya que tiene q salir por longitud ya que hay una mas grande
                j = N - 2;                               // para empezar desde el penultimo
                while (j >= 0 && len > strlen(a[j])) {
                    strcpy(a[j + 1], a[j]);
                    j--;
                }

                strcpy(a[j + 1], buffer);
                i = N; // para no volver a entrar en el if
            }
        }
    }

    for (j = 0; j < i; j++)
    {
        printf("%s \n", a[j]);
        free(a[j]); // vaciamos a la vez que mostramos
    }
    free(a);
    free(buffer);
    return 0;
}