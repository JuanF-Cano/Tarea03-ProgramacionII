/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 6:50 pm
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

- Descripción del programa: Este programa recibe por pantalla el número que el uuarip desea invertir y lo imprime en pantalla

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 999'999.999, ya que si no podría haber un desbordamiento de datos. De lo contrario no se garantizan resultados 
    Al ser un número entero, cuando se invierte si queda un 0 a la izquierda no se mostrará
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h> // Librería que contiene las funciones estándar para entrada y salida de datos
#include <math.h> // Librería que contiene funciones matemáticas avanzadas como el log10 (Logaritmo base 10)

// Inicio función ReverseNumber que recibe un número y lo devuelve invertido
int ReverseNumber(int number) {
    int digits = floor(log10(number)); // Con log10 sacamos logaritmo base 10 y con floor redondeamos ese resultado hacia abajo
    // Con el log encontramos el exponente al que hay que elevar a 10 para obtener number, que es la cantidad de posiciones que tiene 
    // Guardamos el número de dígitos en digits para elevar 10 a ese número y hacer que el último número pase al primero

    if (digits == 0) { // Cuando lleguemos al primer digito se devuelve para finalizar
        return number; // Caso base
    } else { 
        return pow(10, digits) * (number % 10) + ReverseNumber(number / 10); // Llamada recursiva a la función
        // Extraemos el número que está en las unidades con (number % 10) y le pasamos el resto del número a la nueva función
    }
} // Fin función ReverseNumber

int main() { // Inicio función principal
    int number = 0; // Variable que va a contener el número que se va a invertir y que se mandará como argunmento a la función ReverseNumber

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie Triangular
    printf("\nIngrese el n%cmero que desea invertir: ", 163);
    scanf("%i", &number); // Se recibe el dato y se guarda dentro de la variable number

    // Llamamos a la función que devuelve el número ingresado pero invertido
    printf("%i invertido es: %i\n", number, ReverseNumber(number));
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el caracter de nueva linea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
} // Fin función principal