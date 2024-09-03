/* 
- Fecha de publicación: 3/09/2024
- Hora de publicación: 2:10 pm
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

- Descripción del programa: Este programa imprime las tablas de multiplicar del 1 al 10

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 9, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función MakeTables con parametros table y row, para imprimir cada fila de cada tabla
void MakeTables(int table, int row) {
    // Como son 10 tablas, se imprime siempre y cuando el número de tabla sea menor o igual a 10
    if (table <= 10) {
        // Como son 10 multiplos por tabla, se imprime siempre y cuando el número de fila sea menor o igual a 10
        if (row <= 10) {
            // Imprimimos la fila con el correspondiente resultado de la operación
            printf("%i X %i = %i\n", table, row, table * row);
            MakeTables(table, row + 1); // Llamado recursivo a la función
            // La tabla se mantiene y va aumentando la fila
        } else {
            printf("\n"); // Imprimimos salto de línea cuando haya acabado de imprimir una fila, para que haya orden
            MakeTables(table + 1, 1); // Llamado recursivo a la función
            // Se reinicia el valor de fila a 1 y se aumenta en 1 la tabla para que imprima la tabla siguiente
        } // Fin if (row <= 10)
    } // Fin if (table <= 10)
    return; // Se termina la función
} // fin función MakeTables

int main() {

    // Llamamos a la función MakeTables con los parametros iniciales de tabla y fila
    MakeTables(1, 1); // Al ser de tipo void no devuelve nada

    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("Presione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
}
