#!/bin/bash

# Compilar la librería
gcc -c libreria.c -o libreria.o

# Crear la librería estática
ar rcs liblibreria.a libreria.o

# Compilar el programa de prueba y enlazarlo con la librería
gcc test.c -L. -llibreria -o test

# Limpiar archivos objeto intermedios
rm libreria.o

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación completada con éxito"
else
    echo "Error durante la compilación"
fi