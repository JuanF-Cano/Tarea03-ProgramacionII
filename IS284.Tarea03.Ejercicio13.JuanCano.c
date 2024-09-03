/* 
- Fecha de publicación: 2/09/2024
- Hora de publicación: 9:15 am
- Versión de su código: 2.0
- Autor. Ing(c): Juan Fernando Cano Duque
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Nombre y versión del Sistema Operativo(S.O) sobre el que compilo y probo los ejecutables: windows 10.0.22631
- Versión del compilador utilizado: Compilado con GCC 6.3.0 (MinGW.org GCC-6.3.0-1)
- Presentado a: Doctor Ricardo Moreno Laverde
- Universidad Tecnológica de Pereira
- Programa de Ingeniería de Sistemas y Computación
- Asignatura IS284 Programación II

- Descripción del programa: Este programa recibe por teclado 75 números enteros e imprime por pantalla:
    * Cantidad de números Mayores a 150
    * Número mayor y número menor encontrado en el grupo
    * Cantidad de Números negativos encontrados
    * Promedio de los Positivos Encontrados.

    Salvedad: El programa solo funciona si se le ingresan números enteros que no superen el tamaño máximo que cabe en un dato int
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h> // Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función evaluateNumbers que pide un número recursivamente y evaluúa 
void evaluateNumbers(int greaterThan150, int major, int minor, int negativeNumbers, int avarage, int count) {
    // greaterThan150: Cuenta cuántos números son mayores a 150.
    // major: Almacena el número más grande encontrado.
    // minor: Almacena el número más pequeño encontrado.
    // negativeNumbers: Cuenta cuántos números negativos se han ingresado.
    // avarage: Acumula la suma de los números positivos para calcular el promedio.
    // count: Lleva la cuenta de cuántos números han sido ingresados.

    int number = 0; // Variable local que almacena temporalmente el número ingresado por el usuario.

    // Solicita al usuario que ingrese un número y lo guarda en 'number'.
    printf("Ingrese un numero(%i): ", count);
    scanf("%i", &number);

    // Si no se han procesado los 75 números, continúa la evaluación.
    if (count < 75) {
        // Incrementa el contador si el número es mayor a 150.
        if (number > 150) {
            greaterThan150++;
        }
        // Actualiza 'major' si el número es el más grande hasta ahora.
        if (number > major) {
            major = number;
        }
        // Actualiza 'minor' si el número es el más pequeño hasta ahora.
        if (number < minor) {
            minor = number;
        }
        // Incrementa el contador de números negativos si el número es negativo.
        if (number < 0) {
            negativeNumbers++;
        }
        // Suma el número positivo a 'avarage' para luego calcular el promedio.
        if (number > 0) {
            avarage += number;
        }
        // Llama recursivamente a la función con los valores actualizados.
        evaluateNumbers(greaterThan150, major, minor, negativeNumbers, avarage, count + 1);
    } else {
        // Maneja el caso en que no se hayan ingresado números positivos para evitar división por cero.
        if ((75 - negativeNumbers) > 0) {
            printf("\nCantidad de n%cmeros Mayores a 150: %i\nN%cmero mayor: %i\nN%cmero menor: %i\nDatos negativos: %i\nPromedio de los n%cmeros positivos: %.2f", 
            163, greaterThan150, 163, major, 163, minor, negativeNumbers, 163, avarage / (75. - negativeNumbers));
        } else {
            printf("\nCantidad de n%cmeros Mayores a 150: %i\nN%cmero mayor: %i\nN%cmero menor: %i\nDatos negativos: %i\nNo se ingresaron n%cmeros positivos para calcular el promedio.",
            163, greaterThan150, 163, major, 163, minor, negativeNumbers, 163);
        } // Fin else ((75 - negativeNumbers) > 0)
    } // Fin else (count < 75)
} // Fin función evaluateNumbers


int main() { // Inicio función principal

    // Llamado a la función que pide los 72 números, evalúa e imprime la cantidad de mayores a 150, el mayor, el menor, 
    // la cantidad de negativos y el promedio de los positivos
    evaluateNumbers(0, 0, 0, 0, 0, 1);

    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el caracter de nueva linea restante en el buffer
    printf("\n\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
} // Fin función principal