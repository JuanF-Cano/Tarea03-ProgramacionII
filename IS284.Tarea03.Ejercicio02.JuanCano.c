/* 
- Fecha de publicación: 31/08/2024
- Hora de publicación: 10:17 pm
- Versión de su código: 1.0
- Autor. Ing(c): Juan Fernando Cano Duque
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Nombre y versión del Sistema Operativo(S.O) sobre el que compiló y probó los ejecutables: windows 10.0.22631
- Versión del compilador utilizado: Compilado con GCC 6.3.0 (MinGW.org GCC-6.3.0-1)
- Presentado a: Doctor Ricardo Moreno Laverde
- Universidad Tecnológica de Pereira
- Programa de Ingeniería de Sistemas y Computación
- Asignatura IS284 Programación II

- Descripción del programa: Este programa muestra los números de la serie de Fibonacci, entre 0 y 100, y muestra la suma de estos

    Salvedad: Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función PrintFibonacciSeries. Esta función va a imprimir la serie de fibonacci hasta el número menor 100 y devuelve la suma de los dígitos
int PrintFibonacciSeries(int n1, int n2) {
    // n1: primer dígito y dígito imprimible de la serie de fibonacci
    // n2: Segundo dígito y dígito que trae el próximo dígito para la serie.

    if (n1 < 100) { // Condición cota de la función
        printf("%i", n1); // Imprime el dígito de la serie siempre y cuando sea menor a 100
        // Si el siguiente número de la serie es menor a 100 pone coma (Para que no ponga coma luego del último número)
        if (n2 < 100) {
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        }
        // Llamado recursivo a la función en la que se pasa n2 como el n1 y la suma de n1 + n2 para el término siguiente
        return n1 += PrintFibonacciSeries(n2, n1 + n2); //Suma los dígitos del n1 desde el último llamado hasta el primero
    } // Fin condición cota de la función
    return 0; // En el último llamado recursivo devuelve 0 para no afectar a la suma
}// Fin función PrintFibonacciSeries

int main() { // Inicio función principal
    
    int suma = 0; // Variable que va a guardar lo que devuelve la función PrintFibonacciSeries, que es la suma de los dígitos de la serie entre 1 y 100
    
    // Imprimimos una descripción de lo que hace el programa
    printf("\nEste programa presenta la suma de los elementos de la serie de Fibonacci entre 0 y 100.");
    printf("\nLos n%cmeros a sumar son:\n", 163);

    // Llamado a la función que va a imprimir la serie con los dos primeros dígitos de esta (0 y 1)
    suma = PrintFibonacciSeries(0, 1); 
    // guardamos en la variable suma lo que devuelve la función, que es la suma de la serie, en este caso 232 

    printf(" y su suma es: %i\n", suma); // Mensaje de salida 

    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estándar para decir que el programa finalizó de manera correcta
} // Fin función principal
