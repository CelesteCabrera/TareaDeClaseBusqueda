#include <iostream>
#include <stdlib.h>

using namespace std;

/*
    Inicializar un arreglo de tamaño n=100 de forma automatica. Crear un algoritmo
    para realizar:
        - Busqueda Secuencial
        - Busqueda Binaria
    Preguntar al usuario el valor que desea buscar y el tipo de algoritmo a usar.
        - Si encuentra el valor, mostrar el numero y la posicion dentro del arreglo
        en donde se encuentra.
*/

int busquedaSecuencial(int *array, int valor_a_buscar, int tamanioArreglo)
{
    for (int i = 0; i< tamanioArreglo; i++) {
        if (valor_a_buscar == array[i]) {
            cout << "Se encuentra en la posicion " << i + 1 << endl;
        }
   }
}

int busquedaBinaria(int *array, int valor_a_buscar, int tamanioArreglo)
{
    int inicio = 0;
    int pivote_central;
    int finaliza = tamanioArreglo - 1;

    while (inicio <= finaliza) {
        pivote_central = (inicio + finaliza) / 2;

        if (valor_a_buscar == array[pivote_central]) {
            cout << "Se encuentra en la posición " << pivote_central + 1 << endl;
            return array[pivote_central];
        } else {
            if (array[pivote_central] > valor_a_buscar) {
                finaliza = pivote_central - 1;
            } else {
                inicio = pivote_central + 1;
            }
        }
    }
    return -1;
}

void print(int *array, int tamanioArreglo)
{
   for (int i = 0; i < tamanioArreglo; i++) {
        cout << array[i] << "  ";
   }
   cout << endl << endl;
}

int main()
{
    int tamanioArreglo;
    int valor_a_buscar;
    cout << "Ingresa el tamaño del array" << endl;
    cin >> tamanioArreglo;

    int array[tamanioArreglo];

    //srand(time(NULL));
    for (int i = 0; i < tamanioArreglo; i++) {
        array[i] = rand() % 100;
    }

    cout << endl;
    cout << "Array al inicio: " << endl;
    print(array, tamanioArreglo);

    cout << "Busqueda lineal -> Ingresa el elemento a buscar: ";
    cin >> valor_a_buscar;
    busquedaSecuencial(array, valor_a_buscar, tamanioArreglo);

    cout << "Array ordenado: " << endl;
    quicksort(array, 0, tamanioArreglo);
    print(array, tamanioArreglo);

    cout << "Busqueda binaria -> Ingresa el elemento a buscar: ";
    cin >> valor_a_buscar;
    busquedaBinaria(array, valor_a_buscar, tamanioArreglo);
}
