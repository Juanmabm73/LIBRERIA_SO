#include "libreria.h" // libreria propia con comillas porque es nuestra no de c
#include <stdio.h>    //manejo de entrada salida
#include <stdlib.h>   //para poder hacer uso de memoria dinamica
#include <string.h>   //para poder manejar cadenas string





// implementación 

int head(int N){




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