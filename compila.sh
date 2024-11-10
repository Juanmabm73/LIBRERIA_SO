#!/bin/bash

# Compilar la librería
gcc -c libreria.c -o libreria.o


if [ $? -ne 0 ]
then 
    echo "Error al compilar la libreria"
    exit 1
else 
    echo "Libreria compilada correctamente"
fi

# Crear la librería estática
ar rcs liblibreria.a libreria.o

# Compilar el programa de prueba y enlazarlo con la librería
gcc -o test test.c -L. -llibreria

# Limpiar archivos objeto intermedios
rm libreria.o

# Comprobar si la compilación fue exitosa
if [ $? -eq 0 ]; then
    echo "Compilación completada con éxito"
else
    echo "Error durante la compilación"
fi