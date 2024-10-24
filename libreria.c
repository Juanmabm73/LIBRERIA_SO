#include "libreria.h" // libreria propia con comillas porque es nuestra no de c
#include <stdio.h>    //manejo de entrada salida
#include <stdlib.h>   //para poder hacer uso de memoria dinamica
#include <string.h>   //para poder manejar cadenas string





// implementación 

int head(int N){
 char buffer[1024];
    int count = 0;

    while (count < N && fgets(buffer, sizeof(buffer), stdin) != NULL)
    // fgets lee una linea desde la entrada estándar en este caso siendo
    // buffer donde queremos almacenar los caracteres
    // sizeof el tamaño que queremos leer
    // stdin de donde leemos las lineas
    {
        printf("%s", buffer); // imprimimos la linea por pantalla
        count++;             // incrementamos el buffer
    }



}



int tail(int N){
    int init = 0;
    char *buffer = (char *)malloc(1024*(sizeof(char)));
    int count = 0;
    char a[N];
    int i;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL){

        if (count >= N) {  // despues de las N primeras lineas
            
            strcpy(a[init],buffer);
            init += 1;
            
            if (init == N){
                init = 0;
            }
        } else {    //primeras n lineas leidas
            strcpy(a[count],buffer);
        }

        count++;
    }
    
    for ( init; init < N; init++){
        printf("%s", a[init]);
    }

    for ( i = 0; i < init; i++){
        printf("%s", a[i]);
    }
    
    
}



int longlines(int N){


}