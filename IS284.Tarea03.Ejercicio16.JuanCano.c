/* 
- Fecha de publicación: 3/09/2024
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

- Descripción del programa: Este programa recibe por teclado un número n entero positivo y devuelve la suma del factorial de cada digito de 0! hasta n!

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 11, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función GetFactorial  Devuelve un entero (El factorial del número ingresado) 
unsigned long int GetFactorial(long int n) {
    if (n <= 1) { // Inicio condición cota
        return 1; // Devolvemos 1 para los valores de 0! y 1!
    } else {
        return n * GetFactorial(n - 1); // Llamada recursiva a la función
        // Multiplicamos n por el factorial de n - 1
    } // Fin condición cota
}// Fin función GetFactorial

unsigned long int SummationFactorial(long int n) {
    if (n < 0) { // Inicio condición cota
        return 0; // Devolvemos 0 para que cuando ya se haya calculado cada digito hasta n no afecte a la suma
    } else {
        return GetFactorial(n) + SummationFactorial(n - 1); // Llamado recursivo a la función 
        // Sumamos el Factorial del número actual con el factorial del número anterior, hasta llegar a 0
    } // Fin condición cota
} // Fin función SummationFactorial
    
int main() {
    int number = 0; // Variable que va a contener el número ingresado y se mandará como parametro a la función para sumar factoriales
    
    // Pedimos un número y lo guardamos en la variable number
    printf("\nIngrese un n%cmero: ", 163); 
    scanf("%i", &number);

    // Validamos que el número ingresado no sea negativo
    if (number >= 0) { // Si es positivo ejecutamos el programa normalmente
        // Llamamos a la función SummationFactorial e imprimimos el resultado del ella con el número ingresado
        printf("\nLa suma de todos los factoriales de 0 a %i es: %lu", number, SummationFactorial(number));    
        //----------------------------------------- Finalización del programa -------------------------------------------
        getchar(); // Consumimos el caracter de nueva linea restante en el buffer
        printf("\n\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
        getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    } else {
        // Si el número es negativo, damos el mensaje de que ingrese uno positivo y llamamos de nuevo a main
        printf("El número debe ser un entero positivo");
        main();
    }
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
}