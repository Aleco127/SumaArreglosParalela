# Suma de Arreglos en Paralelo con OpenMP

Proyecto que demuestra la suma paralela de dos arreglos utilizando la libreria OpenMP en C++.

## Descripcion

El programa crea dos arreglos de N elementos, les asigna valores y realiza la suma en paralelo utilizando `#pragma omp parallel for` con planificacion estatica y chunks configurables.

## Compilacion

### Visual Studio
1. Crear un proyecto de consola C++
2. Ir a Propiedades del proyecto > C/C++ > Lenguaje > Compatibilidad con OpenMP > Si (/openmp)
3. Compilar y ejecutar

### Linea de comandos (MSVC)
```
cl /EHsc /openmp SumaArreglosParalela.cpp
```

### GCC
```
g++ -fopenmp SumaArreglosParalela.cpp -o SumaArreglosParalela
```

## Configuracion

Las constantes de precompilacion permiten ajustar:
- `N` - Tamano de los arreglos (default: 1000)
- `chunk` - Tamano de los pedazos por hilo (default: 100)
- `mostrar` - Cantidad de elementos a imprimir (default: 10)
