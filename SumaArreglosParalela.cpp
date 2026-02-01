#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <ctime>

#define N 1000
#define chunk 100
#define mostrar 10

void imprimeArreglo(float *d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    std::cout << "Tamano de los arreglos: " << N << std::endl;
    std::cout << "Tamano del chunk: " << chunk << std::endl;
    std::cout << "Numero de hilos disponibles: " << omp_get_max_threads() << std::endl;
    std::cout << std::endl;

    float a[N], b[N], c[N];
    int i;

    // Inicializar arreglos con calculos
    for (i = 0; i < N; i++)
    {
        a[i] = i * 10;
        b[i] = (i + 3) * 3.7f;
    }

    int pedazos = chunk;

    // Medir tiempo de ejecucion paralela
    double inicio = omp_get_wtime();

    #pragma omp parallel for \
        shared(a, b, c, pedazos) private(i) \
        schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    double fin = omp_get_wtime();

    std::cout << "Suma paralela completada en " << (fin - inicio) * 1000 << " ms" << std::endl;
    std::cout << std::endl;

    // Imprimir los primeros elementos de cada arreglo
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c (a+b): " << std::endl;
    imprimeArreglo(c);

    // Verificacion manual
    std::cout << "\nVerificacion: a[0] + b[0] = " << a[0] << " + " << b[0] << " = " << c[0] << std::endl;
    std::cout << "Verificacion: a[9] + b[9] = " << a[9] << " + " << b[9] << " = " << c[9] << std::endl;

    std::cout << "\nPresione Enter para salir...";
    std::cin.get();

    return 0;
}

void imprimeArreglo(float *d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
