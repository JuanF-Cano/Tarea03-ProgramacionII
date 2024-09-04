/* 
- Fecha de publicación: 3/09/2024
- Hora de publicación: 10:00 pm
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

- Descripción del programa: Este programa recibe por teclado el valor de x y la cantidad de digitos a sumar en la serie de teylor, e imprime el resultado del seno para esa x

    Salvedad: El programa solo funciona si se le ingresan un valor de x positivo no mayor a 2 y un número de k entero positivo no mayor a 30, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h> // Librería que contiene las funciones estándar para entrada y salida de datos
#include <math.h> // Librería con funciones matemáticas como el pow()

// Inicio función GetFactorial Devuelve el factorial del número ingresado 
double GetFactorial(long int n) {
    if (n <= 1) { // Inicio condición cota
        return 1; // Devolvemos 1 para los valores de 0! y 1!
    } else {
        return n * GetFactorial(n - 1); // Llamada recursiva a la función
        // Multiplicamos n por el factorial de n - 1
    } // Fin condición cota
}// Fin función GetFactorial

double GetSen(double x, int limit, int k) {
    if (k <= limit) { // Mientras el limite inferior no sea mayor al limite superior se continúa con la recursión
        return (pow(-1, k) * pow(x, 2 * k + 1)) / GetFactorial((2 * k) + 1) + GetSen(x, limit, k + 1); // Llamado recursivo
        // Suma el término de x con los valores de k actuales y vuelve a llamar a la función con (k + 1)
    } else {
        return 0; // Cuando el límite sea pasado no se evalúa más, sino que devuelve 0 para no afectar a la suma
    }// Fin if (k <= limit)
} // Fin función GetSen

int main() {
    double x = 0; // Variable que va a contener el número ingresado y se mandará como parametro a la función GetSen
    int limit = 0; // Variable que guarda el límite superior de la sumatoria par calcular el valor aproximado de la exponencial

    // Pedimos el número a calcular y lo guardamos en la variable x
    printf("\nIngrese el valor de x en radianes a evaluar: "); 
    scanf("%lf", &x);
    // Pedimos el número de terminos para evaluar la serie de taylor y lo guardamos en limit
    printf("Ingrese el n%cmero de terminos con los que desea calcular: ", 163);
    scanf("%d", &limit);

    // Llamamos a la función GetSen e imprimimos el valor que devuelve
    printf("%lf", GetSen(x, limit, 0));

    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("\n\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Consumimos el caracter de nueva línea restante en el buffer
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
}
