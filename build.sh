#!/usr/bin/env bash

# Se crea la carpeta de los archivos de salida del proyecto
if [[ ! -d "output" ]]; then
  echo "Creating output folder"
  mkdir output
fi


# Se crea la carpeta de los archivos objeto del proyecto
if [[ ! -d "bin" ]]; then
  echo "Creating bin folder"
  mkdir bin
fi

# Se compila el proyecto usando las instrucciones de makefile
make

