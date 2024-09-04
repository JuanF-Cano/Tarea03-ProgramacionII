/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 12:35 pm
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

- Descripción del programa: Este programa recibe por teclado un número entero y devuelve el factorial de ese número

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 20, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función GetFactorial Devuelve el factorial del número ingresado
double GetFactorial(long int n) {
    if (n <= 1) { // Inicio condición cota
        return 1; // Devolvemos 1 para los valores de 0! y 1!
    } else {
        return n * GetFactorial(n - 1); // Llamada recursiva a la función
        // Multiplicamos n por el factorial de n - 1
    } // Fin condición cota
}// Fin función GetFactorial
    
int main() {
    int number = 0; // Variable que va a contener el número ingresado y se mandará como parametro a la función factorial
    
    // Pedimos un número y lo guardamos en la variable number
    printf("\nIngrese un n%cmero: ", 163); 
    scanf("%i", &number);

    // Llamamos a la función GetFactorial e imprimimos el resultado del ella con el número ingresado
    printf("\nEl factorial de %i es %.0lf", number, GetFactorial(number));    

    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el caracter de nueva linea restante en el buffer
    printf("\n\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
}
