/* 
- Fecha de publicación: 31/08/2024
- Hora de publicación: 9:50 pm
- Versión de su código: 1.0
- Autor. Ing(c): Juan Fernando Cano Duque
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Nombre y versión del Sistema Operativo(S.O) sobre el que compilo y probo los ejecutables: windows 10.0.22631
- Versión del compilador utilizado: Compilado con GCC 6.3.0 (MinGW.org GCC-6.3.0-1)
- Presentado a: Doctor Ricardo Moreno Laverde
- Universidad Tecnológica de Pereira
- Programa de Ingeniería de Sistemas y Computación
- Asignatura IS284 Programación II

- Descripción del programa: Este programa muestra los números de la serie de Fibonacci, que sean menores a 10000

    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función PrintFibonacciSeries. Esta función va a imprimir la serie de fibonacci hasta el número menor 10000 y no devuelve nada
void PrintFibonacciSeries(int n1, int n2) {
    // n1: Primer digito y digito imprimible de la serie de fibonacci
    // n2: Segundo digito y digito que trae el proximo digito para la serie.

    if (n1 < 10000) { // Condición cota de la función
        printf("%i", n1); // Imprime el digito de la serie siempre y cuando sea menor a 10000
        // Si el siguiente número de la serie es menor a 10000 pone una coma (Esto para que no ponga coma en el último número)
        if (n2 < 10000) {
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf("\n\n"); // Imprimimos espacios al final de la recursión para que en consola se vea más ordenado
        }
        PrintFibonacciSeries(n2, n1 + n2); // Llamado recursivo a la función en la que se pasa n2 como el n1 y la suman de n1 + n2 para el término siguiente
    } // Fin condición cota de la función

    return; // No devuelve nada
}// Fin función PrintFibonacciSeries

int main() { // Inicio función principal

    // Imprimimos una descripción de lo que hace el programa
    printf("\nEste programa presenta la serie de Fibonacci como la serie que comienza con los digitos 1 y 0 y va sumando progresivamente los dos ultimos elementos de la serie, asi: 0 1 1 2 3 5 8 13 21 34.......");
    printf("\nPara este programa, se presentar%c la serie de Fibonacci hasta llegar sin sobrepasar el n%cmero 10,000.\n", 160, 163);

    PrintFibonacciSeries(0, 1); // Llamado a la función que va a imprimir la serie con los dos primeros digitos de esta (0 y 1)
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
} // Fin función principal